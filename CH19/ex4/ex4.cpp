/*Ex 19-4: Create a generic function that collects all elements of a vector<T> that satisfy a given unary callback function. this callback function accepts a T value and returns a Boolean value that indicates whether the element should be part of the function’s output. the resulting elements are to be collected and returned in another vector. use this higher-order function to gather all numbers greater than a user-provided value from a sequence of integers, all capital letters from a sequence of characters, and all palindromes from a sequence of strings. a palindrome is a string that reads the same backward and forward (for example, "racecar", "noon", or "kayak").*/

import std;

template<typename T, typename FilterFunctor>
std::vector<T> filterElements(const std::vector<T>& values, FilterFunctor funcObj)
{
	std::vector<T> resultV{};

	for (auto& val : values)
	{
		if (funcObj(val))
		{
			resultV.push_back(val);
		}
	}

	return resultV;
}

int main()
{
	const std::vector numList{ -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5 };
	int userInput{};

	std::print("Enter a threshold: ");
	std::cin >> userInput;

	const auto filteredNumbers{ filterElements(numList, [userInput](int i) { return i > userInput; }) };

	const std::vector letters{ 'C', 'd', 'a', 'z', 't', 'S', 'p', 'm', 'D', 'f' };
	const auto filteredUpperCaseChars{ filterElements(letters,[](char c) { return std::isupper(c); }) };

	return 0;
}