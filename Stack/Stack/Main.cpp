#include "Stack.h"
#include<iostream>

using namespace std;

int main()
{
	Stack s1;
	Stack s2;
	
	for (int i = 1; i < 60; i++)
	{
		s1.push(i);
		cout << "size of stack: " << s1.size() << endl;
		
	}
	cout << "the stack have" << s1 << endl;
	//s1= s2;
	//
	//cout << "s1: " << endl;
	//cout << s1;
	//cout << endl;

	//cout << "\n";
	//cout << "S2: " << endl;
	//cout << s2;

	//cout << endl;



	cout << endl;
	system("pause");
	return 0;
}