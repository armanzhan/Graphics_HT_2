#pragma once
#include <vector>
#include "MyMatrix.h"
#include "Model.h"
#include "MyPaint.h"
class Object
{
private:
	MyMatrix position;			//позици€ начала локальных координат  - √ќ–»«ќЌ“јЋ№Ќџ… ¬≈ “ќ–
	MyMatrix local_axes;		// локальна€ система координат(3 вектора) расположенные горизонтально
	MyMatrix model_size;		// вектор-3, который хранит данные о том, насоклько используемые резмеры модели отличаютс€ от считанных
public:
	Model* model;				//указатель на используемую модель
	TGAColor color;				//цвет модели(пока что без текстур)
	MyMatrix getPosition();
	double get_x();				//координата центра по x
	double get_y();				//координата центра по y
	double get_z();				//координата центра по z
	MyMatrix get_local_axes();	//копи€ локальной системы координат

	Object(MyMatrix& position, MyMatrix& local_axes, Model* models, TGAColor color);	//создание видимого объекта
	Object(MyMatrix& position, MyMatrix& local_axes, TGAColor color);					//создание источника света
	~Object();					//деструктор не нужен, так как здеcь внутри ничего не создаетс€, все указfтели на внешние объекты.
};

