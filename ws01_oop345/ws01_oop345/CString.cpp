#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "CString.h"

int CHARNUM = 3;

namespace w1
{
	int num = 0;

	CString::CString(char * str) : MAX(CHARNUM)
	{
		if (str[0] != '\0')
		{
			string = new char[MAX + 1];
			strncpy(string, str, MAX);
			string[MAX] = '\0';
		}

		else
		{
			string = nullptr;
		}
	}

	void CString::display(ostream& os)
	{
		os << string;
		return;
	}

	ostream& operator<< (ostream& os, CString& obj)
	{
		os << num++ << ": ";
		obj.display(os);
		return os;
	}
}
