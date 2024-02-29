/*Ex 4-2: Write another program that prompts for two integers to be entered. This time, any negative number or zero is to be rejected. Next, check whether one of the (strictly positive) numbers is an exact multiple of the other. For example, 63 is a multiple of 1, 3, 7, 9, 21, or 63. Note that the user should be allowed to enter the numbers in any order. That is, it does not matter whether the user enters the largest number first or the smaller one; both should work correctly!*/

import std;

int main()
{
	int numOne{ 0 }, numTwo{ 0 };
	
	std::print("Please enter two integers: ");
	std::cin >> numOne >> numTwo;
	std::strong_ordering orderingEnum{ numOne <=> numTwo };

	if (numOne <= 0 || numTwo <= 0)
	{
		std::println("One or all inputs were <= 0. Cannot comparitively check for multiples. Try again....");
	}
	else if (std::is_eq(orderingEnum))
	{
		std::println("Numbers {} and {} are equal!", numOne, numTwo);
	}
	else
	{
		int biggerNum{ (numOne < numTwo) ? numTwo : numOne };
		int smallerNum{ (biggerNum > numOne) ? numOne : numTwo };

		std::println("{} is {} multiple of {}!", biggerNum, ((biggerNum % smallerNum == 0) ? "a" : "not a"), smallerNum);
	}

	return 0;
}

