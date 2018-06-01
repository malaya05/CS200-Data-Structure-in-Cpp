#ifndef ANYLIST_H
#define ANYLIST_H

#include<iostream>
#include <string>				
using namespace std;

class Node
{
public:
	Node() : data(0), link(nullptr){}
    Node(int theData, Node *theLink) : data(theData), link(theLink){}
    Node* getLink( ) const { return link; }
	int getData( ) const { return data; }
    void setData(int theData) { data = theData; }
    void setLink(Node *theLink) { link = theLink; }
private:
    int data;		
    Node *link;	//pointer that points to next node
};


class AnyList
{
	// overloaded insertion operator

public:
	// default constructor

	// copy constructor

	// insertBack

	// overloaded assignment operator

	// append
	
	// destroyList

	// destructor

private:
	Node *first; 
	Node *last;	
	int count;	 
};

#endif