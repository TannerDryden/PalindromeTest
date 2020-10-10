//
//
//// Helper methods
//
//// display stack in reverse order
//void Queue::printQueue(ostream& outStream, Node<T>* start) const
//{
//	while (start != nullptr)
//	{
//		outStream << *start << " ";
//		start = start->getNext();
//	}
//}
//
//// copies the stack of nodes
//void Queue::copyNodes(const Node<T>* nodePtr)
//{
//	while(nodePtr != nullptr)
//	{
//		enqueue(nodePtr->getPayload());
//		nodePtr = nodePtr->getNext();
//	}
//}
//
//// pops everything off the stack
//void Queue::clearQueue()
//{
//	while (front != nullptr)
//	{
//		dequeue();
//	}
//}
//
//
//	// overloads
//	// overloading the insertion operator to print out the stack of an object
//	ostream& operator <<(ostream& outStream, const Queue& queue)
//	{
//		if (queue.front != nullptr)
//		{
//			queue.printQueue(outStream, queue.front);
//		}
//		return(outStream);
//	}
//
//	// overloading the = operator
//	Queue& Queue::operator=(const Queue& fromQueue)
//	{
//		// if the stacks are different, deletes and copies nodes from the fromStack
//		if (this != &fromQueue) // deals with stackA = Stack A
//		{
//			this->clearQueue();
//			this->copyNodes(fromQueue.front);
//		}
//		return (*this);
//	}
//
//	// overloading the == operator
//	bool Queue::operator==(const Queue& left) const
//	{
//		bool retVal = true;
//
//		// stacks cannot be the same if there are uneven amount of nodes
//		if (left.numNodes != this->numNodes)
//		{
//			retVal = false;
//		}
//		// looks for differences within each node
//		else
//		{
//			Node<T>* leftHandTemp = left.front;
//			Node<T>* rightHandTemp = this->front;
//
//			while (leftHandTemp != nullptr && retVal)
//			{
//				if (leftHandTemp->getPayload() != rightHandTemp->getPayload())
//				{
//					retVal = false;
//				}
//				leftHandTemp = leftHandTemp->getNext();
//				rightHandTemp = rightHandTemp->getNext();
//			}
//		}
//		return(retVal);
//	}
//
//	// constructor
//	Queue::Queue()
//	{
//		numQueues++;
//		front = nullptr;
//		rear = nullptr;
//		numNodes = 0;
//	}
//
//	// copy constructor
//	Queue::Queue(const Queue& fromQueue)
//	{
//		numQueues++;
//		front = nullptr;
//		rear = nullptr;
//		numNodes = 0;
//
//		// Deep copies the nodes
//		this->copyNodes(fromQueue.front);
//	}
//
//	// push/pop methods
//	bool Queue::enqueue(const T& newPayload)
//	{
//
//		bool retVal(true);
//		try
//		{
//			Node<T>* tempPtr = new Node<T>(newPayload, nullptr);
//			if (numNodes == 0)
//			{
//				front = tempPtr;
//				rear = tempPtr;
//			}
//			rear->setNext(tempPtr);
//			rear = tempPtr;
//
//			
//			numNodes++;
//		}
//		//error catching
//		catch (exception & error)
//		{
//			error;
//			retVal = false;
//		}
//
//		return(retVal);
//	}
//
//	T Queue::dequeue()
//	{
//		// ensuring the stack is not empty
//		assert(numNodes > 0);
//		if (numNodes <= 0)
//		{
//			throw runtime_error("Illegal pop");
//		}
//
//		// storing payload and next pointer
//		T tempPayload = front->getPayload();
//		Node<T>* tempNode = front->getNext();
//
//		// delete node and decrements the next payload
//		delete front;
//		numNodes--;
//
//		// setting the top of the stack to the next payload
//		front = tempNode;
//
//		// returns what was on top previously
//		return(tempPayload);
//	}
//
//	// top accessor
//	T Queue::readFront() const
//	{
//		// ensures there is a disk on the stack and throws a runtime error if there is an illegal read
//		assert(numNodes > 0);
//		if (numNodes <= 0)
//		{
//			throw runtime_error("illegal readTop");
//		}
//		return(front->getPayload());
//	}
//
//	// number of nodes in the stack accessor
//	int Queue::size() const
//	{
//		return numNodes;
//	}
//
//	bool Queue::isEmpty() const
//	{
//		return (numNodes == 0);
//	}
//
//	// destructor
//	Queue::~Queue()
//	{
//		clearQueue();
//		numQueues--;
//	}