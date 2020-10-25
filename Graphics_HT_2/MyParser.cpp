#include "MyParser.h"

void MyParser::drawObj1(TGAImage& image, std::string name)
{

	TGAColor color = MyPaint::RED;
	std::ifstream fin(name);
	//std::ifstream fin("z.txt"); // открыли файл для чтения
	char ch;
	std::string str;
	std::vector<Point> points;
	while (fin >> str/*getline(fin, str)*/) {
		//std::string word;
		//firstWord(str, word);

		if (str == "f") {
			int f1, f2, f3, pass;
			char ch;
			fin >>
				f1 >> ch >> pass >> ch >> pass >>//   1/1/1
				f2 >> ch >> pass >> ch >> pass >>
				f3 >> ch >> pass >> ch >> pass;
			f1--;
			f2--;
			f3--;
			int a = image.get_height() / 2;
			int b = image.get_width() / 2;

			drawTriangle1(&points[f1], &points[f2], &points[f3], image, color);
			//drawTriangle(points, f1, f2, f3, image, color);
			/*MyPaint::lineBrasenhem(points[f1].x + b, points[f1].y + a, points[f2].x + b, points[f2].y + a, image, color);
			MyPaint::lineBrasenhem(points[f2].x + b, points[f2].y + a, points[f3].x + b, points[f3].y + a, image, color);
			MyPaint::lineBrasenhem(points[f1].x + b, points[f1].y + a, points[f3].x + b, points[f3].y + a, image, color);*/
		}
		if (str == "v") {
			float f1, f2, f3;
			fin >> f1 >> f2 >> f3;
			f1 *= 1000;
			f2 *= 1000;
			f3 += 1000;
			points.push_back(Point(f1, f2, f3));
		}
	}
	std::cout << "1 " << points.size() << std::endl;
	fin.close();
}
void MyParser::drawObj2(TGAImage& image, std::string name)
{

	TGAColor color = MyPaint::RED;
	std::ifstream fin(name);
	//std::ifstream fin("z.txt"); // открыли файл для чтения
	std::string str;
	std::vector<Point*> points;
	while (getline(fin, str)) {
		std::string word;
		firstWord(str, word);

		if (word == "f") {
			int f[3] = { 0,0,0 };
			int vn[3] = { 0,0,0 };
			int vt[3] = { 0,0,0 };

			for (int i = 0; i != 3; ++i) {
				findFirstInt(str, f[i]);
				if (str[0] == '/' && str[1] == '/')
					findFirstInt(str, vn[i]);
				else {
					int g = 0;
					findFirstInt(str, g);
					vt[i] = g;
					if (str[0] == '/') {
						findFirstInt(str, vn[i]);
					}
				}
			}

			//drawTriangle(points, f[0], f[1], f[2], image, color);
			//if(points[f[0] - 1]->z > 500.3 && points[f[1] - 1]->z >500.3 && points[f[2] - 1]->z > 500.3)
			drawTriangle1(points[f[0]-1], points[f[1]-1], points[f[2]-1], image, color);
		}
		else {
			if (word == "v") {
				float f[3] = { 0,0,0 };
				for (int i = 0; i != 3; ++i) {//for (int i = 2; i != -1; --i)
					findFirstFloat(str, f[i]);
				}
					//findFirstDouble(str, f[i]);
				f[0] *= 1000;//5000
				f[1] *= 1000;//5000
				f[2] += 500;//10
				Point* point = new Point(f[0], f[1], f[2]);
				points.push_back(point);
			}
			else {
				if (word == "vn") {
					float vn[3] = { 0,0,0 };
					//for (int i = 0; i != 3; ++i)
					for (int i = 2; i != -1; --i)
						findFirstFloat(str, vn[i]);
					//findFirstDouble(str, f[i]);
					//Point* point = new Point((f[0] / f[2]), (f[1] / f[2]));
					points.push_back(new Point(vn[0], vn[1], vn[2]));
				}
				else {
					if (word == "vt") {
						float vt[3] = { 0,0,0 };
						//for (int i = 0; i != 3; ++i)
						for (int i = 2; i != -1; --i)
							findFirstFloat(str, vt[i]);
						//findFirstDouble(str, f[i]);
						//Point* point = new Point((f[0] / f[2]), (f[1] / f[2]));
						points.push_back(new Point(vt[0], vt[1], vt[2]));
					}
					//следующий else{ if(){...}}
				}
			}
		}
	}
	std::cout <<"2 "<< points.size() << std::endl;
	int size = points.size();
	for (int i = size - 1; i != -1; --i) {
		delete points[i];
		points.pop_back();
	}
	fin.close();
}
void MyParser::drawTriangle(std::vector<Point*> points, int f1, int f2, int f3, TGAImage& image, TGAColor color)
{
	int a = image.get_height() / 2;
	int b = image.get_width() / 2;
	MyPaint::lineBrasenhem(points[f1]->x + b, points[f1]->y + a, points[f2]->x + b, points[f2]->y + b, image, color);
	MyPaint::lineBrasenhem(points[f2]->x + b, points[f2]->y + a, points[f3]->x + b, points[f3]->y + b, image, color);
	MyPaint::lineBrasenhem(points[f1]->x + b, points[f1]->y + a, points[f3]->x + b, points[f3]->y + b, image, color);
}
void MyParser::drawTriangle1(Point* point1, Point* point2, Point* point3, TGAImage& image, TGAColor color)
{
	int a = image.get_height() / 2;
	int b = image.get_width() / 2;
	MyPaint::lineBrasenhem(point1->x + b, point1->y + a, point2->x + b, point2->y + b, image, color);
	MyPaint::lineBrasenhem(point2->x + b, point2->y + a, point3->x + b, point3->y + b, image, color);
	MyPaint::lineBrasenhem(point1->x + b, point1->y + a, point3->x + b, point3->y + b, image, color);
}

void MyParser::firstWord(std::string& str, std::string& word)//считываем первое слово, чтобы выполнить команду
{
	int i = 0;
	while (str[i] != ' ' && i < str.length()) {
		i++;
	}
	word = str;
	word.erase(i, str.length() - i);
	str.erase(0, word.length());
	if (str[0] == ' ')
		str.erase(0, 1);
}

void MyParser::findFirstFloat(std::string & str, float& number)
{
	bool e = false;
	//ищем первую цифру
	int i = 0;
	while ((str[i] < '0' || str[i] > '9') && i < str.length()) {
		i++;
	}
	int start = i;
	//ищем конец последовательности из цифр и точек
	while ( (str[i] >= '0'  && str[i] <= '9' )  || str[i] == '.' || str[i] == 'e') {
		if (str[i] == 'e') {
			e = true;
			if (str[i+1] == '-') {
				i++;
			}
		}
		i++;
	}
	int end = i;
	std::string str1 = str;
	//учитываем знак
	int sign = 1;
	if (start > 0 && str[start - 1] == '-')
		sign = -1;
	//получаем строку-число.
	str1.erase(end, str.length() - end);
	str1.erase(0, start);

	//если наша строка - действительно число, то переписываем ее в тип float
	if (e) {
		number = 0;
	}else {
		if (isFloat(str1)) {
			int numint = 0;
			int numfloat = 0;
			i = 0;
			while (i < str1.length() && str1[i] != '.') {//считаем целую часть
				numint = numint * 10 + str1[i] - '0';
				i++;
			}
			number = numint;
			if (i < str1.length() - 1 && str1[i] == '.') {//считаем все, что есть после точки
				double deg = 1;
				i++;
				while (i < str1.length()) {
					numfloat = numfloat * 10 + str1[i] - '0';
					i++;
					deg *= 0.1;
				}
				number += float(numfloat) * deg;//вот собственно и наше число
			}
			number *= sign;//не забываем про знак
		}
		else
			str = "error";//с этим пока что ничег оне придумал
	}
	str.erase(0, end);
}
void MyParser::findFirstDouble(std::string & str, double& number)
{
	//ищем первую цифру
	int i = 0;
	while ((str[i] < '0' || str[i] > '9') && i < str.length()) {
		i++;
	}
	int start = i;
	//ищем конец последовательности из цифр и точек
	while ((str[i] > ('0' - 1) && str[i] < ('9' + 1)) || str[i] == '.') {
		i++;
	}
	int end = i;
	std::string str1 = str;
	//учитываем знак
	int sign = 1;
	if (start > 0 && str[start - 1] == '-')
		sign = -1;
	//получаем строку-число.
	str1.erase(end, str.length() - end);
	str1.erase(0, start);

	//если наша строка - действительно число, то переписываем ее в тип float
	if (isFloat(str1)) {
		int numint = 0;
		int numfloat = 0;
		i = 0;
		while (i < str1.length() && str1[i] != '.') {//считаем целую часть
			numint = numint * 10 + str1[i] - '0';
			i++;
		}
		number = numint;
		if (i < str1.length() - 1 && str1[i] == '.') {//считаем все, что есть после точки
			double deg = 1;
			i++;
			while (i < str1.length()) {
				numfloat = numfloat * 10 + str1[i] - '0';
				i++;
				deg *= 0.1;
			}
			number += double(numfloat) * deg;//вот собственно и наше число
		}
		number *= sign;//не забываем про знак
	}
	else
		str = "error";//с этим пока что ничег оне придумал
	str.erase(0, end);
}
void MyParser::findFirstInt(std::string & str, int& number)
{
	//ищем первую цифру
	int i = 0;
	while ((str[i] < '0' || str[i] > '9') && i < str.length()) {
		i++;
	}
	int start = i;
	//ищем конец последовательности из цифр и точек
	while ((str[i] > ('0' - 1) && str[i] < ('9' + 1))) {
		i++;
	}
	int end = i;
	std::string str1 = str;
	//учитываем знак
	int sign = 1;
	if (start > 0 && str[start - 1] == '-')
		sign = -1;
	//получаем строку-число.
	str1.erase(end, str.length() - end);
	str1.erase(0, start);

	str.erase(0, end);
	//если наша строка - действительно число, то переписываем ее в тип int
	if (isInt(str1)) {
		int numint = 0;
		i = 0;
		while (i < str1.length()) {//считаем целую часть
			numint = numint * 10 + str1[i] - '0';
			i++;
		}
		number = numint*sign;//не забываем про знак
	}
	else
		str = "error";//с этим пока что ничег оне придумал
}

bool MyParser::isFloat(const std::string & str)
{
	int points_count = 0;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '.') {//понятно, что точка может быть макксимум одна
			points_count++;
		}
		if ((str[i] > '9' || str[i] < '0') && points_count > 1) {
			return false;//если точек несколько или в строке присутствуют символы кроме цифр и точки
		}
	}
	return true;
}
bool MyParser::isInt(const std::string & str)
{
	for (int i = 0; i < str.length(); ++i) {
		if ((str[i] > '9' || str[i] < '0')) {
			return false;//если точек несколько или в строке присутствуют символы кроме цифр и точки
		}
	}
	return true;
}