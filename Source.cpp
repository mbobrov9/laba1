#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "STUDENT.h"

using namespace std;

STUDENT::STUDENT()
{
	cout << "Class STUDENT creator" << endl;
	cout << "Enter name of STUDENT: ";
	cin >> Name;
	cout << "Enter Group of the STUDENT: ";
	cin >> Group;
	cout << "Enter the progress:";
	for (int i = 0; i < 5; i++)
	{
		cin >> progress[i];
	}
}

STUDENT::STUDENT(const STUDENT* P)
{
	cout << "copy ctor" << endl;

	this->Name = P->Name;
	this->Group = P->Group;
	for (int i = 0; i < 5; i++)
	{
		this->progress[i] = P->progress[i];
	}
}

STUDENT :: ~STUDENT()
{
	cout << "STUDENT destructor" << endl;
}

void STUDENT::show()
{
	cout << "Name of the STUDENT:" << Name << endl;
	cout << "Name of the Group:" << Group << endl;
	for (int i = 0; i < 5; i++)
	{
			cout << "progress:" << progress[i] << endl;
	}
}
int STUDENT::searchdebtor()
{
	int flag = 0;
	for (int i = 0; i < 5; i++)
	{
		if (progress[i] == 2)
			flag = 1;
	}
	if (flag == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
string STUDENT::alfavit()
{
	return Name;
}
