/*Ex 3-1: Create a program that prompts for the input of an integer and stores it as an int. Invert all the bits in the value and store the result. output the original value, the value with the bits inverted, and the inverted value plus 1, each in hexadecimal representation and on one line. On the next line, output the same numbers in decimal representation. these two lines should be formatted such that they look like a table where the values in the same column are right aligned in a suitable field width. all hexadecimal values should have leading zeros so eight hexadecimal digits always appear.*/

import std;


int main()
{
	int userInput{ 0 };

	std::print("Enter a positive integer: ");
	std::cin >> userInput;

	// Incomplete. Unsure about how to print hex with leading zeros while sticking within the scope of only hitherto convered concepts.
	std::println("|{:>8x}|{:>8x}|{:>8x}|", userInput, ~userInput, (~userInput + 1));

	return 0;
}

