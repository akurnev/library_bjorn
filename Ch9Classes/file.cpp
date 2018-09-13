#include "stdafx.h"
#include "file.h"
#include <iostream>
#include <string>

using namespace std;

string File::GetFileName()
{
	return FileName;
}

int File::OpenFile(const string pathToFile)
{
	if (pathToFile != "")
	{
		File_Descriptor = 111;
		FileName = pathToFile;

		cout << "OpenFile: " << pathToFile << endl;

		return File_Descriptor;
	}
	else
	{
		cout << "Path To File is not specified" << endl;
		return -1;
	}
}

//
//
//
ostream& operator<<(ostream &os, File f)
{
	return os << f.GetFileName();
}
