#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>
using namespace std;

class DArray
{
public:
    DArray( );
	DArray(const DArray&);
    DArray(int newCapacity);

    void addElement(int newElement);

	int getNumOfElements() const;

	void printArray() const;

	DArray& operator=(const DArray&);
	
	~DArray();

	// Declaration function emptyArray
	void emptyArray();

	// Declaration function append
	void appendArray(const DArray& obj) ;

	// Declaration move constructor
	DArray(DArray&& obj);

	// Declaration move assignment operator
	DArray& operator=(DArray&& obj);

private:
    int *a;					//will point to an array of integers
    int capacity;			//capacity of the array
    int numOfElements;		//total number of elements in the array

};

#endif