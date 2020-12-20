#include "MyPaint.h"

void MyPaint::mydeg(float &e, int what) {
	double a = e;
	for (int i = 0; e < what; ++i)
		e *= a;
};
int MyPaint::mysign(int a) {
	if (a > 0)
		return 1;
	else
		if (a < 0)
			return -1;
		else
			return 0;
}
float MyPaint::fpart(float x) {
	return x - int(x);
}

TGAColor MyPaint::operator*(TGAColor& color, float size) {
	TGAColor clr((int)(color.r * size), (int)(color.g * size), (int)(color.b * size), (int)(color.a * size));
	return clr;
}
bool MyPaint::operator==(TGAColor color1, TGAColor color2) {
	return (color1.r == color2.r) && (color1.g == color2.g) && (color1.b == color2.b);
}
TGAColor MyPaint::operator+(TGAColor& color1, TGAColor color2)
{
	TGAColor clr((int)(color1.r + color2.r), (int)(color1.g + color2.g), (int)(color1.b + color2.b), (int)(color1.a + color2.a));
	return clr;
}
//___LINES__________________
void MyPaint::lineBrasenhem(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color)
{
	int A = y2 - y1;
	int B = x2 - x1;
	int signA, signB;
	signA = mysign(A);
	signB = mysign(B);
	float f = 0;
	float x = x1;
	float y = y1;
	image.set(x, y, color);
	if (x1 == x2)
		for (int i = 0; i != abs(A); ++i)
			image.set(x1, y1 + i * signA, color);
	else
		if (y1 == y2)
			for (int i = 0; i != abs(B); ++i)
				image.set(x1 + i * signB, y1, color);
		else {
			if (abs(A) < abs(B)) {
				while (x != x2) {
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
				while (y != y2) {
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
void MyPaint::lineDDAsimple(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color)
{
	float dx = x2 - x1;
	float dy = y2 - y1;

	float max = std::max(abs(dx), abs(dy));
	float e = 1 / max;

	float x = x1;
	float y = y1;
	for (int i = 0; i != max; ++i) {
		image.set(x + 0.5, y + 0.5, color);
		x += dx * e;
		y += dy * e;
	}
}
void MyPaint::lineDDAsymetric(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color) {
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
void MyPaint::circleBrasenhem(int x0, int y0, int radius, TGAImage &image, TGAColor color) {
	int x = 0;
	int y = radius;
	int delta = 1 - 2 * radius;
	int error = 0;
	while (y >= 0) {
		image.set(x0 + x, y0 + y, color);
		image.set(x0 + x, y0 - y, color);
		image.set(x0 - x, y0 + y, color);
		image.set(x0 - x, y0 - y, color);
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
void MyPaint::circleDDA(int x0, int y0, int radius, TGAImage &image, TGAColor color) {
	float y = radius;
	float stop = (float)radius / sqrt(2.) + 1;
	for (int x = 0; x < stop; ++x) {
		image.set((int)((float)x0 + x + 0.5), int((float)y0 + y + 0.5), color);
		image.set((int)((float)x0 + x + 0.5), int((float)y0 - y + 0.5), color);
		image.set((int)((float)x0 - x + 0.5), int((float)y0 - y + 0.5), color);
		image.set((int)((float)x0 - x + 0.5), int((float)y0 + y + 0.5), color);
		
		image.set((int)((float)x0 + y + 0.5), int((float)y0 + x + 0.5), color);
		image.set((int)((float)x0 + y + 0.5), int((float)y0 - x + 0.5), color);
		image.set((int)((float)x0 - y + 0.5), int((float)y0 - x + 0.5), color);
		image.set((int)((float)x0 - y + 0.5), int((float)y0 + x + 0.5), color);

		
		y -= (float)x / sqrt(radius*radius - x * x);
	}

}
void MyPaint::circleParametr(int x0, int y0, int radius, TGAImage &image, TGAColor color) {
	int x = radius, x1 = radius;
	int y = 0, y1 = 0;
	for (int i = 1; i != 45; ++i) {
		x1 = x;
		y1 = y;
		x = radius *cos(float(i) / 180.0 * PI);
		y = radius * sin(float(i) / 180.0 * PI);

		lineBrasenhem(x0 + x, y0 + y, x0 + x1, y0 + y1, image, color);
		lineBrasenhem(x0 - x, y0 + y, x0 - x1, y0 + y1, image, color);
		lineBrasenhem(x0 - x, y0 - y, x0 - x1, y0 - y1, image, color);
		lineBrasenhem(x0 + x, y0 - y, x0 + x1, y0 - y1, image, color);

		lineBrasenhem(x0 + y, y0 + x, x0 + y1, y0 + x1, image, color);
		lineBrasenhem(x0 - y, y0 + x, x0 - y1, y0 + x1, image, color);
		lineBrasenhem(x0 - y, y0 - x, x0 - y1, y0 - x1, image, color);
		lineBrasenhem(x0 + y, y0 - x, x0 + y1, y0 - x1, image, color);
	}
}
//___размытие______________
void MyPaint::lineBrasenhemMod(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color) {
	if ((x1 - x2)*(y1 - y2) == 0) {
		lineBrasenhem(x1, y1, x2, y2, image, color);
	}
	else {
		int I = 255;
		float x = x1;
		float y = y1;
		int px = abs(x2 - x1);
		int py = abs(y2 - y1);
		int signx = mysign(x2 - x1);
		int signy = mysign(y2 - y1);
		float t = I * py / px;
		float e_ = I / 2;
		float emax = I - t;
		if (px > py) {
			image.set(x, y, color * (t / 2));
			for (int i = 0; i < px; ++i) {
				if (e_ >= emax) {
					y += signy;
					e_ -= emax;
				}
				else {
					e_ += t;
				}
				x += signx;
				image.set(x, y, color * (t / 2));
			}
		}
		else {
			image.set(x, y, color * (t / 2));
			for (int i = 0; i < py; ++i) {
				if (e_ >= emax) {
					x += signx;
					e_ -= emax;
				}
				else {
					e_ += t;
				}
				y += signy;
				image.set(x, y, color * (t / 2));
			}
		}
	}


}
void MyPaint::lineVu(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color) {
	if (x1 == x2 || y1 == y2) {
		lineBrasenhem(x1, y1, x2, y2, image, color);
	}
	else {
		int dx = abs(x2 - x1);
		int dy = abs(y2 - y1);
		int signX = mysign(x2 - x1);
		int signY = mysign(y2 - y1);

		if (dx > dy) {
			int x = x1;
			float y = y1;
			while (x != x2) {
				float light_up = abs((int)(y)-y);
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
				float light_rt = abs((int)(x)-x);
				float light_lt = 1 - light_rt;

				image.set(int(x), int(y), color * light_rt);
				image.set(int(x - 1), int(y), color * light_lt);

				x += (float)dx / (float)std::max(dx, dy) * signX;
				y += signY;
			}
		}
	}
}
// фигуры и объекты
void MyPaint::drawFigure(Figure* figure, TGAImage& image, TGAColor color, std::vector<int> place)
{
	int size = figure->size();
	for (int i = 0; i != size; ++i) {
		MyPaint::lineBrasenhem(
			(figure->get_vertex(i % size)->x)		+ place.at(0),
			(figure->get_vertex(i % size)->y)		+ place.at(1),

			(figure->get_vertex((i + 1) % size)->x) + place.at(0),
			(figure->get_vertex((i + 1) % size)->y) + place.at(1),

			image, color);
	}
}
void MyPaint::drawObj_lines(std::vector<std::vector<int>> * all_ribs, MyMatrix* vertexes, TGAImage & image, TGAColor color)
{
	int a = image.get_height() / 2;
	int b = image.get_width() / 2;
	//double _z = 7;
	double __x = 2000;//7000;
	double __y = 2000;//7000;

	int size = all_ribs->size();

	for (int i = 0; i != size; ++i) { // int i = /*0*/1476; i != /*size*/1477; ++i
		std::vector<int> ribs = all_ribs->at(i);
		for (int j = 0; j != ribs.size(); ++j) {
			//if (vertexes->at(ribs.at(j % size)).at(2) > 0) {
				/*MyPaint::lineBrasenhem(
					(mod_->get_vertex(ribs.at(j	 % ribs.size()))->x) *__x + b,
					(mod_->get_vertex(ribs.at(j	 % ribs.size()))->y) *__y + a,
					(mod_->get_vertex(ribs.at((j + 1) % ribs.size()))->x) *__x + b,
					(mod_->get_vertex(ribs.at((j + 1) % ribs.size()))->y) *__y + a,
					image, color);*/
				MyPaint::lineVu(
					(vertexes->at(ribs.at(j	 % ribs.size())).at(0)) *__x + b,
					(vertexes->at(ribs.at(j	 % ribs.size())).at(1)) *__y + a,
					(vertexes->at(ribs.at((j + 1) % ribs.size())).at(0)) *__x + b,
					(vertexes->at(ribs.at((j + 1) % ribs.size())).at(1)) *__y + a,
					image, color);
			//}
		}
	}
}

void MyPaint::drawObj_zalivka(std::vector<std::vector<int>> * all_ribs, MyMatrix* vertexes, TGAImage & image, TGAColor color)
{
	int a = image.get_height() / 2;
	int b = image.get_width() / 2;
	//double _z = 7;
	double __x = 2000;//7000;
	double __y = 2000;//7000;

	int size = all_ribs->size();

	for (int i = 0; i != size; ++i) {
		std::vector<int> ribs = all_ribs->at(i);
		std::cout << "i = " << i << "---------------------------------------------" << std::endl;
		for (int j = 0; j != ribs.size(); ++j) {
			//std::cout << ribs.at(j) << " "<< vertexes->at(ribs.at(j	 % ribs.size())).at(0) *__x + b  << std::endl;
			//std::cout << ribs.at(j) << " "<< vertexes->at(ribs.at(j	 % ribs.size())).at(1) *__x + b  << std::endl;
			//if (vertexes->at(ribs.at(j % size)).at(2) > 0) {
				MyPaint::lineBrasenhem(
				(vertexes->at(ribs.at(j	 % ribs.size())).at(0)) *__x + b,
				(vertexes->at(ribs.at(j	 % ribs.size())).at(1)) *__y + a,
				(vertexes->at(ribs.at((j + 1) % ribs.size())).at(0)) *__x + b,
				(vertexes->at(ribs.at((j + 1) % ribs.size())).at(1)) *__y + a,
				image, color);
			//}
		}
		
		//float X = ((vertexes->at(ribs.at(0)).at(0)) + (vertexes->at(ribs.at(1)).at(0)) + (vertexes->at(ribs.at(2))).at(0)) * __x / 3;
		//float Y = ((vertexes->at(ribs.at(0)).at(1)) + (vertexes->at(ribs.at(1)).at(1)) + (vertexes->at(ribs.at(2))).at(1)) * __y / 3;
		//MyPaint::line__by__line_fill_algorithm_with_seed(Point(X, Y, 1), { b, a }, image, color);
	}
	
	for (int i = 0; i != size; ++i) {
		std::vector<int> ribs = all_ribs->at(i);
		//if (vertexes->at(ribs.at(0 % size)).at(2) > 0 && vertexes->at(ribs.at(1 % size)).at(2) > 0 && vertexes->at(ribs.at(2 % size)).at(2) > 0) {	
		float X = ((vertexes->at(ribs.at(0)).at(0)) + (vertexes->at(ribs.at(1)).at(0)) + (vertexes->at(ribs.at(2))).at(0)) * __x / 3;
		float Y = ((vertexes->at(ribs.at(0)).at(1)) + (vertexes->at(ribs.at(1)).at(1)) + (vertexes->at(ribs.at(2))).at(1)) * __y / 3;

		MyPaint::line__by__line_fill_algorithm_with_seed(Point(X, Y, 1), { b, a }, image, color);
		//}
	}
}

void MyPaint::an_iterative_algorithm_with_a_seed(Point point, std::vector<int> place, TGAImage& image, TGAColor color)
{
	int x = point.x + place.at(0);
	int y = point.y + place.at(1);
	if (!(image.get(x, y) == color)) {
		image.set(x, y, color);
		int i = 0;
		std::vector<int> steps = { 0 };
		while (steps.size() != 0 /*&& 20 != (i++)*/) {
			if (!(image.get(x, y + 1) == color)) {
				y++;
				steps.push_back(1);
				image.set(x, y, color);
			}
			else {
				if (!(image.get(x, y - 1) == color)) {
					y--;
					steps.push_back(2);
					image.set(x, y, color);
				}
				else {
					if (!(image.get(x + 1, y) == color)) {
						x++;
						steps.push_back(3);
						image.set(x, y, color);
					}
					else {
						if (!(image.get(x - 1, y) == color)) {
							x--;
							steps.push_back(4);
							image.set(x, y, color);
						}
						else {
							switch (steps[steps.size() - 1]) {
							case 1: {
								y--;
								break;
							}
							case 2: {
								y++;
								break;
							}
							case 3: {
								x--;
								break;
							}
							case 4: {
								x++;
								break;
							}
								defaut: {
									break;
							}
							}
							steps.pop_back();
						}
					}
				}
			}
		}
	}
}

void MyPaint::line__by__line_fill_algorithm_with_seed(Point point, std::vector<int> place, TGAImage & image, TGAColor color)
{
	int x = point.x + place.at(0);
	int y = point.y + place.at(1);
	
	if (!(image.get(x, y) == color)) {
		image.set(x, y, color);
		std::vector <std::vector<int>> stack = { {x, y} };
		int i = 0;
		do {
			x = stack[0][0];
			y = stack[0][1];
			stack.erase(stack.begin(), stack.begin() + 1);
			if (!(image.get(x, y) == color)) {
				image.set(x, y, color);
			}
			bool up = false;
			bool down = false;
			for (int i = 1; !(image.get(x + i, y) == color); ++i) {
				image.set(x + i, y, color);
				if (!up && !(image.get(x + i, y + 1) == color)) {
					stack.push_back({ x + i,y + 1 });
					up = true;
				}
				else {
					if (up && image.get(x + i, y + 1) == color) {
						up = false;
					}
				}

				if (!down && !(image.get(x + i, y - 1) == color)) {
					stack.push_back({ x + i, y - 1 });
					down = true;
				}
				else {
					if (down && image.get(x + i, y - 1) == color) {
						down = false;
					}
				}
			}
			for (int i = -1; !(image.get(x + i, y) == color); --i) {
				image.set(x + i, y, color);
				if (!up && !(image.get(x + i, y + 1) == color)) {
					stack.push_back({ x + i,y + 1 });
					up = true;
				}
				else {
					if (up && image.get(x + i, y + 1) == color) {
						up = false;
					}
				}

				if (!down && !(image.get(x + i, y - 1) == color)) {
					stack.push_back({ x + i, y - 1 });
					down = true;
				}
				else {
					if (down && image.get(x + i, y - 1) == color) {
						down = false;
					}
				}
			}
		} while (stack.size() != 0 /* &&  40 > (i++)/**/);
	}
}

void MyPaint::line__by__line_algorithm_with_a_list_of_edge_points(Figure triangle, Point point, std::vector<int> place, TGAImage & image, TGAColor color)
{
}
