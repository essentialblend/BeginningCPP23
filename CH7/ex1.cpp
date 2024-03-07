/*Ex 7-1: Write a program that reads and stores the first names of any number of students, along with their grades. Calculate and output the average grade and output the names and grades of all the students in a table with the name and grade for three students on each line.

*/

import std;

int main()
{
	std::vector<std::string> firstNames{};
	std::vector<double> gradeOf100{};
	bool isInputRemaining{ true };
	std::string firstName{};
	double grade{};
	char userChoice{};

	do
	{ 
		std::print("Enter a first name followed by their grade of 100 (Siddharth 50): ");
		std::cin >> firstName >> grade;
		
		// Skipping input validation for conciseness.
		
		firstNames.push_back(firstName);
		gradeOf100.push_back(grade);

		std::print("Do you wish to enter another record (y/n): ");
		std::cin >> userChoice;

		if (userChoice == 'y')
			isInputRemaining = true;
			else
			isInputRemaining = false;
 
	} while (isInputRemaining);
	
	grade = 0;
	
	for (double& singleGrade : gradeOf100)
	{
		grade += singleGrade;
	}

	grade = grade / gradeOf100.size();

	std::println("\nYou entered {} entries. The average grade is {}...", firstNames.size(), grade);
	std::println("");
	for (int i{}; i < firstNames.size(); i++)
	{
		if (i % 3 == 0) std::println("");
		std::print("| {:^}: {:^.2f} ", firstNames[i], gradeOf100[i]);
	}

	return 0;
}