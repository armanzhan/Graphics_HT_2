#pragma once
#include "Figure.h"
#include "LinAlg.h" 

class Object
{
private:
	float x, y, z;
	MyMatrix tops;
	std::vector<std::vector<int> > ribs; 
public:
	MyMatrix getTops();
	std::vector<double> get_vertex(int i);
	int size();
	std::vector<int>* getRibs(int i);
	Object(float x, float y, float z, std::vector<std::vector<double>>, std::vector<std::vector<int>> ribs);
	~Object();

	void turn3D(int axis, double angle);
	void zoom3D(MyMatrix operator_);
	void parallel_translation3D(MyMatrix operator_);

	void turn2D(int axis, double angle);// предполагается, что плоская фигура - это фигура, лежащая в плоскости z=1 
	void zoom2D(MyMatrix operator_);
	void parallel_translation2D(MyMatrix operator_);
};

