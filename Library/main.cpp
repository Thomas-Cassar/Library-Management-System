#include <iostream>
#include <ctime>
#include <fstream>
#include "LMS.h"

int main()
{	
	LMS mainLMS;//Intitialize LMS class

	mainLMS.LogIn();//Prompt user for log in

	int command = -1;//Variable for input command

	srand(time(NULL));//Set the seed for random generators

	std::cout << "Welcome to the Library Management System" << std::endl;

	std::string date;

	int count = 0; while (count < 500) { mainLMS.incrementDate(); std::cout << mainLMS.getDate() << "\n";count++; } //to test incrementing date
	//std::fstream dateFile ("DateData.txt");

	//dateFile >> date;

	//mainLMS.setDate(date);

	switch (mainLMS.GetUserType())
	{

	case StudentUser:
			while (command != 0)//Main program loop
			{
				mainLMS.PrintCommands();
				std::cin >> command;

				std::cout << std::endl;
			}
			break;



	case TeacherUser:
			while (command != 0)//Main program loop
			{
				mainLMS.PrintCommands();
				std::cin >> command;

				std::cout << std::endl;
			}
			break;



	case LibrarianUser:
			while (command != 0)//Main program loop
			{
				mainLMS.PrintCommands();
				std::cin >> command;

				std::cout << std::endl;
			}
			break;



		default:
			std::cerr << "Critical error: No User Type" << std::endl;
			break;
	}
	
	std::cout << "Goodbye. Thank you for using the Library Management System.";

	return 0;
}
