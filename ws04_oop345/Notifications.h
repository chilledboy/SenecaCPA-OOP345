#ifndef _TN_HEADER_NOTIFS__
#define _TN_HEADER_NOTIFS__

#include "Message.h"

namespace w5
{
	class Notifications
	{
		Message msgNotifs[10];

	public:
		Notifications();
		Notifications(const Notifications&);
		Notifications(Notifications&&);
		~Notifications();

		Notifications& operator=(const Notifications&);
		Notifications& operator=(const Notifications&&);
		void operator+=(const Message& msg);
		void display(std::ostream& os) const;
	};
}


#endif