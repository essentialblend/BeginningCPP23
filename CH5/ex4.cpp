/*Ex 5-4: Use std::cin.getline(...) to obtain a C-style string of a maximum of 1,000 characters from the user. Count the number of characters the user entered using an appropriate loop. Next, write a second loop that prints out all characters, one by one, but in reverse order.*/

import std;

int main()
{
	const std::size_t arraySize{ 1000 };
	char userInput[arraySize]{};
	int charCount{}, totalCount{};
	
	std::print("Enter a max. 1000 ch. sentence: ");
	std::cin.getline(userInput, arraySize);
	std::cout << std::endl;

	for (auto x : userInput)
	{
		totalCount++;

		if (x == '\0')
		{
			break;
		}

		if (x == ' ') continue;

		charCount++;
	}

	std::println("The total number of chars excluding whitespaces: {}", charCount);
	std::print("Characters entered, displayed in reverse:");

	for (std::size_t i{ static_cast<std::size_t>(totalCount - 1) }; i > 0; --i)
	{
		if (i == 1)
		{
			std::print("{} ", userInput[i]);
			std::print("{} ", userInput[i - 1]);
		}
		else if (i > 0)
		{
			std::print("{} ", userInput[i]);
		}
	}

	return 0;
}