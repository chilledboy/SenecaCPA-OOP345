#ifndef _CSTRING_HEADER__
#define _CSTRING_HEADER__

#include <iostream>
using namespace std;

namespace w1
{
	class CString
	{
		const int MAX;
		char * string;

	public:
		CString(char * str);
		void display(ostream& os);
	};

	ostream& operator<< (ostream& os, CString& obj);
}



#endif _CSTRING_HEADER__