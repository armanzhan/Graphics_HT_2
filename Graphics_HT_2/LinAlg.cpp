#include "LinAlg.h"
//==============================================================================================
double LinAlg::MySin(double angle)
{
	angle *= (3.14 / 180);
	return sin(angle);
}
double LinAlg::MyCos(double angle)
{
	angle *= (3.14 / 180);
	return cos(angle);
}
//==============================================================================================
//==============================================================================================

MyMatrix LinAlg::zeros(int a, int b)
{
	std::vector<std::vector<double>> result;
	for (int i = 0; i != a; ++i) {
		std::vector<double> arr;
		for (int j = 0; j != b; ++j) {
			arr.push_back(0.0);
		}
		result.push_back(arr);
	}
	MyMatrix result_(result);
	return result_;
}
MyMatrix LinAlg::ones(int a, int b)
{
	std::vector<std::vector<double>> result;
	for (int i = 0; i != a; ++i) {
		std::vector<double> arr;
		for (int j = 0; j != b; ++j) {
			arr.push_back(1.0);
		}
		result.push_back(arr);
	}
	MyMatrix result_(result);
	return result_;
}
MyMatrix LinAlg::eye(int a, int b)
{
	std::vector<std::vector<double>> result;
	for (int i = 0; i != a; ++i) {
		std::vector<double> arr;
		for (int j = 0; j != b; ++j) {
			if (i != j)
				arr.push_back(0.0);
			else
				arr.push_back(1.0);
		}
		result.push_back(arr);
	}
	MyMatrix result_(result);
	return result_;
}
//==============================================================================================
//==============================================================================================

MyMatrix LinAlg::parallel_translation3D(MyMatrix & matrix, MyMatrix& vector)
{
	if (vector.getSize(1) == 1 && vector.getSize(0) == 3 && matrix.getSize(1) == 3) {
		MyMatrix matr0 = matrix;
		matr0.append(1);

		MyMatrix oper = eye(4, 4);
		oper.set(vector.at(0).at(0), 3, 0);
		oper.set(vector.at(1).at(0), 3, 1);
		oper.set(vector.at(2).at(0), 3, 2);
		MyMatrix matr = matr0 * oper;
		matr.cut(0, matr.getSize(1) - 1, 0, matr.getSize(0));
		return matr;
	}
	else {
		if (vector.getSize(1) == 1 && vector.getSize(0) == 3 && matrix.getSize(1) == 4) {
			MyMatrix oper = eye(4, 4);
			oper.set(vector.at(0).at(0), 3, 0);
			oper.set(vector.at(1).at(0), 3, 1);
			oper.set(vector.at(2).at(0), 3, 2);
			MyMatrix matr = matrix * oper;
			return matr;
		}
	}
}
void LinAlg::parallel_translation3D_(MyMatrix & matrix, MyMatrix& vector)
{
	if (vector.getSize(1) != 1 || vector.getSize(0) != 3 || matrix.getSize(1) != 4) {
		//...
	}
	else {
		MyMatrix oper = eye(4, 4);
		oper.set(vector.at(0).at(0), 3, 0);
		oper.set(vector.at(1).at(0), 3, 1);
		oper.set(vector.at(2).at(0), 3, 2);
		matrix *= oper;
	}
}

//----------------------------------------------------------------------------------------------

MyMatrix LinAlg::zoom3D(MyMatrix & matrix, MyMatrix & vector)
{
	if (vector.getSize(1) == 1 && vector.getSize(0) == 3 && matrix.getSize(1) == 3) {
		MyMatrix matr0 = matrix;
		matr0.append(1);

		MyMatrix oper = eye(4, 4);
		oper.set(vector.at(0).at(0), 0, 0);
		oper.set(vector.at(1).at(0), 1, 1);
		oper.set(vector.at(2).at(0), 2, 2);
		MyMatrix matr = matr0 * oper;

		matr.cut(0, matr.getSize(1) - 1, 0, matr.getSize(0));
		return matr;
	}
	else {
		if (vector.getSize(1) == 1 && vector.getSize(0) == 3 && matrix.getSize(1) == 4) {
			MyMatrix oper = eye(4, 4);
			oper.set(vector.at(0).at(0), 0, 0);
			oper.set(vector.at(1).at(0), 1, 1);
			oper.set(vector.at(2).at(0), 2, 2);
			MyMatrix matr = matrix * oper;
			return matr;
		}
	}
}
void LinAlg::zoom3D_(MyMatrix & matrix, MyMatrix & vector)
{
	if (vector.getSize(1) != 1 || vector.getSize(0) != 3 || matrix.getSize(1) != 4) {
		//...
	}
	else {
		MyMatrix oper = eye(4, 4);
		oper.set(vector.at(0).at(0), 0, 0);
		oper.set(vector.at(1).at(0), 1, 1);
		oper.set(vector.at(2).at(0), 2, 2);
		matrix *= oper;
	}
}

//----------------------------------------------------------------------------------------------

MyMatrix LinAlg::turn3D(MyMatrix & matrix_, int axis, double angle)
{
	MyMatrix matrix = matrix_;	
	if (matrix.getSize(1) == 3) {
		matrix.append(1);
	}
	if(matrix.getSize(1) == 4) {
		switch (axis)
		{
		case 0: {
			MyMatrix oper(
				{
				{ 	1,			0,				0,			0	},
				{ 	0,		MyCos(angle),	MySin(angle),	0,	},
				{	0,	   -MySin(angle),	MyCos(angle),	0,	},
				{	0,			0,				0,			1	}
				});

			MyMatrix matr = matrix * oper;
			matr.cut(0, matr.getSize(1) - 1, 0, matr.getSize(0));
			return matr;
		}
		case 1: {
			MyMatrix oper(
				{
				{ MyCos(angle),		0,	   -MySin(angle),	0	},
				{	0,				1,			0,			0	},
				{ MySin(angle),		0,		MyCos(angle),	0	},
				{	0,				0,			0,			1	}
				});

			MyMatrix matr = matrix * oper;
			matr.cut(0, matr.getSize(1) - 1, 0, matr.getSize(0));
			return matr;
		}
		case 2: {
			MyMatrix oper(
				{
				{ MyCos(angle),	MySin(angle),	0,		0	},
				{-MySin(angle),	MyCos(angle),	0,		0	},
				{	0,				0,			1,		0	},
				{	0,				0,			0,		1	}
				});

			MyMatrix matr = matrix * oper;
			matr.cut(0, matr.getSize(1) - 1, 0, matr.getSize(0));
			return matr;
		}
		default: {
			//...
			break; 
		}
		}
	}
}
void LinAlg::turn3D_(MyMatrix & matrix, int axis, double angle)
{
	if (matrix.getSize(1) != 4) {
	}
	else {
		switch (axis)
		{
		case 0: {
			MyMatrix oper(
				{
				{ 	1,			0,				0,			0	},
				{ 	0,		MyCos(angle),	MySin(angle),	0,	},
				{	0,	   -MySin(angle),	MyCos(angle),	0,	},
				{	0,			0,				0,			1	}
				});
			matrix *= oper;
		}
		case 1: {
			MyMatrix oper(
				{
				{ MyCos(angle),		0,	   -MySin(angle),	0	},
				{	0,				1,			0,			0	},
				{ MySin(angle),		0,		MyCos(angle),	0	},
				{	0,				0,			0,			1	}
				});
			matrix *= oper;
		}
		case 2: {
			MyMatrix oper(
				{
				{ MyCos(angle),	MySin(angle),	0,		0	},
				{-MySin(angle),	MyCos(angle),	0,		0	},
				{	0,				0,			1,		0	},
				{	0,				0,			0,		1	}
				});
			matrix *= oper;
		}
		default: {
			break;
		}
		}
	}
}

//==============================================================================================
//==============================================================================================

MyMatrix LinAlg::parallel_translation2D(MyMatrix & matrix, MyMatrix & vector)
{

	if (vector.getSize(0) != 1 || vector.getSize(1) != 3 || matrix.getSize(1) != 2) {
		//...
	}
	else {
		MyMatrix matrix_ = matrix;
		matrix_.append(1);
		MyMatrix oper = eye(3, 3);
		oper.set(vector.at(0).at(0), 2, 0);
		oper.set(vector.at(0).at(1), 2, 1);
		matrix_ *= oper;
		matrix_.cut(0, matrix.getSize(1), 0, matrix.getSize(0));
		return matrix_;
	}
}		//||
MyMatrix LinAlg::zoom2D(MyMatrix & matrix, MyMatrix & vector)
{
	if (vector.getSize(0) != 1 || vector.getSize(1) != 2 || matrix.getSize(1) != 2) {
		//...
	}
	else {
		MyMatrix matrix_ = matrix;
		matrix_.append(1);
		MyMatrix oper = eye(3, 3);
		oper.set(vector.at(0).at(0), 0, 0);
		oper.set(vector.at(0).at(1), 1, 1);
		matrix_ *= oper;
		matrix_.cut(0, matrix.getSize(1), 0, matrix.getSize(0));
		return matrix_;
	}
}//
MyMatrix LinAlg::turn2D(MyMatrix & matrix, double angle)
{
	if (matrix.getSize(1) != 2) {
		//...
	}
	else {
		MyMatrix matrix_ = matrix;
		matrix_.append(1);
		MyMatrix oper(
			{
				{	MyCos(angle),	MySin(angle),	0},
				{  -MySin(angle),	MyCos(angle),	0},
				{		0,				0,			1}
			}
		);
		matrix_ *= oper;
		matrix_.cut(0, matrix.getSize(1), 0, matrix.getSize(0));
		return matrix_;
	}
}//
//==============================================================================================