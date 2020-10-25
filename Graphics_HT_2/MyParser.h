#pragma once
#include "Header.h"
#include "Point.h"
#include "MyPaint.h"
namespace MyParser {
	void drawObj1(TGAImage &image, std::string name);
	void drawObj2(TGAImage &image, std::string name);

	void firstWord(std::string& str, std::string& word);

	void findFirstFloat(std::string & str, float & number);
	void findFirstDouble(std::string & str, double & number);
	void findFirstInt(std::string & str, int & number);

	bool isFloat(const std::string& str);
	bool isInt(const std::string& str);

	
	void drawTriangle(std::vector<Point*> points, int f1, int f2, int f3, TGAImage& image, TGAColor color);
	void drawTriangle1(Point* point1, Point* point2, Point* point3, TGAImage& image, TGAColor color);
}
