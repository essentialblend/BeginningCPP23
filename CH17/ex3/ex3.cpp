/*Ex 17-3: Define a template for one-dimensional sparse arrays that will store objects of any type so that only the elements stored in the array occupy memory. the potential number of elements that can be stored by an instance of the template should be virtually unlimited. the template might be used to define a sparse array containing elements of type double with the following statement:

	SparseArray<double> values;
	
  Define the subscript operator for the template so that element values can be retrieved and set just like in a normal array. If an element doesn’t exist at an index position, the subscript operator should add a default-constructed object to the sparse array at the given index and return a reference to this newly added object. Because this subscript operator modifies the object, there cannot really be a const overload of this operator. similar to various standard library containers, you should define an at(size_t) member function as well, overloaded on const, that instead of adding a default- constructed value throws an appropriate exception if no value exists for the given index. Because it would still be nice to know in advance whether an element exists at a given index, also add an elementExistsAt() member to check for this.*/

import sparsearray;
import std;

auto createUniformPseudoRandomNumberGenerator(int min, int max)
{
    std::random_device seeder;         // True random number generator to obtain a seed (slow)
    std::default_random_engine generator{ seeder() };     // Efficient pseudo-random generator
    std::uniform_int_distribution distribution{ min, max }; // Generate in [min, max) interval
    return std::bind(distribution, generator);            //... and in the darkness bind them!
}

int main()
{
    const unsigned count{ 20 };     // Number of elements to be created
    const int min_value{ 32 };
    const int max_value{ 212 };
    const std::size_t max_index{ 499 };

    // Create the (pseudo)-random number generators 
    // (we use +1 because these generate integers in a half-open interval [min,max)...)
    auto generate_random_index{ createUniformPseudoRandomNumberGenerator(0, max_index + 1) };
    auto generate_random_value{ createUniformPseudoRandomNumberGenerator(min_value, max_value + 1) };

    SparseArray<int> numbers;               // Create empty sparse array

    for (unsigned i{}; i < count; ++i)       // Create count entries in numbers array
    {
        std::size_t index{};                 // Stores new index value

        // Must ensure that indexes after the first are not duplicates
        do
        {
            index = generate_random_index();    // Get a random index 0 to max_index
        } while (numbers.elementExistsAt(index));

        numbers[index] = generate_random_value();  // Store value at new index position
    }

    for (std::size_t i{}; i <= max_index; ++i)  // Check which elements exist in the numbers array
    {
        if (numbers.elementExistsAt(i))
            std::println("Element at index {} equals {}", i, numbers.at(i));
    }
}