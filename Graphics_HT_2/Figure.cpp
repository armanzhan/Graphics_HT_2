#include "Figure.h"



Figure::Figure(std::vector <Point *> vertex): vertex(vertex)
{
}

void Figure::vertex_back(Point * point)
{
	vertex.push_back(point);
}

void Figure::vertex_pop()
{
	vertex.pop_back();
}

std::vector<float> Figure::extremum()
{
	std::vector<float> vec;
	for (int i = 0; i != vertex.size(); ++i) {
		if (i == 0) { 
			vec.push_back(vertex[i]->x);
			vec.push_back(vertex[i]->x); 
			vec.push_back(vertex[i]->y);
			vec.push_back(vertex[i]->y);
		}
		else {
			if (vertex[i]->x < vec[0])
				vec[0] = vertex[i]->x;
			if (vertex[i]->x > vec[1])
				vec[1] = vertex[i]->x;
			if (vertex[i]->y < vec[2])
				vec[2] = vertex[i]->y;
			if (vertex[i]->y > vec[3])
				vec[3] = vertex[i]->y;
		}
	}
	return vec;
}

Point * Figure::get_vertex(int i)
{
	if (i < vertex.size())
		return vertex[i];
	return nullptr;
}

int Figure::size()
{
	return vertex.size();
}


Figure::~Figure()
{
}
