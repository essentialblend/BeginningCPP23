/*Ex 8-1:Write a function that reads a string or array of characters as input and reverses it. Justify your choice of parameter type? provide a main() function to test your function that prompts for a string of characters, reverses them, and outputs the reversed string. */

import std;

int main()
{
	std::string inpStr{};
	std::string outStr{};

	std::println("Enter a string: ");
	std::getline(std::cin, inpStr, '.');

	for (auto revIt{ inpStr.rbegin() }; revIt != inpStr.rend(); ++revIt)
	{
		outStr.push_back(*revIt);
	}
	
	std::println("String in reverse: {}", outStr);
	
	return 0;
}