#include <iostream>

#include "Notifications.h"

namespace w5
{
	Notifications::Notifications() : msgNotifs{} {}

	Notifications::Notifications(const Notifications& notifParam)
	{
		for (size_t i = 0; i < 10; i++)
		{
			msgNotifs[i] = notifParam.msgNotifs[i];
		}



	}

	Notifications::Notifications(Notifications&& notifParam)
	{
		std::move(notifParam);
	}
	
	Notifications::~Notifications()
	{

	}

	Notifications& Notifications::operator=(const Notifications&)
	{

		return *this;
	}

	Notifications& Notifications::operator=(const Notifications&&)
	{

		return *this;
	}



	void Notifications::operator+=(const Message& msg)
	{

		return;
	}

	void Notifications::display(std::ostream& os) const
	{
		for (size_t i = 0; i < 10; i++)
		{
			msgNotifs[i].display(os);
		}

		return;
	}
}