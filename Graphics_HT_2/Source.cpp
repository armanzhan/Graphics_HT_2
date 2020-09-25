#include "Header.h"


void myline(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {

	int num = std::max(abs(x1 - x0), abs(y1 - y0));
	float dy = (float)(y1 - y0) / (float)num;
	float dx = (float)(x1 - x0) / (float)num;

	for (int t = 0; t != num; ++t) {
		int x = x0 + dx * t;
		int y = y0 + dy * t;
		image.set(x, y, color);
	}
}

void lineBrasenhem(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color) {
	int A = y2 - y1;
	int B = x2 - x1;
	int signA, signB;
	signA = (A > 0) ? 1 : -1;
	signB = (B > 0) ? 1 : -1;
	int f = 0;
	int x = x1;
	int y = y1;
	image.set(x, y, color);

	if (abs(A) < abs(B)) {
		while (x != x2 && y != y2) {
			f = f + A * signA;
			if (f > 0) {
				f -= B * signB;
				y += signA;
			}
			x -= signB;
			image.set(x,y,color);
		}
	}
	else {
		while (x != x2 && y != y2) {
			f = f + B * signB;
			if (f > 0) {
				f -= A * singA;
				x -= singB;
			}
			y += singA;
			image.set(x,y,color);
		}

	}
}


int main(int argc, char** argv) {
	TGAImage image(200, 200, TGAImage::RGB);
	
	myline(100, 100, 200, 150, image, WHITE);
	myline(100, 100, 200, 50, image, WHITE);
	myline(100, 100, 0, 150, image, WHITE);
	myline(100, 100, 0,  50, image, WHITE);
	
	image.flip_vertically();
	image.write_tga_file("output.tga");
	return 0;
}
