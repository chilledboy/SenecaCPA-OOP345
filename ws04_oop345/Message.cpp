// Name:  Tracy Nguyen
// Student ID: 127270171
// Email:  tnguyen157@myseneca.ca
// Date of completion: Oct 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#include <iostream>
#include <string>
#include "Message.h"

namespace w5
{
	Message::Message() : user{}, replyTo{}, tweet{} {}

	Message::Message(std::ifstream& in, char c)
	{
		// at() returns char at given pos
		// find() returns pos of first matched char, 2nd param is starting pos
		// substr() returns str starting AND including at given pos (counts like array), 2nd param is # of chars


		// jim @fred what?
		// 0123456789123456

		std::string line;
		std::getline(in, line, c);

		user = line.substr(0, line.find(' ') + 1);

		if (user.length())
		{

		char at;
		at = line.at(line.find(user) + user.length());


			if (at == '@')
			{
				size_t secondSpace = line.find(' ');

				// Find position of second space and subtract user's name length and 3 chars (2 spaces and '@' sign), will return length of reply name
				replyTo = line.substr(line.find(at) + 1, line.find(' ', secondSpace + 1) - (user.length() + 1));
				tweet = line.substr(line.find(replyTo) + replyTo.length() + 1, line.find(c));
			}

			else
			{
				tweet = line.substr(line.find(at), line.find(c));
			}
		}

		else
		{
			user = "";
		}
		
	}

	bool Message::empty() const
	{
		bool empty = false;

		if (tweet.empty())
		{
			empty = true;
		}

		return empty;
	}

	void Message::display(std::ostream& os) const
	{
		if (!empty())
		{
			os << "Message" << std::endl
				<< "User : " << user << std::endl;
			std::cout << user << std::endl;
			if (replyTo.length() != 0)
			{
				os << "Reply : " << replyTo << std::endl;
			}

			os << "Tweet : " << tweet << std::endl << std::endl;
		}

		return;
	}

	Message& Message::operator=(const Message& objParam)
	{
		if (this != &objParam)
		{
			user = objParam.user;
			replyTo = objParam.replyTo;
			tweet = objParam.tweet;
		}

		return *this;
	}
}