#pragma once

#include <string>

class Teacher
{
private:
	std::string Username;
	std::string Password;

public:
	Teacher();
	Teacher(std::string user, std::string pswd);

	void SetUser(std::string usr);
	void SetPswd(std::string pswd);

	std::string GetUser();
	std::string GetPswd();


};