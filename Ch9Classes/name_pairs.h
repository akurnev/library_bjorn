#pragma once

#include <string>
#include <vector>

using namespace std;

class Name_pairs
{
public:
	Name_pairs() {};
	Name_pairs(string name, double age);
	void read_names();
	void read_ages();
	void print();
	void sort();
	vector<string> Get_Names() const;
	vector<double> Get_Ages() const;
	
private:
	vector<string> names;
	vector <double> ages;
};

ostream& operator<<(ostream &os, Name_pairs name_pairs);
bool operator==(const Name_pairs &a, const Name_pairs &b);
bool operator!=(const Name_pairs &a, const Name_pairs &b);
