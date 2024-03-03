/*Ex 5-8: The famous Fibonacci series is a sequence of integers with the first two values as 1 and the subsequent values as the sum of the two preceding values. So, it begins 1, 1, 2, 3, 5, 8, 13, and so on. This is not just a mathematical curiosity. The sequence also regularly appears in biological settings, for instance, it relates to the way shells grow in a spiral, and the number of petals on many flowers is a number from this sequence. Create an array<> container with 93 elements. Store the first 93 numbers in the Fibonacci series in the array and then output them one per line. any idea why we’d be asking you to generate 93 Fibonacci numbers and not, say, 100?*/

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
