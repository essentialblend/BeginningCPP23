/*Ex 3-2: Write a program to calculate how many square boxes can be contained in a single layer on a rectangular shelf with no overhang. The dimensions of the shelf in feet and the dimensions of the side of the box in inches are read from the keyboard. Use variables of type double for the length and depth of the shelf and type int for the length of the side of a box. Define and initialize an integer constant to convert from feet to inches (1 foot equals 12 inches). Calculate the number of boxes that the shelf can hold in a single layer of type long and output the result.*/

import std;


int main()
{
	const int inchesPerFoot{ 12 };

	double shelfLengthFoot{ 0 };
	double shelfBreadthFoot{ 0 };
	int squareBoxSideLengthInches{ 0 };
	long numBoxesResult{ 0 };


	std::print("Enter the length and breadth of the shelf (in foot): ");
	std::cin >> shelfLengthFoot >> shelfBreadthFoot;
	std::print("Enter the square box's length (in inches): ");
	std::cin >> squareBoxSideLengthInches;

	numBoxesResult = static_cast<long>(((shelfLengthFoot * inchesPerFoot) / squareBoxSideLengthInches) * ((shelfBreadthFoot * inchesPerFoot) / squareBoxSideLengthInches));

	std::println("On this shelf, you may store {} boxes without overhang.", std::floor(numBoxesResult));


	return 0;
}

