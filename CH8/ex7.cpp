/*Ex 8-7: the so-called fibonacci function is popular among lecturers in computer science and mathematics for introducing recursion. this function has to compute the nth number from the famous fibonacci sequence, named after italian mathematician Leonardo of pisa, known also as fibonacci. this sequence of positive integer numbers is characterized by the fact that every number after the first two is the sum of the two preceding ones. for n ≥ 1, the sequence is defined as follows: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597,
2584, 4181... for convenience, computer scientists mostly define an additional zeroth fibonacci number as zero. 

Write a function to compute the nth fibonacci number recursively. test it with a simple program that prompts the user for how many numbers should be computed and then prints them out one by one, each on a different line.*/

import std;

static void computeFib(unsigned long long first, unsigned long long penultimate, unsigned long long ultimate, std::vector<unsigned long long>& masterList, int limitFib);

int main()
{
	int firstFib{ 1 };
	std::vector<unsigned long long> masterFibList;
	int limitFib{ 93 };

	masterFibList.push_back(firstFib);
	computeFib(0, firstFib, 0, masterFibList, limitFib);

	for (auto& x : masterFibList)
	{
		std::println("{}", x);
	}

	return 0;
}

static void computeFib(unsigned long long first, unsigned long long penultimate, unsigned long long ultimate, std::vector<unsigned long long>& masterList, int limitFib)
{
	if (masterList.size() == limitFib) return;
	ultimate = first + penultimate;
	masterList.push_back(ultimate);
	return computeFib(penultimate, ultimate, ultimate, masterList, limitFib);
}