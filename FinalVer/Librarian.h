#pragma once
#include "User.h"
#include <iostream>
class Librarian : public User
{
private:
public:
    Librarian();
    Librarian(std::string user, std::string pswd);

    //Overloaded operators
    friend std::ostream& operator << (std::ostream& out, Librarian& librarian);
    friend std::istream& operator >> (std::istream& in, Librarian& librarian);
};

//Overloaded operators
std::ostream& operator << (std::ostream& out, Librarian& librarian);
std::istream& operator >> (std::istream& in, Librarian& librarian);