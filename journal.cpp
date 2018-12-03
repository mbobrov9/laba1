#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "journal.h"

using namespace std;
journal:: ~journal() {
	cout << "dtor journal" << endl;
	for (int i = 0; i < size; i++)
	{
		delete[] Data[i];
	}
}

journal::journal(journal C, int value)
{
	cout << "copy Ctor Container" << endl;
	size = value;
	Data = new STUDENT*[size];
	for (int i = 0; i < (C.size < this->size ? C.size : this->size); i++)
		this->Data[i] = C.Data[i];
}

journal::journal(int value)
{
	cout << "ctor with param value" << endl;
	size = value;
	Data = new STUDENT*[size];
	for (int i = 0; i < size; i++)
	{
		Data[i] = new STUDENT;
		Data[i]->fullin();
	}
}
void journal::showjournal()
{
	for (int i = 0; i < this->size; i++)
		Data[i]->show();
}
void journal::showdebtor()
{
	int flag;
	for (int i = 0; i < this->size; i++)
	{
		flag = Data[i]->searchdebtor();
		if (flag == 1)
		{
			Data[i]->show();
		}
	}
}
void journal::sort()
{
	string first, second;
	for (int i = 0; i < this->size-1; i++)
	{
		for (int j = (this->size - 1); j > i; j--)
		{
			first = this->Data[j - 1]->alfavit();
			second = this->Data[j]->alfavit();
			if (first > second)
			{
				STUDENT *X = new STUDENT(Data[j - 1]);
				this->Data[j - 1] = this->Data[j];
				this->Data[j] = X;
			}
		}
	}
}


journal& journal:: operator +=(STUDENT* P)
{
	cout << "Operator +=" << endl;
	journal newC(*this, (this->getSize() + 1));
	newC.Data[(newC.size) - 1] = P;
	this->size++;
	this->Data = new STUDENT*[this->size];
	for (int i = 0; i < this->size; i++)
		this->Data[i] = newC.Data[i];
	return *this;
}

journal& journal:: operator --()
{
	cout << "Operator --" << endl;
	this->size--;
	journal newC(*this, (this->size));
	this->Data = new STUDENT*[this->size];
	for (int i = 0; i < this->size; i++)
		this->Data[i] = newC.Data[i];
	return *this;

}


int journal::getSize()
{
	return this->size;
}

bool journal::isEmpty()
{
	if (this->size == 0)
		return true;
	else return false;
}
