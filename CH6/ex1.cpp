/*Ex 6-1: Write a program that declares and initializes an array with the first 50 odd (as in not even) numbers. output the numbers from the array ten to a line using pointer notation and then output them in reverse order, also using pointer notation.*/

/*Ex 6-2: Revisit the previous exercise, but instead of accessing the array values using the loop
counter, this time, you should employ pointer increments(using the++ operator) to traverse the
array when outputting it for the first time.After that, use pointer decrements(using--) to traverse
the array again in the reverse direction.*/


import std;

int main()
{
	const int maxSize{ 50 };

	int oddarray[maxSize]{};
	oddarray[0] = 1;

	int* pToOddArray{ oddarray };

	for (std::size_t i{ 1 }; i < maxSize; i++)
	{
		oddarray[i] = oddarray[i - 1] + 2;
	}

	std::println("The numbers in ascending: ");

	for (int i{}; i < maxSize; i++)
	{
		std::print("{:5}", *(pToOddArray++));

		if ((i + 1) % 10 == 0)
			std::println("");
	}

	std::println("The numbers in descending: ");

	for (int i{}; i < maxSize; i++)
	{
		std::print("{:5}", *(--pToOddArray));

		if ((i + 1) % 10 == 0)
			std::println("");
	}


	return 0;
}