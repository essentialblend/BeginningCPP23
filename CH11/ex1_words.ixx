export module words;

import std;

export using Words = std::vector<std::shared_ptr<std::string>>;

// Helpers.
namespace words
{
	std::size_t maxWordLength(const Words& words);
	void swapWords(Words& words, std::size_t first, std::size_t second);
	void sortWords(Words& words, std::size_t start, std::size_t end);
}

// Exported.
export namespace words
{

	void sortWords(Words& words);
	Words extractWords(const std::string& text, const std::string& separators);
	void printWords(const Words& words);
}

// Impl.
void words::sortWords(Words & words)
{
	if (!words.empty())
		sortWords(words, 0, words.size() - 1);
}

void words::sortWords(Words & words, std::size_t start, std::size_t end)
{
	if (!(start < end))
		return;

	swapWords(words, start, (start + end) / 2);

	std::size_t current{ start };
	for (std::size_t i{ start + 1 }; i <= end; i++)
	{
		if (*words[i] < *words[start])
			swapWords(words, ++current, i);
	}
	swapWords(words, start, current);
	if (current > start) sortWords(words, start, current - 1);
	if (end > current + 1) sortWords(words, current + 1, end);
}

Words words::extractWords(const std::string & text, const std::string & separators)
{
	Words words;
	std::size_t start{ text.find_first_not_of(separators) };
	while (start != std::string::npos)
	{
		std::size_t end{ text.find_first_of(separators, start + 1) };
		if (end == std::string::npos)
			end = text.length();
		words.push_back(std::make_shared<std::string>(text.substr(start, end - start)));
		start = text.find_first_not_of(separators, end + 1);
	}
	return words;
}

void words::printWords(const Words& words)
{
	const std::size_t field_width{ maxWordLength(words) + 1 };
	const std::size_t words_per_line{ 8 };
	std::print("{:{}}", *words[0], field_width);
	std::size_t words_in_line{};
	for (std::size_t i{ 1 }; i < words.size(); ++i)
	{
		if ((*words[i])[0] != (*words[i - 1])[0] || ++words_in_line == words_per_line)
		{
			words_in_line = 0;
			std::println("");
		}
		std::print("{:{}}", *words[i], field_width);
	}
	std::println("");
}

std::size_t words::maxWordLength(const Words& words)
{
	std::size_t max{};
	for (auto& pword : words)
		if (max < pword->length()) max = pword->length();

	return max;
}

void words::swapWords(Words& words, std::size_t first, std::size_t second)
{
	auto temp{ words[first] };
	words[first] = words[second];
	words[second] = temp;
}


