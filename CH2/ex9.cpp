/*Ex 2-9: Here’s an extra exercise for puzzle fans. Write a program that prompts the user to enter two different positive integers and then prints out the value of the larger integer first, followed by that of the smaller one. using the decision-making facilities from Chapter 5 would be like stealing a piece of cake from a baby while walking in the park. What makes this a tough brain teaser is that you can do this solely with the operators you’ve learned about in this chapter! */

import std;

int main()
{
	short unsigned int userNum1{ 0 };
	short unsigned int userNum2{ 0 };

	std::print("Enter two positive integers: ");
	std::cin >> userNum1 >> userNum2;

	short unsigned int largerNum = (userNum1 * (userNum1 / userNum2)) + (userNum2 * (userNum2 / userNum1)) / ((userNum1 / userNum2) + (userNum2 / userNum1));
	short unsigned int smallerNum = (userNum2 * (userNum1 / userNum2)) + (userNum1 * (userNum2 / userNum1)) / ((userNum1 / userNum2) + (userNum2 / userNum1));

	std::println("The larger number is {}, and the smaller number is {}.", largerNum, smallerNum);

	return 0;
}