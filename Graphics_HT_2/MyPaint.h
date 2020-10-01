#pragma once
#include "Header.h"
struct Point
{
	float x, y;
	Point(float x, float y);
	~Point();
};

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

	void drawObj(TGAImage &image, std::string name);
}