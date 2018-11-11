#pragma once
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

class STUDENT
{
private:
	string Name;
	string Group;
	int progress[5];
public:
	STUDENT();
	STUDENT(const STUDENT*);
	~STUDENT();
	void show();
	int searchdebtor();
	string alfavit();
}; 
