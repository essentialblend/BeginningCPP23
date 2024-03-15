/*Ex 15-1: Define a base class called Animal with two member variables: a string member to store the name of the animal (e.g., "Fido") and an integer member, weight, that will contain the weight of the Animal in pounds. also include a public member function, who(), that returns a string object containing the name and weight of the Animal object, as well as a pure virtual function called sound() that in a derived class should return a string representing the sound the animal makes. Derive at least three classes—Sheep, Dog, and Cow—with the class Animal as a public base and implement the sound() function appropriately in each class. */

export module Animal;

import std;

export class Animal
{
public:
	// Constructors.
	Animal() = delete;
	virtual ~Animal() = default;

	Animal(std::string_view aN, unsigned aW) : memName{ aN }, memWeight{ aW } {}

	virtual std::string identifySelf() const
	{
		return "My name is " + memName + ". My weight is " + std::to_string(memWeight) + " lbs.\n";
	}

	virtual std::string_view identifySound() const = 0;

	// Getters/Setters.
	const std::string& getName() const
	{
		return memName;
	}

	unsigned getWeight() const
	{
		return memWeight;
	}

private:
	std::string memName{};
	unsigned memWeight{};
};

export class Sheep : public Animal
{
public:

	Sheep(std::string_view shName, unsigned sW) : Animal{ shName, sW }, memWool{ static_cast<float>(0.1 * sW) } {}

	Sheep(std::string_view shName, unsigned sW, double sWW) : Animal{ shName, sW }, memWool{ static_cast<float>(sWW) } {}

	std::string identifySelf() const override
	{
		return "My name is Wolly " + getName() + ". My weight is " + std::to_string(getWeight() - memWool) + " lbs.\n";
	}

	std::string_view identifySound() const override
	{
		return "BAAAAAA";
	}
private:
	float memWool{};

};

export class Dog : public Animal
{
public:
	using Animal::Animal;
	std::string_view identifySound() const override
	{
		return "BOWWWW";
	}
};

export class Cow : public Animal
{
public:
	using Animal::Animal;

	std::string identifySelf() const override
	{
		return "My name is " + getName() + ".\n";
	}

	std::string_view identifySound() const override
	{
		return "MEEHEEHEHEHHEE";
	}
};

// ZOO Class

export class Zoo
{
public:
	Zoo() = default;
	virtual ~Zoo() = default;

	Zoo(const std::vector<std::shared_ptr<Animal>>& aList) : zooList{ aList } {}

	void printZooDeets() const
	{
		for (const auto& animal : zooList)
		{
			std::println("{}{}", animal->identifySelf(), animal->identifySound());
		}
	}


private:
	std::vector<std::shared_ptr<Animal>> zooList{};
};