#include <cstring>
#include "process.h"
#include "CString.h"

using namespace w1;

ostream& process(char * str, ostream& os)
{
	CString obj(str);
	os << obj;
	os << endl;

	return os;
}