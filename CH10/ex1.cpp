/*Ex 10-1: In C++17, the standard library <algorithm> module gained the handy std::clamp() function template. the expression clamp(a,b,c) is used to clamp the value a to a given closed interval [b,c]. that is, if a is less than b, the result of the expression will be b; and if a is greater than c, the result will be c; otherwise, a lies within the interval [b,c] and clamp() simply returns a. Write your own my_clamp() function template and try it with a little test program.*/

import std;

template <typename T>
decltype(auto) clampValue(const T& input, const T& minRange, const T& maxRange)
{
	if constexpr (std::is_pointer_v<T>)
	{
		return (*input < *minRange) ? (minRange) : (*input > *maxRange ? maxRange : input);
	}

	return (input < minRange) ? (minRange) : (input > maxRange ? maxRange : input);
}

int main()
{
	const int a{ 150 };

	auto b{ clampValue(a, 100, a) };

	return 0;
}

// TEST
//template<typename T> const T* larger(const std::vector<T>& data);
//template<typename T1, typename T2>
//decltype(auto) larger(const T1& a, const T2& b)
//{
//	if constexpr (std::is_pointer_v<T1> && std::is_pointer_v<T2>)
//	{
//		return *a > *b ? a : b;
//	}
//	else
//		return a > b ? a : b;
//}
//
//
//int main()
//{
//	const int big_int{ 17011983 }, small_int{ 10 };
//	const int* big_intP{ &big_int };
//	std::println("Larger of {} and {} is {}", big_int, small_int, larger(big_int, small_int));
//	std::println("Larger of {} and {} is {}", big_int, small_int, *larger(&big_int, &small_int));
//	
//	const std::vector<double> data{ -1.4, 7.3, -100.0, 54.1, 16.3 };
//	
//	std::println("The largest value in data is {}", *larger(data));
//	
//	const std::vector<std::string> words{ "The", "higher", "the", "fewer" };
//	
//	//std::println(R"(The largest word in words is "{}")", *larger(words));
//
//	std::println("Larger of {} and {} is {}", small_int, big_int, larger(small_int, *big_intP));
//
//}
//
//template <typename T> const T* larger(const std::vector<T>& data)
//{
//	std::vector<T> temp{ data };
//
//	std::sort(temp.begin(), temp.end());
//
//	static T returnVal{};
//
//	for (int i{}; i < data.size(); i++)
//	{
//		if (temp.back() == data[i])
//		{
//			returnVal = data[i];
//		}
//	}
//
//	return &returnVal;
//}