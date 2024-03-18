/*Ex 17-1: The Array<> template of Ex17_01 is in many ways similar to std::vector<>. One obvious shortcoming is that the size of an Array<T> needs to be fixed at construction time. Let’s remedy that and add a push_back() member function that inserts a single element of type T after all existing elements. to keep things simple, your version of push_back() could allocate a new, larger array to hold size + 1 elements each time it is invoked. Also, make sure an (empty) Array<> can be default-constructed. Write a small program to exercise the new functionality. 
  
  Extra: It shouldn’t be hard to make push_back() strongly exception-safe. that is, if any operation during push_back() should go wrong and throw an exception, make sure that no memory is leaked and the original Array<> is left as is, discarding the new element.*/

import trial_array;

int main()
{
	// With init size.
	Array<int> arrayTrial{ 4 };
	// With 0 elem.
	Array<double> arrayDoubleTrial;

	for (std::size_t i{}; i < 5; i++)
	{
		arrayDoubleTrial.pushBack(i * 5);
	}
	

	for (std::size_t i{}; i < arrayDoubleTrial.getSize(); i++)
	{
		std::println("{}", arrayDoubleTrial[i]);
	}
}