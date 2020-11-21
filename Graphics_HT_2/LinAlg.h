#include "MyMatrix.h"
namespace LinAlg
{
	double MySin(double angle);
	double MyCos(double angle);
	MyMatrix zeros(int a, int b);
	MyMatrix ones(int a, int b);
	MyMatrix eye(int a, int b);

	MyMatrix parallel_translation2D(MyMatrix& matrix, MyMatrix & vector);// в эти методы передаются матрицы  
	MyMatrix zoom2D(MyMatrix& matrix, MyMatrix & vector);				 // в !!!!однородных!!!! координатах
	MyMatrix turn2D(MyMatrix& matrix, double angle);
	
	MyMatrix parallel_translation3D(MyMatrix& matrix, MyMatrix& operator_);
	MyMatrix zoom3D(MyMatrix& matrix, MyMatrix& operator_);
	MyMatrix turn3D(MyMatrix& matrix, int axis, double angle);

	void turn3D_(MyMatrix& matrix, int axis, double angle);
	void zoom3D_(MyMatrix& matrix, MyMatrix &operator_);
	void parallel_translation3D_(MyMatrix& matrix, MyMatrix& operator_);


};
