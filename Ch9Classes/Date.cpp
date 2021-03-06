// Date.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


//#include "pch.h"
#include "stdafx.h"

#include <iostream>
#include <assert.h>
#include <stdio.h>
#include "Date.h"

using namespace std;

ostream& operator<<(ostream& os, Date date)
{
	return os << date.y << ":" << date.m << ":" << date.d;
}

Date::Month operator++(Date::Month& m)
{
	m = (m == Date::Month::dec) ? Date::Month::jan : Date::Month(m + 1);
	return m;
}

Date::Month operator++(Date::Month& m, int)
{
	Date::Month tmp_m;
	tmp_m = m;
	m = (m == Date::Month::dec) ? Date::Month::jan : Date::Month(m + 1);
	return tmp_m;
}

bool leapy_year(int year)
{
	const int leap_number = 4;
	double res = 0.;
	

	res = year % leap_number;

	if (res)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Date::add_day(int n)
{
	int s;
	s = d + n;

	if (s > days_in_month[m])
	{
		int r = days_in_month[m] - d;
		s = n - r;

		int counter = 0;
		do
		{
			if (counter > 0)
			{
				s -= r;
			}
			m++;
			if (m == Date::jan)
			{
				y++;
			}
			r = days_in_month[m];
			counter++;

		} while (s > days_in_month[m]);

		d = s;
	}
	else
	{
		d += n;
	}		
}

bool check_date(int day, Date::Month m, int year)
{
	if (day <= 0 || day > 31 || day < 0)
	{
		cout << "Incorrect date: " << day << endl;
		return false;
	}

	switch (m)
	{
	case Date::Month::apr:
	case Date::Month::jun:
	case Date::Month::sep:
	case Date::Month::nov:
	{
		if (day == 31)
		{
			cout << "Incorrect date: " << day << endl;
			return false;
		}
		break;
	}
	case Date::Month::feb:
	{
		// leapy year - 29 days, if not - 28 days in feb
		if (!leapy_year(year) && day > 28)
		{ 
			cout << "Incorrect date: " << day << endl;
			return false;
		}
		break;
	}
		
	}

	return true;
}

Date::Date(int day, Date::Month month, int year)
{	
	if (check_date(day, month, year))
	{
		d = day;
		m = month;
		y = year;
	}
	else
	{
		throw(runtime_error("provided date is incorrect"));
	}

	days_in_month[0] = 0;
	days_in_month[jan] = 31;
	days_in_month[feb] = (leapy_year(year)) ? 29 : 28;
	days_in_month[mar] = 31;
	days_in_month[apr] = 30;
	days_in_month[may] = 31;
	days_in_month[jun] = 30;
	days_in_month[jul] = 31;
	days_in_month[aug] = 31;
	days_in_month[sep] = 30;
	days_in_month[oct] = 31;
	days_in_month[nov] = 30;
	days_in_month[dec] = 31;

}
/*
int main()
try {
	struct Date test_date(31, Date::aug, 2018);
	cout << test_date << endl;
	test_date.add_day(1);
	
	struct Date tomorrow = test_date;
	cout << tomorrow;

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
*/