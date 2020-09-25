#include "Header.h"

void mydeg(float &e, int deg) {
	float a = 1;
	for (int i = 0; i != deg; ++i) {
		a *= e;
	}
	e = a;
};

int mysign(int a) {
	if (a > 0)
		return 1;
	else
		if (a < 0)
			return -1;
		else
			return 0;
}


//___LINES__________________
void lineBrasenhem(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color) 
{
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
				f -= A * signA;
				x -= signB;
			}
			y += signA;
			image.set(x,y,color);
		}

	}
}
void lineDDAsimple(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color) 
{
	float dx = x2 - x1;
	float dy = y2 - y1; 

	int max = std::max(abs(dx), abs(dy));
	float e = 1.0 / (float)max;

	int x = x1;
	int y = y1;
	for (int i = 0; i != max; ++i) {
		image.set(x, y, color);
		x += dx*e;
		y += dy*e;
	}
}
void lineDDAsymetric(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color) {
	float dx = x2 - x1;
	float dy = y2 - y1;

	int max = std::max(abs(dx), abs(dy));
	
	float e = 2;
	mydeg(e, (int)max);
	e = 1 / e;

	int x = x1;
	int y = y1;
	for (int i = 0; i != max; ++i) {
		image.set(x, y, color);
		x += dx * e;
		y += dy * e;
	}
}

//___CIRCLE_________________
float func1(int x, int y, int r) 
{ 
	return x * x + y * y - r * r; 
}

float func2(int x, int y, int r)
{
	return x * x + y * y - r * r;
}

void circleBrasenhem(int x0, int y0, int radius, TGAImage &image, TGAColor color) {
	int x = 0;
	int y = radius;
	int delta = 1 - 2 * radius;
	int error = 0;
	while (y >= 0) {
		image.set(x0 + x, y0 + y, WHITE);
		image.set(x0 + x, y0 - y, WHITE);
		image.set(x0 - x, y0 + y, WHITE);
		image.set(x0 - x, y0 - y, WHITE);
		error = 2 * (delta + y) - 1;
		if ((delta < 0) && (error <= 0)) {
			delta += 2 * ++x + 1;
			continue;
		}
		if ((delta > 0) && (error > 0)) {
			delta -= 2 * --y + 1;
			continue;
		}
		delta += 2 * (++x - --y);
	}
}

void circleDDA(int x0, int y0, int radius, TGAImage &image, TGAColor color) {

}

void circleParametr(int x0, int y0, int radius, TGAImage &image, TGAColor color) {


}

//____TESTS_________________
void testBrasenhem(TGAImage &image, TGAColor color) {

}

void testDDAsimple(TGAImage &image, TGAColor color) {
	
}

void testDDAsymetric(TGAImage &image, TGAColor color) {
	
}



int main(int argc, char** argv) {
	TGAImage image(200, 200, TGAImage::RGB);

	testBrasenhem(image, WHITE);
	testDDAsimple(image, RED);
	testDDAsymetric(image, GREEN);

	circleBrasenhem(50, 50, 50, image, RED);

	image.flip_vertically();
	image.write_tga_file("output.tga");

	/*
	float a = 2;
	mydeg(a, (int)std::log(10));
	std::cout << (int)std::log(10) << std::endl;
	std::cout << a << std::endl;
	int c = 0;
	std::cin >> c;
	*/
	return 0;
}
