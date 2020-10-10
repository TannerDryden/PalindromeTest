
#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
using namespace std;

bool isPalindome(const string word);

int main()
{

	// Let's play with our Queue class
	{
		const unsigned int numElements = 5;

		// Try to dequeue an empty queue; tests throw
		Queue<int> queue1;
		try
		{
			queue1.dequeue();
		}
		catch (exception & e)
		{
			cerr << "Caught: " << e.what() << endl;
			cerr << "Type: " << typeid(e).name() << endl;
		}

		// Load up a queue
		for (unsigned int i = 0; i < numElements; i++)
		{
			queue1.enqueue(i);
		}
		cout << boolalpha << "queue1: " << queue1 << " is empty? " << queue1.isEmpty() << ", right # of elements? " << (queue1.size() == numElements) << endl;
		queue1 = queue1; // Verify queue can handle queue1 = queue1
		cout << "queue1: " << queue1 << " should match queue1 above" << endl;
		{ // Test the copy constructor and == operator
			Queue<int> queue2(queue1); cout << "queue2: " << queue2 << ", is queue1 == queue2? " << (queue1 == queue2) << endl;
		} // Test the queue destructor
		{ // Test the = operator
			Queue<int> queue3;
			queue3.enqueue(10); queue3.enqueue(11);
			cout << "queue3: " << queue3 << ", is queue1 == queue3? " << (queue1 == queue3) << endl;
			queue3 = queue1;
			cout << "queue3: " << queue3 << ", is queue1 == queue3? " << (queue1 == queue3) << endl;
		} // Test the queue destructor

		// Final confirmation that queue1 is whole
		cout << "queue1: " << queue1 << " queue1 should remain unchanged" << endl;

		// Verify the dequeue order
		for (unsigned int i = 0; i < numElements; i++)
		{
			int temp = queue1.dequeue();
			if (temp != i)
			{
				cout << "Dequeue Error!" << endl;
			}
		}
		// queue1 should now be empty
		cout << "queue1: " << queue1 << " is empty? " << queue1.isEmpty() << ", right # of elements? " << (queue1.size() == 0) << endl;

			// Verify queue works with the string class
			Queue<string> queue4;
			queue4.enqueue("This"); queue4.enqueue(" is"); queue4.enqueue(" a"); queue4.enqueue(" test.");
			cout << "queue4: " << queue4 << endl << endl;
		}

		string userInput;
		cout << "Welcome to Tanner's Palindrome Test" << endl;
		//cout << "Enter your word: ";
		//cin >> userInput;
		for (int i = 0; i < 2; i++)
		{
			if (i == 0)
			{
				userInput = "racecar";
			}
			if (i == 1)
			{
				userInput = "regularcar";
			}
			cout << endl;
			if (isPalindome(userInput))
			{
				cout << userInput << " is a palidrome" << endl;
			}
			else
			{
				cout << userInput << " is not a palidrome" << endl;
			}
		}
}

bool isPalindome(const string word)
{
	Stack<char> stack;
	Queue<char> queue;
	unsigned int i = 0;
	bool retVal = true;

	for (i = 0; i < word.size(); i++)
	{
		stack.push(word[i]);
		queue.enqueue(word[i]);
	}

	i = 0;
	while (i++ < word.size() && retVal)
	{
		if (stack.pop() != queue.dequeue())
		{
			retVal = false;
		}
	}
	return(retVal);
}

