#pragma once

#include <string>
#include <vector>
#include "Date.h"

using namespace std;

struct ISBN
{
	ISBN() {};
	ISBN(int a, int b, int c, char x) :
		n1(a), n2(b), n3(c), x(x) {};
	
	int n1;
	int n2;
	int n3;
	char x;
};

class Book
{
public:
	enum Genre { fantasy = 0, prose, periodicals, biography, kids_literature, programming };
	Book() {};
	Book(ISBN isbn, string book_name, string author, Date date_of_reg, Genre genre, bool issued) :
		isbn(isbn), book_name(book_name), author(author), date_of_reg(date_of_reg), genre(genre), issued(issued) {};

	struct ISBN Get_Isbn() const;
	string Get_Book_Name() const;
	string Get_Author() const;
	Date Get_Date_of_Reg() const;
	bool Is_Issued() const;
	void Set_Issued() { issued = true; }

private:
	ISBN isbn;
	string book_name;
	string author;
	Date date_of_reg;
	bool issued;
	Genre genre;
};

class Patron
{
public:
	Patron() {};
	Patron(string user_name, int library_card_number, double membership_fee) :
		user_name(user_name), library_card_number(library_card_number), membership_fee(membership_fee) {};
	bool Is_Membership_Fee_Paid() { return (membership_fee > 0) ? true : false; }
	void Set_User_Name(string user_name) { user_name = user_name; }
	string Get_User_Name() const { return user_name; }
	void Set_Library_Card_Number(int library_card_number) { library_card_number = library_card_number; }
	int Get_Library_Card_Number() const { return library_card_number; }
	void Set_Membership_Fee(double membership_fee) { membership_fee = membership_fee; }
	double Get_Membership_Fee() const { return membership_fee; }

private:
	string user_name;
	int library_card_number;
	double membership_fee;
};

class Library
{
public:
	struct Transaction
	{
		Transaction(Book book, Patron patron, Date date);
		Book book;
		Patron patron;
		Date date;
	};

	void Add_Book(Book book);
	void Add_Patron(Patron patron);
	vector<Transaction> transactions;

	//What the fuck!!


private:
	static vector<Book> books;
	static vector<Patron> patrons;
};

bool operator==(const ISBN &a, const ISBN &b);
bool operator!=(const ISBN &a, const ISBN &b);
ostream& operator<<(ostream& os, const Book book);

bool operator==(const Patron &a, const Patron &b);
