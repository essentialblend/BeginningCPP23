/*Ex 4-1: Write a program that prompts for two ints to be entered and then uses an if-else statement to output a message that states whether they're the same.*/

import std;

int main()
{
	int numOne{ 0 }, numTwo{ 0 };
	
	std::print("Please enter two integers: ");
	std::cin >> numOne >> numTwo;
	std::strong_ordering orderingEnum{ numOne <=> numTwo };
	
	if (std::is_eq(orderingEnum))
	{
		std::println("Numbers {} and {} are equal!", numOne, numTwo);
	}
	else
	{
		std::println("Numbers {} and {} are not equal!", numOne, numTwo);
	}

	return 0;
}

