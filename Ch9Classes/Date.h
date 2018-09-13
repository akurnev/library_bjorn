#pragma once


/*class Date
{
};
*/

bool leapy_year(int year);

struct Date
{
	Date() : y(2000), m(jan), d(1) {
		days_in_month[0] = 0;
		days_in_month[jan] = 31;
		days_in_month[feb] = (leapy_year(2000)) ? 29 : 28;
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
	};
	enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
	Date(int day, Month month, int year);
	void add_day(int n);
	//
	int d;
	Month m;
	int y;

	int days_in_month[13];
};

void add_days(Date& date, int number_of_days);
bool check_date(int day, Date::Month m, int year);

