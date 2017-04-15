#pragma once



namespace linkedList
{
	template <class T> class Node
	{
	private:
		T value;
		Node *next;
		Node *prev;
	public:
		Node(T value, Node *next, Node *prev);
		Node(T value);
		~Node();
		void setNext(Node *next);
		Node* getNext();
		void setPrev(Node* prev);
		Node* getPrev();
		void setValue(T value);
		T getValue();
	};
}

