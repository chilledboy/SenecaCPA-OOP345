// Name:  Tracy Nguyen
// Student ID: 127270171
// Email:  tnguyen157@myseneca.ca
// Date of completion: Oct 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#include <string>
#include "iProduct.h"

namespace w6 {
	std::ostream& operator<< (std::ostream& os, const iProduct* obj)
	{
		return os << obj;
	}

	iProduct* readProduct(std::ifstream& is)
	{
		// at() returns char at given pos
		// find() returns pos of first matched char, 2nd param is starting pos
		// substr() returns str starting AND including at given pos (counts like array), 2nd param is # of chars

		std::string line;
		std::getline(is, line);
		int num = atoi(line.substr(0, 5).c_str());

		if (line.at(12) != '\n')
		{
			double price = atoi(line.substr(num + num.length(), 5).c_str());
		}

		else
		{
			double price = atoi(line.substr(num + num.length(), 5, ' '));
			char taxStatus = line.at();
		}

		return;
	}
}