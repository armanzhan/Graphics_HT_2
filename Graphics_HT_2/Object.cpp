#include "Object.h"







Point * Object::get_vertex(int i)
{
	return tops.at(i);
}

int Object::size()
{
	return ribs.size();
}

std::vector<int>* Object::getRibs(int i)
{
	return &(ribs.at(i));
}

Object::Object(float x, float y, float z, std::vector<Point*> tops, std::vector<std::vector<int>> ribs):
	x(x), y(y),z(z), tops(tops), ribs(ribs) {}

Object::~Object()
{
	int size = tops.size();
	for (int i = size - 1; i != -1; --i) {
		delete tops[i];
		tops.pop_back();
	}
}
