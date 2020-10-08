#pragma once

#include <string>

class Student
{
private:
	std::string Username;
	std::string Password;

public:
	Student();
	Student(std::string user, std::string pswd);

	void SetUser(std::string usr);
	void SetPswd(std::string pswd);


};
