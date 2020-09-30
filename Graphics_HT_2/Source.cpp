#include "Header.h"

void mydeg(float &e, int what) {
	double a = e;
	for (int i = 0; e < what; ++i)
		e *= a;
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
int sign(int A) {
	if (A > 0)
		A = 1;
	else
		if (A < 0)
			A = -1;
		else
			A = 0;
	return A;
}
TGAColor operator*(TGAColor color, float size) {
	TGAColor clr((int)(color.r * size), (int)(color.g * size), (int)(color.b * size), (int)(color.a * size));
	return clr;
}

//___LINES__________________

void lineBrasenhem(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color)
{
	int A = y2 - y1;
	int B = x2 - x1;
	int signA, signB;
	signA = sign(A);
	signB = sign(B);
	float f = 0;
	float x = x1;
	float y = y1;
	image.set(x, y, color);
	if (x1 == x2)
		for (int i = 0; i != A; ++i)
			image.set(x1, y1 + i * signA, color);
	else
		if (y1 == y2)
			for (int i = 0; i != B; ++i)
				image.set(x1 + i * signB, y1, color);
		else {
			if (abs(A) < abs(B)) {
				while (x != x2 && y != y2) {
					f = f + A * signA;
					if (f > 0) {
						f -= B * signB;
						y += signA;
					}
					x += signB;
					image.set(x, y, color);
				}
			}
			else {
				while (x != x2 && y != y2) {
					f = f + B * signB;
					if (f > 0) {
						f -= A * signA;
						x += signB;
					}
					y += signA;
					image.set(x, y, color);
				}

			}
		}
}
void lineDDAsimple(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color) 
{
	float dx = x2 - x1;
	float dy = y2 - y1; 

	float max = std::max(abs(dx), abs(dy));
	float e = 1 / max;

	float x = x1;
	float y = y1;
	for (int i = 0; i != max; ++i) {
		image.set(x + 0.5, y + 0.5, color);
		x += dx*e;
		y += dy*e;
	}
}
void lineDDAsymetric(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color) {
	float dx = x2 - x1;
	float dy = y2 - y1;

	int max = std::max(abs(dx), abs(dy));
	
	float e = 2;
	mydeg(e, max);
	e = 1 / e;

	float x = x1;
	float y = y1;
	for (int i = 0; i != max; ++i) {
		image.set(x + 0.5, y + 0.5, color);
		x += dx * e;
		y += dy * e;
	}
}

//___CIRCLE_________________

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
			delta += 2 * (++x) + 1;
			continue;
		}
		if ((delta > 0) && (error > 0)) {
			delta -= 2 * (--y) + 1;
			continue;
		}
		delta += 2 * ((++x) - (--y));
	}
}
void circleDDA(int x0, int y0, int radius, TGAImage &image, TGAColor color) {

}
void circleParametr(int x0, int y0, int radius, TGAImage &image, TGAColor color) {

}

//___размытие______________

void lineBrasenhemMod(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color) {

}
float fpart(float x) {
	return x - int(x);
}
void lineVu(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color) {
	if (x1 == x2 || y1 == y2) {
		lineBrasenhem(x1, y1, x2, y2, image, color);
	}
	else {
		//int i = 4;
		//int st = 255 / i;
		int dx = abs(x2 - x1);
		int dy = abs(y2 - y1);
		int signX = sign(x2 - x1);
		int signY = sign(y2 - y1);

		if (dx > dy) {
			int x = x1;
			float y = y1;
			while (x != x2) {
				float light_up = abs((int)(y) - y);
				float light_dn = 1 - light_up;

				image.set(int(x), int(y), color * light_up);
				image.set(int(x), int(y - 1), color * light_dn);
				x += signX;
				y += (float)dy / (float)std::max(dx, dy) * signY;
			}
		}
		else {
			float x = x1;
			int y = y1;
			while (y != y2) {
				float light_rt = abs((int)(x) - x);
				float light_lt = 1 - light_rt;

				image.set(int(x), int(y), color * light_rt);
				image.set(int(x - 1), int(y), color * light_lt);

				x += (float)dx / (float)std::max(dx, dy) * signX;
				y += signY;
			}
		}
	}
	/*if (x1 == x2 || y1 == y2) {
		lineBrasenhem(x1, y1, x2, y2, image, color);
	}
	else {
		if (x2 < x1) {
			std::swap(x2, x1);
			std::swap(y2, y1);
		}
		int dx = x2 - x1;
		int dy = y2 - y1;
		float grdnt = float(dy) / float(dx);

		float xend = x1;
		float yend = y1 + grdnt * (xend - 1);
		float xgap = 1 - fpart(x1 + 0.5);
		int xpxl1 = xend;
		int ypxl1 = int(yend);
		float light1 = (1 - fpart(yend)) * xgap;
		float light2 = fpart(yend) * xgap;
		TGAColor clr1(int(color.r * light1), int(color.g * light1), int(color.b * light1), int(color.a * light1));
		TGAColor clr2(int(color.r * light2), int(color.g * light2), int(color.b * light2), int(color.a * light2));
		image.set(xpxl1, ypxl1, clr1);
		image.set(xpxl1, ypxl1 + 1, clr2);
		float intery = yend + grdnt; // первое y-пересечение для цикла

		xend = x2;
		yend = y2 + grdnt * (xend - x2);
		xgap = fpart(x2 + 0.5);
		float xpxl2 = xend;  // будет использоваться в основном цикле
		float ypxl2 = int(yend);
		image.set(xpxl2, ypxl2, clr1);
		image.set(xpxl2, ypxl2 + 1, clr2);

		for (int x = xpxl1 + 1; x != xpxl2; ++x) {
			light1 = 1 - fpart(intery);
			light2 = fpart(intery);
			TGAColor clr_1(int(color.r * light1), int(color.g * light1), int(color.b * light1), int(color.a * light1));
			TGAColor clr_2(int(color.r * light2), int(color.g * light2), int(color.b * light2), int(color.a * light2));

			image.set(x, int(intery), clr_1);
			image.set(x, int(intery) + 1, clr_2);
			intery = intery + grdnt;
		}
	}*/
}

//____TESTS_________________
//_test_lines____(0,0)-(300,100)___________
void testBrasenhem(TGAImage &image, TGAColor color) {
	lineBrasenhem(50, 50, 100, 50, image, color);

	lineBrasenhem(50, 50, 0, 75, image, color);
	lineBrasenhem(50, 50, 100, 100, image, color);
	lineBrasenhem(50, 50, 75, 0, image, color);

	lineBrasenhem(50, 50, 75, 100, image, color);

	/*lineBrasenhem(50, 50, 25, 100, image, color);
	lineBrasenhem(50, 50, 0, 100, image, color);
	lineBrasenhem(50, 50, 0, 75, image, color);*/
}
void testDDAsimple(TGAImage &image, TGAColor color) {
	lineDDAsimple(150, 50, 150, 100, image, color);
	lineDDAsimple(150, 50, 175, 0, image, color);
	lineDDAsimple(150, 50, 200, 100, image, color);
	lineDDAsimple(150, 50, 175, 100, image, color);

}
void testDDAsymetric(TGAImage &image, TGAColor color) {
	lineDDAsymetric(250, 50, 300, 100, image, color);
	lineDDAsymetric(250, 50, 300, 50, image, color);
	lineDDAsymetric(250, 50, 200, 75, image, color);
}

void testlineBrasenhemMod(TGAImage &image, TGAColor color) {
	//lineBrasenhemMod(0, 150, 100, 100, image, color);
}
void testlineVu(TGAImage &image, TGAColor color) {
	//lineVu(150, 150, 110, 200, image, color);
	lineVu(150, 150, 200, 155, image, color);
	//lineVu(150, 150, 200, 160, image, color);
	lineVu(150, 150, 200, 165, image, color);

	lineVu(150, 150, 160, 200, image, color);
	lineVu(150, 150, 135, 100, image, color);
}

//_test_circles_____________
void testCircleBrasenhem(TGAImage &image, TGAColor color) {
	circleBrasenhem(350, 50, 50, image, color);
	circleBrasenhem(350, 50, 25, image, color);
	circleBrasenhem(350, 50, 10, image, color);
}
void testCircleDDA(TGAImage &image, TGAColor color) {
}
void testCircleParametr(TGAImage &image, TGAColor color) {


}


//___MAIN__________________
int main(int argc, char** argv) {
	TGAImage image(600, 200, TGAImage::RGB);

	testBrasenhem(image, WHITE);//_________________________+
	testDDAsimple(image, RED);//___________________________+
	testDDAsymetric(image, GREEN);//_______________________+-(присутствует 4-связность)

	testCircleBrasenhem(image, WHITE);//___________________+-(присутствует 4-связность)
	//testCircleDDA(image, RED);
	//testCircleParametr(image, GREEN);

	//testlineBrasenhemMod( image, BLUE);
	testlineVu( image, GREEN);//___________________________+

	//image.flip_vertically();
	image.write_tga_file("output.tga");

	return 0;
}
