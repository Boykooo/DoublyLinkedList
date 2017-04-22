// DoublyLinkedList.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "LinkedList.cpp"
#include "Node.cpp"

using namespace linkedList;
using namespace std;


int main()
{
	//cout << "List of int";

	//LinkedList<int> *intList = new LinkedList<int>();
	//intList->push_back(1);
	//intList->push_back(2);
	//intList->push_back(3);
	//intList->push_back(4);

	//cout << endl << "Elements : " << endl;
	//LinkedList<int>::iterator intIt = intList->begin();
	//for (; intIt != intList->end(); intIt++)
	//{					
	//	cout << intIt->getValue() << " ";
	//}

	//cout << endl << "Insert to 4 item " << endl;
	//LinkedList<int>::iterator it = intList->begin() + 3;
	//intList->insert(it, 12);
	//for (intIt = intList->begin() ; intIt != intList->end(); intIt++)
	//{
	//	cout << intIt->getValue() << " ";
	//}
	//
	//cout << endl << "Remove first element" << endl;
	//intList->erase(intList->begin());
	//for (intIt = intList->begin() ; intIt != intList->end(); intIt++)
	//{
	//	cout << intIt->getValue() << " ";
	//}

	//cout << endl << "Remove first to second elements" << endl;
	//intList->erase(intList->begin(), intList->begin() + 1);
	//for (intIt = intList->begin(); intIt != intList->end(); intIt++)
	//{
	//	cout << intIt->getValue() << " ";
	//}

	//delete intList;


	//cout << endl << endl << "List of string";
	//LinkedList<string> *stringList = new LinkedList<string>();
	//stringList->push_top("one");
	//stringList->push_top("two");
	//stringList->push_top("three");
	//stringList->push_top("four");

	//LinkedList<string>::iterator stringIt = stringList->begin();

	//cout << endl << "Elements : " << endl;

	//for ( ; stringIt != stringList->end(); stringIt++)
	//{
	//	cout << stringIt->getValue() + " ";
	//}

	//cout << endl << "Remove first element" << endl;
	//stringList->erase(stringList->begin());
	//stringIt = stringList->begin();
	//for (; stringIt != stringList->end(); stringIt++)
	//{
	//	cout << stringIt->getValue() + " ";
	//}

	//cout << endl << "Remove second element" << endl;
	//stringList->erase(stringList->begin() + 1);
	////stringList->erase(stringList->begin(), stringList->begin() + 1);
	//stringIt = stringList->begin();
	//for (; stringIt != stringList->end(); stringIt++)
	//{
	//	cout << stringIt->getValue() + " ";
	//}

	//delete stringList;


	LinkedList<int> *list = new LinkedList<int>();
	list->push_top(1);
	list->push_top(2);
	list->push_top(3);
	list->push_back(4);
	list->push_back(5);
	list->push_back(6);

	cout << "List :" << endl;
	for (auto i = list->begin(); i != list->end(); i++)
	{
		cout << *i << " ";
	}

	cout << endl << endl << "Back : " << endl;
	for (auto i = list->end(); i != list->begin(); i--)
	{
			cout << *i << " ";
	}



	printf("\n\n\n");
	system("pause");
	return 0;
}