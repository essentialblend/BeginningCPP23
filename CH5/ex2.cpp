/*Ex 5-2:  Write a program that uses a while loop to accumulate the sum of an arbitrary number of integers entered by the user. After every iteration, ask the user whether they are done entering numbers. The program should output the total of all the values and the overall average as a floating-point value.*/

import std;

int main()
{
	std::vector<int> sumArray{};
	int userInput{};
	bool isInputComplete{ false };
	char repeatDecisionYN{};
	float averageValue{};

	while (!isInputComplete)
	{
		std::print("\nEnter an arbitrary integer: ");
		std::cin >> userInput;
		sumArray.push_back(userInput);

		std::print("Would you like to enter another number (y/n)?...");
		std::cin >> repeatDecisionYN;
		repeatDecisionYN == 'y' ? isInputComplete = false : isInputComplete = true;
	}

	for (auto x : sumArray)
	{
		averageValue += x;
	}

	std::println("\nThe average of all your inputs is: {}", averageValue / sumArray.size());

	return 0;
}