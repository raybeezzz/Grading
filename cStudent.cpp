
#include "pch.h"
#include "cStudent.h"

void cStudent::print_grades()
{
	std::cout << std::fixed << std::setprecision(1) << std::setw(15) <<
		student_number << std::setw(10) << lab_grade << std::setw(11) <<
		quiz_grade << std::setw(14) << midterm_grade << std::setw(17) <<
		final_exam_grade << std::setw(13) << std::setprecision(2) <<
		std::fixed << final_grade << std::endl;


}

