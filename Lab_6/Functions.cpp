/*
	Alaya, Jason

	CS A200
	October 30, 2017

	Lab 6
*/

#include "HTArray.h"

//Definition overloaded insertion operator
ostream& operator<<(ostream& out, const HTArray& table)
{
	if (table.numOfElements > 0)
	{
		for (int i = 0; i < table.capacity; i++)
		{
			out << "IDX " << i << ": ";
			table.ht[i]->printList();
			out << endl;
		}
	}
	else
		cerr << "The table is empty." << endl;;
	return out;
}

//Definition function overloaded constructor
HTArray::HTArray(int s)
{
	this->capacity = s;
	numOfElements = 0;
	ht = new LinkedList*[capacity];

	for(int i = 0; i < capacity; i++)
	{
		ht[i] = new LinkedList;
	}
}

//Definition function addElement
void HTArray::addElement(int elem)
{
		int index = hashValue(elem);
		ht[index]->insertBack(elem);
		numOfElements++;
}

//Definition function getNumOfElements
int HTArray::getNumOfElements() const
{
	return numOfElements;
}

//Definition function isEmpty
bool HTArray::isEmpty() const
{
	return (numOfElements == 0);
}

//Definition function searchElement
bool HTArray::searchElement(int elem) const
{
	
	int index = hashValue(elem);
	if(ht[index]->getCount() >0)
		return (ht[index]->search(elem));
	else
		return false;
}

//Definition destructor
HTArray::~HTArray()
{
	for(int i = 0; i < capacity; i++)
		ht[i]->~LinkedList();
	
	delete [] ht;
	ht = nullptr;
}

//Definition function hashValue
int HTArray::hashValue(int key) const
{
	return key % capacity;
}