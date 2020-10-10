#pragma once
#include "Node.h"
#define NDEBUG
#include <assert.h>

template<class T>
class Queue
{
private:
	// Data Elements
	Node<T>* front, * rear;
	int numNodes = 0;
	int numQueues = 0;

	void clearQueue()
	{
		while (front != nullptr)
		{
			dequeue();
		}
	}

	void copyNodes(const Node<int>* nodePtr)
	{
		while (nodePtr != nullptr)
		{
			enqueue(nodePtr->getPayload());
			nodePtr = nodePtr->getNext();
		}
	}

	//void printQueue(ostream& outStream, Node<T>* start) const
	//{
	//	while (start != nullptr)
	//	{
	//		outStream << *start << " ";
	//		start = start->getNext();
	//	}
	//}

public:

	//constructor
	Queue()
	{
		numQueues++;
		front = nullptr;
		rear = nullptr;
		numNodes = 0;
	}

	//copy constructor
	Queue(const Queue& fromQueue)
	{
		numQueues++;
		front = nullptr;
		rear = nullptr;
		numNodes = 0;

		// Deep copies the nodes
		this->copyNodes(fromQueue.front);
	}
	
	friend ostream& operator <<(ostream& outStream, const Queue& queue)
	{
		//if (queue.front != nullptr)
		//{
		//	queue.printQueue(outStream, queue.front);
		//}
		//return(outStream);

			Node<T>* start = queue.front;
			while (start != nullptr)
			{
				outStream << *start << " ";
				start = start->getNext();
			}
			return outStream;
	}

	bool operator==(const Queue& left) const
	{
		bool retVal = true;

		// queue cannot be the same if there are uneven amount of nodes
		if (left.numNodes != this->numNodes)
		{
			retVal = false;
		}
		// looks for differences within each node
		else
		{
			Node<T>* leftHandTemp = left.front;
			Node<T>* rightHandTemp = this->front;

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

	Queue& operator=(const Queue& fromQueue)
	{
		// if the queues are different, deletes and copies nodes from the fromQueue
		if (this != &fromQueue) // deals with queue A = queue A
		{
			this->clearQueue();
			this->copyNodes(fromQueue.front);
		}
		return (*this);
	}

	bool enqueue(const T& newPayload)
	{

		bool retVal(true);
		try
		{
			Node<T>* tempPtr = new Node<T>(newPayload, nullptr);
			if (numNodes == 0)
			{
				front = tempPtr;
				rear = tempPtr;
			}
			rear->setNext(tempPtr);
			rear = tempPtr;


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

	T dequeue()
	{
		// ensuring the queue is not empty
		assert(numNodes > 0);
		if (numNodes <= 0)
		{
			throw runtime_error("Illegal dequeue");
		}

		// storing payload and next pointer
		T tempPayload = front->getPayload();
		Node<T>* tempNode = front->getNext();

		// delete node and decrements the next payload
		delete front;
		numNodes--;

		// setting the front of the queue to the next payload
		front = tempNode;

		// returns what was in the front of queue previously
		return(tempPayload);
	}

	T readFront() const
	{
		// ensures there is a node in the queue and throws a runtime error if there is an illegal read
		assert(numNodes > 0);
		if (numNodes <= 0)
		{
			throw runtime_error("illegal readFront");
		}
		return(front->getPayload());
	}

	int size() const
	{
		return numNodes;
	}

	bool isEmpty() const
	{
		return (numNodes == 0);
	}

	~Queue()
	{
		clearQueue();
		numQueues--;
	}

};

