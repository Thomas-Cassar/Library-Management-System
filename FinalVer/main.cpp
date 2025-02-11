#include <iostream>
#include <ctime>
#include <fstream>
#include "LMS.h"

int main()
{
	LMS mainLMS;//Intitialize LMS class

	int command = -1;//Variable for input command

	srand((unsigned int)time(NULL));//Set the seed for random generators

	std::string date;// Var for holding date
	// Open date file to read last date on exit
	std::fstream dateFile("DateData.txt");
	if (dateFile.fail())
	{
		std::cerr << "Could not open date file";
		exit(1);
	}

	int count = 0;

	//loop through date file to get the most recent date
	while (dateFile >> date >> count);

	if (date != "")
	{
		mainLMS.setDate(date);
		mainLMS.setCounter(count);
	}

	//Reset fstream flags
	dateFile.close();
	//opens file again
	dateFile.open("DateData.txt");

	clock_t t = clock();

	clock_t m = t;

	while (command != 0)//Main program loop exit when quit command
	{
		//Print commands and take in user input for command
		mainLMS.PrintCommands();
		std::cin >> command;
		if (!std::cin.good())//Make sure command entered is an integer if not ignore
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			command = -1;
			std::cout << "Wrong command!" << std::endl;
			continue;
		}
		mainLMS.ExecuteCommand(command);
		mainLMS.AutoRemove();
		mainLMS.updateBooks();
	}

	m = clock() - m;
	std::string LMSDATE = mainLMS.getDate();

	//increments the date of LMS system based on the amount of time that has passed between login and logout
	for (int iter = 0; iter < float(m) / 1000; iter++)
	{
		if (iter != 0 && iter % 5 == 0)
		{
			LMSDATE = mainLMS.incrementDate(LMSDATE);
			mainLMS.incCounter();
		}
	}
	mainLMS.setDate(LMSDATE);
	dateFile << mainLMS.getDate();
	dateFile << " ";
	dateFile << mainLMS.getCounter() << std::endl;


	std::cout << "The date is: " << mainLMS.getDate() << std::endl;

	std::cout << "Goodbye. Thank you for using the Library Management System.";

	mainLMS.updateFiles();
	dateFile.close();

	return 0;
}
