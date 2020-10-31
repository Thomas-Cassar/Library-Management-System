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

	std::fstream dateFile ("DateData.txt");

	if (dateFile.fail())
	{
		std::cerr << "Could not open date file";
		exit(1);
	}

	int count = 0;

	while (dateFile >> date >> count);

	if (date != "")
	{
	    mainLMS.setDate(date);
		mainLMS.setCounter(count);
	}

	dateFile.close();

	dateFile.open("DateData.txt");

	clock_t t = clock();

	clock_t m = t;

	switch (mainLMS.GetUserType())
	{

	case StudentUser:
			while (command != 0)//Main program loop
			{
				mainLMS.PrintCommands();
				std::cin >> command;
				//switch (command)
				//{
				//case 1: 
				//}
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
    
	m = clock() - m;

	for (int iter = 0; iter < float(m)/1000; iter ++)
	{
		if (iter != 0 && iter % 5 == 0)
		{
			mainLMS.incrementDate();
			mainLMS.incCounter();
		}
	}
	
	dateFile << mainLMS.getDate();
	dateFile << " ";
	dateFile << mainLMS.getCounter() << std::endl;

	
	std::cout << "The date is: " << mainLMS.getDate() << std::endl;

	std::cout << "Goodbye. Thank you for using the Library Management System.";

	dateFile.close();

	return 0;
}
