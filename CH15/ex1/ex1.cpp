/*Ex 15-1: Define a base class called Animal with two member variables: a string member to store the name of the animal (e.g., "Fido") and an integer member, weight, that will contain the weight of the Animal in pounds. also include a public member function, who(), that returns a string object containing the name and weight of the Animal object, as well as a pure virtual function called sound() that in a derived class should return a string representing the sound the animal makes. Derive at least three classes—Sheep, Dog, and Cow—with the class Animal as a public base and implement the sound() function appropriately in each class.

Define a class called Zoo that can store the addresses of any number of Animal objects of various types in a vector<> container. Write a main() function to create a random sequence of an arbitrary number of objects of classes derived from Animal and store pointers to them in a Zoo object. to keep things simple, work with std::shared_ptr<> pointers to transfer and store Animals into the Zoo. (later, in Chapter 18, we’ll teach you about move semantics, which will allow you to use unique_ptr<> smart pointers for this as well.) the number of objects should be entered from the keyboard. Define a member function of the Zoo class that outputs information about each animal in the Zoo, including the text of the sound they all make.*/

/*Ex 15-2: Start from the solution in exercise 15-1. Because Cows are notoriously self-conscious about their weight, the result of the who() function of this class must no longer include the weight of the animal. Sheep, on the other hand, are whimsical creatures. They tend to prefix their name with "Woolly"—that is, for a Sheep called "Pete" who() should return a string containing "Woolly Pete". Besides that, it should also reflect a Sheep’s true weight, which is its total weight (as stored in the Animal base object) minus that of its wool (known by the Sheep itself). say that a new Sheep’s wool by default weighs 10% of his total weight.*/

import Animal;

int main()
{
	Dog nyx{ "Nyx", 50 };
	Sheep sheep{ "Tim", 40 };
	Cow cow{ "Jim", 100 };

	std::shared_ptr<Dog> dogP{ std::make_shared<Dog>(nyx) };
	std::shared_ptr<Sheep> sheepP{ std::make_shared<Sheep>(sheep) };
	std::shared_ptr<Cow> cowP{ std::make_shared<Cow>(cow) };


	std::vector<std::shared_ptr<Animal>> zooAnimals{ dogP, sheepP, cowP };

	Zoo mainZoo{ zooAnimals };

	mainZoo.printZooDeets();

	return 0;
}