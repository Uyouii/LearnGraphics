#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <iostream>


int main() {
	int nx = 200, ny = 100, n = 3;
	char* data = new char[nx * ny * n];

	for (int row = 0; row < ny ; row++) {
		for (int col = 0; col < nx; col++) {
			float r = float(col) / float(nx);
			float g = float(ny - row - 1) / float(ny);
			float b = 0;
			int ir = int(255.99 * r);
			int ig = int(255.99 * g);
			int ib = int(255.99 * b);
			int index = row * nx * n + col * n;
			data[index] = ir;
			data[index + 1] = ig;
			data[index + 2] = ib;
		}
	}
	stbi_write_jpg("images/1 out_an_image.jpg", nx, ny, n, data, 100);
	system("pause");
}