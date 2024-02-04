/*Ex 2-1: Print the number of bytes occupied by values of all integral and floating-point types seen in this chapter. If a type has multiple equivalent names, group them together in a single line.*/

import std;

int main()
{
	// Integral types.
	std::string typesList[]{ "signed char", "short, short int", "int, signed int", "long, long int signed, signed long int", "long long, signed long long, long long int" };

	std::println("--INTEGRALS--");
	std::println("Num bytes for {} is: {}", typesList[0], sizeof(unsigned char));
	std::println("Num bytes for \"{}\": {}", typesList[1], sizeof(short));
	std::println("Num bytes for \"{}\": {}", typesList[2], sizeof(int));
	std::println("Num bytes for \"{}\": {}", typesList[3], sizeof(long));
	std::println("Num bytes for \"{}\": {}", typesList[4], sizeof(long long));

	return 0;

}


