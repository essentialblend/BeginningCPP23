/*Ex 4-3: Create a program that prompts for input of a number (nonintegral numbers are allowed) between 1 and 100. Use a nested if, first to verify that the number is within this range and then, if it is, to determine whether it is greater than, less than, or equal to 50. The program should output information about what was found.!*/

import std;

int main()
{
	float userInput{};

	std::print("Enter a number between 1 and 100: ");
	std::cin >> userInput;

	if (1 <= userInput && userInput <= 100)
	{
		std::partial_ordering floatOrderEnum{ userInput <=> 50 };

		std::println("Input {} was within the range 1 to 100, and was {} 50.", 
			userInput, 
			(std::is_eq(floatOrderEnum) ? "equal to" : 
			(std::is_lt(floatOrderEnum) ? "less than" : "greater than")));
	}
	else
	{
		std::println("Erroneus/out of bounds input. Try again...");
	}

	return 0;
}

