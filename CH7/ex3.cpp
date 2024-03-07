/*Ex 7-3: Write a program that reads a text string of arbitrary length from the keyboard and prompts for entry of a word that is to be found in the string. The program should find and replace all occurrences of this word, regardless of case, by as many asterisks as there are characters in the word. it should then output the new string. only whole words are to be replaced. For example, if the string is "Our house is at your disposal." and the word that is to be found is "our", then the resultant string should be as follows: "*** house is at your disposal." and not "*** house is at y*** disposal.". */

import std;

int main()
{
	std::string inputString{};
	std::string sepStr{ " ,;:.\"!?'\n" };
	std::string replacementChar{ "*" };
	std::string repWord{};

	std::print("Enter a sentence terminated by \".\": ");
	std::getline(std::cin, inputString);

	if (inputString.empty())
	{
		std::println("Empty input. Try again...");
		return 0;
	}
	
	std::print("Enter a word to be replaced with *: ");
	std::cin >> repWord;
	
	auto startIndex{ inputString.find_first_not_of(sepStr) };
	
	while (startIndex != std::string::npos)
	{
		auto endIndex{ inputString.find_first_of(sepStr, startIndex) };
		std::string currWord{ inputString.substr(startIndex, endIndex - startIndex) };
		if (currWord == repWord)
		{
			std::string repStr{};
			for (int i{}; i < currWord.length(); i++)
			{
				repStr.append(replacementChar);
			}
			inputString.replace(startIndex, endIndex - startIndex, repStr);
		}
		startIndex = inputString.find_first_not_of(sepStr, endIndex + 1);
	}
	std::print("{}", inputString);

	return 0;
}