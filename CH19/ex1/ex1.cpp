/*Ex 19-1: Define and test a lambda expression that returns the number of elements in a vector<string> container that begin with a given letter. The vector is always the same, and should therefore not be passed as a function argument. invoke the lambda function for a couple of letters. */

import std;

int main()
{
	auto stringLetterCounter{ [](std::string_view lStr) { return lStr.length(); } };

	std::string testString{ "SIDDHARTH" };

	std::println("Total number of letters: {}", stringLetterCounter(testString));

	std::println("Three letters: {} {} {}", stringLetterCounter("S"), stringLetterCounter("I"), stringLetterCounter("D"));


	return 0;
}