#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <malloc.h>
#include "STUDENT.h"
using namespace std;

int main()
{
	
	char first, second;
	int i, size;
	cin >> size;
	STUDENT **C = new STUDENT*[size];
	for (int i = 0; i < size; i++)
		C[i] = new STUDENT;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = (size - 1); j > i; j--)
		{
			first = C[j-1]->alfavit();
			second = C[j]->alfavit();
			if (first > second)
			{
				STUDENT *X = new STUDENT(C[j - 1]);
				C[j - 1] = C[j];
				C[j] = X;
			}
		}
	}
	cout << " 1 - show STUDENTS\n 2 - show debtors \n Press 3 to exit" << endl;
	while (true)
	{
		int flag1 = 0, flag2;
		switch (getchar())
		{
		case '1':
			for (int i = 0; i < size; i++)
				C[i]->show();
			
			break;
		case '2':
			for (int i = 0; i < size; i++)
			{
				flag2=C[i]->showdebtor();
				if (flag2 == 1)
					flag1 = 1;
			}
			if (flag1==0)
			{
				cout << "no debtor here" << endl;
			}
			break;

		case '3':
			cout << "Esc" << endl;
			exit(EXIT_SUCCESS);
		}
	}

	system("pause");
	return 0;
}