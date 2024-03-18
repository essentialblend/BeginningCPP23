/*Ex 17-2: Define a template for classes that represent pairs of values of possibly different types. the values can be accessed using getFirst() and getSecond() member functions, and updated only through setFirst() and setSecond(). make sure a pair of an int and a std::string can be created and used as follows: 

	Pair<int, std::string> pair{ 122, "abc" };
	pair.setFirst(pair.getFirst() + 1);
	std::println("pair equals ({}, {})", pair.getFirst(), pair.getSecond());
  
  Make sure pairs can be default-constructed as well. Will CtaD work for the Pair<> template? Next, make sure pairs can be compared using operators ==, <, >=, and so on, based on a lexicographical comparison. that is, pairs should be ordered using the same logic as used when sorting two-letter words, except that now the words do not consist of two letters but two different values. suppose you have the following three pairs:
	
	const Pair<int, std::string> pair1{ 0, "def" };
	const Pair<int, std::string> pair2{ 123, "abc" };
	const Pair<int, std::string> pair3{ 123, "def" };

  Then the expressions pair1 < pair2 and pair2 < pair3 should both evaluate to true. the first because 0 < 123; the second because "abc" < "def". the second values of the Pairs are looked at only if the first ones compare equal using ==.
  
  Hint: Do you really need much code for this?

  Finally, since we seem to be testing your operator prowess, make sure Pairs can be streamed to output streams such as std::cout. Create a small program to proof that your templates work as required.*/

import pair;

int main()
{
	Pair<int, double> pair1{ 10, 10.5 };

	std::println("{} {}", pair1.getFirstMember(), pair1.getSecondMember());

	std::cout << pair1 << "\n";

	return 0;
}