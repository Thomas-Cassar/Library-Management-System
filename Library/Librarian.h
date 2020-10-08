#pragma once

#include <string>

class Librarian
{
private:
	std::string Username;
	std::string Password;

public:
	Librarian();
	Librarian(std::string user, std::string pswd);

	void SetUser(std::string usr);
	void SetPswd(std::string pswd);


};

