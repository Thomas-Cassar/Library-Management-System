#include <iostream>

#include "LMS.h"

int main()
{
	LMS mainLMS;//Intitialize LMS class

	mainLMS.LogIn();//Prompt user for log in

	int command = -1;//Variable for input command

	std::cout << "Welcome to the Library Mangement System" << std::endl;

	while (command != 0)//Main program loop
	{
		std::cout << "Enter a command number from the list below" << std::endl;
		std::cin >> command;
	
		std::cout << std::endl;
	}
//hello
//jdijfosjoidsjfodsjofdso testst
	return 0;
}
