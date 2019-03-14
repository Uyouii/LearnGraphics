#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <iostream>
#include "sphere.h"
#include "hitable_list.h"
#include "camera.h"
#include "time.h"


vec3 getColor(const ray& r, hitable *world) {
	hit_record rec;
	if (world->hit(r, 0.0, FLT_MAX, rec)) {
		return 0.5 * vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1);
	}
	else {
		vec3 unit_direction = unit_vector(r.direction());
		float t = 0.5 * (unit_direction.y() + 1.0);
		return (1 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
	}
}

int main() {
	int nx = 600, ny = 300, n = 3, ns = 50;
	char* data = new char[nx * ny * n];

	srand((unsigned)time(NULL));

	hitable *list[2];
	list[0] = new sphere(vec3(0, 0, -1), 0.5);
	list[1] = new sphere(vec3(0, -100.5, -1), 100);
	hitable *world = new hitable_list(list, 2);
	camera cam;

	for (int row = 0; row < ny; row++) {
		for (int col = 0; col < nx; col++) {
			vec3 color(0, 0, 0);
			for (int s = 0; s < ns; s++) {
				float ran = rand() / double(RAND_MAX);
				float u = float(col + ran) / float(nx);
				float v = float(ny - row - 1 + ran) / float(ny);
				ray r = cam.get_ray(u, v);
				vec3 p = r.point_at_parameter(2.0);
				color += getColor(r, world);
			}
			
			color /= float(ns);
			
			int ir = int(255.99 * color.r());
			int ig = int(255.99 * color.g());
			int ib = int(255.99 * color.b());

			int index = row * nx * n + col * n;
			data[index] = ir;
			data[index + 1] = ig;
			data[index + 2] = ib;
		}
	}
	stbi_write_jpg("images/6 Antialiasing.jpg", nx, ny, n, data, 100);
	system("pause");
}