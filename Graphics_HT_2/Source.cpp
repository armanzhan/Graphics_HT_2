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

//test_object_______________
void testObj(TGAImage &image) {
	MyParser::drawObj1( image, "african_head.obj");
	MyParser::drawObj2(image, "african_head.obj");
}
/**/
//___MAIN__________________
int main(int argc, char** argv) {
	
	std::cout << "2 - HT 2, 3: lines, circles, Vu" << std::endl;
	std::cout << "4 - simple parsing" << std::endl;
	std::cout << "4 - clever parsing" << std::endl;
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
		TGAImage image1(4000, 4000, TGAImage::RGB);

		MyParser::drawObj1(image1, "african_head.txt");
		image1.flip_vertically();
		image1.write_tga_file("output1.tga");
		
		std::cout << "the result 1 is in output1.tga" << std::endl;
		
		TGAImage image2(4000, 4000, TGAImage::RGB);

		MyParser::drawObj2(image2, "african_head.txt");
		image2.flip_vertically();
		image2.write_tga_file("output2.tga");

		std::cout << "the result 2 is in output2.tga" << std::endl;
		break;
	}
	default:{
		std::cout << "нет такой команды, до свидания" << std::endl;
		break;
	}
	}
	//


	std::cout << "tap a button to close the window" << std::endl;
	char c;
	std::cin >> c;
	return 0;
}
/**/
/*
int main() {
	std::string str = "v -100e50/ 20.5 300e.";
	std::string word = "bbb";
	//std::string number = "bbb";
	int numint = 0;
	float numfloat = 0.0;

	std::cout << std::endl;
	std::cout << "str         = |"<< str <<std::endl;

	MyParser::firstWord(str, word);
	
	std::cout << "first word  = |"<<word << std::endl;
	std::cout << "changed str = |"<< str << std::endl;
	
	//MyParser::findFirstInt(str, numint);

	//std::cout << "first number= |" << numint << std::endl;
	//std::cout << "changed str = |" << str << std::endl;



	MyParser::findFirstFloat(str, numfloat);

	std::cout << "first number= |" << numfloat << std::endl;
	std::cout << "changed str = |" << str << std::endl;


	char c;
	std::cin >> c;
	//MyParser::findFirstNumber(str, word);
	return 0;
}/**/