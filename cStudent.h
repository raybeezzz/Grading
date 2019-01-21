#pragma once

#include <string>
#include <iostream>
#include <iomanip>

class cStudent {
	friend class cCourse;
	private:
		std::string student_number;
		float lab_grade;
		float quiz_grade;
		float midterm_grade;
		float final_exam_grade;
		float final_grade;
		void print_grades();

};