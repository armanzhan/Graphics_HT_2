#pragma once
#include "Point.h"
#include "Header.h"

class Figure
{
private:
	std::vector <Point *> vertex;
public:
	Figure();
	void vertex_back(Point * point);
	void vertex_pop();
	Point * get_vertex(int i);
	int size();
	~Figure();
};

