// Name:  Tracy Nguyen
// Student ID: 127270171
// Email:  tnguyen157@myseneca.ca
// Date of completion: Dec 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

/*
EXPLANATION
An assembly line is made up of tasks. Each task will only fill the same item on any order. 
Task will check first if the order has the item before trying to fill it.
pNextTask is used to ensure that the orders are passed through every task. (ex. If you have Task 1 - 5, you want to make sure the order goes through all 5 rather than maybe just one then five.)
The line manager is what make the assembly line run. Even though the tasks are under the assembly line, the calls are done by the line manager.
*/


#include <sstream>
#include <fstream>
#include <algorithm>
#include "LineManager.h"


LineManager::LineManager(std::string& filename, std::vector<Task*>& AssemblyLine_, std::vector<CustomerOrder>& ToBeFilled_)
{
	std::ifstream fileParam(filename);
	std::vector<std::string>strVec;
	std::string record;
	std::string line;
	std::stringstream cmpstrs;

	// Create vector of every record
	while (std::getline(fileParam, line))
	{
		std::stringstream strs(line);
		while (std::getline(strs, record, '|'))
		{
			strVec.push_back(record);
		}
	}

	CustomerOrder_Count = ToBeFilled_.size();
	for (size_t i = 0; i < ToBeFilled_.size(); i++)
	{
		ToBeFilled.push_front(std::move(ToBeFilled_[i]));
	}
	
	for (size_t i = 0; i < AssemblyLine_.size(); i++)
	{
		// Copy tasks that are in any of the customer orders
		if(std::any_of(strVec.cbegin(), strVec.cend(), [&](std::string str1) {return !str1.compare(AssemblyLine_[i]->getName()); }))
		{
			AssemblyLine.push_back(AssemblyLine_[i]);
			cmpstrs << AssemblyLine_[i]->getName();		// Make string stream of all matched item names for validation
		}
	}

	for (size_t i = 0; i < AssemblyLine.size() - 1; i++)
	{
		AssemblyLine[i]->setNextTask(*AssemblyLine[i + 1]);
	}

	// Input name of last item into cmpstrs
	// Input name of first item as it won't be inputted within the loop
	cmpstrs << AssemblyLine.back()->getName();
	std::stringstream validstrs;
	validstrs << AssemblyLine[0]->getName();

	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		AssemblyLine[i]->Validate(validstrs);
	}

	try
	{
		if (cmpstrs.str() != validstrs.str())
		{
			throw "Error! Tasks are linked incorrectly.";
		}
	}

	catch (const char *msg)
	{
		std::cout << msg << std::endl;
		std::cout << "Press any key to continue..." << getchar();
	}

	
}

bool LineManager::Run(std::ostream& os)
{
	bool runComplete = false;

	while (ToBeFilled.size())
	{
		*AssemblyLine.front() += std::move(ToBeFilled.back());
		ToBeFilled.pop_back();
	}

	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		AssemblyLine[i]->RunProcess(os);
	}

	CustomerOrder tmpObj;
	for (size_t i = 0; i < CustomerOrder_Count; i++)
	{
		if (AssemblyLine.back()->getCompleted(tmpObj))
		{
			Completed.push_back(std::move(tmpObj));
		}

		else
		{
			AssemblyLine.back()->display(std::cout, true);
			std::cout << getchar();
		}
	}

	if (Completed.size() == CustomerOrder_Count)
	{
		runComplete = true;
		os << std::endl << "COMPLETED" << std::endl;
		for (size_t i = 0; i < Completed.size(); i++)
		{
			Completed[i].Display(os);
		}
	}


	return runComplete;
}
