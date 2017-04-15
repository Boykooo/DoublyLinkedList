#include "stdafx.h"

using namespace linkedList;

template <class T>
Node<T>::Node(T value, Node* next, Node* prev)
{
	this->next = next;
	this->prev = prev;
	this->value = value;
}

template <class T>
Node<T>::Node(T value)
{
	this->prev = nullptr;
	this->next = nullptr;
	this->value = value;
}

template <class T>
Node<T>::~Node()
{
	this->next = nullptr;
	this->prev = nullptr;
	//TODO: Value???
}

template <class T>
void Node<T>::setNext(Node* next)
{
	this->next = next;
}

template <class T>
Node<T>* Node<T>::getNext()
{
	return this->next;
}

template <class T>
void Node<T>::setPrev(Node* prev)
{
	this->prev = prev;
}

template <class T>
Node<T>* Node<T>::getPrev()
{
	return this->prev;
}

template <class T>
void Node<T>::setValue(T value)
{
	this->value = value;
}

template <class T>
T Node<T>::getValue()
{
	return this->value;
}

