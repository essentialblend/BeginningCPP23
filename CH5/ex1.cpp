/*Ex 5-1: Write a program that outputs the squares of the odd integers from 1 up to a limit that is entered by the user.*/

import std;

int main()
{
	unsigned int userInput{};

	std::print("Please enter an integer between 1 to 100 (n), and we'll calculate squares of odd integers from 1 to n: ");
	std::cin >> userInput;

	if (userInput <= 0 || userInput > 100)
	{
		std::println("Invalid input, just try again?");
		return 0;
	}


	std::println("| {:^10} | {:^10} |", "num", "num_squared");
	for (std::size_t i{ 1 }, numSquared{ 1 }; i < userInput; i += 2, numSquared = i * i)
	{
		std::println("| {:^10} | {:^11} |", i, numSquared);
	}

	return 0;
}