/*Ex 2-7: Reproduce Table 2.9. Add a row to your table in exercise 2-7 for sin(π/4), showing the result with exponent notation and five digits after the decimal point. make sure the exponent component begins with a capital e, not a lowercase e.*/

import std;

int main()
{
	std::println("|{:25}|{:35}|{:15}|", "CONSTANT", "DESC", "APPROX VALUE");
	std::println("|{:25}|{:35}|{:15}|", "std::numbers::e", "The base of the natural log", "2.71828...");
	std::println("|{:25}|{:35}|{:15}|", "std::numbers::pi", "π", "3.1415...");
	std::println("|{:25}|{:35}|{:15}|", "std::numbers::sqrt2", "The square root of 2", "1.41421...");
	std::println("|{:25}|{:35}|{:15}|", "std::numbers::phi", "The golden ratio constant φ", "1.618...");
	std::println("|{:25}|{:35}|{:<15.5E}|", "sin(π/4)", "Ex 2.8", std::stod("0.70710678118"));

	return 0;


}