#ifndef _TN_LIST_HEADER__
#define _TN_LIST_HEADER__


template <typename T, int N = 1>
class List
{
	T listArr[N];
	int entryNum;

	T obj;

public:
	List() : listArr{}, entryNum{ 0 } { };
	size_t size() const { return entryNum; };
	const T& operator[] (int index) const {  return index < N ? listArr[index] : obj; };
	void operator +=(const T& paramT) { if (entryNum < N) listArr[entryNum] = paramT; entryNum++; };

};


#endif