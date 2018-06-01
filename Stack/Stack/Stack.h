#pragma once

#include<iostream>
#include<stdexcept>

using namespace std;
const int MAX = 20;

class Stack
{
	friend ostream& operator<<(ostream& out, const Stack& obj);

public:
	//Constructors & Copy assigment opreator 
	Stack();
	Stack(const Stack& obj);
	~Stack();
	Stack& operator=(const Stack& obj);
	
	// MOVE Constructor & assigment opreator
	Stack(Stack&& obj);
	Stack& operator=(Stack&& obj);

	// Boolean Functions
	bool isFull() const;
	bool isEmpty() const;

	// return the last entred element
	int top() const; 
	int size() const;

	// clear everything inside the continer
	void clearStack();

	// add elements into the stack
	void push(int x);

	// delete elements from the stack
	void pop();



	// to grow the array
	int* growSize();
	
private:
	int* stack;
	int cap;
	int numElem;

};

// overloeaded inseartion operator
 ostream& operator<<(ostream& out, const Stack& obj)
{
	if (obj.isEmpty())
		cerr << "Nothing to print" << endl;
	else
	{
		out << "The Stack contians: ";
		for (int i = 0; i < obj.numElem; i++)
			out << obj.stack[i] << " ";
		out << endl;
	}
	return out;
}

// defulte constructor
Stack::Stack()
{
	cap = MAX;
	stack = new int[cap];
	numElem = 0;
}

// COPY Constructor
Stack::Stack(const Stack& obj)
{
	cap = obj.cap;
	stack = new int[cap];
	numElem = obj.numElem;

	for (int i = 0; i < numElem; i++)
		stack[i] = obj.stack[i];
}
// destrcoutor
Stack::~Stack()
{
	delete[] stack;
}
// isFUll
bool Stack::isFull() const
{
	return (numElem == cap);
}
//isEmpty
bool Stack::isEmpty() const
{
	return (numElem == 0);
}

// return the last entred element
int Stack::top() const
{
	if (isEmpty())
	{
		//throw length_error("Empty stack excption");
		cerr << "Empty stack excption" << endl;
		return -1;
	}
	else
		return stack[numElem - 1];
}

// return the size 
int Stack::size() const
{
	return numElem;
}

// clear everything inside the continer
void Stack::clearStack()
{
	delete[] stack;
	stack = new int[cap];
	numElem = 0;
}
// add elements into the stack
void Stack::push(int x)
{
	if (numElem == cap)
	{
		/*
		int* w = growSize();
		delete[] stack;
		stack = nullptr;
		stack = w;
		stack[numElem++] = x;
		*/
		//throw length_error("Failed to push, obj is full.");
	cerr << "Failed to push, obj is full" << endl;
	}
	else
	{
		stack[numElem++] = x;
		//numElem++;
	}
}
// delete elements from the stack
void Stack::pop()
{
	if (isEmpty())
		throw length_error("Cannot delete from empty stack");
	else
		numElem--;
}
// assigment opreator 
Stack& Stack::operator=(const Stack& obj)
{
	if (this != &obj)
	{
		if (obj.isEmpty())
		{
			this->clearStack();
		}
		else if (obj.cap == cap)
		{
			numElem = obj.numElem;
			for (int i = 0; i < numElem; i++)
				stack[i] = obj.stack[i];
		}
		else if (obj.cap < cap)
		{
			delete[] stack;
			cap = obj.cap;
			numElem = obj.numElem;
			stack = new int[cap];
			for (int i = 0; i < numElem; i++)
				stack[i] = obj.stack[i];
		}
		else
		{
			cap = obj.cap;
			numElem = obj.numElem;
			for (int i = 0; i < numElem; i++)
				stack[i] = obj.stack[i];
		}
	}
	else
		cerr << "Self assigment" << endl;
	return *this;
}

// MOVE Constructor & assigment opreator
Stack::Stack(Stack&& obj)
{
	// pointing to same location
	stack = obj.stack;
	numElem = obj.numElem;
	cap = obj.cap;

	// freeing the param object
	obj.cap = 0;
	obj.numElem = 0;
	obj.stack = nullptr;
}
Stack& Stack::operator=(Stack&& obj)
{
	if (this != &obj)
	{
		//free the calling object
		delete[] stack;

		// pointing to same location
		stack = obj.stack;
		numElem = obj.numElem;
		cap = obj.cap;

		// freeing the param object
		obj.cap = 0;
		obj.numElem = 0;
		obj.stack = nullptr;
	}
	else
		cerr << "Self assigment" << endl;
	return *this;
}

// function to grow the size of the array
int* Stack::growSize()
{
	int newCap = cap * 2;
	int* newArray = new int[newCap];
	for (int i = 0; i < numElem; i++)
		newArray[i] = stack[i];
	return newArray;
}