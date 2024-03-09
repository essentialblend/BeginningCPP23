/*Ex 10-3: Write one or more function templates so that you can call plus() functions with two arguments of potentially different types to obtain a value equal to the sum of both arguments. next, make sure that plus() can be used as well to add the values pointed to by two given pointers.*/

import std;

template <typename T1, typename T2>
decltype(auto) plus(const T1& a, const T2& b)
{
	if constexpr (std::is_pointer_v<T1> && std::is_pointer_v<T2>)
	{
		return *a + *b;
	}

	return a + b;
}

int main()
{
	const int a{ 150 };
	const double b{ 150.5 };

	auto c{ plus(a,b) };

	return 0;
}