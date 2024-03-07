/*Ex 7-2: Write a program that reads text entered over an arbitrary number of lines. Find and record each unique word that appears in the text and record the number of occurrences of each word. output the words and their occurrence counts. Words and counts should align in columns. The words should align to the left; the counts to the right. There should be three words per row in your table.
*/

import std;

int main()
{
	std::string inputString{};
	std::string sepStr{ " ,;:.\"!?'\n" };

	std::unordered_map<std::string, int> finalMap{};

	std::print("Enter a sentence terminated by \".\": ");
	std::getline(std::cin, inputString);
	
	if (inputString.empty())
	{
		std::println("Empty input. Try again...");
		return 0;
	}

	auto firstOcc{ inputString.find_first_not_of(sepStr) };

	while (firstOcc != std::string::npos)
	{
		auto endOcc{ inputString.find_first_of(sepStr, firstOcc + 1) };
		if (endOcc == std::string::npos)
		{
			endOcc = inputString.length();
		}
		auto word{ inputString.substr(firstOcc, endOcc - firstOcc) };
		std::transform(word.begin(), word.end(), word.begin(), [](char c) { return std::tolower(c); });
		auto searchIter{ finalMap.find(word) };

		if (searchIter != finalMap.end())
		{
			searchIter->second += 1;
		}
		else
		{
			finalMap.insert(std::pair(word, 1));
		}
		
		firstOcc = inputString.find_first_not_of(sepStr, endOcc + 1);
	}

	std::println("Your sentence contained {} unique words...\n", finalMap.size());
	int count{};
	int varsPerLine{ 3 };
	for (auto& word : finalMap)
	{
		if (count % varsPerLine == 0) std::println("");

		std::print("{:<15} {:>3} | ", word.first + ":", word.second);
		count++;
	}

	return 0;
}