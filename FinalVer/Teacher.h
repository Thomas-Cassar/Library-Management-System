#pragma once
#include "Reader.h"
#include <string>
class Teacher : public Reader
{
private:
public:
	//Constructors
	Teacher();
	Teacher(std::string user, std::string pswd);
};

