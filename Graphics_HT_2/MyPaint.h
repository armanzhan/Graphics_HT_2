#pragma once
#include "Header.h"
#include "Point.h"
#include "Figure.h"
#include "Object.h"

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
	void drawFigure(Figure* figure, TGAImage& image, TGAColor color);
	void drawFigures(std::vector <Figure*> figures, TGAImage& image, TGAColor color);

	void drawTriangle(std::vector<Point*> points, int f1, int f2, int f3, TGAImage& image, TGAColor color);
	void drawTriangle1(Point* point1, Point* point2, Point* point3, TGAImage& image, TGAColor color);
	void drawObj(Object * obj, TGAImage &image, TGAColor color);

	//методы_заливки_________________________________

}