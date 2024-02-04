/*Ex 2-5/6: your body mass index (BMI) is your weight, w, in kilograms divided by the square of your height, h, in meters (w/(h*h)). Write a program to calculate the BMI from a weight entered in pounds and a height entered in feet and inches. A kilogram is 2.2 pounds, and a foot is 0.3048 meters. Knowing your BMI with a precision higher than one decimal digit after the decimal point is pointless. adjust the program in exercise 2-6 accordingly.*/

import std;

int main()
{
	const double metersPerFoot{ 0.3048f };
	const double poundsPerKg{ 2.2f };
	const double inchesPerFoot{ 12.0f };
	double weightPounds{ 0 };
	double heightFeet{ 0 };
	double heightInches{ 0 };

	// BMI = weight(kg) / (height in m.) sq
	std::print("Enter your weight in lbs: ");
	std::cin >> weightPounds;
	std::print("Enter your height in feet inches: ");
	std::cin >> heightFeet >> heightInches;

	const double BMIResult = (weightPounds / poundsPerKg) / std::pow((heightFeet + (heightInches / inchesPerFoot)) * metersPerFoot, 2);
	std::println("Your BMI is: {:.1f} kg per square meter.", BMIResult);

	return 0;

}


