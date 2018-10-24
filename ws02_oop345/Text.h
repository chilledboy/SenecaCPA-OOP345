// Name:  Tracy Nguyen
// Student ID: 127270171
// Email:  tnguyen157@myseneca.ca
// Date of completion: Oct 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#ifndef _TEXT_HEADER_TN__
#define _TEXT_HEADER_TN__

#include <string>

using namespace std;

namespace w2 {
	class Text {
		
		std::string fileName;
		std::string* fileTxt;
		int numLines = 0;

	public:
		Text();
		Text(const string& str);
		Text(Text& obj);
		Text(Text&& objP);

		Text& operator=(const Text& obj);		
		Text& operator=(Text&& objP);

		bool isEmpty() const;
		

		~Text();
		size_t size() const;
	};
}

#endif _TEXT_HEADER_TN__
