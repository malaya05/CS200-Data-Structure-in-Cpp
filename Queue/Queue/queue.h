#pragma once

#include<iostream>

using namespace std;

const int MAX = 15;

class queue
{
public:
	queue();
	queue(const queue& obj);

	bool isEmpty() const;
	bool isFull() const;
	
	void push(int);
	void pop();

	int size() const;
	int front() const;
	int queue::r() const;

private:
	int cap;
	int* a;
	int f;
	int back;
};

queue::queue()
{
	cap = MAX;
	 a = new int[cap];
	 f = back = -1;
}
queue::queue(const queue& obj)
{
	cap = obj.cap;
	a = new int[cap];
	f = obj.f;
	back = obj.back;

	for (int i = 0; i < size(); i++)
		a[i] = obj.a[i];
}

bool queue::isEmpty() const
{
	return (f == back);
}

bool queue::isFull() const
{
	return f == (back+1) % cap;
}

void queue::push(int num)
{
	if (isFull())
		cerr << " FUll" << endl;
	else if (f == -1)
	{
		f = 0;
		back = 1;
		a[f] = num;
	}
	else
	{
	
		a[back] = num;
		back = (back + 1 ) % cap;
	}
}
void queue::pop()
{
	if (isEmpty())
		cerr << "Empty!" << endl;
	else
	{
		f = (f+ 1) % cap;
	}
}

int queue::size() const
{
	return (cap-f+back)% cap;
}

int queue::front() const
{
	if (isEmpty())
		cerr << "Empty"<<endl;
	else
		return a[f];
}

int queue::r() const
{
		return back;
}

