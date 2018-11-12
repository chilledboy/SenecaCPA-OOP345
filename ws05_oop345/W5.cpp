// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Elliott Coleshill
// 2018-08-22

#include <iostream>
#include <fstream>
#include <cmath>
#include "Grades.h"
#include "Letter.h"

using namespace sict;

int main(int argc, char* argv[]) {

	std::ofstream ofs("Lab5Output.txt");

	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	try
	{
		auto letter = [](double grd)
		{
			grd = std::round(grd);
			Letter ltrGrd;

			if (grd > C_plus)
			{
				if (grd <= A_plus && grd > A)
				{
					ltrGrd = A_plus;
				}

				else if (grd <= A && grd > B_plus)
				{
					ltrGrd = A;
				}

				else if (grd <= B_plus && grd > B)
				{
					ltrGrd = B_plus;
				}

				else
				{
					ltrGrd = B;
				}
			}

			else if (grd > F)
			{
				if (grd <= C_plus && grd > C)
				{
					ltrGrd = C_plus;
				}

				else if (grd <= C && grd > D_plus)
				{
					ltrGrd = C;
				}

				else if (grd <= D_plus && grd > D)
				{
					ltrGrd = D_plus;
				}

				else
				{
					ltrGrd = D;
				}
			}

			else if (grd >= 0)
			{
				ltrGrd = F;
			}

			else
			{
				throw "Error! Invalid grade.";
			}

			return enumToLtr(ltrGrd);
		};

		sict::Grades grades(argv[1]);
		grades.displayGrades(ofs, letter);

		ofs.close();
	}

	catch (const char* grdErrMsg)
	{
		std::cout << grdErrMsg << std::endl << std::endl;
		std::cout << "Enter any key to continue...";
		std::getchar();
	}
}