// Name:  Tracy Nguyen
// Student ID: 127270171
// Email:  tnguyen157@myseneca.ca
// Date of completion: Nov 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#include "Utilities.h"

char Utilities::delimiter;

Utilities::Utilities()
{
	field_width = 1;

}

void Utilities::setFieldWidth(size_t fw)
{
	field_width = fw;
	return;
}

size_t Utilities::getFieldWidth() const
{
	return field_width;
}

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
	if (next_pos)
	{
		next_pos = str.find(delimiter, next_pos + 1) + 1;
	}

	std::string temp = str.substr(next_pos);
	size_t pos = temp.find(delimiter);
	// npos
	// extract at next_pos, field length is the space between the delimiter before and after it
		//temp = str.substr(next_pos, str.find(delimiter, next_pos) - str.find(delimiter, next_pos - 1) - 1);

	if (pos != std::string::npos)
	{
		temp = temp.substr(0, pos);
		more = true;
	}

	else
	{
		more = false;
	}

	return temp;
}

void Utilities::setDelimiter(const char delimParam)
{
	delimiter = delimParam;
	return;
}

const char Utilities::getDelimiter() const
{
	return delimiter;
}