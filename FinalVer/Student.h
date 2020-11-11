#pragma once

#include "Reader.h"
#include <string>
#include "BookCopy.h"
#include <vector>
#include <iostream>
class Student:
	public Reader
{
private:
public:
	//Constructors
	Student();
	Student(std::string user, std::string pswd);
};

