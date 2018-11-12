#include <fstream>
#include <iomanip>
#include "Grades.h"

namespace sict
{
	Grades::Grades(const std::string& filename)
	{
		if (!filename.empty())
		{
			try {
				std::string line;

				// Find # of records
				std::ifstream ifs(filename);

				// Error message if file couldn't open
				if (!ifs.is_open())
				{
					throw "Error! File could not be opened.";
				}

				for (; !ifs.eof(); numOfRecords++)
				{
					std::getline(ifs, line);
				}

				// Rewind file for reading
				ifs.clear();
				ifs.seekg(0);


				stdID = new int[numOfRecords];
				stdGrades = new double[numOfRecords];

				// at() returns char at given pos
				// find() returns pos of first matched char, 2nd param is starting pos
				// substr() returns str starting AND including at given pos (counts like array), 
				//	2nd param is # of chars

				for (size_t i = 0; i < numOfRecords; i++)
				{
					std::getline(ifs, line);
					stdID[i] = std::stoi(line.substr(0, line.find(' ')));
					stdGrades[i] = std::stod(line.substr(line.find(' ') + 1));

				}

				ifs.close();
			}

			catch (const char* fileErrMsg)
			{
				std::cout << fileErrMsg << std::endl << std::endl;
				std::cout << "Enter any key to continue...";
				std::getchar();
			}
		}
	}

	void Grades::displayGrades(std::ostream& os, std::string (*funcP) (double)) const
	{
		for (size_t i = 0; i < numOfRecords; i++)
		{
			os << stdID[i] << ' ' << std::fixed << std::setprecision(2) << stdGrades[i] << ' ' << funcP(stdGrades[i]) << std::endl;
		}


		return;
	}

	Grades::~Grades()
	{
		delete[] stdID;
		delete[] stdGrades;
	}
}