#ifndef _TN_PAIR_HEADER__
#define _TN_PAIR_HEADER__

template <typename A, typename B>
class Pair 
{
	A valueA;
	B valueB;
public:
	Pair() : valueA(), valueB() {};
	Pair(const A& A, const B& B) : valueA(A), valueB(B) {};
	const A& getKey() const { return valueA;  };
	const B& getValue() const { return valueB; };

};



#endif