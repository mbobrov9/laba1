#pragma once
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "STUDENT.h"
class journal
{
private:
	STUDENT** Data;
	int size;
public:
	journal();
	~journal();
	journal(journal C, int value);
	journal(int value);
	journal& operator +=(STUDENT* P);
	journal& operator --();
	void showjournal();
	void showdebtor();
	void sort();
	int getSize();
	bool isEmpty();

}; 
