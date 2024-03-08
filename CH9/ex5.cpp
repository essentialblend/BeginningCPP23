/*Ex 9-5: As promised, write yet another variant of Ex8_09A, Ex8_09B, and Ex8_09C, where this time the average10() function uses one of the vocabulary types seen in this chapter. Show that this one function can be called both for fixed-size C-style arrays and std::array<> containers and only so for arrays of ten elements.*/

/*Ex 9-6: Suppose you have a vector<>, and you know for a fact that it contains exactly ten elements (or at least ten elements). Can you then call the average10() function of the previous example to compute the average of these ten elements (or the ten first elements) Not directly, obviously, but it is possible! After all, all the necessary data (ten consecutive elements) is present in the vector. you may want to consult a standard library reference for this.*/

import std;

double average10(std::span<const double, 10> arr);

int main()
{
	const double values[10]{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };
	std::vector valuesArr{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };
	
	// 9.5
	average10(values);
	// 9.6
	average10(std::span<const double, 10>{valuesArr.data(), valuesArr.size()});

	return 0;
}

double average10(std::span<const double, 10> arr)
{
	double sum{};              
	for (double val : arr)
		sum += val;              
	return sum / arr.size();
}