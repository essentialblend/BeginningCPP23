export module dll;

import std;

export template<typename T>
class DLL
{
public:
	void pushFront(T val);
	void pushBack(T val);
	void popFront();
	void popBack();
	void clearList();

	void swap(DLL& other) noexcept;
	std::size_t getSize() const noexcept;

	class Iterator;

	Iterator iterHead() const;
	Iterator iterTail() const;

private:
	class Node
	{
	public:
		Node(const T& data) : nodeData{ data }, prevNode{ nullptr }, nextNode{ nullptr } {}

		Node* prevNode{};
		std::unique_ptr<Node> nextNode{};
		T nodeData{};
	};

	std::unique_ptr<Node> mHead{};
	Node* mTail{};
	std::size_t mSize{};
};

template<typename T>
void DLL<T>::pushFront(T val)
{
	// Copy old head to stack var.
	auto oldHead{ std::move(mHead) };

	// Repoint mHead to a new Node with val.
	mHead = std::make_unique<Node>(std::move_if_noexcept(val));

	mSize++;

	// If oldHead was a proper Node
	if (oldHead)
	{
		// Set mHead's next to point to oldHead. Set oldHead's prev to point to mHead.
		mHead->nextNode = std::move(oldHead);
		mHead->nextNode->prevNode = mHead.get();
	}
	else
	{
		mTail = mHead.get();
	}
}

template<typename T>
void DLL<T>::pushBack(T val)
{
	auto newNode = std::make_unique<Node>(std::move_if_noexcept(val)); // newNode is owned by unique_ptr.

	Node* newTailNode = newNode.get(); // newTailNode is the raw pointer to the new node.

	if (mTail) {
		// If the list is not empty, link the current tail to the new node.
		mTail->nextNode = std::move(newNode); // Transfer ownership to nextNode of the current tail.
		newTailNode->prevNode = mTail; // Link back from the new node to the current tail.
	}
	else {
		// If the list is empty, the new node is also the head.
		mHead = std::move(newNode); // Transfer ownership to mHead.
	}

	// Update mTail to point to the new node.
	mTail = newTailNode;

	// Increment list size.
	++mSize;
}

template<typename T>
void DLL<T>::popFront()
{
	if (!mHead) return;

	auto oldHead{ std::move(mHead) };

	if (oldHead->nextNode)
	{
		mHead = std::move(oldHead->nextNode);
		mHead->prevNode = nullptr;
	}
	else
	{
		mHead = nullptr;
		mTail = nullptr;
	}

	--mSize;
}

template<typename T>
void DLL<T>::popBack()
{
	if (!mHead) return;

	if (mTail->prevNode)
	{
		mTail = mTail->prevNode;
		mTail->nextNode = nullptr;
	}
	else
	{
		mHead = nullptr;
		mTail = nullptr;
	}

	--mSize;
}

template<typename T>
void DLL<T>::clearList()
{
	while (mSize > 0)
	{
		popFront();
	}
}


template<typename T>
class DLL<T>::Iterator
{
public:
	explicit Iterator(Node* node)
		: memCurrNode{ node }
	{}

	const T& value() const { return memCurrNode->nodeData; }
	bool hasValue() const { return memCurrNode != nullptr; }
	operator bool() const { return memCurrNode != nullptr; }

	void next() { memCurrNode = memCurrNode->nextNode.get(); }
	void previous() { memCurrNode = memCurrNode->prevNode; }

private:
	Node* memCurrNode;
};

template<typename T>
void DLL<T>::swap(DLL& other) noexcept
{
	std::swap(mHead, other.mHead);
	std::swap(mTail, other.mTail);
	std::swap(mSize, other.mSize);
}

template<typename T>
std::size_t DLL<T>::getSize() const noexcept
{
	return mSize;
}

template<typename T>
typename DLL<T>::Iterator DLL<T>::iterHead() const
{
	return Iterator{ mHead.get() };
}

template<typename T>
typename DLL<T>::Iterator DLL<T>::iterTail() const
{
	return Iterator{ mTail };
}

template<typename T>
void swap(DLL<T>& first, DLL<T>& sec) noexcept
{
	first.swap(sec);
}

template<typename T>
std::conditional_t<std::is_nothrow_move_assignable_v<T>, T&&, T&> 
move_assign_if_noexcept(T& x) noexcept
{
	return std::move(x);
}

