#ifndef _TN_MESSAGE_HEADER__
#define _TN_MESSAGE_HEADER__

#include <fstream>
#include <cstring>

namespace w5
{
	class Message
	{

		std::string user;
		std::string replyTo;
		std::string tweet;

	public:
		Message();
		Message(std::ifstream& in, char c);
		bool empty() const;
		void display(std::ostream&) const;
		Message& operator=(const Message&);
	};
}



#endif
