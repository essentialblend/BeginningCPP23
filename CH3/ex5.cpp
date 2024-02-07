/*Ex 3-5: Write a program that defines an enumeration of type Color where the enumerators are red, green, yellow, purple, blue, black, and white. define the type for enumerators as an unsigned integer type and arrange for the integer value of each enumerator to be the RGB combination of the color it represents. (you can easily find the hexadecimal rgB encoding of any color online.) Create variables of type Color initialized with enumerators for yellow, purple, and green. access the enumerator value and extract and output the rgB components as separate values.*/

import std;

int main()
{
	const enum class Color : unsigned int {Red = 0xFF0000, Green = 0x00FF00, Yellow = 0xFFFF00, Purple = 0xFF00FF, Blue = 0x0000FF, Black = 0x000000, White = 0xFFFFF};


	const Color yellowColor{ Color::Yellow };
	const Color purpleColor{ Color::Purple };
	const Color greenColor{ Color::Green };
	
	std::println("Yellow RGB: {} | {} | {}",
		((static_cast<unsigned int>(yellowColor) & static_cast<unsigned int>(Color::Red)) >> 16),
		((static_cast<unsigned int>(yellowColor)& static_cast<unsigned int>(Color::Green)) >> 8),
		((static_cast<unsigned int>(yellowColor)& static_cast<unsigned int>(Color::Blue))));

	std::println("Purple RGB: {} | {} | {}",
		((static_cast<unsigned int>(purpleColor)& static_cast<unsigned int>(Color::Red)) >> 16),
		((static_cast<unsigned int>(purpleColor)& static_cast<unsigned int>(Color::Green)) >> 8),
		((static_cast<unsigned int>(purpleColor)& static_cast<unsigned int>(Color::Blue))));

	std::println("Green RGB: {} | {} | {}",
		((static_cast<unsigned int>(greenColor)& static_cast<unsigned int>(Color::Red)) >> 16),
		((static_cast<unsigned int>(greenColor)& static_cast<unsigned int>(Color::Green)) >> 8),
		((static_cast<unsigned int>(greenColor)& static_cast<unsigned int>(Color::Blue))));

	return 0;
}

