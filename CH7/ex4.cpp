/*Ex 7-4:  Write a program that prompts for the input of two words and determines whether one is an anagram of the other. An anagram of a word is formed by rearranging its letters, using each of the original letters precisely once. For instance, listen and silent are anagrams of one another, but listens and silent are not. */

/*Ex 7-5: Generalize the program in exercise 7-4 such that it ignores spaces when deciding whether two strings are anagrams. With this generalized definition, funeral and real fun are considered anagrams, as are eleven plus two and twelve plus one, and desperation and a rope ends it.*/

import std;

static void parseInput(std::string& fP, std::string& sepStr);
static void collectStats(std::string& fP, std::unordered_map<char, int>& lMap);

int main()
{
	// Ex 7-4

	//std::string fW{};
	//std::string sW{};
	//std::unordered_map<char, int> fLetterMap{};
	//std::unordered_map<char, int> sLetterMap{};
	//std::print("Enter two words (e.g: one word): ");
	//std::cin >> fW >> sW;
	//std::transform(fW.begin(), fW.end(), fW.begin(), [](char c) { return std::tolower(c); });
	//std::transform(sW.begin(), sW.end(), sW.begin(), [](char c) { return std::tolower(c); });
	//if ((fW.length() != sW.length()) || fW == sW )
	//{
	//	std::println("Either the words are same, or differ in length. Try again...");
	//	return 0;
	//}
	//for (auto& letter : fW)
	//{
	//	auto seekIter{ fLetterMap.find(letter) };
	//	if (seekIter == fLetterMap.end())
	//	{
	//		fLetterMap.insert(std::pair(letter, 1));
	//	}
	//	else
	//	{
	//		seekIter->second++;
	//	}
	//}
	//for (auto& letter : sW)
	//{
	//	auto seekIter{ sLetterMap.find(letter) };
	//	if (seekIter == sLetterMap.end())
	//	{
	//		sLetterMap.insert(std::pair(letter, 1));
	//	}
	//	else
	//	{
	//		seekIter->second++;
	//	}
	//}
	//for (auto& key : fLetterMap)
	//{
	//	if (key.second != sLetterMap[key.first])
	//	{
	//		std::println("Sadly, it wasn't meant to be an anagram this time...\n");
	//		break;
	//	}
	//}
	//std::println("This time, {} and {} are anagrams...\n", fW, sW);

	// Ex 7-5
	std::string fP{}, sP{};
	std::string sepStr{ " ,;:.\"!?'\n" };
	std::unordered_map<char, int> fLMap{};
	std::unordered_map<char, int> sLMap{};

	std::print("Enter first word or phrase: ");
	std::getline(std::cin, fP);
	std::print("Enter second word or phrase: ");
	std::getline(std::cin, sP);

	if (fP.empty() || sP.empty())
	{
		std::println("Empty input. Try again...");
		return 0;
	}

	parseInput(fP, sepStr);
	parseInput(sP, sepStr);

	std::transform(fP.begin(), fP.end(), fP.begin(), [](char c) { return std::tolower(c); });
	std::transform(sP.begin(), sP.end(), sP.begin(), [](char c) { return std::tolower(c); });

	collectStats(fP, fLMap);
	collectStats(sP, sLMap);

	for (auto& key : fLMap)
	{
		if (key.second != sLMap[key.first])
		{
			std::println("Sadly, it wasn't meant to be an anagram this time...\n");
			break;
		}
	}
	std::println("This time, we have anagrams...\n");

	return 0;
}

static void parseInput(std::string& fP, std::string& sepStr)
{
	auto seekIter{ fP.find_first_of(sepStr) };
	while (seekIter != std::string::npos)
	{
		fP.erase(seekIter, 1);
		seekIter = fP.find_first_of(sepStr, seekIter + 1);
	}
}

static void collectStats(std::string& fP, std::unordered_map<char, int>& lMap)
{
	for (auto& letter : fP)
	{
		auto seekIter{ lMap.find(letter) };
		if (seekIter == lMap.end())
		{
			lMap.insert(std::pair(letter, 1));
		}
		else
		{
			seekIter->second++;
		}
	}
}
