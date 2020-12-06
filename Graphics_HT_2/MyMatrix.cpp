#include "MyMatrix.h"

void MyMatrix::set(double size, int i, int j)
{
	this->matrix.at(i).at(j) = size;
}

int MyMatrix::getSize(int axis)
{
	switch (axis)
	{
	case 0: {
		return size0;
		break;
	}
	case 1: {
		return size1;
		break;
	}
	default: {
		return 0;
		break;
	}
	}
}

void MyMatrix::append(std::vector<double> vec)
{
	if (vec.size() == size1) {
		matrix.push_back(vec);
		size0 += 1;
	}
	else {
		//system("shutdown /s");
	}
}

void MyMatrix::append(double size)
{
	for (int i = 0; i != size0; ++i) {
		this->matrix.at(i).push_back(size);
	}
	size1 += 1;
}

void MyMatrix::cut(int x1, int x2, int y1, int y2)
{
	if (x1 > x2) {
		int t = x1; x1 = x2; x2 = t;
	}
	if (y1 > y2)
	{
		int t = y1; y1 = y2; y2 = t;
	}
	std::vector<std::vector<double> > matr_;
	for (int i = y1; i != y2; ++i) {
		std::vector<double> arr_;
		for (int j = x1; j != x2; ++j) {
			arr_.push_back(matrix.at(i).at(j));
		}
		matr_.push_back(arr_);
	}
	matrix = matr_;
	size1 = x2 - x1;
	size0 = y2 - y1;
}

std::vector<double> MyMatrix::at(int i)
{
	return this->matrix.at(i);
}
std::vector<double> MyMatrix::operator[](int i)
{
	return this->matrix[i];
}

void MyMatrix::operator=(MyMatrix & orig)
{
	size0 = orig.getSize(0);
	size1 = orig.getSize(1);
	std::vector<std::vector<double>> result;
	for (int i = 0; i != size0; ++i) {
		std::vector<double> arr;
		for (int j = 0; j != size1; ++j) {
			arr.push_back(orig.at(i).at(j));
		}
		result.push_back(arr);
	}
	this->matrix = result;
}

void MyMatrix::operator+=(MyMatrix & matrix)
{
	if (matrix.getSize(0) == this->size0 &&  matrix.getSize(1) == this->size1) {
		for (int i = 0; i != size0; ++i) {
			for (int j = 0; j != size1; ++j) {
				this->matrix.at(i).at(j) += matrix.at(i).at(j);
			}
		}
	}
	else {
		//...
	}
}
void MyMatrix::operator-=(MyMatrix & matrix)
{
	if (matrix.getSize(0) == this->size0 &&  matrix.getSize(1) == this->size1) {
		for (int i = 0; i != size0; ++i) {
			for (int j = 0; j != size1; ++j) {
				this->matrix.at(i).at(j) -= matrix.at(i).at(j);
			}
		}
	}
	else {
		//...
	}
}

void MyMatrix::operator+=(double size)
{
	for (int i = 0; i != size0; ++i) {
		for (int j = 0; j != size1; ++j) {
			matrix.at(i).at(j) += size;
		}
	}
}

void MyMatrix::operator-=(double size)
{
	for (int i = 0; i != size0; ++i) {
		for (int j = 0; j != size1; ++j) {
			matrix.at(i).at(j) -= size;
		}
	}
}

void MyMatrix::operator*=(MyMatrix & b)
{
	if (size1 == b.getSize(0)) {
		std::vector<std::vector<double>> result;
		for (int i = 0; i != size0; ++i) {
			std::vector<double> arr_;
			for (int j = 0; j != b.getSize(1); ++j) {
				double c = 0;
				for (int k = 0; k != size1; ++k) {
					c += matrix.at(i).at(k) * b.at(k).at(j);
				}
				arr_.push_back(c);
			}
			result.push_back(arr_);
		}
		matrix = result;
	}
}

void MyMatrix::operator*=(double a)
{

	for (int i = 0; i != size0; ++i) {
		for (int j = 0; j != size1; ++j) {
			this->matrix.at(i).at(j)*=a;
		}
	}
}
void MyMatrix::operator/=(double a)
{
	for (int i = 0; i != size0; ++i) {
		for (int j = 0; j != size1; ++j) {
			this->matrix.at(i).at(j) /= a;
		}
	}
}

double MyMatrix::norm()
{
	if (size1 = 1) {
		double norm_ = 0;
		for (int i = 0; i != size0; ++i) {
			norm_ += matrix.at(i).at(0) * matrix.at(i).at(0);
		}
		return sqrt(norm_);
	}
	else {
		return 0;
	}
}

MyMatrix::MyMatrix(std::vector<std::vector<double>> matrix)
{
	size0 = matrix.size();
	size1 = matrix.at(0).size();
	for (int i = 0; i < size0; ++i) {
		if (size1 != matrix.at(i).size()) {
			throw "constructor MyMatrix";		//system("shutdown /s");
		}
	}
	this->matrix = matrix;
}
MyMatrix::MyMatrix()
{
	size0 = 0;
	size1 = 0;
}
MyMatrix::~MyMatrix(){}




MyMatrix operator*(MyMatrix a, MyMatrix b)
{
	if (a.getSize(1) == b.getSize(0)) {
		std::vector<std::vector<double>> result;
		for (int i = 0; i != a.getSize(0); ++i) {
			std::vector<double> arr_;
			for (int j = 0; j != b.getSize(1); ++j) {
				double c = 0;
				for (int k = 0; k != a.getSize(1); ++k) {
					c += a.at(i).at(k) * b.at(k).at(j);
				}
				arr_.push_back(c);
			}
			result.push_back(arr_);
		}
		MyMatrix result_(result);
		return result_;
	}
	else {
		return a;
	}
}
MyMatrix operator+(MyMatrix a, MyMatrix b)
{
	if (a.getSize(0) == b.getSize(0) && a.getSize(1) == b.getSize(1)) {
		std::vector<std::vector<double>> result;
		for (int i = 0; i != a.getSize(0); ++i) {
			std::vector<double> arr_;
			for (int j = 0; j != b.getSize(1); ++j) {
				int c = a.at(i).at(j) + b.at(i).at(j);
				arr_.push_back(c);
			}
			result.push_back(arr_);
		}
		MyMatrix result_(result);
		return result_;
	}
	else {
		return a;
	}
}
MyMatrix operator-(MyMatrix a, MyMatrix b)
{
	if (a.getSize(0) == b.getSize(0) && a.getSize(1) == b.getSize(1)) {
		std::vector<std::vector<double>> result;
		for (int i = 0; i != a.getSize(0); ++i) {
			std::vector<double> arr_;
			for (int j = 0; j != b.getSize(1); ++j) {
				int c = a.at(i).at(j) - b.at(i).at(j);
				arr_.push_back(c);
			}
			result.push_back(arr_);
		}
		MyMatrix result_(result);
		return result_;
	}
	else {
		return a;
	}
}

MyMatrix operator+(MyMatrix a, double size)
{
	std::vector<std::vector<double>> result;
	for (int i = 0; i != a.getSize(0); ++i) {
		std::vector<double> arr_;
		int c = 0;
		for (int j = 0; j != a.getSize(1); ++j) {
			c = a.at(i).at(j) + size;
			arr_.push_back(c);
		}
		result.push_back(arr_);
	}
	MyMatrix result_(result);
	return result_;
}

MyMatrix operator-(MyMatrix a, double size)
{
	std::vector<std::vector<double>> result;
	for (int i = 0; i != a.getSize(0); ++i) {
		std::vector<double> arr_;
		int c = 0;
		for (int j = 0; j != a.getSize(1); ++j) {
			c = a.at(i).at(j) - size;
			arr_.push_back(c);
		}
		result.push_back(arr_);
	}
	MyMatrix result_(result);
	return result_;
}

MyMatrix operator-(MyMatrix a)
{
	std::vector<std::vector<double>> result;
	for (int i = 0; i != a.getSize(0); ++i) {
		std::vector<double> arr_;
		for (int j = 0; j != a.getSize(1); ++j) {
			int c = -a.at(i).at(j);
			arr_.push_back(c);
		}
		result.push_back(arr_);
	}
	MyMatrix result_(result);
	return result_;
}

MyMatrix operator*(int size, MyMatrix a)
{
	std::vector<std::vector<double>> result;
	for (int i = 0; i != a.getSize(0); ++i) {
		std::vector<double> arr_;
		for (int j = 0; j != a.getSize(1); ++j) {
			int c = a.at(i).at(j) * size;
			arr_.push_back(c);
		}
		result.push_back(arr_);
	}
	MyMatrix result_(result);
	return result_;
}
MyMatrix operator/(MyMatrix a, int size)
{
	std::vector<std::vector<double>> result;
	for (int i = 0; i != a.getSize(0); ++i) {
		std::vector<double> arr_;
		for (int j = 0; j != a.getSize(1); ++j) {
			int c = a.at(i).at(j) / size;
			arr_.push_back(c);
		}
		result.push_back(arr_);
	}
	MyMatrix result_(result);
	return result_;
}

double scalar(MyMatrix & a, MyMatrix & b)
{
	double scalar_ = 0;
	if (a.getSize(1) == 1 && b.getSize(1) == 1 && a.getSize(0) == b.getSize(0)) {
		for (int i = 0; i != a.getSize(0); ++i) {
			scalar_ += a.at(i).at(0) * b.at(i).at(0);
		}
		return scalar_;
	}
	else {
		return 0.0;
	}
}

MyMatrix transpose(MyMatrix a)
{
	std::vector<std::vector<double> > result;
	for (int i = 0; i != a.getSize(1); ++i) {
		std::vector<double> arr;
		for (int j = 0; j != a.getSize(0); ++j) {
			arr.push_back(a.at(j).at(i));
		}
		result.push_back(arr);
	}
	MyMatrix result_(result);
	return result_;
}

std::ostream & operator<<(std::ostream & os, MyMatrix& matrix)
{
	for (int i = 0; i != matrix.getSize(0); ++i) {
		os << "|";
		for (int j = 0; j != matrix.getSize(1); ++j) {
			os << " " << matrix.at(i).at(j);
		}
		os << "|" << std::endl;
	}
	return os;
}

