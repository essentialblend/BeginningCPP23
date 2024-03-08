/*Ex 8-4: Create a function, plus(), that adds two values and returns their sum. Provide overloaded versions to work with int, double, and strings, and test that they work with the following calls:
    const int n {plus(3, 4)};
    const double d {plus(3.2, 4.2)};
    const string s {plus("he", "llo")};
    const string s1 {"aaa"};
    const string s2 {"bbb"};
    const string s3 {plus(s1, s2)}; */

import std;

int plus(int a, int b);
double plus(double a, double b);
std::string plus(const std::string& a, const std::string& b);

int main(int numArguments, char* arguments[])
{
    const double d{ plus(3.2, 4.2) };
    const std::string s{ plus("he", "llo") };
    const std::string s1{ "aaa" };
    const std::string s2{ "bbb" };
    const std::string s3{ plus(s1, s2) };
    return 0;
}

int plus(int a, int b)
{
    return a + b;
}

double plus(double a, double b)
{
    return a + b;
}

std::string plus(const std::string& a, const std::string& b)
{
    return a + b;
}