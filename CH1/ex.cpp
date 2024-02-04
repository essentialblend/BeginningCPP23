import std;

static void helloWorld();

int main()
{
	std::string myName{ "Siddharth" };
	int myAge{ 30 };
	
	//Ex 1
	helloWorld();

	//Ex 2
	std::println("My name is {}, and I'm {} years old.", myName, myAge);

	return 0;

}

static void helloWorld()
{
	std::println("Hello World!");
}

