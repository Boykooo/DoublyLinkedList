#pragma once

namespace linkedList
{
	template <class T> class Node;

	template <class T> class LinkedList
	{
	
	public:
		struct iterator
		{
			Node<T> *item;
			iterator(Node<T> *item_);
			T operator*();
			Node<T>* operator->();
			iterator& operator++(int);
			iterator& operator--(int);
			iterator& operator--();
			iterator& operator+(int value);
			iterator& operator-(int value);
			bool operator==(iterator second);
			bool operator!=(iterator second);
			Node<T>* getNode();
		};

		LinkedList();
		~LinkedList();
		void push_top(T value);
		void push_back(T value);
		void insert(iterator pos, T value);
		void erase(iterator pos); 
		void erase(iterator first, iterator last);
		iterator begin();	 
		iterator end();
		int size();
		void clear();
		bool isEmpty();

	private:
		Node<T>* top;
		Node<T>* tail;
		int listSize;
		void moveNodeIndex(iterator it);
	};
}
