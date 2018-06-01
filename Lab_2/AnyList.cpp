/*
	Alaya, Jason

	CS A200
	September 6, 2017

	Lab 2
*/

#include "AnyList.h"

// overloaded insertion operator
ostream& operator<<(ostream & out, const AnyList& list)
{
	if (list.first == nullptr)
		out << "List is empty." << endl;
	else
	{
		Node* temp = list.first;
		while (temp != nullptr)
		{
			out << temp->getData() << " ";
			temp = temp->getLink();
		}
		out << endl;
	}
	return out;
}

	// default constructor
	AnyList::AnyList()
	{
		Node *first = nullptr;
		Node *last = nullptr;
		int count = 0;
	}

	// copy constructor
	AnyList::AnyList(const AnyList& list)
	{
		// at this point member variables
		//initialized by defult values
		Node * temp = list.first;
		while (temp != nullptr)
		{
	    // insertBack will take care of first, last, count
			insertBack(temp->getData());
			temp = temp->getLink();
		}
	}

	// insertBack
	void AnyList::insertBack(int num)
	{
		if (count == 0)
		{
			first = new Node(num, nullptr);
			last = first;
		}
		else
		{
			last->setLink(new Node(num, nullptr));
			last = last->getLink();
		}
		count++;
	}

	// overloaded assignment operator
	AnyList& AnyList::operator=(const AnyList& list)
	{
		if (this != &list)
		{
			this->destroyList();
			Node* temp = list.first;

			while (temp != nullptr)
			{
				insertBack(temp->getData());
				temp = temp->getLink();
			}
		}
		return *this;
	}

	// append
	void AnyList::append(const AnyList& list)
	{
		Node* temp = list.first;
		while (temp != nullptr)
		{
			insertBack(temp->getData());
			temp = temp->getLink();
		}
	}

	// destroyList
	void AnyList::destroyList()
	{
		while (first != nullptr)
		{
			Node* temp = first;
			first = first->getLink();
			delete temp;
			temp = nullptr; // no need
		}

		last = nullptr;
		count = 0;
	}

	// destructor
AnyList::~AnyList()
{
	destroyList();
}