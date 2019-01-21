#include "pch.h"
#include "cCourse.h"

#include <string>
#include <iomanip>
#include <vector>
#include <regex>


int main()
{
	//delcaration of string for welcome message
	std::string welcome_message_string;

	cCourse course;
	//welcome message
	welcome_message_string = "*******************************************\n\n";
	welcome_message_string += "  ELEX4618 Grade System, by RAYMOND BEDRY   \n\n";
	welcome_message_string += "*******************************************\n\n";

	std::cout << welcome_message_string;

	char user_input;
	while (1) //forever loop
	{

		course.print_main_menu();

		//taking input from keyboard and assigning it to variable
		std::cin >> user_input;

		switch (user_input)
		{
		case'A': case'a':
			course.add_student();
			break;
		case'D': case 'd':
			course.delete_student();
			break;
		case 'E': case 'e':
			course.edit_student();
			break;
		case 'L': case 'l':
			course.load_file();
			break;
		case 'H': case 'h':
			course.print_all();
			break;
		case'P': case 'p':
			course.print_grade();
			break;
		case'Q': case 'q':
			course.quit();
			break;
		case'S': case 's':
			course.save_file();
			break;
		default:
			std::cout << "Invalid Response, please try again entering a valid response corresponding to desired action." << std::endl;
		}//end switch
	}//end while
}//end main

//adding stuff for the sake of stuff

