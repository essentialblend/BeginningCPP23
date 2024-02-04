/*Ex 2-2: Create a program that converts a person’s weight from SI to imperial units. Concretely, ask users for their (potentially nonintegral) weight in kilograms and output how much they weigh in stones and pounds. the number of pounds should be given as an integral value.
Can you think of at least two ways to accomplish this? If you’re unfamiliar with the SI and/or imperial units, 1 stone equals 14 pounds, and 1 pound equals 0.45359237 kg.*/

import std;

int main()
{
	const double kgPerPound{ 0.45359237 };
	const int poundsPerStone { 14 };

	float userWeightKilos{ 0 };

	std::println("--SI to stones and pounds Weight Converter--");
	std::print("Enter your weight(in kilograms): ");
	std::cin >> userWeightKilos;
	
	const double userWeightStone{ std::floor((userWeightKilos / kgPerPound) / poundsPerStone)};
	const double remainingPounds{ std::fmod((userWeightKilos / kgPerPound), poundsPerStone) };

	std::println("Converted weight: {} stones and {:.0f} pounds.", userWeightStone, remainingPounds);
	return 0;

}


