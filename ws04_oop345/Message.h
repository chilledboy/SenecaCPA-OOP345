#ifndef _TN_MESSAGE_HEADER__
#define _TN_MESSAGE_HEADER__

#include <fstream>

namespace w5
{
	class Message
	{
		std::ifstream is;

	public:
		Message();
		Message(std::ifstream& in, char c);
		bool empty() const;
		void display(std::ostream&) const;
	};
}



#endif
