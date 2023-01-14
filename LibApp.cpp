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
#include<fstream>
#include <iomanip>
#include"Utils.h"
#include"LibApp.h"
#include"Book.h"
#include"PublicationSelector.h"

using namespace std;

namespace sdds
{
	
	bool LibApp::confirm(const char* message) {
		return !strcmp("yes", message);
	}

	void LibApp::load(const char* name) {

		std::cout << "Loading Data" << endl;
		ifstream filein(name);
		char pType{};
		for (int i = 0;filein; i++) {			
			filein >> pType;
			filein.ignore();
			if (filein) {
				if (pType == 'P') {
					all_record[i] = new Publication;
					load_number++;
				}			
				else if (pType == 'B') {
					all_record[i] = new Book;
					load_number++;
				}					
				if (all_record[i]) {
					filein >> *all_record[i];
				}				
			}
		}
		new_number = all_record[load_number-1]->getRef();
	}

	void LibApp::save() {
		cout << "Saving Data" << endl;
		ofstream fileout("LibRecs.txt");
		for (int i = 0; i < load_number; i++) {
			if (all_record[i]->getRef()) {
				fileout << *all_record[i] << endl;
			}			
		}
	}
	int LibApp::search(int typesearch) {
		PublicationSelector temp{};
	    char* tempTitle{};		
		tempTitle = new char[256];
		tempTitle[0] = '\0';
		unsigned int select{};
		int ref_number{};

		cout << "Choose the type of publication:" << endl;
		cout << " 1- Book" << endl;
		cout << " 2- Publication" << endl;
		cout << " 0- Exit" << endl;
		select = userEnterInt(2);
		cin.ignore(100,'\n');
		switch (typesearch)
		{
		case 1:
			if (select == 1) {
				cout << "Publication Title: ";
				cin.getline(tempTitle, 256);
				int j = 0;
				for (int i = 0;i < load_number; i++) {
					if (all_record[i]->type() == 'B' &&
						all_record[i]->getRef() != 0 && 
						*all_record[i] == tempTitle) {
						temp << all_record[i];					
						j++;
					}
				}
				if (j == 0) {
					cout << "No matches found!" << endl;
				}
				else {
					temp.sort();
					ref_number = temp.run();
					if (ref_number == 0) {
						cout << "Aborted!" << endl;
					}
					else {
						cout << *getPub(ref_number) << endl;
					}
				}				
			}
			if (select == 2) {
				cout << "Publication Title: ";
				cin.getline(tempTitle, 256);
				int j = 0;
				for (int i = 0;i < load_number; i++) {
					if (*all_record[i] == tempTitle &&
						all_record[i]->getRef() != 0 &&
						all_record[i]->type() == 'P') {
						temp << all_record[i];
						j++;
					}
				}
				if (j == 0) {
					cout << "No matches found!" << endl;
				}
				else {
					temp.sort();
					ref_number = temp.run();
					if (ref_number == 0) {
						cout << "Aborted!" << endl;
					}
					else {
						cout << *getPub(ref_number) << endl;
					}				
				}
			}
			if (select == 0) {
				cout << "Aborted!" << endl;
			}
				break;
		case 2:
			if (select == 1) {
				cout << "Publication Title: ";
				cin.getline(tempTitle, 256);
				int j = 0;
				for (int i = 0;i < load_number; i++) {
					if (*all_record[i] == tempTitle &&
						all_record[i]->getRef() != 0
						&& all_record[i]->type() == 'B'
						&& all_record[i]->onLoan()) {
						temp << all_record[i];
						j++;
					}
				}
				if (j == 0) {
					cout << "No matches found!" << endl;
				}
				else {
					temp.sort();
					ref_number = temp.run();
					if (ref_number == 0) {
						cout << "Aborted!" << endl;
					}
					else {
						cout << *getPub(ref_number) << endl;
					}
				}
			}
			if (select == 2) {
				cout << "Publication Title: " ;
				cin.getline(tempTitle, 256);
				int j = 0;
				for (int i = 0;i < load_number; i++) {
					if (*all_record[i] == tempTitle &&
						all_record[i]->getRef() != 0 && 
						all_record[i]->type() == 'P'
						&& all_record[i]->onLoan()) {
						temp << all_record[i];
						j++;
					}
				}
				if (j == 0) {
					cout << "No matches found!" << endl;
				}
				else {
					temp.sort();
					ref_number = temp.run();
					if (ref_number == 0) {
						cout << "Aborted!" << endl;
					}
					else {
						cout << *getPub(ref_number) << endl;
					}
				}
			}
			if (select == 0) {
				cout << "Aborted!" << endl;
			}
			 break;
		case 3:
			if (select == 1) {
				cout << "Publication Title: ";
				cin.getline(tempTitle, 256);
				int j = 0;
				for (int i = 0;i < load_number; i++) {
					if (*all_record[i] == tempTitle &&
						all_record[i]->getRef() != 0 && 
						all_record[i]->type() == 'B'
						&& !(all_record[i]->onLoan())) {
						temp<< all_record[i];
						j++;
					}
				}
				if (j == 0) {
					cout << "No matches found!" << endl;
				}
				else {
					temp.sort();
					ref_number = temp.run();
					if (ref_number == 0) {
						cout << "Aborted!" << endl;
					}
					else {
						cout << *getPub(ref_number) << endl;
					}
				}
			}
			if (select == 2) {
				cout << "Publication Title: ";
				cin.getline(tempTitle, 256);
				int j = 0;
				for (int i = 0;i < load_number; i++) {
					if (*all_record[i] == tempTitle &&
						all_record[i]->getRef() != 0 &&
						all_record[i]->type() == 'P'
						&& !(all_record[i]->onLoan())) {
						temp << all_record[i];
						j++;
					}
				}
				if (j == 0) {
					cout << "No matches found!" << endl;
				}
				else {
					temp.sort();
					ref_number = temp.run();
					if (ref_number == 0) {
						cout << "Aborted!" << endl;
					}
					else {
						cout << *getPub(ref_number) << endl;
					}
				}
			}
			if (select == 0) {
				cout << "Aborted!" << endl;
			}
				break;
		}
		delete [] tempTitle;
		return ref_number;
	}

	void LibApp::returnPub() {
		int loan_days{};
		int extr_loan_days{};
		int  ref_number{};
		unsigned int select{};
		double payment{};
		cout << "Return publication to the library" << endl;
		ref_number=search(2);
		if (ref_number != 0) {
			cout << "Return Publication?" << endl;
			cout << " 1- Yes" << endl;
			cout << " 0- Exit" << endl;
			select = userEnterInt(1);
			if (select == 1) {
				Date today;
				loan_days = today - (getPub(ref_number)->checkoutDate());
				if (loan_days > 15) {
					extr_loan_days = loan_days - 15;
					payment = (loan_days - 15) * 0.5;
					cout.setf(ios::fixed);
					cout.precision(2);
					cout << "Please pay $" << payment << " penalty for being " << extr_loan_days << " days late!" << endl;
				}
				getPub(ref_number)->set(0);
				cout << "Publication returned" << endl;
				m_changed = true;
			}
			if (select == 0) {
				cout << "Aborted!" << endl;
			}
		}			
	}
	

	void LibApp::newPublication() {		
		unsigned int select{};
		if (load_number == SDDS_LIBRARY_CAPACITY) {
			cout << "Library is at its maximum capacity!" << endl;
		}
		else {
			cout << "Adding new publication to the library" << endl;
			cout << "Choose the type of publication:" << endl;
			cout << " 1- Book" << endl;
			cout << " 2- Publication" << endl;
			cout << " 0- Exit" << endl;
			select = userEnterInt(2);
			FlushKeys();
			if (select == 1) {			
				Book* temp1{};
				temp1 = new Book;
				cin >> *temp1;
				cin.ignore(100, '\n');
				if (cin.fail()) {
					cin.ignore(100, '\n');
					cin.clear();
					cout << "Aborted!" << endl;
					delete temp1;
				}
				if (!cin.fail()) {
					cout << "Add this publication to the library?" << endl;
					cout << " 1- Yes" << endl;
					cout << " 0- Exit" << endl;
					select = userEnterInt(1);
					FlushKeys();
					if (select == 1) {						
						if (temp1->operator bool()) {						
							new_number++;
							temp1->setRef(new_number);
							all_record[load_number] = temp1;
							load_number++;
							cout << "Publication added" << endl;
							m_changed = true;
						}
						else {
							cout << "Failed to add publication!" << endl;
							delete temp1;
						}						
					}
					else{
						cout << "Aborted!" << endl;
						delete temp1;
					}
				}
			}else if (select == 2) {
				Publication* temp2{};
				temp2 = new Publication;
				cin >> *temp2;
				cin.ignore(100, '\n');
				if (cin.fail()) {
					cin.ignore(1000, '\n');
					cin.clear();
					cout << "Aborted!" << endl;
					delete temp2;
				}
				if (!cin.fail()) {
					cout << "Add this publication to the library?"<<endl;
					cout << " 1- Yes" << endl;
					cout << " 0- Exit" << endl;	
					select = userEnterInt(1);
					FlushKeys();
					if (select == 1) {
						if (temp2->operator bool()) {
							new_number++;
							temp2->setRef(new_number);
							all_record[load_number] = temp2;
							load_number++;
							cout << "Publication added" << endl;
							m_changed = true;
						}
						else {
							cout << "Failed to add publication!" << endl;
							delete temp2;
						}
					}
					else {
						cout << "Aborted!" << endl;
						delete temp2;
					}
				}
			}else {
				cout << "Aborted!" << endl;
			}
		}					
	}
	void LibApp::removePublication() {
		int ref_number{};
		unsigned int select{};
		cout << "Removing publication from the library" << endl;
		ref_number = search(1);
		if (ref_number != 0) {
			cout << "Remove this publication from the library?" << endl;
			cout << " 1- Yes" << endl;
			cout << " 0- Exit" << endl;
			select = userEnterInt(1);
			FlushKeys();
			if (select == 1) {
				getPub(ref_number)->setRef(0);
				m_changed = true;
				cout << "Publication removed" << endl;
			}
		}
		
	}
	void LibApp::checkOutPub() {
		int ref_number{};
		unsigned int select{};
		int mem_ship{};
		cout << "Checkout publication from the library" << endl;
		ref_number = search(3);
		if (ref_number != 0) {
			cout << "Check out publication?" << endl;
			cout << " 1- Yes" << endl;
			cout << " 0- Exit" << endl;
			select = userEnterInt(1);
			if (select == 1) {
				cout << "Enter Membership number: ";
				do {
					cin >> mem_ship;
					if (mem_ship < 9999 || mem_ship >100000) {
						cout << "Invalid membership number, try again: ";
					}
				} while (mem_ship < 9999 || mem_ship >100000);
				getPub(ref_number)->set(mem_ship);
				m_changed = true;
				cout << "Publication checked out" << endl;
			}
			if (select == 0) {
				cout << "Aborted!" << endl;
			}
		}		
	}
	LibApp::LibApp(const char* name) {
		load(name);
		set();
	}
	void LibApp::set() {
		m_typepub_Menu.setMenuTitle("Choose the type of publication:");
		m_typepub_Menu << "Book" << "Publication";
		m_mainMenu.setMenuTitle("Seneca Library Application");
		m_mainMenu << "Add New Publication"  
			<< "Remove Publication" 
			<<"Checkout publication from library" 
			<< "Return publication to library";
		m_exitMenu.setMenuTitle("Changes have been made to the data, what would you like to do?");
		m_exitMenu << "Save changes and exit"
			<< "Cancel and go back to the main menu";
	}
	void LibApp::run() {

		unsigned int i=0;
		unsigned int k=0;

		do {
			i = m_mainMenu.run();
			if (i == 1) {
				newPublication();
			}
			else if (i == 2) {
				removePublication();
			}
			else if (i == 3) {
				checkOutPub();
			}
			else if (i == 4) {
				returnPub();
			}
			else if (i == 0) {
				if (m_changed) {					
					k = m_exitMenu.run();
					if (k == 1) {
						save();
						m_changed = false;
						k = 0;
					}
					else if (k == 2) {
					}
					else if (k == 0) {
						cout << "This will discard all the changes are you sure?" << endl;
						cout << " 1- Yes" << endl;
						cout << " 0- Exit" << endl;
						if (confirm(userEnter())) {
							m_changed = false;
						}
					}
				}

			}
			cout << endl;
		} while (!(i ==0 && m_changed == false && k ==0));		
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}

	LibApp::~LibApp() {
		for (int i = 0; i < load_number; i++) {
			delete all_record[i];
		}
	}
	Publication* LibApp::getPub(int libRef) {
		Publication* temp{};
		for (int i = 0; i < load_number; i++) {
			if (all_record[i]->getRef() == libRef) {
				temp = all_record[i];
			}			
		}
		return temp;
	}
}