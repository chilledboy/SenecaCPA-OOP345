// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// w1.cpp
//Author:  Dr. Elliott Coleshill
//Date:    2018-08-22

#include <iostream>
#include <fstream>
#include "process.h"


int main(int argc, char* argv[]) {

	extern int CHARNUM;

	//std::ofstream std::cout("Lab1Output.txt");

	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
    if (argc < 2) {
        std::cout << "\nInsufficient number of arguments\n";
        return 1;
	}

	/****
	TO DO:  Add code here that will print out the max characters stored
	              by your CString object
	*****/

	std::cout << std::endl << "Maximum number of characters stored: " << CHARNUM << endl;

	for (int i = 1; i < argc; i++) {
		process(argv[i], std::cout);
	}

	int WaitKey;
	std::cin >>  WaitKey;

	//ofs.close();
	return 0;
}
