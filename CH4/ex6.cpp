/*Ex 4-5: Write a program that determines, using only the conditional operator, if an integer that is entered has a value that is 20 or less, is greater than 20 but not greater than 30, is greater than 30 but not exceeding 100, or is greater than 100.*/

import std;

int main()
{
	int userInput{};

	std::print("Enter an integer (floating-point input will be truncated): ");
	std::cin >> userInput;
	std::string outputString;

	userInput <= 20 ? outputString = "is less than or equal to 20..." : ((userInput > 20 && userInput <= 30) ? outputString = "is greater than 20 and less than 30..." : ((userInput > 30 && userInput <= 100) ? outputString = "is greater than 30 and less than 100..." : outputString = "is greater than 100..."));

	std::println("\n{} {}", userInput, outputString);

	return 0;
}