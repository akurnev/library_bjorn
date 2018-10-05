#include "stdafx.h"
#include "Date.h"
#include "library.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<Book>Library::books;
vector<Patron>Library::patrons;


/*Book::Book(ISBN isbn, string book_name, string author, Date date, bool issued)
{

}
*/

struct ISBN Book::Get_Isbn() const
{
	return isbn;
}
string Book::Get_Book_Name() const
{
	return book_name;
}
string Book::Get_Author() const
{
	return author;
}
Date Book::Get_Date_of_Reg() const
{
	return date_of_reg;
}
bool Book::Is_Issued() const
{
	return issued;
}
bool operator==(const ISBN &a, const ISBN &b)
{
	return (a.n1 == b.n1) && (a.n2 == b.n2) && (a.n3 == b.n3) && (a.x == b.x);
}
bool operator!=(const ISBN &a, const ISBN &b)
{
	return !((a.n1 == b.n1) && (a.n2 == b.n2) && (a.n3 == b.n3));
}
ostream& operator<<(ostream& os, const Book book)
{
	os << book.Get_Book_Name() << endl;
	os << book.Get_Author() << endl;
	os << book.Get_Isbn().n1 
		<< "-" << book.Get_Isbn().n2 
		<< "-" << book.Get_Isbn().n3 
		<< "-" << book.Get_Isbn().x << endl;

	return os;
}

void Library::Add_Book(Book book)
{
	books.push_back(book);
}

void Library::Add_Patron(Patron patron)
{
	patrons.push_back(patron);
}

bool operator==(const Patron &a, const Patron &b)
{
	return	a.Get_Library_Card_Number() == b.Get_Library_Card_Number() &&
			a.Get_User_Name() == b.Get_User_Name() &&
			a.Get_Membership_Fee() == b.Get_Membership_Fee();
}

Library::Transaction::Transaction(Book tbook, Patron tpatron, Date tdate)
{
	bool patron_found = false;
	bool book_found = false;

	for (int i = 0; i < patrons.size(); ++i)
	{
		if (tpatron == patrons[i])
		{
			patron_found = true;
			break;
		}
	}

	if (patron_found == false)
	{
		throw runtime_error("[transaction]: patron is not found in library");
	}

	if (tpatron.Is_Membership_Fee_Paid() == false)
	{
		cout << "[transaction]: patron has membership fee debt!" << endl;
	}

	for (int i = 0; i < books.size(); ++i)
	{
		if (tbook.Get_Isbn() == books[i].Get_Isbn())
		{
			book_found = true;
			break;

		}
	}

	if (book_found == false)
	{
		throw runtime_error("[transaction]: book is not found in library");
	}

	tbook.Set_Issued();
	book = tbook;
	patron = tpatron;
	date = tdate;
}

vector<Patron> Library::Get_Patrons_With_Debt_In_Membership_Fee()
{
	vector<Patron> Patrons_With_Debt(0);

	for (int i = 0; i < patrons.size(); ++i)
	{
		if (patrons[i].Is_Membership_Fee_Paid() == false)
		{
			Patrons_With_Debt.push_back(patrons[i]);
		}
	}
	
	return Patrons_With_Debt;
}

