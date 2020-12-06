#pragma once
#include "Header.h"
#include "Point.h"
#include "Figure.h"
#include "MyPaint.h"
#include "Model.h"
namespace MyParser {
	
	Model * read_Obj(std::string name);

	void firstWord(std::string& str, std::string& word);

	void findFirstFloat(std::string & str, float & number);
	void findFirstDouble(std::string & str, double & number);
	void findFirstInt(std::string & str, int & number);

	bool isFloat(const std::string& str);
	bool isInt(const std::string& str);
	
}
