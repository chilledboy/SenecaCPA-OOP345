// Name:  Tracy Nguyen
// Student ID: 127270171
// Email:  tnguyen157@myseneca.ca
// Date of completion: Nov 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#include "Item.h"
#include "Utilities.h"

Item::Item(std::string& record)
{
	Utilities obj;
	bool value = false;
	
	size_t pos = 0;
	name = obj.extractToken(record, pos, value);
	pos++;

	//pos = record.find('|', pos + 1) + 1;
	serialNumber = std::stoi(obj.extractToken(record, pos, value));
	
	//pos = record.find('|', pos + 1) + 1;
	Quantity = std::stoi(obj.extractToken(record, pos, value));
	
	//pos = record.find('|', pos + 1) + 1;
	description = obj.extractToken(record, pos, value);
	
	if (obj.getFieldWidth() > field_width)
	{
		field_width = obj.getFieldWidth();
	}

}

const std::string& Item::getName() const
{
	return name;
}

const unsigned int Item::getSerialNumber()
{
	return serialNumber;
}

const unsigned int Item::getQuantity()
{
	return Quantity;
}

void Item::updateQuantity()
{
	if (Quantity)
	{
		Quantity--;
	}

	return;
}

void Item::display(std::ostream& os, bool full) const
{
	os << std::setw(20) << std::left << name << '[' << serialNumber << ']';

	if (full)
	{
		os << " Quantity " << Quantity << " Description: " << description;
	}

	os << std::endl;

	return;
}