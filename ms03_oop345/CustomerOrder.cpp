// Name:  Tracy Nguyen
// Student ID: 127270171
// Email:  tnguyen157@myseneca.ca
// Date of completion: Nov 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#include <utility>
#include <vector>
#include <cstring>
#include "Utilities.h"
#include "Item.h"
#include "CustomerOrder.h"

CustomerOrder::CustomerOrder()
{
	Name = '\0';
	Product = '\0';
	ItemCount = 0;
	ItemList = nullptr;
	field_width = 0;
}

CustomerOrder::CustomerOrder(std::string& str)
{
	Utilities utilObj;
	
	size_t pos = 0;
	bool value = false;
	std::vector<ItemInfo*> ItemVctr;

	Name = utilObj.extractToken(str, pos, value);
	pos++;

	Product = utilObj.extractToken(str, pos, value);

	while(value)
	{
		//ItemInfo tempItm(utilObj.extractToken(str, pos, value));
		ItemVctr.push_back(new ItemInfo(utilObj.extractToken(str, pos, value)));
	}

	ItemCount = ItemVctr.size();

	ItemList = new ItemInfo* [ItemCount];
	for (size_t i = 0; i < ItemCount; i++)
	{
		ItemList[i] = std::move(ItemVctr[i]);
	}

}

CustomerOrder::CustomerOrder(CustomerOrder&& obj)
{
	*this = std::move(obj);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& obj)
{
	if(this != &obj)
	{
		Name = obj.Name;
		Product = obj.Product;
		ItemList = obj.ItemList;
		ItemCount = obj.ItemCount;
		field_width = obj.field_width;

		obj.Name = "";
		obj.Product = "";
		obj.ItemList = nullptr;
		obj.ItemCount = 0;
		obj.field_width = 0;
	}

	return *this;
}

CustomerOrder::~CustomerOrder()
{
	for (size_t i = 0; i < ItemCount; i++)
	{
		delete ItemList[i];
		ItemList[i] = nullptr;
	}

	delete[] ItemList;
	ItemList = nullptr;
}

bool CustomerOrder::getOrderFillState()
{
	bool filled = true;

	for (size_t i = 0; i < ItemCount; i++)
	{
		filled *= ItemList[i]->FillState;
	}

	return filled;
}

bool CustomerOrder::getItemFillState(std::string itemName)
{
	bool filled = false;
	size_t i = 0;
	
	for (; i < ItemCount; i++)
	{
		if (ItemList[i]->ItemName.compare(itemName) == 0 && ItemList[i]->FillState)
		{
			filled = true;
		}
	}

	return filled;
}

void CustomerOrder::fillItem(Item& item_, std::ostream& os)
{
	for (size_t i = 0; i < ItemCount; i++)
	{
		if(ItemList[i]->ItemName.compare(item_.getName()) == 0)
		{
			// Filled Mary M., Desktop PC[CPU]
			os << "Filled " << Name << ", " 
				<< Product << '[' << item_.getName() << ']' 
				<< std::endl;

			ItemList[i]->ItemName = item_.getName();
			ItemList[i]->SerialNumber = item_.getSerialNumber();
			ItemList[i]->FillState = true;
		}
	}

	return;
}

void CustomerOrder::Display(std::ostream& os)
{
	os << Name << std::endl;
	os << Product << std::endl;

	// [0] GPU - MISSING
	// Cycle through duplicates*
	for (size_t i = 0; i < ItemCount; i++)
	{
		os << '[';
		//os << getItemFillState(ItemList[i]->ItemName) ? ItemList[i]->SerialNumber : '0';
		os << ItemList[i]->SerialNumber;
		os << "] ";

		os << ItemList[i]->ItemName << " - ";
		os << (getItemFillState(ItemList[i]->ItemName) ? "FILLED" : "MISSING");
		os << std::endl;
	}

	return;
}