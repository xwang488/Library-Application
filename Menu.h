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

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include<iostream>
#include<string>

namespace sdds
{
	const unsigned int MAX_MENU_ITEMS = 20;
	class Menu;

	class MenuItem
	{
		char* menu_name;
		MenuItem();
		MenuItem(const char*);
		void setEmpty();
		void set(const char*);
		~MenuItem();
		void deallocate();
		MenuItem(const MenuItem&) = delete;
		MenuItem& operator=(const MenuItem&) = delete;
		operator bool()const;
		operator const char* ();
		std::ostream& display(std::ostream& os)const;
	public:
		friend class sdds::Menu;
	};

	class Menu
	{
		unsigned int num_point;
		MenuItem title;
		MenuItem* menu_point[MAX_MENU_ITEMS] = { nullptr };
	public:
		Menu();
		Menu(const char*);
		void SetEmpty();
		void setMenuTitle(const char*);
		~Menu();
		void deallocate_menu();
		Menu(const Menu&) = delete;
		Menu& operator=(const Menu&) = delete;
		std::ostream& displayTitle(std::ostream& os)const;
		std::ostream& displayMenu(std::ostream& os)const;
		unsigned int run();
		unsigned int get_Num_point();
		unsigned int operator~();
		Menu& operator<<(const char* menuitemConent);
		operator int();
		operator unsigned int();
		operator bool();
		const char* operator[](int index)const;
	};
	std::ostream& operator<<(std::ostream& os, const Menu& menu_title);
}

#endif