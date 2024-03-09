/*Ex 10-4: Write your own version of the std::size() family of functions called my_size() that work not only for fixed-size arrays but also for std::vector<> and std::array<> objects. You are not allowed to use the sizeof() operator or std::span<>.*/

import std;

template<typename T, std::size_t N> std::size_t computeSize(const T (&inpArr)[N])
{
	return N;
}

template<typename T> std::size_t computeSize(const std::vector<T>& inpVec)
{
	return inpVec.size();
}

template<typename T, std::size_t N> std::size_t computeSize(const std::array<T, N>& inpVec)
{
	return N;
}

int main()
{
	const int arr[]{ 1, 2, 3 };
	const std::vector<int> arrVec{ 1, 2, 3 };
	const std::array<double, 3> arrArr{ 1, 2, 3 };

	auto a{ computeSize(arr) };
	auto b{ computeSize(arrVec) };
	auto c{ computeSize(arrArr) };


	return 0;
}

