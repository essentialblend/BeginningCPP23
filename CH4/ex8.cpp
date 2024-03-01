/*Ex 4-8: Create a program that prompts the user to enter an amount of money between $0 and $10 (decimal places allowed). Any other value is to be rejected politely. Determine how many quarters (25c), dimes (10c), nickels (5c), and pennies (1c) are needed to make up that amount. For our non-american readers, one dollar ($) equals 100 cents (c). Output this information to the screen and ensure that the output makes grammatical sense (for example, if you need only one dime, then the output should be “1 dime” and not “1 dimes”). Naturally, the goal is to pay with as few coins as possible.*/

import std;

int main()
{
	double userInput{ 0 };

	std::print("Enter an amount of money between USD 0 and 10: ");
	std::cin >> userInput;

	if (userInput < 0 || userInput > 10)
	{
		std::println("\nInvalid input. Please try again, and enter a value between 0 and 10...");
		return 0;
	}

	int numCents = static_cast<int>(userInput * 100.f);
	
	int numQuarters = numCents / 25;

	int centsAfterAllocQuarters = numCents - (numQuarters * 25);

	int numDimes = centsAfterAllocQuarters / 10;

	int centsAfterAllocDimes = centsAfterAllocQuarters - (numDimes * 10);

	int numNickels = static_cast<int>(centsAfterAllocDimes / 5.f);

	int centsAfterAllocNickels = centsAfterAllocDimes - (numNickels * 5);

	int numPennies = centsAfterAllocNickels;

	double sanityCheckTotal{ (((25 * numQuarters) + (10 * numDimes) + (5 * numNickels) + (1 * numPennies)) / 100.f) };

	std::string quarterString{ numQuarters <= 1 ? (numQuarters == 1 ? "one quarter" : "no quarters") : (std::to_string(numQuarters) + " quarters") };
	std::string dimeString{ numDimes <= 1 ? (numDimes == 1 ? "one dime" : "no dimes") : (std::to_string(numDimes) + " dimes") };
	std::string nickelString{ numNickels <= 1 ? (numNickels == 1 ? "one nickel" : "no nickels") : (std::to_string(numNickels) + " nickels") };
	std::string pennyString{ numPennies <= 1 ? (numPennies == 1 ? "one penny" : "no pennies") : (std::to_string(numPennies) + " pennies") };

	std::println("You requested change for ${}.\n", userInput);
	std::println("We give you back {}, {}, {}, and {}...", quarterString, dimeString, nickelString, pennyString);
	std::println("\nTo conclude, the returned change per your request was distributed as follows: (25 * {}) + (10 * {}) + (5 * {}) + (1 * {}): ${:.2f} ", numQuarters, numDimes, numNickels, numPennies, sanityCheckTotal);

	return 0;
}