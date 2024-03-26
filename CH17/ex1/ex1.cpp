/*Ex 17-1: The Array<> template of Ex17_01 is in many ways similar to std::vector<>. One obvious shortcoming is that the size of an Array<T> needs to be fixed at construction time. Let’s remedy that and add a push_back() member function that inserts a single element of type T after all existing elements. to keep things simple, your version of push_back() could allocate a new, larger array to hold size + 1 elements each time it is invoked. Also, make sure an (empty) Array<> can be default-constructed. Write a small program to exercise the new functionality. 
  
  Extra: It shouldn’t be hard to make push_back() strongly exception-safe. that is, if any operation during push_back() should go wrong and throw an exception, make sure that no memory is leaked and the original Array<> is left as is, discarding the new element.*/

import trial_array;
import std;

// Construct an Array<> of a given size, filled with some arbitrary string data
Array<std::string> buildStringArray(const std::size_t size)
{
	Array<std::string> result{ size };
	for (std::size_t i{}; i < size; ++i)
		result[i] = "You should learn from your competitor, but never copy. Copy and you die.";
	return result;
}

int main()
{
	const std::size_t numArrays{ 10 }; // Fill 10 Arrays with 1,000 strings each
	
	const std::size_t numStringsPerArray{ 1'000 };
	
	std::vector<Array<std::string>> vectorOfArrays;
	
	vectorOfArrays.reserve(numArrays); // Inform the vector<> how many Arrays we'll be adding
	
	for (std::size_t i{}; i < numArrays; ++i)
	{
		vectorOfArrays.push_back(buildStringArray(numStringsPerArray));
	}
}
