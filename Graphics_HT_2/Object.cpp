#include "Object.h"



MyMatrix Object::getPosition()
{
	return MyMatrix(
		{ 
		{ get_x() },
		{ get_y() }, 
		{ get_z() } 
		}
	);
}

double Object::get_x()
{
	return position.at(0).at(0);
}

double Object::get_y()
{
	return position.at(0).at(1);
}

double Object::get_z()
{
	return position.at(0).at(2);
}

MyMatrix Object::get_local_axes()
{
	return local_axes;
}

Object::Object(MyMatrix& position, MyMatrix& local_axes, Model* models, TGAColor color):
	position(position), local_axes(local_axes), model(model), color(color)
{}
Object::Object( MyMatrix& position, MyMatrix& local_axes, TGAColor color) :
	local_axes(local_axes), position(position), color(color)
{}


Object::~Object()
{
	// не писать, модель внешн€€. она может использоватьс€ во многих объектах
}
