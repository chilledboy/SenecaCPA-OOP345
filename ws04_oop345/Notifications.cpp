// Name:  Tracy Nguyen
// Student ID: 127270171
// Email:  tnguyen157@myseneca.ca
// Date of completion: Oct 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#include <iostream>
#include "Notifications.h"

namespace w5
{
	Notifications::Notifications() : msgNotifs{ nullptr } {}

	Notifications::Notifications(const Notifications& objParam)
	{
		msgNotifs = new Message[objParam.numOfMsgs];

		for (size_t i = 0; i < objParam.numOfMsgs; i++)
		{
			msgNotifs[i] = objParam.msgNotifs[i];
		}

		numOfMsgs = objParam.numOfMsgs;

	}

	Notifications::Notifications(Notifications&& objParam)
	{
		*this = std::move(objParam);
	}

	Notifications::~Notifications()
	{
		delete[] msgNotifs;
		msgNotifs = nullptr;
	}

	Notifications& Notifications::operator=(const Notifications& objParam)
	{
		if (this != &objParam)
		{
			delete[] msgNotifs;

			msgNotifs = objParam.msgNotifs;
			numOfMsgs = objParam.numOfMsgs;

		}

		return *this;
	}

	Notifications& Notifications::operator=(Notifications&& objParam)
	{
		if (this != &objParam)
		{
			delete[] msgNotifs;

			msgNotifs = objParam.msgNotifs;
			numOfMsgs = objParam.numOfMsgs;

			 objParam.msgNotifs = nullptr;
		}

		return *this;
	}



	void Notifications::operator+=(const Message& msg)
	{

		if (numOfMsgs < MAX_SIZE && !msg.empty())
		{

			Notifications tempObj = *this;

			delete[] msgNotifs;

			numOfMsgs++;
			msgNotifs = new Message[numOfMsgs];

			for (size_t i = 0; i < tempObj.numOfMsgs; i++)
			{
				msgNotifs[i] = tempObj.msgNotifs[i];
			}

			msgNotifs[numOfMsgs - 1] = msg;

		}

		return;
	}

	void Notifications::display(std::ostream& os) const
	{
		for (size_t i = 0; i < numOfMsgs; i++)
		{
			msgNotifs[i].display(os);
		}

		return;
	}
}

