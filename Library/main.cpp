#include <iostream>

#include "LMS.h"

int main()
{
	LMS mainLMS;//Intitialize LMS class

	mainLMS.LogIn();//Prompt user for log in

	int command = -1;//Variable for input command

	std::cout << "Welcome to the Library Mangement System" << std::endl;

	switch (mainLMS.GetUserType())
	{

	case StudentUser:
			while (command != 1)//Main program loop
			{
				std::cout << "Enter a command number from the list below" << std::endl;
				std::cin >> command;

				std::cout << std::endl;
			}
			break;



	case TeacherUser:
			while (command != 1)//Main program loop
			{
				std::cout << "Enter a command number from the list below" << std::endl;
				std::cin >> command;

				std::cout << std::endl;
			}
			break;



	case LibrarianUser:
			while (command != 1)//Main program loop
			{
				std::cout << "Enter a command number from the list below" << std::endl;
				std::cin >> command;
	
				std::cout << std::endl;
			}
			break;



		default:
			std::cerr << "Critical error no usertype" << std::endl;
			break;
	}

	std::cout << "Goodbye thank you for using the Library Management System";

	return 0;
}
