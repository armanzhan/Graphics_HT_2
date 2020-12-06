#pragma once
#include <vector>
#include "MyMatrix.h"
#include "Model.h"
#include "MyPaint.h"
class Object
{
private:
	MyMatrix position;			//������� ������ ��������� ���������  - �������������� ������
	MyMatrix local_axes;		// ��������� ������� ���������(3 �������) ������������� �������������
	MyMatrix model_size;		// ������-3, ������� ������ ������ � ���, ��������� ������������ ������� ������ ���������� �� ���������
public:
	Model* model;				//��������� �� ������������ ������
	TGAColor color;				//���� ������(���� ��� ��� �������)
	MyMatrix getPosition();
	double get_x();				//���������� ������ �� x
	double get_y();				//���������� ������ �� y
	double get_z();				//���������� ������ �� z
	MyMatrix get_local_axes();	//����� ��������� ������� ���������

	Object(MyMatrix& position, MyMatrix& local_axes, Model* models, TGAColor color);	//�������� �������� �������
	Object(MyMatrix& position, MyMatrix& local_axes, TGAColor color);					//�������� ��������� �����
	~Object();					//���������� �� �����, ��� ��� ���c� ������ ������ �� ���������, ��� ����f���� �� ������� �������.
};

