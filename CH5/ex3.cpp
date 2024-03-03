/*Ex 5-3: Create a program that uses a do-while loop to count the number of nonwhitespace characters entered on a line. The count should end when the first # character is found.*/

import std;

int main()
{
	std::vector<char> userArray{};
	char tempChar{};

	int nonWhiteSpaceCount{};

	std::print("Enter a sentence: ");
	while (std::cin.get(tempChar) && tempChar != '\n')
	{
		userArray.push_back(tempChar);
	}

	for (auto letter : userArray)
	{
		if (letter == '#') break;
		if (letter != ' ')
		{
			nonWhiteSpaceCount++;
		}
	}

	std::println("\nNum non white-space chars before encountering the first #: {}", nonWhiteSpaceCount);

	return 0;
}