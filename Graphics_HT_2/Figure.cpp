#include "Figure.h"



Figure::Figure()
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
