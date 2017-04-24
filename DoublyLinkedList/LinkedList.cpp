#include "stdafx.h"


using namespace linkedList;


template <class T>
LinkedList<T>::iterator::iterator(Node<T> *item = nullptr)
{
	iterator::item = item;
}

template <class T>
T LinkedList<T>::iterator::operator*()
{
	return iterator::item->getValue();
}

template <class T>
Node<T>* LinkedList<T>::iterator::operator->()
{
	return iterator::item;
}

template <class T>
typename LinkedList<T>::iterator& LinkedList<T>::iterator::operator++(int)
{
	this->item = this->item->getNext();
	return *this;
}

template <class T>
typename LinkedList<T>::iterator& LinkedList<T>::iterator::operator--(int)
{
	this->item = this->item->getPrev();
	return *this;
}

template <class T>
typename LinkedList<T>::iterator& LinkedList<T>::iterator::operator--()
{
	this->item = this->item->getPrev();
	return *this;
}

template <class T>
typename LinkedList<T>::iterator& LinkedList<T>::iterator::operator+(int value)
{
	while (value--)
	{
		this->item = this->item->getNext();
	}

	return *this;
}

template <class T>
typename LinkedList<T>::iterator& LinkedList<T>::iterator::operator-(int value)
{
	while (--value)
	{
		this->item = this->item->getPrev();
	}

	return *this;
}

template <class T>
bool LinkedList<T>::iterator::operator==(iterator second)
{
	if (item == nullptr)
	{
		return true;
	}

	if (item->getIndex() == 0 && second.item->getIndex() == 0)
	{
		return false;
	}

	if (item->getNext() == nullptr && second.item->getNext() == nullptr)
	{
		return false;
	}

	/*if (item->getIndex() > second.item->getIndex())
	{
		return true;
	}*/

	return this->item->getIndex() == second.item->getIndex();
}					

template <class T>
bool LinkedList<T>::iterator::operator!=(iterator second)
{
	return !(*this == second);
}

template <class T>
Node<T>* LinkedList<T>::iterator::getNode()
{
	return this->item;
}

template <class T>
LinkedList<T>::LinkedList()
{
	this->listSize = 0;
	this->top = nullptr;
	this->tail = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template <class T>
void LinkedList<T>::push_top(T value)
{
	Node<T> *node = new Node<T>(value, 0);

	if (isEmpty())
	{
		tail = node;
	}
	else
	{
		top->setPrev(node);
	}

	node->setNext(top);
	top = node;

	incNodeIndex(top->getNext());

	listSize++;
}

template <class T>
void LinkedList<T>::push_back(T value)
{
	int index = (!tail) ? 0 : tail->getIndex() + 1;
	Node<T> *node = new Node<T>(value, index);

	if (!isEmpty())
	{
		tail->setNext(node);
		node->setPrev(tail);
	}
	else
	{
		top = node;
	}

	tail = node;

	listSize++;
}

template <class T>
void LinkedList<T>::insert(iterator pos, T value)
{
	Node<T> *newNode = new Node<T>(value, pos.item->getIndex());
	Node<T> *insertNode = pos.getNode();
	newNode->setNext(insertNode);

	if (insertNode->getPrev())
	{
		insertNode->getPrev()->setNext(newNode);
		newNode->setPrev(insertNode->getPrev());
		insertNode->setPrev(newNode);
	}
	else
	{
		top->setPrev(newNode);
		top = newNode;
	}

	incNodeIndex(newNode->getNext());

	listSize++;
}

template <class T>
void LinkedList<T>::erase(iterator pos)
{
	Node<T> *node = pos.getNode();
	decNodeIndex(node->getNext());

	if (node->getNext())
	{
		node->getNext()->setPrev(node->getPrev());
	}
	else
	{
		tail = node->getPrev();
	}

	if (node->getPrev())
	{
		node->getPrev()->setNext(node->getNext());
	}
	else
	{
		top = node->getNext();
	}

	delete node;
	listSize--;
}

template <class T>
void LinkedList<T>::erase(iterator first, iterator last)
{
	for (; first != last; first++)
	{
		iterator temp = first;
		first++;
		erase(temp);
	}

	/*while (first != last)
	{
		iterator temp = first->getNext();
		if (last.item != nullptr && temp != last.item->getNext())
		{
			erase(first);
			first = temp;
		}
		else
		{
			break;
		}
		
	}*/
}

template <class T>
typename LinkedList<T>::iterator LinkedList<T>::begin()
{
	return top;
}

template <class T>
typename LinkedList<T>::iterator LinkedList<T>::end()
{
	return tail;
}

template <class T>
int LinkedList<T>::size()
{
	return listSize;
}

template <class T>
void LinkedList<T>::clear()
{
	erase(begin(), end());
}

template <class T>
bool LinkedList<T>::isEmpty()
{
	return listSize == 0;
}

template <class T>
void LinkedList<T>::incNodeIndex(iterator it)
{
	if (it.item == nullptr)
	{
		return;
	}

	for (; it != end(); it++)
	{
		if (it.item != nullptr)
		{
			it.item->setIndex(it.item->getIndex() + 1);
		}
	}
}

template <class T>
void LinkedList<T>::decNodeIndex(iterator it)
{
	if (it.item == nullptr)
	{
		return;
	}

	for (; it != end(); it++)
	{
		if (it.item != nullptr)
		{
			it.item->setIndex(it.item->getIndex() - 1);
		}
	}
}