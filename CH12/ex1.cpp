/*Ex 12-1: Create a class called Integer that has a single, private member variable of type int. provide a class constructor that outputs a message when an object is created. Define member functions to get and set the member variable and to print its value. write a test program to create and manipulate at least three Integer objects and verify that you can’t assign a value directly to the member variable. exercise all the class member functions by getting, setting, and outputting the value of the member variable of each object. Make sure to create at least one const Integer object and verify which operations you can and cannot apply on it.*/

/*Ex 12-2: Modify the Integer class in the previous exercise so that an Integer object can be created without an argument. the member value should then be initialized to zero. Can you think of two ways to do this? also, implement a copy constructor that prints a message when called.*/

/*Ex 12-3: implement member functions add(), subtract(), and multiply() for the Integer class that will add, subtract, and multiply the current object by the value represented by the argument of type Integer. Demonstrate the operation of these functions in your class with a version of main() that creates several Integer objects encapsulating integer values and then uses these to calculate the value of expr. implement the functions so that the calculation and the output of the result can be performed in a single statement.*/

/*Ex 12-4: Update your solution for exercise 12-3 such that 4×53+6×52+7×5+8 is guaranteed to be computed at compile time.*/

/*Ex 12-5: 5. Change your solution for exercise 12-2 so that it implements the compare() function as a friend of the Integer class. afterward, ask yourself whether it was really necessary for this function to be a friend. - Not necessary.*/

import std;

class Integer
{
public:

	Integer(int x = 0) : memberInt{ x }
	{
		std::println("Int created with value: {}", memberInt);
	}

	Integer(const Integer& intObj) : memberInt{ intObj.memberInt }
	{
		std::println("Copy constructor was called...");
	}

	int getInt() const
	{
		return memberInt;
	}

	void setInt(int n)
	{
		memberInt = n;
	}

	int compareWith(const Integer& other) const
	{
		std::strong_ordering orderingObj{ memberInt <=> other.memberInt };

		if (std::is_eq(orderingObj))
		{
			return 0;
		}
		if (std::is_lt(orderingObj))
		{
			return -1;
		}
		
		return 1;
	}

	Integer& addIntegerTo(const Integer& other)
	{
		memberInt += other.memberInt;
		return *this;
	}

	Integer& subtractIntegerFrom(const Integer& other)
	{
		memberInt -= other.getInt();
		return *this;
	}

	Integer& multIntegerWith(const Integer& other)
	{
		memberInt *= other.getInt();
		return *this;
	}


private:
	int memberInt{};
};


int main()
{
	Integer four{ 4 };
	
	Integer six{ 6 };
	
	Integer eight{ 8 };

	// 12-4 Guaranteed expr at compile time.
	// constexpr Integer four{ 4 };
	// constexpr Integer six{ 6 };
	// constexpr Integer eight{ 8 };	
	// constexpr result{ /*eval expr*/ }


	// 4 * 5^3 + 6 * 5^2 + 7 * 5 + 8
	Integer result{ four };
	std::println("Result is {}",
		result.multIntegerWith(5).addIntegerTo(six).multIntegerWith(5).addIntegerTo(7).multIntegerWith(5).addIntegerTo(eight).getInt());

	return 0;
}


