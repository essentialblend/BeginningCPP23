/*Ex 3-5: We’ll conclude with one more exercise for puzzle fans (and exclusively so). Write a program that prompts for two integer values to be entered and store them in integer variables, a and b, say. Swap the values of a and b without using a third variable. output the values of a and b. 
Hint: This is a particularly tough nut to crack. to solve this puzzle, you exclusively need one single compound assignment operator.*/

import std;

int main()
{
	unsigned short first{ 0 };
	unsigned short sec{ 0 };
	unsigned int a = 100;

	std::cout << (a << 3) << "\n";

	std::print("Enter two ints for slot A and B: ");
	std::cin >> first >> sec;

	first ^= sec;
	sec ^= first;
	first ^= sec;

	std::println("After swap, A is {} and B is {}.", first, sec);

	return 0;
}

