// Name:  Tracy Nguyen
// Student ID: 127270171
// Email:  tnguyen157@myseneca.ca
// Date of completion: Dec 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#include "Task.h"


Task::Task(std::string& str) : Task::Item(str)
{
	pNextTask = nullptr;
}

void Task::RunProcess(std::ostream& os)
{
	// Maker counter since MoveTask() will not work on last task. Otherwise would be stuck in inifinite loop
	size_t orderCount = Orders.size() - 1;
	while (orderCount + 1)
	{
		if (pNextTask != nullptr)
		{
			Orders.back().fillItem(*this, os);
			MoveTask();
		}

		else
		{
			Orders[orderCount].fillItem(*this, os);
		}

		orderCount--;
	}

	return;
}

bool Task::MoveTask()
{
	bool moved = false;

	if (Orders.size() && pNextTask != nullptr)
	{
		*pNextTask += std::move(Orders.back());
		Orders.pop_back();
		moved = true;
	}

	return moved;
}

void Task::setNextTask(Task& task)
{
	pNextTask = &task;
	return;
}

bool Task::getCompleted(CustomerOrder& src)
{
	bool completed = false;

	if (Orders.size() > 0 && pNextTask == nullptr && Orders.back().getOrderFillState())
	{
		src = std::move(Orders.back());
		Orders.pop_back();
		completed = true;
	}


	return completed;
}

void Task::Validate(std::ostream& os)
{
	if (pNextTask != nullptr)
	{
		os << pNextTask->getName();
	}

	else
	{
		os << getName();
	}

	return;
}

Task& Task::operator+=(CustomerOrder&& newOrder)
{
	Orders.push_front(std::move(newOrder));
	return *this;
}

