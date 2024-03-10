/*Ex 11-1: one of the larger programs you have seen thus far is that of Ex8_17.cpp. extract all its functions and put them in a single - file words module, with all functions part of a words namespace.The module should only export those functions that are relevant to the main() function, which, for the most part, should be kept as is.All other functions, and especially the ternary overload of sort(), exist solely to support these exported functions.*/

import std;

import words;

int main()
{	
	std::string inputText; 
	
	const auto separatorStr{ " ,.!?\"\n" };
	
	std::print("Enter a string terminated by '.':");
	getline(std::cin, inputText, '*');
	
	Words words{ words::extractWords(inputText, separatorStr) };

	if (words.empty())
	{
		std::println("No words in text.");
		return 0;
	}
	
	words::sortWords(words); 
	words::printWords(words); 

	return 0;
}




