// Name:  Tracy Nguyen
// Student ID: 127270171
// Email:  tnguyen157@myseneca.ca
// Date of completion: Oct 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#include "Product.h"

namespace w6
{
	double Product::getPrice() const
	{
		return prdCost;
	}

	void Product::display(std::ostream& os) const
	{
		os << prdNum << prdCost << std::endl;
		return;
	}
}