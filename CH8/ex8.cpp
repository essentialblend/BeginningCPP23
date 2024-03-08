/*Ex 8-8 If written using a more mathematical notation, the power() functions we wrote in Ex8_01 and especially Ex8_16 both essentially compute a power(x, n) for n > 0. Clearly, this method requires exactly n-1 multiplications. it may surprise you, but there is another, much more effective way. suppose n is even; then you know the following: power(x,n) = power(x,n/2) * power(x,n/2)*/

/*Ex 8-9 Modify the solution in exercise 8-8 so that it counts the number of times the call power(1.5,1000) performs a multiplication. Do so by replacing each multiplication with a helper function mult() that takes two arguments, prints a message of how many multiplications have been performed thus far, and then simply returns the product of both arguments. use at least one static variable.*/

import std;

constexpr double computePower(const double x, const int n);
double computeMult(double x, double y);

int main()
{
	double power{ computePower(1.5, 1000) };
	return 0;
}

constexpr double computePower(const double x, const int n)
{
	double halfV{};

	if (n == 0) return 1;

	if (n < 0) return 1 / computePower(x, -n);

	if (!(n % 2))
	{
		halfV = computePower(x, n / 2);
		return computeMult(halfV, halfV);
	}

	return computeMult(x, computePower(x, n - 1));
}

double computeMult(double x, double y)
{
	static unsigned countTrack{};
	std::println("{} total mults.", ++countTrack);
	return x * y;
}