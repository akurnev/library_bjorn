// Ch9Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "file.h"
#include "name_pairs.h"
#include "library.h"
#include "Date.h"

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
try {
	Library my_library;
	
	Book cpp_book(ISBN(1, 2, 3, 'b'), "C++ Book", "Straustroup", Date(28, Date::feb, 2011), Book::programming, false);
	Book the_bip_car(ISBN(1, 2, 3, 'a'), "The Bip Car", "Tamara Krykova", Date(31, Date::dec, 2012), Book::kids_literature, false);

	cout << cpp_book;
	cout << the_bip_car;
	
	Patron("Anton Kurnev", 1, 0.);

	my_library.Add_Book(cpp_book);
	my_library.Add_Book(the_bip_car);
	my_library.Add_Patron(Patron("Anton Kurnev", 1, 0.));
	my_library.Add_Patron(Patron("Igor Linnik", 2, 1000.));
	//...
	my_library.transactions.push_back(Library::Transaction(cpp_book, Patron("Anton Kurnev", 1, 0.), Date(10, Date::sep, 2018)));




	return 0;
}
catch (exception &e)
{
	cout << e.what() << endl;
	return 1;
}
catch (...)
{
	cout << "Something else" << endl;
	return 2;
}



/*
try {
	File myFile1;
	File myFile2;
	string firstPathToFile =  "C:\\Windows\\system.dll";

	myFile1.OpenFile(firstPathToFile);

	cout << myFile1 << endl;
	return 0;
	}
*/

/*try {
	Name_pairs name_pairs("Ekaterina", 29.2);

	name_pairs.read_names();
	name_pairs.read_ages();
	cout << name_pairs;
	name_pairs.sort();
	cout << name_pairs;

	Name_pairs name_pairs_2 = name_pairs;

	if (name_pairs == name_pairs_2)
	{
		cout << "Name_pairs are equal" << endl;
	}


	return 0;
}*/