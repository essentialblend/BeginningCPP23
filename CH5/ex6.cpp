/*Ex 5-6: Create a vector<> container with elements containing the integers from 1 to an arbitrary upper bound entered by the user. Output the elements from the vector that contain values that are not multiples of 7 or 13. Output them ten on a line, aligned in columns.*/

import std;

int main()
{
	std::vector<int> userArray{};
	std::vector<int> outputArray{};

	int userChoice{};
	int numElementsPerColumn{ 10 };
	int numElementsPerRow{};

	std::print("Enter an arbitrary integral upper bound for our vec: ");
	std::cin >> userChoice;

	for (std::size_t i{ 0 }; i < userChoice; ++i)
	{
		userArray.push_back(static_cast<int>(i + 1));
	}

	for (auto x : userArray)
	{
		if (x % 7 == 0 || x % 13 == 0)
		{
			continue;
		}

		outputArray.push_back(x);
	}

	numElementsPerRow = outputArray.size() / 10;
	int count{ 0 };
	std::cout << std::endl;
	for (int i{}; i < (numElementsPerColumn - 1); i++)
	{
		for (int j{}; j < (numElementsPerRow - 1), count < (outputArray.size() - 1); j++)
		{
			std::print("| {:^5} |", outputArray[count]);
			count += 9;
		}
		count = i + 1;
		std::cout << std::endl;
	}

	return 0;
}