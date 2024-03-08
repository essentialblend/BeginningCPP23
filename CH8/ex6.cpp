/*Ex 8-6:  implement a program that queries the user for a number of grades. a grade is an integer number between 0 and 100 (both inclusive). the user can stop at any time by entering a negative number. once all grades have been collected, your program is to output the following statistics: the five highest grades, the five lowest grades, the average grade, the median grade, and the standard deviation and variance of the grades. of course, you’re to write a separate function to compute each of these statistics. also, you must write the code to print five values only once. to practice, use arrays to store any five extremes and not, for instance, vectors.

Hint: as a preprocessing step, you should first sort the grades the user enters; you’ll see that this will make writing the functions to compute the statistics much easier. You can adapt the quicksort algorithm from Ex8_17 to work with grade numbers. */

import std;

void enterInputAndSort(bool& isInputRemaining, int& grade, std::vector<double>& gradeArr);
void displayStats(const std::vector<double>& numArr);
const double computeMedian(const std::vector<double>& numArr);
const double computeMean(const std::vector<double>& numArr, int startIndex = 0, int endIndex = 0);
const double computeStdDev(const std::vector<double>& numArr);
const double computeVariance(const std::vector<double>& numArr);


int main()
{
	bool isInputRemaining{ true };
	int grade{};
	std::vector<double> gradeArr{};
	std::println("Enter a grade between 0 and 100, enter a negative number if you wish to stop entering grades...");
	
	enterInputAndSort(isInputRemaining, grade, gradeArr);

	if (gradeArr.size() >= 5)
	{
		std::sort(gradeArr.begin(), gradeArr.end());
		displayStats(gradeArr);
	}
	else
	{
		std::println("Invalid sample size, try again...");
		return 0;
	}

	return 0;
}

void enterInputAndSort(bool& isInputRemaining, int& grade, std::vector<double>& gradeArr)
{
	while (isInputRemaining)
	{
		std::print("Enter a grade: ");
		std::cin >> grade;

		if (grade < 0)
		{
			isInputRemaining = true;
			break;
		}
		gradeArr.push_back(grade);
	}

	
}

void displayStats(const std::vector<double>& numArr)
{
	// Five highest grades.
	std::print("\nThe 5 highest grades are: ");
	for (int i{ static_cast<int>(numArr.size() - 1) }; i > static_cast<int>(numArr.size() - 6); i--)
	{
		std::print("{:3}{} ", numArr[i], (i == static_cast<int>(numArr.size() - 5) ? "." : ","));
	}
	std::println("\n");

	// Five lowest grades.
	std::print("The 5 lowest grades are: ");
	for (int i{ 0 }; i < 5; i++)
	{
		std::print("{:3}{} ", numArr[i], (i == 4 ? "." : ","));
	}
	std::println("\n");

	// Average, median, std dev, and variance.
	std::println("The average(mean) grade is: {:.2f}.", computeMean(numArr, 0, static_cast<int>(numArr.size() - 1)) );
	std::println("\n");
	std::println("The median is: {:.2f}", computeMedian(numArr));
	std::println("\n");

	std::println("The variance is: {:.2f}.", computeVariance(numArr));
	std::println("\n");
	
	std::println("The std dev is: {:.2f}", computeStdDev(numArr));
	std::println("\n");
}

const double computeMedian(const std::vector<double>& numArr)
{
	if (numArr.size() % 2 == 0)
	{
		int getSecond{ static_cast<int>(numArr.size() / 2) };

		return ((numArr[getSecond - 1] + numArr[getSecond]) / 2);
	}
	else
	{
		int median{ static_cast<int>(numArr.size() / 2) };
		return numArr[median];
	}
}

const double computeMean(const std::vector<double>& numArr, int startIndex, int endIndex)
{
	int n = (endIndex - startIndex) + 1;

	double accum{};
	for (int i{ startIndex }; i < (startIndex + n); i++)
	{
		accum += numArr[i];
	}

	return (accum / n);

}

const double computeVariance(const std::vector<double>& numArr)
{
	double meanV{ computeMean(numArr, 0, static_cast<int>(numArr.size() - 1)) };
	double accum{};
	for (auto& x : numArr)
	{
		accum += (x - meanV) * (x - meanV);
	}

	return accum / numArr.size();
}

const double computeStdDev(const std::vector<double>& numArr)
{
	return std::sqrt(computeVariance(numArr));
}