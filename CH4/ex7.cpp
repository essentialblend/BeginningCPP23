/*Ex 4-7:  Implement a program that prompts for the input of a letter. Use a library function to determine whether the letter is a vowel and whether it is lowercase or not, and output the result. Finally, output the lowercase letter together with its character code as a binary value. as a bonus exercise, you could try to do the latter by printing to std::cout without the use of the formatting capabilities of the std::print() or std::format() family of functions.

Hint: even though C++ supports binary integral literals (of the form 0b11001010; see Chapter 2), C++ streams do not support outputting integral values in binary format. Besides the default decimal formatting, they only support hexadecimal and octal formatting (for std::cout, for instance, you can use the std::hex and std::oct output manipulators). so, to stream a character in binary format without the assistance of std::format(), you’ll have to write some code yourself. It shouldn’t be too hard, though; a char only has eight bits, remember? You can stream these bits one by one, even without knowing about loops (see the next chapter). perhaps binary integer literals can also be helpful—why else would we have mentioned them at the start of this hint?*/

import std;

int main()
{
	unsigned char userCharInput{};
	unsigned char lowerCaseInput{};


	std::print("Please enter an alphabet: ");
	std::cin >> userCharInput;

	if (!std::isalpha(userCharInput))
	{
		std::println("Invalid input! Try any letter from this sentence, perhaps...");
		return 0;
	}

	lowerCaseInput = std::tolower(userCharInput);

	std::print("\nThe alphabet entered was '{}'. It is {} letter", static_cast<char>(userCharInput), std::islower(userCharInput) ? "a lowercase" : "an uppercase");

	switch (lowerCaseInput)
	{
		case 'a': case 'e': case 'i': case 'o': case 'u':
			std::print(", and a vowel!\n");
			break;
		default:
			std::print(", and a consonant!\n");
			break;
	}

	std::println("Lowercase conversion: {}\nBinary representation: {:b}", lowerCaseInput, lowerCaseInput);


	return 0;
}