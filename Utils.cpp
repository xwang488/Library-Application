/***********************************************************************
// OOP244 Utils Module:
// File  utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "Utils.h"

using namespace std;
namespace sdds
{
	char single[5];
	void FlushKeys() {
		while (cin.get() != '\n');
	}
	char* userEnter() {
		int i;
		do {
			cin.clear();
			cout << "> ";
			cin >> i;
			if (cin.fail()) {
				cout << "Please enter number";
				FlushKeys();
			}
		} while (cin.fail());

		if (i == 1) {
			strcpy(single, "yes");
		}
		else {
			strcpy(single, "no");
		}
		return  single;
	}

	unsigned int userEnterInt(unsigned int number) {
		unsigned int i;		
		do {
			cout << "> ";
			cin >> i;
			if (cin.fail()) {
				cout << "Please enter number(0-"<< number<< ")";
				FlushKeys();
				cin.clear();
			}
		} while (cin.fail());

		return i;
	}

}