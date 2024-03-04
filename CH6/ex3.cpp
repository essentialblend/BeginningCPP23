/*Ex 6-3: Write a program that reads an array size from the keyboard and dynamically allocates an array of that size to hold floating-point values. Using pointer notation, initialize all the elements of the array so that the value of the element at index position n is 1 / (n + 1)2. Calculate the sum of the elements using array notation, multiply the sum by 6, and output the square root of that result. 

Test the program with more than 100,000 elements. do you notice anything interesting about the result? 

Note: If the interesting result you see is infinity (printed by std::println() as "inf"): don’t worry, it happens to the best of us (yours truly included). While perhaps not the interesting result that we were aiming for, this type of bug is a very interesting learning opportunity in its own right. In fact, try to figure out what went wrong without reading the upcoming tip.

Note: Even if your result is not infinity (congratulations, btw!), maybe it’s still worth thinking where and how it could’ve gone wrong? Tip: start by asking yourself: What elementary mathematical operation is often said to lead to infinity? And then: What computational limitation of integer numbers could lead to that situation in this particular case?

*/

/*Ex 6-4, 6-5, 6-6 simply relate to replacing raw with smart pointers or dynamic containers.*/


import std;

int main()
{
	int arraySize{};
	double accumVal{};

	std::print("Enter an integral array size: ");
	std::cin >> arraySize;

	// Raw pointers (legacy).
	double* fpArray{ new double[arraySize] {} };

	// Smart pointers.
	// std::unique_ptr<std::vector<double>> fpArray = std::make_unique<std::vector<double>>(arraySize);

	for (int i{ 0 }; i < arraySize; i++)
	{
		double valStored{ (1 / (2 * static_cast<double>(i + 1))) };

		fpArray[i] = valStored;
		accumVal += valStored;
	}

	accumVal = std::sqrt(accumVal * 6);

	std::println("Array from 1 to {}:", arraySize);
	for (int i{}; i < arraySize; i++)
	{
		if (i % 5 == 0)
		{
			std::println("");
		}

		std::print("{:^10.3f}", fpArray[i]);
	}

	std::println("\n\nThe sqrt of the (sum * 6): {}", accumVal);


	delete[] fpArray;
	fpArray = nullptr;

	return 0;
}