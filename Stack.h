/* Name: Tanner Dryden
Description: this class works in conjuntion with my Node class to create a stack
*/

#pragma once
#include "Node.h"
//#define NDEBUG
#include <assert.h>

template <class T>

class Stack
{

private:

	// Data Elements
	Node<T>* top;
	int numNodes;
	int numStacks = 0;

	// Helper methods

	// display stack in reverse order
	void printStackReverseHelper(ostream& outStream, Node<T>* start) const
	{
		// Recurse to the end of the stack
		if (start != nullptr)
		{
			printStackReverseHelper(outStream, start->getNext());
			outStream << *start << " ";
		}
	}

	// copies the stack of nodes
	void copyNodes(const Node<T>* nodePtr)
	{
		// goes to the bottom of the stack then pushes each node onto the stack
		if (nodePtr != nullptr)
		{
			copyNodes(nodePtr->getNext());
			push(nodePtr->getPayload());
		}

	}

	// pops everything off the stack
	void clearStack()
	{
		while (top != nullptr)
		{
			pop();
		}
	}

public:

	// overloads
	// overloading the insertion operator to print out the stack of an object
	friend ostream& operator <<(ostream& outStream, const Stack& stack)
	{
		if (stack.top != nullptr)
		{
			stack.printStackReverseHelper(outStream, stack.top);
		}
		return(outStream);
	}

	// overloading the = operator
	Stack& operator=(const Stack& fromStack)
	{
		// if the stacks are different, deletes and copies nodes from the fromStack
		if (this != &fromStack) // deals with stackA = Stack A
		{
			this->clearStack();
			this->copyNodes(fromStack.top);
		}
		return (*this);
	}

	// overloading the == operator
	bool operator==(const Stack& left) const
	{
		bool retVal = true;

		// stacks cannot be the same if there are uneven amount of nodes
		if (left.numNodes != this->numNodes)
		{
			retVal = false;
		}
		// looks for differences within each node
		else
		{
			Node<T>* leftHandTemp = left.top;
			Node<T>* rightHandTemp = this->top;

			while (leftHandTemp != nullptr && retVal)
			{
				if (leftHandTemp->getPayload() != rightHandTemp->getPayload())
				{
					retVal = false;
				}
				leftHandTemp = leftHandTemp->getNext();
				rightHandTemp = rightHandTemp->getNext();
			}
		}
		return(retVal);
	}

	// constructor
	Stack()
	{
		numStacks++;
		top = nullptr;
		numNodes = 0;
	}

	// copy constructor
	Stack(const Stack& fromStack)
	{
		numStacks++;
		top = nullptr;
		numNodes = 0;

		// Deep copies the nodes
		this->copyNodes(fromStack.top);
	}

	// push/pop methods
	bool push(T newPayload)
	{
		bool retVal(true);
		try
		{
			top = new Node<T>(newPayload, top);
			numNodes++;
		}
		//error catching
		catch (exception & error)
		{
			error;
			retVal = false;
		}

		return(retVal);
	}

	T pop()
	{
		// ensuring the stack is not empty
		assert(numNodes > 0);
		if (numNodes <= 0)
		{
			throw runtime_error("Illegal pop");
		}

		// storing payload and next pointer
		T tempPayload = top->getPayload();
		Node<T>* tempNode = top->getNext();

		// delete node and decrements the next payload
		delete top;
		numNodes--;

		// setting the top of the stack to the next payload
		top = tempNode;

		// returns what was on top previously
		return(tempPayload);
	}

	// top accessor
	T readTop() const
	{
		// ensures there is a disk on the stack and throws a runtime error if there is an illegal read
		assert(numNodes > 0);
		if (numNodes <= 0)
		{
			throw runtime_error("illegal readTop");
		}
		return(top->getPayload());
	}

	// number of nodes in the stack accessor
	int sizeO() const
	{
		return numNodes;
	}

	// destructor
	~Stack()
	{
		clearStack();
		numStacks--;
	}
};