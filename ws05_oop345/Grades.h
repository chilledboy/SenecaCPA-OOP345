#ifndef _TN_GRADES_HEADER__
#define _TN_GRADES_HEADER__

#include <iostream>
#include <string>

namespace sict
{
	class Grades
	{
		int* stdID;
		double* stdGrades;
		size_t numOfRecords = 0;

	public:
		Grades(const std::string& filename);
		~Grades();
		void displayGrades(std::ostream& os, std::string (*funcP) (double)) const;

		// Deleted functions
		Grades(Grades&) = delete;
		Grades(Grades&&) = delete;
		Grades& operator=(Grades&) = delete;
		Grades& operator=(Grades&&) = delete;

	};
}




#endif