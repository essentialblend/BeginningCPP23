/*Ex 13-1: Define an operator function in the Box class from Ex13_05 that allows a Box object to be post-multiplied by a numeric value to produce a new object that has a height that is n times the original object. This should work for both integer and fractional multiples. Demonstrate that your operator function works as it should.*/

/*Ex 13-2: Define an operator function that will allow a Box object to be premultiplied by a numeric value to produce the same result as the operator in exercise 13-1. Demonstrate that this operator works.*/

/*Ex 13-3: Remember that we said that one thing always leads to another in the world of operator overloading? While subtracting Boxes does not work well, surely if you have operators to multiply with an integer, you’d also want operators to divide by one? Furthermore, each binary arithmetic operator op() creates the expectation of a corresponding compound assignment operator op =(). Make sure to implement all requested operators using the canonical patterns!*/

/*Ex 13-4: If we allow my_box <= 6.0 and 6.0 <= my_box, then why not allow my_box == 6.0 and 6.0 != my_box? how many operator functions do you need to accomplish this? extend the Box class of Ex13_03A and try out your latest operator.*/

import std;

import box;

auto genPURNG(double max)
{
	// Get a seed. (slow)
	std::random_device seeder; 
	// Efficient pseudo-random generator.
	std::default_random_engine generator{ seeder() };
	// Generate in [1, max) interval.
	std::uniform_real_distribution distribution{ 1.0, max };

	return std::bind(distribution, generator); 
}
int main()
{
	const double limit{ 99 }; 
	auto random{ genPURNG(limit) };
	const std::size_t boxCount{ 20 };
	std::vector<Box> boxes;
	
	// Create 20 Box objects
	for (std::size_t i{}; i < boxCount; ++i)
		boxes.push_back(Box{ random(), random(), random() });
	
	std::size_t first{}; 
	std::size_t second{ 1 }; 
	
	double minVolume{ (boxes[first] + boxes[second]).volume() };
	for (std::size_t i{}; i < boxCount - 1; ++i)
	{
		for (std::size_t j{ i + 1 }; j < boxCount; j++)
		{
			if (boxes[i] + boxes[j] < minVolume)
			{
				first = i;
				second = j;
				minVolume = (boxes[i] + boxes[j]).volume();
			}
		}
	}
	
	std::println("The two boxes that sum to the smallest volume are {} and {}",
		to_string(boxes[first]), to_string(boxes[second]));
	std::println("The volume of the first box is {:.1f}", boxes[first].volume());
	std::println("The volume of the second box is {:.1f}", boxes[second].volume());
	std::println("The sum of these boxes is {}", to_string(boxes[first] + boxes[second]));
	std::println("The volume of the sum is {:.1f}", minVolume);

	// Ex 13-1:
	Box box{ 2, 3, 4 };
	unsigned n{ 3 };
	Box newBox{ box * n };

	// 13-2
	Box newBox2{ n * box };

	return 0;
}
