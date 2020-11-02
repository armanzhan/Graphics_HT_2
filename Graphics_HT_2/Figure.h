#pragma once
#include "Point.h"
#include "Header.h"

class Figure
{
private:
	std::vector <Point *> vertex;
public:
	Figure(std::vector <Point *> vertex) ;
	void vertex_back(Point * point);
	void vertex_pop();
	std::vector<float> extremum();

	Point * get_vertex(int i);
	int size();
	~Figure();
};

