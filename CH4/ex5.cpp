/*Ex 4-5: Add some code to the end of the main() function of Ex4_07.cpp to print an additional message. If you have exactly one mouse, output a message of the form “It is a brown / white mouse.” Otherwise, if you have multiple mice, compose a grammatically correct message of the form “of these mice, n is a / are brown mouse / mice.” If you have no mice, no new message needs to be printed. Use an appropriate mixture of conditional operators and if / else statements.*/

import std;

int main()
{
	int totalMiceCount{};
	int brownMiceCount{};
	int whiteMiceCount{}; 
	
	std::print("How many brown mice do you have? ");
	std::cin >> brownMiceCount;
	
	std::print("How many white mice do you have? ");
	std::cin >> whiteMiceCount;
	
	totalMiceCount = brownMiceCount + whiteMiceCount;
	
	std::println("\nYou have {} {} in total.", totalMiceCount, totalMiceCount == 1 ? "mouse" : "mice");

	if (totalMiceCount == 1)
	{
		std::println("\nIt is a brown / white mouse...");
	}
	else if (totalMiceCount > 1)
	{
		std::println("\nOf the total {} mice, there {} {} brown {}, and {} white {}...", totalMiceCount, (brownMiceCount < 2 ? "is" : "are"), brownMiceCount, (brownMiceCount < 2 ? "mouse" : "mice"), whiteMiceCount, (whiteMiceCount < 2 ? "mouse" : "mice"));
	}

	return 0;
}