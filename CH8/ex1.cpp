/*Ex 8-1: Write a function, validate_input(), that accepts two integer arguments that represent the upper and lower limits for an integer that is to be entered. It should accept a third argument that is a string describing the input, with the string being used in the prompt for input to be entered. The function should prompt for input of the value within the range specified by the first two arguments and include the string identifying the type of value to be entered.

The function should check the input and continue to prompt for input until the value entered by the user is valid. Use the validate_input() function in a program that obtains a user’s date of birth and outputs it in the form of this example: 

You were born on the 21st of November, 2012. 

The program should be implemented so that separate functions, month(), year(), and day(), manage the input of the corresponding numerical values. Don’t forget leap years—february 29, 2023, is not allowed! */

import std;

int validateInput(int lower, int upper, const std::string& descStr);
int inputYear();
int inputMonth();
int inputDay(int month, int year);
std::string endingStr(int dateDay);

int main()
{
	std::println("Enter a DOB: ");
	int dateMonth{ inputMonth() };
	int dateYear{ inputYear() };
	int dateDay{ inputDay(dateMonth, dateYear) };

	std::string monthsList[]{ "January", "February", "March", "April", "May", "June", "July",
						 "August", "September", "October", "November", "December" };

	std::println("\nYou were born on the {} of {}, {}.",
		std::to_string(dateDay) + endingStr(dateDay),
		monthsList[dateMonth - 1],
		dateYear);

	return 0;
}

int validateInput(int lower, int upper, const std::string& descStr)
{
	int data{};

	std::println("Please enter {} from {} to {}: ", descStr, lower, upper);
	std::cin >> data;

	while (data < lower || data > upper)
	{
		std::print("Invalid input, please re-enter {}: ", descStr);
		std::cin >> data;
	}
	return data;
}

int inputYear()
{
	const int lM{ 1900 };
	const int uM{ 2024 };
	return validateInput(lM, uM, "a year (1900-2024)");
}

int inputMonth()
{
	const int lM{ 1 };
	const int uM{ 12 };
	return validateInput(lM, uM, "a month (1-12)");
}

int inputDay(int month, int year)
{
	const int feb{ 2 };
	const int dateMin{ 1 };
	const int dateMax[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month == feb && year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0))
		return validateInput(dateMin, 29, "a day of the month");
	else
		return validateInput(dateMin, dateMax[month - 1], "a day of the month");
}

std::string endingStr(int dateDay)
{
	switch (dateDay)
	{
	case 1: case 21: case 31:
		return "st";
	case 2: case 22:
		return "nd";
	case 3: case 23:
		return "rd";
	default:
		return "th";
	}
}