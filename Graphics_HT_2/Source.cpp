#include "Header.h"
#include "MyPaint.h"
#include "MyParser.h"
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
	MyPaint::an_iterative_algorithm_with_a_seed(triangle, Point(0, 5, 1), {25, 25}, image, color);
	MyPaint::an_iterative_algorithm_with_a_seed(square, Point(0, 5, 1), { 50, 25 }, image, color);
	MyPaint::an_iterative_algorithm_with_a_seed(pentagon, Point(0, 5, 1), { 25, 50 }, image, color);
	MyPaint::an_iterative_algorithm_with_a_seed(hexagon, Point(0, 5, 1), { 50, 50 }, image, color);


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

	MyPaint::line__by__line_fill_algorithm_with_seed(triangle, Point(0, 5, 1), { 75, 25 }, image, color);
	MyPaint::line__by__line_fill_algorithm_with_seed(square, Point(0, 5, 1), { 100, 25 }, image, color);
	MyPaint::line__by__line_fill_algorithm_with_seed(pentagon, Point(0, 5, 1), { 75, 50 }, image, color);
	MyPaint::line__by__line_fill_algorithm_with_seed(hexagon, Point(0, 5, 1), { 100, 50 }, image, color);

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

int main(int argc, char** argv) {
	
	std::cout << "2 - HT 2, 3: lines, circles, Vu" << std::endl;
	std::cout << "4 - clever parsing" << std::endl;
	std::cout << "5 - painting figures" << std::endl;
	std::cout << "6 - painted head" << std::endl;
	int a;
	std::cin >> a;
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
		testlineBrasenhemMod( image, MyPaint::BLUE);//________________-
		testlineVu( image, MyPaint::GREEN);//___________________________+

		image.flip_vertically();
		image.write_tga_file("output.tga");

		std::cout << "the result is in output.tga" << std::endl;
		break;
	}
	case 4: {
		//домашка 4(объекты)

		TGAImage image2(4000, 4000, TGAImage::RGB);

		Object * head = MyParser::read_Obj("african_head.txt");
		MyPaint::drawObj_lines(head, image2, MyPaint::GREEN);
		delete head;
		image2.flip_vertically();
		image2.write_tga_file("output2.tga");

		std::cout << "the result 2 is in output2.tga" << std::endl;
		break;
	}
	case 5: {
		TGAImage image3(200, 200, TGAImage::RGB);
		//домашка 2
		test_an_iterative_algorithm_with_a_seed(image3, MyPaint::RED);//_________________________+
		test_line__by__line_fill_algorithm_with_seed(image3, MyPaint::BLUE);//___________________________+
		//test_line_by_line_algorithm_with_a_list_of_edge_points(image3, MyPaint::GREEN);//_______________________+-(присутствует 4-связность)
		//test_line_by_line_algorithm_with_a_list_of_active_edges(image3, MyPaint::BLUE);

		image3.flip_vertically();
		image3.write_tga_file("output3.tga");

		std::cout << "the result is in output3.tga" << std::endl;
		break;
	}
	case 6: {
		TGAImage image4(4000, 4000, TGAImage::RGB);

		Object * head = MyParser::read_Obj("african_head.txt");
		MyPaint::drawObj_zalivka(head, image4, MyPaint::GREEN);
		delete head;
		image4.flip_vertically();
		image4.write_tga_file("output4.tga");

		std::cout << "the result 2 is in output4.tga" << std::endl;
		break;
	}
	default:{
		std::cout << "there is no such command" << std::endl;
		break;
	}
	}
	//


	std::cout << "tap a button to close the window" << std::endl;
	char c;
	std::cin >> c;
	return 0;
}

/*
bool operator==(TGAColor color1, TGAColor color2) {
	return (color1.r == color2.r) && (color1.g == color2.g) && (color1.b == color2.b) && (color1.a == color2.a);
}
int main() {
	std::cout << (MyPaint::RED == MyPaint::RED) << std::endl;
	std::cout << (MyPaint::RED == MyPaint::BLUE) << std::endl;
	std::cout << (1==0) << std::endl;
	char c;
	std::cin >> c;
	return 0;
}/**/