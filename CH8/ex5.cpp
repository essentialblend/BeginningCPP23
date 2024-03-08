/*Ex 8-5:Define a function that checks whether a given number is prime. Your primal check does not have to be efficient; any algorithm you can think of will do. In case you have forgotten, a prime number is a natural number strictly greater than 1 and with no positive divisors other than 1 and itself. Write another function that generates a vector<> with all natural numbers less than or equal to a first number and starting from another. By default, it should start from 1. 

Create a third function that given a vector<> of numbers outputs another vector<> containing all the prime numbers it found in its input. use these three functions to create a program that prints out all prime numbers less or equal to a number chosen by the user (print, for instance, 15 primes per line). note: in principle, you do not need any vectors to print these prime numbers; obviously, these extra functions have been added for the sake of the exercise. */

import std;

bool isPrime(int i);
std::vector<int> genVector(int last, int start = 1);
std::vector<int> genFilterPrimes(const std::vector<int>& numArr);

int main()
{
    std::vector<int> numArr{ genVector(100) };
    std::vector<int> finalPrimes{ genFilterPrimes(numArr) };

    unsigned count{};

    for (int x : finalPrimes)
    {
        if (count % 10 == 0) std::println("");
        std::print("{:5}| ", x);
        count++;
    }



    return 0;
}

bool isPrime(int n)
{
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;

    for (int i{ 3 }; i <= std::sqrt(n); i += 2)
    {
        if (n % i == 0) return false;
    }

    return true;
}

std::vector<int> genVector(int last, int start)
{
    std::vector<int> returnVec{};
    for (int i{ start }; i <= last; i++)
    {
        returnVec.push_back(i);
    }

    return returnVec;
}

std::vector<int> genFilterPrimes(const std::vector<int>& numArr)
{
    std::vector<int> retArr{};

    for (auto num : numArr)
    {
        if (isPrime(num)) retArr.push_back(num);
    }

    return retArr;
}