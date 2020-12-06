#pragma once
#include "Header.h"
#include "Point.h"
#include "Figure.h"
#include "Model.h"

namespace MyPaint {
	const TGAColor WHITE = TGAColor(255, 255, 255, 255);
	const TGAColor RED = TGAColor(255, 0, 0, 255);
	const TGAColor GREEN = TGAColor(0, 255, 0, 255);
	const TGAColor BLUE = TGAColor(0, 0, 255, 255);
	const float PI = 3.14;
	
	void mydeg(float &e, int what);
	int mysign(int a);
	TGAColor operator*(TGAColor& color, float size);
	TGAColor operator+(TGAColor& color1, TGAColor color2);
	bool operator==(TGAColor color1, TGAColor color2);
	//___LINES__________________
	void lineBrasenhem(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color);
	void lineDDAsimple(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color);
	void lineDDAsymetric(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color);

	//___CIRCLE_________________
	void circleBrasenhem(int x0, int y0, int radius, TGAImage &image, TGAColor color);
	void circleDDA(int x0, int y0, int radius, TGAImage &image, TGAColor color);
	void circleParametr(int x0, int y0, int radius, TGAImage &image, TGAColor color);

	//___размытие______________
	void lineBrasenhemMod(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color);
	float fpart(float x);
	void lineVu(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color);

	// фигуры и не только
	void drawFigure(Figure* figure, TGAImage& image, TGAColor color, std::vector<int> place);

	void drawObj_lines(std::vector<std::vector<int>> * ribs, MyMatrix* vertex, TGAImage &image, TGAColor color);
	void drawObj_zalivka(Model * mod_, TGAImage &image, TGAColor color);

	//методы_заливки_________________________________
	void an_iterative_algorithm_with_a_seed(Point point, std::vector<int> place, TGAImage& image, TGAColor color);
	void line__by__line_fill_algorithm_with_seed(Point point, std::vector<int> place, TGAImage& image, TGAColor color);
	void line__by__line_algorithm_with_a_list_of_edge_points(Figure triangle, Point point, std::vector<int> place, TGAImage& image, TGAColor color);
}