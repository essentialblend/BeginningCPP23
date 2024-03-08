/*Ex 8-1: Write a program that accepts from two to four command-line arguments. if it is called with less than two or more than four arguments, output a message telling the user what they should do and then exit. if the number of arguments is correct, output them, each on a separate line.*/

import std;

int main(int numArguments, char* arguments[])
{
    switch (numArguments - 1) // arguments[0] is the name of the program!
    {
    case 2: case 3: case 4:
        for (std::size_t i{ 1 }; i < numArguments; ++i)
            std::println("Argument {} is {}", i, arguments[i]);
        break;
    default:
        std::println("You entered an incorrect number of arguments.\nPlease enter 2, 3, or 4 arguments.");
    }

	return 0;
}