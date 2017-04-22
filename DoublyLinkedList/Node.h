#pragma once



namespace linkedList
{
	/*template <class T> class NodeValue
	{
	private:
		T value;
	public:
		NodeValue();
		~NodeValue();
		void setValue(T value);
		T getValue();
	};*/

	template <class T> class Node
	{
	private:
		int index;
		T value;
		Node *next;
		Node *prev;
	public:
		Node(T value, Node *next, Node *prev, int index);
		Node(T value, int index);
		~Node();
		void setNext(Node *next);
		Node* getNext();
		void setPrev(Node* prev);
		Node* getPrev();
		void setValue(T value);
		T getValue();
		void setIndex(int index);
		int getIndex();
	};
}

