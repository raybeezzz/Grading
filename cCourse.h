#pragma once

#include "cStudent.h"

#include <vector>
#include <fstream>

class cCourse {
	public: 
		void add_student();
		void edit_student();
		void delete_student();
		void quit();
		void print_grade();
		void print_all();
		void print_edit_menu();
		void print_main_menu();
		void save_file();
		void load_file();
		bool error_check(std::string grade);

	private:  
		std::vector<cStudent> student;
 };
