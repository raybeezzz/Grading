#include "pch.h"
#include "cCourse.h"
#include "cStudent.h"


#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

#define YES 1
#define NO 0

//print all student function
void cCourse::print_all()
{
	std::cout << "There are " << this->student.size() << " students in this class\n ";
	std::cout << std::setw(2) << "#" << std::setw(10) <<
		"Student Number " << std::setw(6) << "Lab Grade " << std::setw(6) <<
		"Quiz Grade " <<  std::setw(9) << "Midterm Grade " << std::setw(12) <<
		"Final Exam Grade " << std::setw(13) << std::setprecision(2) <<
		std::fixed << "Final Grade " << std::endl;
	for (int count = 0; count < this->student.size(); count++)
	{
		std::cout << std::setw(2) << count + 1;
		this->student[count].print_grades();
	}//end for
}//end print all function

void cCourse::print_grade() {

	int response = 0;
	std::cout << "Which student would you like to print?" << std::endl;
	std::cin >> response;
	std::cout << std::setw(3) << "#" << std::setw(10) <<
		"Student Number " << std::setw(6) << "Lab Grade " << std::setw(6) <<
		"Quiz Grade " << std::setw(9) << "Midterm Grade " << std::setw(12) <<
		"Final Exam Grade " << std::setw(13) << std::setprecision(2) <<
		std::fixed << "Final Grade " << std::endl;
	std::cout << std::setw(2) << response;
	this->student[response - 1].print_grades();
}//end print grade gunction

//delete student function
void cCourse::delete_student()
{
	int response;

	std::cout << "Which Student would you like to delete?" << std::endl;
	std::cin >> response;
	student.erase(student.begin() + response - 1);
	
}//end delete student function

//edit student function
void cCourse::edit_student() {

	std::string input_student_number, mark;
	std::regex student_id("([A|a]0[0-1][0-9]{6})$");
	bool validity;
	int correct;

	//variables for stepping through options and identifying user response
	int editer, edit_response;
	std::string response;
	char user_input, continue_edit_answer;

	//Question followed with input from user
	std::cout << "Which student would you like to edit?  ";
	std::cin >> editer;
	

	do {
		//determing what the user would like to edit
		std::cout << "What would you like to edit?  ";
		//call to print edit menu function
		print_edit_menu();
		//waiting for user input
		std::cin >> user_input;

		//matching user input to cases and performing appropriate task
		switch (user_input)
		{
		case'S': case's':
		{
			std::cout << "New Student Number:";
			do
			{
				std::cin >> input_student_number;
				if (std::regex_match(input_student_number, student_id))
				{
					this->student[editer -1].student_number = input_student_number;
					correct = YES;
				}
				else
				{
					std::cout << "Invalid Student Number Entered. Student Number must be in form \"A00950868\"\n Please try again:\n";
					correct = NO;
				}
			} while (correct == NO);
		}
		break;
		case 'L': case 'l':
		{
			std::cout << "New Lab Grade:";
			do
			{
				validity = false;
				std::cin >> mark;
				validity = error_check(mark);
				if (validity == true)
				{
					this->student[editer - 1].lab_grade = stof(mark);
				}
				else
				{
					std::cout << "Invalid Grade Entered. Grade must be numeric, eg. 98.7 \n Please try again:\n";
				}

			} while (validity == false);
		}
			break;
		case'Q': case 'q':
		{
			std::cout << "New Quiz Grade:";
			do
			{
				std::cin >> mark;
				validity = error_check(mark);
				if (validity == true)
				{
					this->student[editer - 1].quiz_grade = stof(mark);
				}
				else
				{
					std::cout << "Invalid Grade Entered. Grade must be numeric, eg. 98.7 \n Please try again:\n";
				}
			} while (validity == false);

		}
		break;
		case'M': case 'm':
		{
			std::cout << "New Midterm Grade:";
			do
			{
				std::cin >> mark;
				validity = error_check(mark);
				if (validity == true)
				{
					this->student[editer - 1].midterm_grade = stof(mark);
				}
				else
				{
					std::cout << "Invalid Grade Entered. Grade must be numeric, eg. 98.7 \n Please try again:\n";
				}
			} while (validity == false);
		}
		break;
		case'F': case 'f':
		{
			std::cout << "New Final Exam Grade:";
			do
			{
				std::cin >> mark;
				validity = error_check(mark);
				if (validity == true)
				{
					this->student[editer - 1].final_exam_grade = stof(mark);
				}
				else
				{
					std::cout << "Invalid Grade Entered. Grade must be numeric, eg. 98.7 \n Please try again:\n";
				}
			} while (validity == false);
		}
		break;
		default:
			std::cout << "Invalid Response";
		}
		//asking user if they would like to continue to edit
		std::cout << "Continue to edit?\n\n (Y)es or any other key to exit editing   ";
		std::cin >> continue_edit_answer;
		switch (continue_edit_answer)
		{
		case 'Y': case 'y':
			edit_response = YES;
			break;
		default:
			edit_response = NO;
		}//end switch 
	} while (edit_response == YES);//end do-while
		this->student[editer -1].final_grade = ((student[editer - 1].lab_grade * 40) + (student[editer - 1].quiz_grade * 10) + (student[editer - 1].midterm_grade * 20) + (student[editer - 1].final_exam_grade * 30)) / 100;

}//end edit student function

//add student function 
void cCourse::add_student()
{

	cStudent etudient;
	std::string input_student_number, mark;
	std::regex student_id("([A|a]0[0-1][0-9]{6})$"); 
	bool validity;
	int correct;

	std::cout << "\nEnter Data:\n";

	//Student Number
	std::cout << "Student Number:";
	do
	{
		std::cin >> input_student_number;
		if (std::regex_match(input_student_number, student_id))
		{
			etudient.student_number = input_student_number;
			correct = YES;
		}
		else 
		{
			std::cout << "Invalid Student Number Entered. Student Number must be in form \"A00950868\"\n Please try again:\n";
			correct = NO;
		}
	} while (correct == NO);
	

	//Lab Grade
	std::cout << "\nLab Grade:";
	do
	{
		validity = false;
		std::cin >> mark;
		validity = error_check(mark);
		if (validity == true)
		{
			etudient.lab_grade = stof(mark);
		}
		else
		{
			std::cout << "Invalid Grade Entered. Grade must be numeric, eg. 98.7 \n Please try again:\n";
		}

	} while (validity == false);

	//Quiz Grade
	std::cout << "\nQuiz Grade:";
	do
	{
		std::cin >> mark;
		validity = error_check(mark);
		if (validity == true)
		{
			etudient.quiz_grade = stof(mark);
		}
		else
		{
			std::cout << "Invalid Grade Entered. Grade must be numeric, eg. 98.7 \n Please try again:\n";
		}
	} while (validity == false);
	
	//Midterm Grade
	std::cout << "\nMidterm Grade:";
	do
	{
		std::cin >> mark;
		validity = error_check(mark);
		if (validity == true)
		{
			etudient.midterm_grade = stof(mark);
		}
		else
		{
			std::cout << "Invalid Grade Entered. Grade must be numeric, eg. 98.7 \n Please try again:\n";
		}
	} while (validity == false);

	//Final Exam Grade
	std::cout << "\nFinal Exam Grade:";
	do
	{
		std::cin >> mark;
		validity = error_check(mark);
		if (validity == true)
		{
			etudient.final_exam_grade = stof(mark);
		}
		else
		{
			std::cout << "Invalid Grade Entered. Grade must be numeric, eg. 98.7 \n Please try again:\n";
		}
	} while (validity == false);

	std::cout << std::setw(13);
	etudient.final_grade = (((etudient.lab_grade * 40) + (etudient.quiz_grade * 10) + (etudient.midterm_grade * 20) + (etudient.final_exam_grade * 30)) / 100);
	
	this->student.push_back(etudient);

}//end add student function 

//quit function 
void cCourse::quit() {
	exit(0);
}//end quit function

// edit menu function 
void cCourse::print_edit_menu() {
		std::string menu_string;
		menu_string += "\n\n (S)Student Number\n";
		menu_string += " (L)Lab Grade\n";
		menu_string += " (Q)uiz Grade\n";
		menu_string += " (M)Midterm Grade\n";
		menu_string += " (F)inal Exam Grade\n";
		std::cout << menu_string << std::endl;
} //end edit menu function

//main menu function 
void cCourse::print_main_menu() {
	std::string menu_string;
	menu_string += "\n (A)dd Student\n\n";
	menu_string += " (E)dit Student\n\n";
	menu_string += " (D)elete Student\n\n";
	menu_string += " (P)rint grades\n\n";
	menu_string += " (S)ave File\n\n";
	menu_string += " S(H)ow All Students\n\n";
	menu_string += " (L)oad File\n\n";
	menu_string += " (Q)uit\n\n";
	menu_string += " CMD>  ";
	std::cout << menu_string;
}//end main menu function 

//error checking function
bool cCourse::error_check(std::string grade)
{
	float entered_grade;
	std::regex alpha("(^[0-9\.]{1,5})*$");

	if (std::regex_match(grade, alpha))
	{
		entered_grade = stof(grade);

		if (entered_grade <= 100 && entered_grade >= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void cCourse::save_file()
{
	std::string name_of_file;
	std::string file_type = ".txt";

	std::cout << "\nWhat would you like to call this file?\n";
	std::cin >> name_of_file;

	std::ofstream saved(name_of_file);

	if (!saved)
	{
		std::cout << "oops, something went wrong! Please contact IT for support" << std::endl;
		return;
	}
	for (int count = 0; count < student.size(); count++)
	{
		saved << student[count].student_number << "," <<
			student[count].lab_grade << "," <<
			student[count].quiz_grade << "," <<
			student[count].midterm_grade << "," <<
			student[count].final_exam_grade << "," <<
			student[count].final_grade << "," << std::endl;
	}
	std::cout << "File Saved Succesfully \n";
	saved.close();
	return;
}

void cCourse::load_file()
{
	//instantiate cStudent
	cStudent etudient;
	std::string line;
	std::string file_name;
	std::string data_load;
	std::cout << "Name of file to load: \n";
	std::cin >> file_name;

	std::ifstream myfile{ file_name };
	
	//if error opening
	if (!myfile)
	{
		std::cout << "Can't open input file ", file_name;
	}
	//if opened
	else
	{
		
		while (std::getline(myfile, data_load, ','))
		{
			etudient.student_number = data_load;
			//lab grade load
			std::getline(myfile, data_load, ',');
			etudient.lab_grade = stof(data_load);
			//quiz grade load
			std::getline(myfile, data_load, ',');
			etudient.quiz_grade = stof(data_load);
			//midterm grade load
			std::getline(myfile, data_load, ',');
			etudient.midterm_grade = stof(data_load);
			//final exam grade load
			std::getline(myfile, data_load, ',');
			etudient.final_exam_grade = stof(data_load);
			//final grade load
			std::getline(myfile, data_load);
			etudient.final_grade = stof(data_load);
			//push back in vector
			this->student.push_back(etudient);
		}

	}
	return;
}