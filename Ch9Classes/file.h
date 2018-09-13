#pragma once

#include <stdio.h>
#include <string>

using namespace std;

class File
{
public:
	File() : FileName("DefaultFileName") { File_Descriptor = 111; }
	File(const string pathToFile) : FileName(pathToFile) { File_Descriptor = 111; }
	int OpenFile(const string pathToFile);
	string GetFileName();

private:
	int File_Descriptor;
	string FileName;
};

ostream& operator<<(ostream &os, File f);
