/*Ex 2-3: Write a program that will compute the area of a circle. the program should prompt the radius of the circle to be entered from the keyboard. Calculate the area using the formula area = pi * radius * radius, and then display the result. */

import std;

int main()
{
	float inputRadius{ 0 };
	std::print("Please enter radius (cm): ");
	std::cin  >> inputRadius;

	std::println("Area of circle: {:.2f} cm squared.", std::numbers::pi * std::pow(inputRadius, 2));

	return 0;

}


