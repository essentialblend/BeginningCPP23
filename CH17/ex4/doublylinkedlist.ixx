export module doublylinkedlist;

import std;

export template<typename T>
class LinkedList
{
public:
	LinkedList() = default;

	LinkedList(const LinkedList& l);

	LinkedList& operator=(LinkedList other); 

	// Inserts: pushFront, pushBack, (at/after node)
	void pushFront(const T& val);
	void pushBack(const T& val);
		
	// Removal: popFront, popBack, clear.
	void popFront();
	void popBack();

	void clearLinkedList();

	// Checks: isEmpty.
	bool isEmpty() const;
	
	
	T& getFront();
	const T& getFront() const;

	T& getBack();
	const T& getBack() const;

	std::size_t getSize() const noexcept;
	void swap(LinkedList& other) noexcept;

	// Nested iterator.
	class Iterator;
	Iterator iterateFromHead() const;
	Iterator iterateFromTail() const;

	~LinkedList();

private:
	// Nested Node class.
	class Node
	{
	public:
		Node() = default;
		explicit Node(const T& data, Node* prev = nullptr, Node* next = nullptr) : memData{ data }, memPrev{ prev }, memNext{ next } {}
		
		Node(const Node& other) = default;
		
		~Node() = default;
		
		T memData{};
		Node* memPrev{};
		Node* memNext{};
	};

	Node* headNode{};
	Node* tailNode{};
	std::size_t numElements{};
};

// Members
template<typename T>
LinkedList<T>::LinkedList(const LinkedList& l)
{
	for (auto iter{ l.iterateFromHead() }; iter; iter.next())
		pushBack(iter.value());
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList other)
{
	this->swap(other);
	return *this;
}

template<typename T>
void LinkedList<T>::pushFront(const T& val)
{
	Node* oldHead{ headNode };

	headNode = new Node{ val };
	++numElements;

	if (oldHead)
	{
		oldHead->memPrev = headNode;
		headNode->memNext = oldHead;
	}
	else
	{
		tailNode = headNode;
	}
}


template<typename T>
void LinkedList<T>::pushBack(const T& val)
{
	Node* oldTail{ tailNode };

	tailNode = new Node{ val };
	++numElements;

	if (oldTail)
	{
		oldTail->memNext = tailNode;
		tailNode->memPrev = oldTail;
	}
	else
	{
		headNode = tailNode;
	}
}

template<typename T>
void LinkedList<T>::popFront()
{
	Node* oldHead{ headNode };

	if (oldHead == tailNode)
	{
		headNode = tailNode = nullptr;
	}
	else
	{
		headNode = oldHead->memNext;
		headNode->memPrev = nullptr;
	}

	--numElements;

	delete oldHead;
	oldHead = nullptr;
}

template<typename T>
void LinkedList<T>::popBack()
{
	Node* oldTail{ tailNode };

	if (oldTail == headNode)
	{
		tailNode = headNode = nullptr;
	}
	else
	{
		tailNode = oldTail->memPrev;
		tailNode->memNext = nullptr;
	}

	--numElements;

	delete oldTail;
	oldTail = nullptr;
}

template<typename T>
void LinkedList<T>::clearLinkedList()
{
	while (!isEmpty())
		popFront();
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
	return numElements == 0;
}

template<typename T>
T& LinkedList<T>::getFront()
{
	return headNode->memData;
}

template<typename T>
const T& LinkedList<T>::getFront() const
{
	return headNode->memData;
}

template<typename T>
T& LinkedList<T>::getBack()
{
	return tailNode->memData;
}

template<typename T>
const T& LinkedList<T>::getBack() const
{
	return tailNode->memData;
}

template<typename T>
std::size_t LinkedList<T>::getSize() const noexcept
{
	return numElements;
}

template<typename T>
void LinkedList<T>::swap(LinkedList<T>& other) noexcept
{
	std::swap(headNode, other.headNode);
	std::swap(tailNode, other.tailNode);
	std::swap(numElements, other.numElements);
}

// Definition of the nested Iterator class.
template<typename T>
class LinkedList<T>::Iterator
{
public:
	explicit Iterator(Node* node)
		: memCurrNode{ node }
	{}

	const T& value() const { return memCurrNode->memData; }

	bool hasValue() const { return memCurrNode != nullptr; }
	operator bool() const { return memCurrNode != nullptr; }

	void next() { memCurrNode = memCurrNode->memNext; }
	void previous() { memCurrNode = memCurrNode->memPrev; }

private:
	Node* memCurrNode;
};

template<typename T>
LinkedList<T>::Iterator LinkedList<T>::iterateFromHead() const
{
	return Iterator{ headNode };
}

template<typename T>
LinkedList<T>::Iterator LinkedList<T>::iterateFromTail() const
{
	return Iterator{ tailNode };
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	clearLinkedList();
}

// Non-members.
export template<typename T>
void swap(LinkedList<T>& first, LinkedList<T>& second)
{
	first.swap(second);
}