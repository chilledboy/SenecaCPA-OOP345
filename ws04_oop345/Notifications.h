#ifndef _TN_HEADER_NOTIFS__
#define _TN_HEADER_NOTIFS__

#include "Message.h"

#define MAX_SIZE 10

namespace w5
{
	class Notifications
	{
		Message* msgNotifs;
		size_t numOfMsgs = 0;

	public:
		Notifications();
		Notifications(const Notifications&);
		Notifications(Notifications&&);
		~Notifications();

		Notifications& operator=(const Notifications&);
		Notifications& operator=(Notifications&&);
		void operator+=(const Message& msg);
		void display(std::ostream& os) const;
	};
}


#endif