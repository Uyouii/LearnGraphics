#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <iostream>
#include "vec3.h"


int main() {
	int nx = 200, ny = 100, n = 3;
	char* data = new char[nx * ny * n];

	for (int row = 0; row < ny; row++) {
		for (int col = 0; col < nx; col++) {
			vec3 color(float(col) / float(nx), float(ny - row - 1) / float(ny), 0.2);
			int ir = int(255.99 * color.r());
			int ig = int(255.99 * color.g());
			int ib = int(255.99 * color.b());

			int index = row * nx * n + col * n;
			data[index] = ir;
			data[index + 1] = ig;
			data[index + 2] = ib;
		}
	}
	stbi_write_jpg("images/2 the vec3 class.jpg", nx, ny, n, data, 50);
	system("pause");
}