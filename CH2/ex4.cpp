/*Ex 2-4: For your birthday, you’ve been given a long tape measure and an instrument that measures angles (the angle between the horizontal and a line to the top of a tree, for instance). If you know the distance, d, you are from a tree, and the height, h, of your eye, when peering into your angle-measuring device, you can calculate the height of the tree with the formula h + d*tan(angle). Create a program to read h in inches, d in feet and inches, and angle in degrees from the keyboard, and output the height of the tree in feet. */

import std;
#include <print>


int main()
{
	const double inchesPerFoot{ 12.0 };
	const double piDegrees{ 180.0 };
	
	double eyeHeightInches{ 0 };
	double distFromTreeFeet{ 0 };
	double distFromTreeInches{ 0 };
	double inputAngleDegrees{ 0 };
	double inputAngleRad{ 0 };

	//h
	std::print("Enter your eye-height(inches): ");
	std::cin >> eyeHeightInches;

	//d
	std::print("Enter your distance from tree (feet inches): ");
	std::cin >> distFromTreeFeet >> distFromTreeInches;
	distFromTreeFeet = distFromTreeFeet + (distFromTreeInches / inchesPerFoot);

	//angle
	std::print("Enter the angle of the top of the tree (degrees): ");
	std::cin >> inputAngleDegrees;
	inputAngleRad = inputAngleDegrees * (std::numbers::pi / piDegrees);

	const double resultTreeHeight = (eyeHeightInches / inchesPerFoot) + (distFromTreeFeet * std::tan(inputAngleRad));

	std::println("Height of the tree: {:.2f} feet.", resultTreeHeight);

	return 0;

}


