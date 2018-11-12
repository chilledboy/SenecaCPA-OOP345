#ifndef _TN_LETTER_HEADER__
#define _TN_LETTER_HEADER__

namespace sict
{
	enum Letter{A_plus = 100, A = 89, B_plus = 79, B = 74, C_plus = 69, C = 64, D_plus = 59, D = 54, F = 49};

	std::string enumToLtr(Letter enumConst) 
	{
		std::string strGrd;

		if (enumConst == A_plus)
		{
			strGrd = "A+";
		}
		else if (enumConst == A)
		{
			strGrd = 'A';
		}
		else if (enumConst == B_plus)
		{
			strGrd = "B+";
		}
		else if (enumConst == B)
		{
			strGrd = 'B';
		}
		else if (enumConst == C_plus)
		{
			strGrd = "C+";
		}
		else if (enumConst == C)
		{
			strGrd = 'C';
		}
		else if (enumConst == D_plus)
		{
			strGrd = "D+";
		}
		else if (enumConst == D)
		{
			strGrd = 'D';
		}
		else
		{
			strGrd = 'F';
		}

		return strGrd; 
	};

}




#endif