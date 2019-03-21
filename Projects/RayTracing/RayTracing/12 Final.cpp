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

hitable *random_scene() {
	int n = 500;
	float littleRidus = 0.4f;
	hitable **list = new hitable *[n + 1];
	list[0] = new sphere(vec3(0, -1000, 0), 1000, new lambertian(vec3(0.5, 0.5, 0.5)));
	int i = 1;
	for (int a = -20; a < 20; a+=2) {
		for (int b = -20; b < 20; b+=2) {
			float choose_mat = RANDOM_NUM;
			vec3 center(a + 1.8 * RANDOM_NUM, littleRidus, b + 1.8 * RANDOM_NUM);
			if ((center - vec3(4, littleRidus, 0)).length() > 1.8) {
				if (choose_mat < 0.7) { // diffuse
					list[i++] = new sphere(center, littleRidus,
						new lambertian(vec3(RANDOM_NUM * RANDOM_NUM, RANDOM_NUM * RANDOM_NUM, RANDOM_NUM * RANDOM_NUM)));
				}
				else if (choose_mat < 0.9) {// mental
					list[i++] = new sphere(center, littleRidus,
						new metal(vec3(0.5 * (1 + RANDOM_NUM), 0.5 * (1 + RANDOM_NUM), 0.5 * (1 + RANDOM_NUM)), 0.3 * RANDOM_NUM));
				}
				else {	// glass
					list[i++] = new sphere(center, littleRidus, new dielectric(1.5));
				}
			}
		}
	}

	list[i++] = new sphere(vec3(0, 2, 0), 2.0, new dielectric(1.5));
	list[i++] = new sphere(vec3(-4, 2, 0), 2.0, new lambertian(vec3(0.4, 0.2, 0.1)));
	list[i++] = new sphere(vec3(4, 2, 0), 2.0, new metal(vec3(0.7, 0.6, 0.5), 0.0));

	return new hitable_list(list, i);
}

int main() {
	int nx = 800, ny = 400, n = 3, ns = 100;
	char* data = new char[nx * ny * n];

	srand((unsigned)time(NULL));

	hitable *world = random_scene();

	vec3 lookfrom(7, 3, 6);
	vec3 lookat(0, 2, 0);
	float dist_to_focus = (lookfrom - lookat).length();
	float aperture = 0.2;

	camera cam(lookfrom, lookat, vec3(0, 1, 0), 45, float(nx) / float(ny), aperture, dist_to_focus);

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
	stbi_write_jpg("images/12 Final.jpg", nx, ny, n, data, 100);
	//system("pause");
}