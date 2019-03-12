#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <iostream>
#include "vec3.h"
#include "ray.h"

// t*t*dot(B,B) + 2*t*dot(A-C,B) + doc(C,C) - R*R = 0

bool hit_sphere(const vec3& center, float radius, const ray& r) {
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0 * dot(oc, r.direction());
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b * b - 4 * a*c;
	return (discriminant > 0);
}

vec3 color(const ray& r) {
	if (hit_sphere(vec3(0, 0, -1), 0.5, r))
		return vec3(0.8, 0, 0);
	vec3 unit_direction = unit_vector(r.direction());
	float t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}

int main() {
	int nx = 400, ny = 200, n = 3;
	char* data = new char[nx * ny * n];

	vec3 lower_left_corner(-2.0, -1.0, -1.0);
	vec3 horizontal(4.0, 0.0, 0.0);
	vec3 vertical(0.0, 2.0, 0.0);
	vec3 origin(0.0, 0.0, 0.0);

	for (int row = 0; row < ny; row++) {
		for (int col = 0; col < nx; col++) {
			float u = float(col) / float(nx);
			float v = float(ny - row - 1) / float(ny);
			ray r(origin, lower_left_corner + u * horizontal + v * vertical);
			vec3 co = color(r);
			int ir = int(255.99 * co.r());
			int ig = int(255.99 * co.g());
			int ib = int(255.99 * co.b());

			int index = row * nx * n + col * n;
			data[index] = ir;
			data[index + 1] = ig;
			data[index + 2] = ib;
		}
	}
	stbi_write_jpg("images/4 Adding a sphere.jpg", nx, ny, n, data, 100);
	system("pause");
}