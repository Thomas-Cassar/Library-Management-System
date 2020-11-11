#pragma once
#include <string>

class User
{
private:
	std::string Username;//Stores logged in students username
	std::string Password;//Stores logged in students password
public:
	//Constructor
	User(std::string user, std::string pswd);
	//Destructor
	virtual  ~User();
	//Getter Functions
	std::string GetUser();
	std::string GetPswd();
	//Setter Funtions
	void SetUser(std::string usr);
	void SetPswd(std::string pswd);
	//Command functions
	void Print();
};

