#include "MyParser.h"

/*
void MyParser::drawObj2(TGAImage& image, std::string name)
{

	TGAColor color = MyPaint::RED;
	std::ifstream fin(name);
	//std::ifstream fin("z.txt"); // открыли файл для чтения
	std::string str;
	std::vector<Point*> points;
	std::vector <Figure*> figures;
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
			Figure* figure = new Figure();
			figure->vertex_back(points[f[0] - 1]);
			figure->vertex_back(points[f[1] - 1]);
			figure->vertex_back(points[f[2] - 1]);

			figures.push_back(figure);

			//drawTriangle1(points[f[0]-1], points[f[1]-1], points[f[2]-1], image, color);
		}
		else {
			if (word == "v") {
				float f[3] = { 0,0,0 };
				for (int i = 0; i != 3; ++i) {//for (int i = 2; i != -1; --i)
					findFirstFloat(str, f[i]);
				}
					//findFirstDouble(str, f[i]);
				//f[0] *= 1000;//5000
				//f[1] *= 1000;//5000
				//f[2] += 500;//10
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

	drawFigures(figures, image, color);

	int size;
	std::cout << "2 points"<< points.size() << std::endl;
	std::cout << "2 triangles" << points.size() << std::endl;

	size = figures.size();
	for (int i = size - 1; i != -1; --i) {
		delete figures[i];
		figures.pop_back();
	}

	size = points.size();
	for (int i = size - 1; i != -1; --i) {
		delete points[i];
		points.pop_back();
	}
	fin.close();
}
*/


Model * MyParser::read_Obj(std::string name)
{
	std::ifstream fin(name);
	std::string str;

	std::vector<std::vector<double>> points;
	std::vector <std::vector<int>> ribs;

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
					if (str[0] == '/')
						findFirstInt(str, vn[i]);
				}
			}
			std::vector<int> cur_rib;
			cur_rib.push_back(f[0] - 1);
			cur_rib.push_back(f[1] - 1);
			cur_rib.push_back(f[2] - 1);
			ribs.push_back(cur_rib);
		}
		else {
			if (word == "v") {
				double f[3] = { 0,0,0 };
				for (int i = 0; i != 3; ++i) {
					//findFirstFloat(str, f[i]);
					findFirstDouble(str, f[i]);
				}
				//Point* point = new Point(f[0], f[1], f[2]);
				std::vector<double> point = { f[0],f[1],f[2] };
				points.push_back(point);
			}
			else {
				if (word == "vn") {
					//float vn[3] = { 0,0,0 };
					double vn[3] = { 0,0,0 };
					for (int i = 2; i != -1; --i) {
						//findFirstFloat(str, vn[i]);
						findFirstDouble(str, vn[i]);
					}
					std::vector<double> arr = { vn[0], vn[1], vn[2] };
					points.push_back(arr);
				}
				else {
					if (word == "vt") {
						double vt[3] = { 0,0,0 };
						//for (int i = 0; i != 3; ++i)
						for (int i = 2; i != -1; --i) {
							//findFirstFloat(str, vt[i]);
							findFirstDouble(str, vt[i]);
						}
						//Point* point = new Point((f[0] / f[2]), (f[1] / f[2]));
						std::vector<double> arr = { vt[0], vt[1], vt[2] };
						points.push_back(arr);
					}
					//следующий else{ if(){...}}
				}
			}
		}
	}
	fin.close();
	Model * model = new Model(0, 0, 0, points, ribs);
	return model;
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

	bool e = false;
	//ищем первую цифру
	int i = 0;
	while ((str[i] < '0' || str[i] > '9') && i < str.length()) {
		i++;
	}
	int start = i;
	//ищем конец последовательности из цифр и точек
	while ((str[i] >= '0'  && str[i] <= '9') || str[i] == '.' || str[i] == 'e') {
		if (str[i] == 'e') {
			e = true;
			if (str[i + 1] == '-') {
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
	}
	else {
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
	}
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
// перенести в рисовальщик
