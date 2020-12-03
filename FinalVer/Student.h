#pragma once

#include "Reader.h"
#include <string>
class Student : public Reader
{
private:
public:
	//Constructors
	Student();
	Student(std::string user, std::string pswd);
};

