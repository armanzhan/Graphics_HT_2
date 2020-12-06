#include "Header.h"
#include "MyPaint.h"
#include "MyParser.h"
#include "MyMatrix.h"
#include "Linalg.h"

//____TESTS_________________

//_test_lines____(0,0)-(300,100)___________
void testBrasenhem(TGAImage &image, TGAColor color) {
	MyPaint::lineBrasenhem(50, 50, 100, 50, image, color);

	MyPaint::lineBrasenhem(50, 50, 0, 75, image, color);
	MyPaint::lineBrasenhem(50, 50, 100, 100, image, color);
	MyPaint::lineBrasenhem(50, 50, 75, 0, image, color);

	MyPaint::lineBrasenhem(50, 50, 75, 100, image, color);

}
void testDDAsimple(TGAImage &image, TGAColor color) {
	MyPaint::lineDDAsimple(150, 50, 150, 100, image, color);
	MyPaint::lineDDAsimple(150, 50, 175, 0, image, color);
	MyPaint::lineDDAsimple(150, 50, 200, 100, image, color);
	MyPaint::lineDDAsimple(150, 50, 175, 100, image, color);

}
void testDDAsymetric(TGAImage &image, TGAColor color) {
	MyPaint::lineDDAsymetric(250, 50, 300, 100, image, color);
	MyPaint::lineDDAsymetric(250, 50, 300, 50, image, color);
	MyPaint::lineDDAsymetric(250, 50, 200, 75, image, color);
}
//_test_lines____(0, 100) - (300, 200)___________
void testlineBrasenhemMod(TGAImage &image, TGAColor color) {
	MyPaint::lineBrasenhemMod(50, 150, 100, 153, image, color);
	//MyPaint::lineBrasenhemMod(50, 150, 100, 100, image, color);
	//MyPaint::lineBrasenhemMod(50, 150, 50, 100, image, color);
	
	MyPaint::lineBrasenhemMod(50, 150, 100, 125, image, color);
	MyPaint::lineBrasenhemMod(50, 150, 100, 175, image, color);
}
void testlineVu(TGAImage &image, TGAColor color) {
	//lineVu(150, 150, 110, 200, image, color);
	MyPaint::lineVu(150, 150, 200, 155, image, color);
	//lineVu(150, 150, 200, 160, image, color);
	MyPaint::lineVu(150, 150, 200, 165, image, color);

	MyPaint::lineVu(150, 150, 160, 200, image, color);
	MyPaint::lineVu(150, 150, 135, 100, image, color);
}

//_test_circles_____________
void testCircleBrasenhem(TGAImage &image, TGAColor color) {
	MyPaint::circleBrasenhem(350, 50, 50, image, color);
	MyPaint::circleBrasenhem(350, 50, 25, image, color);
	MyPaint::circleBrasenhem(350, 50, 10, image, color);
}
void testCircleDDA(TGAImage &image, TGAColor color) {
	MyPaint::circleDDA(450, 50, 50, image, color);
	MyPaint::circleDDA(450, 50, 25, image, color);
	MyPaint::circleDDA(450, 50, 10, image, color);
}
void testCircleParametr(TGAImage &image, TGAColor color) {
	MyPaint::circleParametr(550, 50, 50, image, color);
	MyPaint::circleParametr(550, 50, 25, image, color);
	MyPaint::circleParametr(550, 50, 10, image, color);
}
//_______тесты_к_заливкам____________________________________
void test_an_iterative_algorithm_with_a_seed(TGAImage& image, TGAColor color){
	std::vector <Point*> tops = { &Point(10, -10, 1), &Point(10, 10, 1), &Point (-10, 10, 1)};
	Figure triangle(tops);

	tops.push_back(&Point(-10, -10, 1));
	Figure square(tops);

	tops.push_back(&Point(0, 0, 1));
	Figure pentagon(tops);

	tops.push_back(&Point(0, -10, 1));
	Figure hexagon(tops);

	MyPaint::drawFigure(&triangle, image, color, { 25, 25 });
	MyPaint::drawFigure(&square, image, color, { 50, 25 });
	MyPaint::drawFigure(&pentagon, image, color, { 25, 50 });
	MyPaint::drawFigure(&hexagon, image, color, { 50, 50 });

	MyPaint::an_iterative_algorithm_with_a_seed(Point(0, 5, 1), {25, 25}, image, color);
	MyPaint::an_iterative_algorithm_with_a_seed(Point(0, 5, 1), { 50, 25 }, image, color);
	MyPaint::an_iterative_algorithm_with_a_seed(Point(0, 5, 1), { 25, 50 }, image, color);
	MyPaint::an_iterative_algorithm_with_a_seed(Point(0, 5, 1), { 50, 50 }, image, color);


}
void test_line__by__line_fill_algorithm_with_seed(TGAImage& image, TGAColor color){

	std::vector <Point*> tops = { &Point(10, -10, 1), &Point(10, 10, 1), &Point(-10, 10, 1) };
	Figure triangle(tops);
	tops.push_back(&Point(-10, -10, 1));
	Figure square(tops);
	tops.push_back(&Point(0, 0, 1));
	Figure pentagon(tops);
	tops.push_back(&Point(0, -10, 1));
	Figure hexagon(tops);

	MyPaint::drawFigure(&triangle, image, color, { 75, 25 });
	MyPaint::drawFigure(&square, image, color, { 100, 25 });
	MyPaint::drawFigure(&pentagon, image, color, { 75, 50 });
	MyPaint::drawFigure(&hexagon, image, color, { 100, 50 });

	MyPaint::line__by__line_fill_algorithm_with_seed(Point(0, 5, 1), { 75, 25 }, image, color);
	MyPaint::line__by__line_fill_algorithm_with_seed(Point(0, 5, 1), { 100, 25 }, image, color);
	MyPaint::line__by__line_fill_algorithm_with_seed(Point(0, 5, 1), { 75, 50 }, image, color);
	MyPaint::line__by__line_fill_algorithm_with_seed(Point(0, 5, 1), { 100, 50 }, image, color);

	//line__by__line_fill_algorithm_with_seed()
}
void test_line__by__line_algorithm_with_a_list_of_edge_points(TGAImage& image, TGAColor color)
{
	/*std::vector <Point*> tops = { &Point(10, -10, 1), &Point(10, 10, 1), &Point(-10, 10, 1) };
	Figure triangle(tops);

	tops.push_back(&Point(-10, -10, 1));
	Figure square(tops);

	tops.push_back(&Point(0, 0, 1));
	Figure pentagon(tops);

	tops.push_back(&Point(0, -10, 1));
	Figure hexagon(tops);

	MyPaint::drawFigure(&triangle, image, color, { 125, 25 });
	//MyPaint::line__by__line_algorithm_with_a_list_of_edge_points(triangle, Point(0, 5, 1), { 125, 25 }, image, color);

	//MyPaint::drawFigure(&square, image, color, { 150, 25 });
	//MyPaint::line__by__line_algorithm_with_a_list_of_edge_points(square, Point(0, 5, 1), { 150, 25 }, image, color);

	//MyPaint::drawFigure(&pentagon, image, color, { 125, 50 });
	//MyPaint::line__by__line_algorithm_with_a_list_of_edge_points(pentagon, Point(0, 5, 1), { 125, 50 }, image, color);

	//MyPaint::drawFigure(&hexagon, image, color, { 150, 50 });
	//MyPaint::line__by__line_algorithm_with_a_list_of_edge_points(hexagon, Point(0, 5, 1), { 150, 50 }, image, color);*/
}
void test_line__by__line_algorithm_with_a_list_of_active_edges(TGAImage& image3, TGAColor color){

	//line__by__line_algorithm_with_a_list_of_active_edges()
}
//____________________________________________________________________________



//___MAIN__________________
/**/
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	int a = -1;
	while (a != 0) {
		std::cout << "========================================================================" << std::endl;
		std::cout << std::endl;
		std::cout << "при запуске программ данные и переменные вводить не нужно" << std::endl;
		std::cout << std::endl;
		std::cout << "2 - Домашние задания 2, 3 - линии и окружности + линии размытия Ву и бразенхема" << std::endl;
		std::cout << "4 - Парсинг объекта из файла формата .obj" << std::endl;
		std::cout << "5 - Домашнее задание на закраску фигур" << std::endl;
		std::cout << "6 - Красим голову(не рекомендуется запускать, не работает)" << std::endl;
		std::cout << "7 - Преобразования 2d" << std::endl;
		std::cout << "8 - Преобразования 3d" << std::endl;
		std::cout << "9 - Преобразования координат головы" << std::endl;
		std::cout << "0 - выход из цикла" << std::endl;
		std::cout << "введите цифру:" << std::endl;
		std::cin >> a;
		std::cout << "============================================================" << std::endl;
		switch (a)
		{
		case 2: {
			TGAImage image(600, 300, TGAImage::RGB);
			//домашка 2
			testBrasenhem(image, MyPaint::WHITE);//_________________________+
			testDDAsimple(image, MyPaint::RED);//___________________________+
			testDDAsymetric(image, MyPaint::GREEN);//_______________________+-(присутствует 4-связность)

			testCircleBrasenhem(image, MyPaint::WHITE);//___________________+-(присутствует 4-связность)
			testCircleDDA(image, MyPaint::RED);//_________________________-
			testCircleParametr(image, MyPaint::GREEN);//____________________+
			//домашка 3(размытие)
			testlineBrasenhemMod(image, MyPaint::BLUE);//________________-
			testlineVu(image, MyPaint::GREEN);//___________________________+

			image.flip_vertically();
			image.write_tga_file("output.tga");

			std::cout << "выполнен код, рисующий линии и окружности различными методами" << std::endl;
			std::cout << std::endl;
			std::cout << "в первом ряду:" << std::endl;
			std::cout << "метод бразенхема для линий         -      белый цвет" << std::endl;
			std::cout << "DDA простой метод                  -      красный цвет" << std::endl;
			std::cout << "DDA симметрический метод           -      зеленый цвет" << std::endl;
			std::cout << std::endl;
			std::cout << "во первом ряду:" << std::endl;
			std::cout << "метод бразенхема для окружности    -      белый цвет " << std::endl;
			std::cout << "метод DDA для окружностей          -      красный цвет" << std::endl;
			std::cout << "параметрический метод рисования    -      зеленый цвет" << std::endl;
			std::cout << std::endl;
			std::cout << "во третьем ряду:" << std::endl;
			std::cout << "модифицированный метод бразенхема  -      градации синего " << std::endl;
			std::cout << "алгоритм Ву                        -      зеленый цвет" << std::endl;
			std::cout << std::endl;
			std::cout << "результат в файле output.tga" << std::endl;
			break;
		}
		case 4: {
			//домашка 4(объекты)
			std::cout << "сейчас будет выполнен код, рисующий объект, считанный из файла формата .obj" << std::endl;

			TGAImage image2(4000, 4000, TGAImage::RGB);
			Model * head = MyParser::read_Obj("african_head.txt");
			MyPaint::drawObj_lines(&(head->ribs), &(head->tops), image2, MyPaint::GREEN);
			delete head;
			image2.flip_vertically();
			image2.write_tga_file("output2.tga");

			std::cout << "результат работы программы в файле output2.tga" << std::endl;
			break;
		}
		case 5: {
			std::cout << "сделана лишь половина дз (затравочные алгоритмы)" << std::endl;
			std::cout << "итеративный алгоритм с затравкой  -     красный" << std::endl;
			std::cout << "алгоритм с линиями и затравкой    -     синий" << std::endl;
			TGAImage image3(200, 200, TGAImage::RGB);
			//домашка 2
			test_an_iterative_algorithm_with_a_seed(image3, MyPaint::RED);//_________________________+
			test_line__by__line_fill_algorithm_with_seed(image3, MyPaint::BLUE);//___________________________+
			//test_line_by_line_algorithm_with_a_list_of_edge_points(image3, MyPaint::GREEN);//_______________________+-(присутствует 4-связность)
			//test_line_by_line_algorithm_with_a_list_of_active_edges(image3, MyPaint::BLUE);

			image3.flip_vertically();
			image3.write_tga_file("output3.tga");

			std::cout << "результат работы программы в файле output3.tga" << std::endl;
			break;
		}
		case 6: {
			std::cout << "этот код неисправен" << std::endl;
			TGAImage image4(4000, 4000, TGAImage::RGB);

			Model * head = MyParser::read_Obj("african_head.txt");
			MyPaint::drawObj_zalivka(head, image4, MyPaint::GREEN);
			delete head;
			image4.flip_vertically();
			image4.write_tga_file("output4.tga");

			std::cout << "результат работы программы в файле output4.tga" << std::endl;
			break;
		}
		case 7: {
			std::cout << "последовательная работа с матрицами 2D (без вводов данных):" << std::endl;
			MyMatrix a(
				{
				{ 2.0, 2.0},
				{ 1.0,  0 }
				});
			std::cout << "исходная матрица:" << std::endl;
			std::cout << a << std::endl;
			MyMatrix b = LinAlg::turn2D(a, 90);
			std::cout << "поворот на 90 градусов " << std::endl;
			std::cout << b << std::endl;

			MyMatrix vec_to({ {2},{-1} });
			MyMatrix c = LinAlg::parallel_translation2D(a, vec_to);
			std::cout << "параллельный перенос на вектор {2, -1}" << std::endl;
			std::cout << c << std::endl;

			MyMatrix zoo({ {2},{3} });
			MyMatrix d = LinAlg::zoom2D(a, zoo);
			std::cout << "растяжение матрицы по I столбцу в 2 раза, по II в 3 раза" << std::endl;
			std::cout << d << std::endl;
			std::cout << "конец" << std::endl;
			break;
		}
		case 8: {
			std::cout << "последовательная работа с матрицами 3D (без вводов данных):" << std::endl;
			MyMatrix a(
				{
				{ 2.0, 2.0, 1 },
				{ 1.0,  0,  0 },
				{  3 ,  0,  1 }
				});
			std::cout << "исходная матрица:" << std::endl;
			std::cout << a << std::endl;

			MyMatrix b1 = LinAlg::turn3D(a, 0, 90);
			std::cout << "поворот на 90 градусов вокруг оси x" << std::endl;
			std::cout << b1 << std::endl;

			MyMatrix b2 = LinAlg::turn3D(a, 1, 90);
			std::cout << "поворот на 90 градусов вокруг оси y" << std::endl;
			std::cout << b2 << std::endl;

			MyMatrix b3 = LinAlg::turn3D(a, 2, 90);
			std::cout << "поворот на 90 градусов вокруг оси z" << std::endl;
			std::cout << b3 << std::endl;


			MyMatrix vec_to({ {2},{-1},{0} });
			std::cout << "параллельный перенос на вектор {2, -1, 0}" << std::endl;
			MyMatrix c = LinAlg::parallel_translation3D(a, vec_to);
			std::cout << c << std::endl;

			MyMatrix zoo({ {2},{3},{1} });
			std::cout << "растяжение матрицы по I столбцу в 2 раза, по II в 3 раза, по III не меням" << std::endl;
			MyMatrix d = LinAlg::zoom3D(a, zoo);
			std::cout << d << std::endl;
			break;
		}
		case 9: {
			std::cout << "код будет выполняться довольно долго" << std::endl;
			TGAImage image9(4000, 4000, TGAImage::RGB);

			Model * head = MyParser::read_Obj("african_head.txt");
			//
			std::cout << "поворот вокруг оси x на 30 градусов" << std::endl;
			head->turn3D(0, 30);
			std::cout << "поворот вокруг оси y на 60 градусов" << std::endl;
			head->turn3D(1, 60);
			std::cout << "поворот вокруг оси z на 45 градусов" << std::endl;
			head->turn3D(2, 45);
			MyMatrix vec({
				{1},
				{1},
				{0.1 }
				});
			std::cout << "перенос на вектор { 1, 1, 0.1 }" << std::endl;
			head->parallel_translation3D(vec);

			MyMatrix koef({
				{0.5},
				{0.5},
				{0.5}
				}
			);
			std::cout << "сжатие головы в 2 раза по всем осям" << std::endl;
			head->zoom3D(koef);

			MyPaint::drawObj_lines(&(head->ribs), &(head->tops), image9, MyPaint::RED);
			delete head;
			image9.flip_vertically();
			image9.write_tga_file("output9.tga");

			std::cout << "результат работы программы в файле output9.tga" << std::endl;
			break;
		}
		case 0: {
			break;
		}
		default: {
			std::cout << "Такое команды нет, попробуйте другую" << std::endl;
			break;
		}
		}
	}


	std::cout << "Введите любой символ, чтобы завершить работу программы:" << std::endl;
	char c;
	std::cin >> c;
	return 0;
}

/*
bool operator==(TGAColor color1, TGAColor color2) {
	return (color1.r == color2.r) && (color1.g == color2.g) && (color1.b == color2.b) && (color1.a == color2.a);
}/*
MyMatrix oper(
				{
				{ 	1,			0,				0,			0	},
				{ 	0,		MyCos(angle),	MySin(angle),	0,	},
				{	0,	   -MySin(angle),	MyCos(angle),	0,	},
				{	0,			0,				0,			1	}
				});
			matrix *= oper;

*//*
int main() {
	/*MyMatrix a(
		{
		{ 0, 1, 0},
		{ 0, 0, 1},
		{ 1, 0, 0}
		}
	);
	MyMatrix d(
		{
		{ 1, 2, 3},
		{ 1, 2, 3},
		{ 1, 2, 3},
		{ 1, 2, 3}
		}
	);

	MyMatrix e(
		{
		{ 1, 2, 1, 2},
		{ 0, 0, 0, 0},
		{ 1, 2, 1, 2},
		}
	);

	MyMatrix b(
		{
		{ 1, 2, 3},
		{ 4, 5, 6},
		{ 7, 8, 9},
		}
	);
	//MyMatrix c = LinAlg::turn2D(a, 45);
	/*MyMatrix c = a * b;//* a;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;	
	MyMatrix c = d * e;//* a;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;*/
	//std::cout << LinAlg::MyCos(1) << std::endl;
	//std::cout << LinAlg::MyCos(60) << std::endl;
	/*
	MyMatrix matrix(
		{
		{	1,		1,		1,		1	},
		{	0,		0,		1,		1	},
		{	0,		3,		4,		1	},
		{	0,		1.7,	1,		1	}
		});
	MyMatrix oper(
		{
		{ 	1,				0,					0,				0	},
		{ 	0,		LinAlg::MyCos(90),	LinAlg::MySin(90),		0	},
		{	0,	   -LinAlg::MySin(90),	LinAlg::MyCos(90),		0	},
		{	0,				0,					0,				1	}
		});
	std::cout << matrix << std::endl;
	std::cout << oper << std::endl;
	matrix *= oper;
	std::cout << matrix << std::endl;
	std::cout << LinAlg::MySin(30) << std::endl;
	std::cout << LinAlg::MyCos(30) << std::endl;

	char ch;
	std::cin >> ch;
	return 0;
}/**//*
int main() {
	return 0;
}*/