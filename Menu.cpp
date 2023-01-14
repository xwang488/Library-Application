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
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Utils.h"
#include"Menu.h"

using namespace std;

namespace sdds
{
	MenuItem::MenuItem() {
		setEmpty();
	}
	MenuItem::MenuItem(const char* name) {
		set(name);
	}
	void MenuItem::setEmpty() {
		menu_name = nullptr;
	}
	void MenuItem::set(const char* name) {
		setEmpty();
		menu_name = new char[strlen(name) + 1];
		strcpy(menu_name, name);
	}
	MenuItem::~MenuItem() {
		deallocate();
	}
	void MenuItem::deallocate() {
		delete[] menu_name;
		menu_name = nullptr;
	}
	MenuItem::operator bool()const {
		return menu_name && menu_name[0];
	}
	MenuItem::operator const char* () {
		return menu_name;
	}

	ostream& MenuItem::display(ostream& os)const {
		if (*this) {
			os << menu_name;
		}
		return os;
	}

	Menu::Menu() {
		SetEmpty();
	}
	Menu::Menu(const char* name) {
		title.set(name);
		SetEmpty();
	}
	void Menu::SetEmpty() {
		num_point = 0;
	}
	void  Menu::setMenuTitle(const char* name) {
		title.set(name);
		SetEmpty();
	}
	Menu::~Menu() {
		deallocate_menu();
	}
	void Menu::deallocate_menu() {
		for (unsigned int i = 0; i < num_point;i++) {
			delete menu_point[i];
			menu_point[i] = nullptr;
		}
	}


	ostream& Menu::displayTitle(ostream& os)const {
		title.display(os);
		return os;
	}


	ostream& Menu::displayMenu(ostream& os)const {
		if (title) {
			displayTitle(os) << endl;
		}
		for (unsigned int i = 0; i < num_point;i++) {
			os << " " << i + 1 << "- " << menu_point[i]->menu_name << endl;
		}
		os << " 0- Exit" << endl;
		os << "> ";
		return os;
	}

	unsigned int Menu::run() {
		unsigned int selection = 0;
		displayMenu(cout);
		cin >> selection;
		while (cin.fail() || selection < 0 || selection > num_point) {
			cout << "Invalid Selection, try again: ";
			if (cin.fail()) {
				cin.clear();
			}
			FlushKeys();
			cin >> selection;
			if (selection == 0 && cin) {
				FlushKeys();
			}
		}
		return selection;
	}
	unsigned int Menu::get_Num_point() {
		return  num_point;
	}
	unsigned int Menu::operator~() {
		return run();
	}

	Menu& Menu::operator << (const char* menuitemConent) {
		if (num_point < MAX_MENU_ITEMS) {
			char* temp;
			temp = new char[strlen(menuitemConent) + 1];
			strcpy(temp, menuitemConent);
			menu_point[num_point] = new MenuItem;
			menu_point[num_point]->menu_name = temp;
			num_point++;
		}
		return *this;
	}

	Menu::operator int() {
		return num_point;
	}
	Menu::operator unsigned int() {
		return  (unsigned int)num_point;
	}
	Menu::operator bool() {
		return num_point > 0;
	}
	const char* Menu::operator[](int index)const {
		return menu_point[index % num_point]->menu_name;
	}

	ostream& operator<<(ostream& os, const Menu& menu_title) {
		menu_title.displayTitle(os);
		return os;
	}
}