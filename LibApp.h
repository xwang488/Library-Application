/*
			Ms-5
Full Name  :Jennifer Wang
Student ID#: 169554219
Email      : xwang488@myseneca.ca
Section    : NII
Date       :2022/8/05
Version 1.0
I have done all the coding by myself and only
copied the code that my professor provided to
complete my workshops and assignments.
*/
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include<iostream>
#include<string>
#include"Menu.h"
#include"Publication.h"
#include"Lib.h"
namespace sdds
{
	//class MenuItem;
	//class Menu;
	class LibApp
	{
		char file_name[257]{};
		Publication* all_record[SDDS_LIBRARY_CAPACITY]{};
		int load_number{};
		int new_number{};
		bool m_changed = false;
		Menu m_typepub_Menu;
		Menu m_mainMenu;
		Menu m_exitMenu;
		bool confirm(const char* message);
		void load(const char* name);  // prints: "Loading Data"<NEWLINE>
		void save();  // prints: "Saving Data"<NEWLINE>
		int search(int typesearch);  // prints: "Searching for publication"<NEWLINE>

		void returnPub();  /*  Calls the search() method.
							   prints "Returning publication"<NEWLINE>
							   prints "Publication returned"<NEWLINE>
							   sets m_changed to true;
						   */
		void newPublication();
		void removePublication();
		void checkOutPub();
	public:
		LibApp(const char*);
		void set();
		void run();
		~LibApp();
		Publication* getPub(int libRef);
		
	};

}
#endif