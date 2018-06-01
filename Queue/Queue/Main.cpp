#include<iostream>
#include "queue.h"

using namespace std;

int main()
{
	queue q1; 
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(5);
	q1.pop();

	cout << q1.size() <<" " << q1.front() << q1.r() << endl;

	cout << endl;
	system("pause");
	return 0;
}