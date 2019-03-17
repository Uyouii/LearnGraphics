#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <iostream>
#include "sphere.h"
#include "hitable_list.h"
#include "material.h"
#include "camera.h"
#include "tools.h"

vec3 getColor(const ray& r, hitable *world, int depth) {
	hit_record rec;
	if (world->hit(r, 0.001, FLT_MAX, rec)) {
		ray scattered;
		vec3 attenuation;
		if (depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
			//std::cout << 0 << std::endl;
			return attenuation * getColor(scattered, world, depth + 1);
		}
		else {
			//std::cout << 1 << std::endl;
			return vec3(0, 0, 0);
		}
	}
	else {
		vec3 unit_direction = unit_vector(r.direction());
		float t = 0.5 * (unit_direction.y() + 1.0);
		return (1 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
	}
}

int main() {
	int nx = 400, ny = 200, n = 3, ns = 100;
	char* data = new char[nx * ny * n];

	srand((unsigned)time(NULL));

	hitable *list[5];
	list[0] = new sphere(vec3(0, 0, -1), 0.5, new lambertian(vec3(0.8, 0.3, 0.3)));
	list[1] = new sphere(vec3(0, -100.5, -1), 100, new lambertian(vec3(0.8, 0.8, 0.0)));
	list[2] = new sphere(vec3(1, 0, -1), 0.5, new metal(vec3(0.8, 0.6, 0.2), 0.1));
	list[3] = new sphere(vec3(-1, 0, -1), 0.5, new dielectric(1.5));
	list[4] = new sphere(vec3(-1, 0, -1), -0.45, new dielectric(1.5));
	hitable *world = new hitable_list(list, 5);

	camera cam;

	for (int row = 0; row < ny; row++) {
		for (int col = 0; col < nx; col++) {
			vec3 color(0, 0, 0);
			for (int s = 0; s < ns; s++) {
				float u = float(col + RANDOM_NUM) / float(nx);
				float v = float(ny - row - 1 + RANDOM_NUM) / float(ny);
				ray r = cam.get_ray(u, v);
				vec3 p = r.point_at_parameter(2.0);
				color += getColor(r, world, 0);
			}

			color /= float(ns);
			color = vec3(sqrt(color[0]), sqrt(color[1]), sqrt(color[2]));

			int ir = int(255.99 * color.r());
			int ig = int(255.99 * color.g());
			int ib = int(255.99 * color.b());

			int index = row * nx * n + col * n;
			data[index] = ir;
			data[index + 1] = ig;
			data[index + 2] = ib;
		}
	}
	stbi_write_jpg("images/9 Dielectrics.jpg", nx, ny, n, data, 100);
	//system("pause");
}