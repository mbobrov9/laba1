#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <malloc.h>
#include "STUDENT.h"
#include "journal.h"
using namespace std;

int main()
{
	
	journal J;

	J.sort();
	cout << " 1 - show STUDENTS\n 2 - show debtors \n Press 3 to exit" << endl;
	while (true)
	{
		int flag1 = 0, flag2;
		switch (getchar())
		{
		case '1':
			
		     J.showjournal();
			
			break;
		case '2':
			 J.showdebtor();
			break;

		case '3':
			cout << "Esc" << endl;
			exit(EXIT_SUCCESS);
		}
	}

	system("pause");
	return 0;
}