
#include "stdafx.h"
#include "name_pairs.h"

#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <limits>  
#include <vector>


#include <stdlib.h>  
#include <stdio.h>  
#include <time.h>
#include <assert.h>

using namespace std;


//class my_exceptions {};

////////////////////////////////////////////////////////

unsigned int min_val(vector<double> converted_double_numbers);
using namespace std;

Name_pairs::Name_pairs(string name, double age)
{
	if (age < 0 || 100 < age)
	{
		throw runtime_error("[read_ages]: incorrect age provided");
	}

	names.push_back(name);
	ages.push_back(age);
}


void Name_pairs::read_names()
{
	string name;

	while (cin >> name)
	{
		if (name == "q" || name == "Q" || name == "quit" || name == "Quit")
		{
			break;
		}
		names.push_back(name);
	}
}

void Name_pairs::read_ages()
{
	int i = 0;
	double age = 0.;

	for (i; i < names.size(); ++i)
	{
		if (i >= ages.size())
		{
			cout << "Enter " << names[i] << "'s " << "age: ";

			cin >> age;
			if (age < 0 || 100 < age)
			{
				throw runtime_error("[read_ages]: incorrect age provided");
			}
			ages.push_back(age);
		}
	}
}

void Name_pairs::print()
{
	int i = 0;

	cout << "===============" << endl;

	for (i; i < ages.size(); ++i)
	{
		cout << names[i] << " : " << ages[i] << endl;
	}

	if (names.size() > ages.size())
	{
		cout << "[print]: Ages not specified for below names" << endl;
			
		for (i; i < names.size(); ++i)
		{
			cout << names[i] << endl;
		}
	}
}

void Name_pairs::sort()
{
	string tmp_name;
	double tmp_age = 0.;
	int i = 0;
	int j = 0;

	if (names.size() > ages.size())
	{
		throw runtime_error("[sort]: Ages not specified for some names");
	}

	for (j = 0; j < names.size(); j++) 
	{
		for (i = 0; i < names.size(); ++i)
		{
			if (i != 0 && names[i] < names[i - 1])
			{
				tmp_name = names[i];
				tmp_age = ages[i];
				names[i] = names[i - 1];
				ages[i] = ages[i - 1];
				names[i - 1] = tmp_name;
				ages[i - 1] = tmp_age;
			}
		}
	}
}

ostream& operator<<(ostream &os, Name_pairs name_pairs)
{
	int i = 0;

	os << "===============" << endl;

	for (i; i < name_pairs.Get_Ages().size(); ++i)
	{
		os << name_pairs.Get_Names()[i] << " : " << name_pairs.Get_Ages()[i] << endl;
	}

	if (name_pairs.Get_Names().size() > name_pairs.Get_Ages().size())
	{
		os << "[print]: Ages not specified for below names" << endl;

		for (i; i < name_pairs.Get_Names().size(); ++i)
		{
			os << name_pairs.Get_Names()[i] << endl;
		}
	}

	return os;
}

vector<string> Name_pairs::Get_Names() const
{
	return names;
}
vector<double> Name_pairs::Get_Ages() const
{
	return ages;
}

bool operator==(const Name_pairs &a, const Name_pairs &b)
{
	return a.Get_Names() == b.Get_Names() && a.Get_Ages() == b.Get_Ages();

}

bool operator!=(const Name_pairs &a, const Name_pairs &b)
{
	return !(a == b);
}
