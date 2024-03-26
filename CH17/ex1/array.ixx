export module trial_array;

import std;

export template<typename T>
class Array
{
public:
	explicit Array<T>(std::size_t arrSize = 0); // Constructor.
	Array<T>(const Array<T>& arr); // Copy constructor.
	Array<T>(Array<T>&& movedArr); // Move constructor.
	
	Array<T>& operator=(const Array<T>& rhs_arr); // Assignment operator.
	const T& operator[](std::size_t index) const; // Const subscript operator.
	T& operator[](std::size_t index); // Non-const subscript operator.
	
	std::size_t getSize() const noexcept; // Getter.
	void swapObjects(Array<T>& second) noexcept; // Member-swap.

	void pushBack(const T& valToPush);


	~Array<T>(); // Destructor.

private:
	T* memArrElements{ nullptr };
	std::size_t memArrSize{};
};

// Member functions.

template<typename T>
Array<T>::Array(std::size_t arrSize) : memArrElements{ new T[arrSize] {} }, memArrSize{ arrSize } 
{}

template<typename T>
Array<T>::Array(const Array& arr) : Array(arr.memArrSize)
{
	std::println("Array of {} elements copied", memArrSize);

	for (std::size_t i{}; i < memArrSize; ++i)
	{
		memArrElements[i] = arr.memArrElements[i];
	}
}

template<typename T>
Array<T>::Array(Array&& movedArr) : memArrSize(movedArr.memArrSize), memArrElements(movedArr.memArrElements)
{
	std::println("Array of {} elements moved", movedArr.memArrSize);
	movedArr.memArrElements = nullptr;

}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs_arr)
{
	Array<T> copy{ rhs_arr };

	swapObjects(copy);

	return *this;
}

template<typename T>
const T& Array<T>::operator[](std::size_t index) const
{
	if (index >= memArrSize)
	{
		throw std::out_of_range{ "Index too large: " + std::to_string(index) };
	}
	return memArrElements[index];
}

template<typename T>
T& Array<T>::operator[](std::size_t index)
{
	return const_cast<T&>(std::as_const(*this)[index]);
}

template<typename T>
std::size_t Array<T>::getSize() const noexcept
{
	return memArrSize;
}

template<typename T>
void Array<T>::swapObjects(Array<T>& second) noexcept
{
	std::swap(memArrElements, second.memArrElements);
	std::swap(memArrSize, second.memArrSize);
}

// Non-member Array<T> swap.
template<typename T>
void swapObjects(Array<T>& first, Array<T>& second) noexcept
{
	first.swapObjects(second);
}

template<typename T>
void Array<T>::pushBack(const T& valToPush)
{
	Array<T> copyArr{ memArrSize + 1 };

	for (std::size_t i{}; i < memArrSize; i++)
	{
		copyArr[i] = memArrElements[i];
	}

	copyArr[memArrSize] = valToPush;

	swapObjects(copyArr);
}

template <typename T>
Array<T>::~Array() { delete[] memArrElements; }
