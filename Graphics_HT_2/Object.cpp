#include "Object.h"

MyMatrix Object::getTops()
{
	return tops;
}

std::vector<double> Object::get_vertex(int i)
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

Object::Object(float x, float y, float z, std::vector<std::vector<double> > tops, std::vector<std::vector<int>> ribs):
	x(x), y(y),z(z), tops(tops), ribs(ribs) {}

Object::~Object()
{
	/*int size = tops.size();
	for (int i = size - 1; i != -1; --i) {
		delete tops[i];
		tops.pop_back();
	}*/
}

void Object::turn3D(int axis, double angle)
{
	MyMatrix tops_ = tops;
	tops_.append(1);
	LinAlg::turn3D_(tops_, axis, angle);
	tops_.cut(0, tops.getSize(1), 0, tops.getSize(0));
	tops = tops_;
}

void Object::zoom3D(MyMatrix vec)
{
	MyMatrix tops_ = tops;
	tops_.append(1);
	LinAlg::zoom3D_(tops_, vec);
	tops_.cut(0, tops.getSize(1), 0, tops.getSize(0));
	tops = tops_;
}

void Object::parallel_translation3D(MyMatrix vec)
{
	MyMatrix tops_ = tops;
	tops_.append(1);
	LinAlg::parallel_translation3D_(tops_, vec);
	tops_.cut(0, tops.getSize(1), 0, tops.getSize(0));
	tops = tops_;
}

void Object::turn2D(int axis, double angle)
{
	MyMatrix tops_ = tops;
	tops_.append(1);
	LinAlg::turn3D_(tops_, 2/*ось z*/, angle);
	tops_.cut(0, tops.getSize(1), 0, tops.getSize(0));
	tops = tops_;
}

void Object::zoom2D(MyMatrix vec)
{
	if (vec.getSize(0) == 2) {
		vec.append({ {1} });
	}
	MyMatrix tops_ = tops;
	tops_.append(1);
	LinAlg::zoom3D_(tops_, vec);
	tops_.cut(0, tops.getSize(1), 0, tops.getSize(0));
	tops = tops_;
}

void Object::parallel_translation2D(MyMatrix vec)
{
	if (vec.getSize(0) == 2) {
		vec.append({ {0} });
	}
	MyMatrix tops_ = tops;
	tops_.append(1);
	LinAlg::parallel_translation3D_(tops_, vec);
	tops_.cut(0, tops.getSize(1), 0, tops.getSize(0));
	tops = tops_;
}

