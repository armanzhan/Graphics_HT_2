#pragma once

#include "Header.h"
class MyMatrix
{
private://Нафиг вложенные вектора, они мешают, все заменить завтра
	int size0, size1;
	std::vector<std::vector<double>> matrix;
public:
	void set(double size, int i, int j);
	int getSize(int axis);
	void append(std::vector<double>);
	void append(double size);
	void cut(int x1, int x2, int y1, int y2);
	std::vector<double> at(int i);
	std::vector<double> operator[](int i);

	void operator=(MyMatrix& matrix);

	void operator+=(MyMatrix& matrix);
	void operator-=(MyMatrix& matrix);

	void operator+=(double size);
	void operator-=(double size);

	void operator*=(MyMatrix& matrix);
	
	void operator*=(double a);
	void operator/=(double a);

	double norm();

	MyMatrix(std::vector<std::vector<double> > matrix);
	MyMatrix();
	~MyMatrix();
};

MyMatrix operator*(MyMatrix a, MyMatrix b);
MyMatrix operator+(MyMatrix a, MyMatrix b);
MyMatrix operator-(MyMatrix a, MyMatrix b);

MyMatrix operator+(MyMatrix a, double size);
MyMatrix operator-(MyMatrix a, double size);

MyMatrix operator-(MyMatrix a);
MyMatrix operator*(int size, MyMatrix a);
MyMatrix operator/(MyMatrix a, int size);
double scalar(MyMatrix& a, MyMatrix& b);
MyMatrix transpose(MyMatrix a);

std::ostream& operator<<(std::ostream&, MyMatrix&);