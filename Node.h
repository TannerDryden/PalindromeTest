/* Name: Tanner Dryden
Description: This Class creates a singly linked list
*/

#pragma once
#include <ostream>
using namespace std;

template<class P>
class Node
{
private:
	// Data elements
	P payload;
	Node<P>* node;

public:
	// overloading insertion operator to get the nodes payload
	friend ostream& operator <<(ostream& outStream, const Node<P>& node)
	{
		outStream << node.getPayload();
		return(outStream);
	}

	// constructor - note no default
	Node(P newPayload, Node<P>* newNext)
	{
		setPayload(newPayload);
		setNext(newNext);
	}

	// accessors
	P getPayload() const
	{
		return(payload);
	}

	Node* getNext() const
	{
		return(node);
	}

	// mutators
	void setPayload(P newPayload)
	{
		payload = newPayload;
	}

	void setNext(Node<P>* next)
	{
		node = next;
	}

	// destructor
	~Node()
	{

	}
};

