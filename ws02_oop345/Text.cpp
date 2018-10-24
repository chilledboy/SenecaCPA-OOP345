// Name:  Tracy Nguyen
// Student ID: 127270171
// Email:  tnguyen157@myseneca.ca
// Date of completion: Oct 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#include <iostream>
#include <fstream>
#include <iomanip>
#include <utility>
#include "Text.h"

using namespace std;

namespace w2
{
	// Empty state
	Text::Text()
	{
		fileTxt = nullptr;
	}

	Text::Text(const string& str)
	{
		if (!str.empty())
		{
			fileName = str;

			ifstream ifs(str);
			for (; !ifs.eof(); numLines++)
			{
				ifs.ignore('\n');
			}

			if (numLines > 0)
			{
				ifs.seekg(0);

				fileTxt = new string[numLines];
				for (int i = 0; i < numLines; i++)
				{
					 getline(ifs, fileTxt[i]);
				}
			}

			ifs.close();
		}
	}

	// Copy constructor
	Text::Text(Text& obj)
	{
		*this = obj;
	}

	// Move constructor
	Text::Text(Text&& objP)
	{
		*this = move(objP);
	}

	// Copy assignment
	Text& Text::operator=(const Text& obj)
	{
		if (this != &obj)
		{
			if (!isEmpty() && !obj.isEmpty())
			{
				fileName = obj.fileName;

				delete[] fileTxt;
				fileTxt = new string[obj.numLines];
				for (int i = 0; i < obj.numLines; i++)
				{
					fileTxt[i] = obj.fileTxt[i];
				}


				numLines = obj.numLines;
			}
		}

		return *this;
	}


	// Move assignment
	Text& Text::operator=(Text&& objP)
	{
		if (this != &objP)
		{
			if (!isEmpty() && !objP.isEmpty())
			{
				fileName = objP.fileName;
				fileName.assign(objP.fileName);

				delete[] fileTxt;
				fileTxt = objP.fileTxt;

				delete[] objP.fileTxt;
				objP.fileTxt = nullptr;

				numLines = objP.numLines;
			}
		}

		return *this;
	}

	Text::~Text()
	{
		delete[] fileTxt;
	}

	size_t Text::size() const
	{
		return numLines;
	}

	bool Text::isEmpty() const
	{
		bool empty = false;

		if (fileTxt == nullptr)
		{
			empty = true;
		}

		return empty;
	}
}

//#include <iostream>
//#include <fstream>
//#include <cstring>
//#include "Text.h"
//
//using namespace w2;
//using namespace std;
//
//Text::Text()
//	{
//		fileName = nullptr;
//		fileTxt = nullptr;
//		numLines = 0;
//	}
//
//// default & 1-arg constructor
//Text::Text(const string& file) {
//	if (!file.empty()) { // check empty string
//		ifstream fin(file); // open file
//		if (fin.good()) { // does file exist?
//			// copy fileName of file
//			fileName.assign(file);
//			// check number of fileTxt in file
//			size_t ln_cnt = 0;
//			while (!fin.eof()) {
//				std::string line;
//				getline(fin, line);
//				++ln_cnt;
//			}
//
//			// allocate new array based on ln_cnt
//			fileTxt = new std::string[ln_cnt];
//
//			fin.close();
//
//			// copy fileTxt into array
//			fin.open(file);
//			for (size_t i = 0; i < ln_cnt; i++) {
//				getline(fin, fileTxt[i]);
//			}
//			numLines = ln_cnt;
//			fin.close();
//		}
//	}
//}
//
//// destructor
//Text::~Text() {
//	delete[] fileTxt;
//}
//
////copy constructor
//Text::Text(Text& other) {
//	*this = other;
//}
//
////copy assignment
//Text& Text::operator=(Text& other) {
//	if (this != &other) {
//		// shallow copy
//		numLines = other.numLines;
//		fileName.assign(other.fileName);
//
//		// deep copy
//		delete[] fileTxt;
//		fileTxt = new std::string[numLines];
//		for (size_t i = 0; i < numLines; i++) {
//			fileTxt[i] = other.fileTxt[i];
//		}
//	}
//
//	return *this;
//}
//
////move constructor
//Text::Text(Text&& other) {
//	*this = std::move(other);
//}
////move assignment
//Text& Text::operator=(Text&& other) {
//	if (this != &other) {
//		// shallow copy
//		numLines = other.numLines;
//		fileName.assign(other.fileName);
//		// transfer ownership of addresses
//		delete[] fileTxt; // delete the original
//		fileTxt = other.fileTxt;
//		other.fileTxt = nullptr;
//	}
//
//	return *this;
//}
//
//size_t Text::size() const {
//	return numLines;
//}