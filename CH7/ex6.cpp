/*Ex 7-6: Write a program that reads a text string of arbitrary length from the keyboard followed by a string containing one or more letters. Output a list of all the whole words in the text that begin with any of the letters, uppercase or lowercase.*/

/* 7-7, 7-8, 7-9 WIP, pure boredom. */

import std;

int main()
{
	std::string inputString{};
	std::string sepStr{ " ,;:.\"!?'\n" };
	std::string replacementChar{ "*" };
	std::string lettersStr{};

	std::vector<std::string> finalArr{};

	std::print("Enter a sentence terminated by \".\": ");
	std::getline(std::cin, inputString, '.');

	if (inputString.empty())
	{
		std::println("Empty input. Try again...");
		return 0;
	}

	std::print("Enter a non-empty non-case sensitive string containing letters (e.g. asdf ): ");
	std::cin >> lettersStr;

	auto seekIter{ inputString.find_first_not_of(sepStr) };

	while (seekIter != std::string::npos)
	{
		auto nextIter{ inputString.find_first_of(sepStr, seekIter) };

		if (nextIter == std::string::npos)
		{
			nextIter = inputString.length();
		}

		auto wordLength{ nextIter - seekIter };
		std::string currWord{ inputString.substr(seekIter, wordLength) };

		std::string tempW{ currWord };
		std::transform(tempW.begin(), tempW.end(), tempW.begin(), [](char c) {return std::tolower(c); });

		std::string tempSort{ lettersStr };
		std::transform(tempSort.begin(), tempSort.end(), tempSort.begin(), [](char c) {return std::tolower(c); });
		auto finalIter{ tempW.find_first_of(tempSort, 0) };
	
		if (finalIter == 0)
		{
			auto arrayIter{ std::find(finalArr.begin(), finalArr.end(), currWord) };

			if (arrayIter == finalArr.end())
			{
				finalArr.push_back(currWord);
			}
		}

		seekIter = inputString.find_first_not_of(sepStr, nextIter + 1);
	}

	std::println("\nAll words parsed using the separators string: ");
	int count{};
	
	for (auto& word : finalArr)
	{
		if (count % 3 == 0) std::println("");
		std::print("| {} | ", word);
		count++;
	}

	return 0;
}