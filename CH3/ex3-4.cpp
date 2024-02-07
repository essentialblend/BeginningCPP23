/*Ex 3-4: Write a program to read four characters from the keyboard and pack them into a single integer variable. Display the value of this variable as hexadecimal. Unpack the four bytes of the variable and output them in reverse order, with the low-order byte first.*/

import std;

int main()
{
	unsigned char storedChar{ 0 };
	unsigned int packedChar{ 0 };
	unsigned int mask{ 0xff };

	std::print("Enter the first character: ");
	std::cin >> storedChar;
	packedChar |= storedChar;
	
	std::print("Enter the second character: ");
	std::cin >> storedChar;
	packedChar <<= 8;
	packedChar |= storedChar;

	std::print("Enter the third character: ");
	std::cin >> storedChar;
	packedChar <<= 8;
	packedChar |= storedChar;

	std::print("Enter the fourth character: ");
	std::cin >> storedChar;
	packedChar <<= 8;
	packedChar |= storedChar;

	std::println("Packed 4 bytes displayed in hex: {:#x}", packedChar);

	// Output unpacked in reverse order.
	std::println("Outputting in reverse order: {}|{}|{}|{}", static_cast<char>(packedChar & mask), static_cast<char>(packedChar >> 8 & mask), static_cast<char>(packedChar >> 16 & mask), static_cast<char>(packedChar >> 24 & mask));

	return 0;
}

