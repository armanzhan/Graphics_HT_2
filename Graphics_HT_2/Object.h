#pragma once
#include "Point.h"
#include "Figure.h"

class Object
{
private:
	float x, y, z;
	std::vector<Point*> tops;
	std::vector<std::vector<int> > ribs; 
public:
	Point* get_vertex(int i);
	int size();
	std::vector<int>* getRibs(int i);
	Object(float x, float y, float z, std::vector<Point*> tops, std::vector<std::vector<int> > ribs);
	~Object();
};

