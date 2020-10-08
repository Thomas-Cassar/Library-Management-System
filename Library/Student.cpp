#include "Student.h"

Student::Student()
{
	Username = "NULL";
	Password = "NULL";
}

Student::Student(std::string user, std::string pswd)
{
	Username = user;
	Password = pswd;
}


void Student::SetUser(std::string usr)
{
	Username = usr;
}

void Student::SetPswd(std::string pswd)
{
	Password = pswd;
}

std::string Student::GetUser()
{
	return Username;
}

std::string Student::GetPswd()
{
	return Password;
}
