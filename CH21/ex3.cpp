/*Ex 21-3: While uncommon, concepts can be used to constrain non-type template parameters as well. Create a medianOfSorted<>() template that computes the median of any fixed-size span<> (see Chapter 9), assuming the input span is sorted. For odd span sizes, the median is then simply the middle element; for even span sizes, the median is the mean of the two middle elements. Aalso, make sure that the template does not instantiate for empty spans. */

/*Ex 21-5: Generalize your solution to exercise 21-3 such that medianOfSorted() works for any pre-sorted range (that is, not just for fixed-size spans as in Eexercise 21-3) with appropriate and sufficiently complete type constraints. Tthis time, don’t use std::span<>. Aalso, generalize it such that medianOfSorted() also works for element types where you cannot compute an average (that is, that not support division by two). For non-arithmetic types, you may simply pick the first of the two obvious candidates as the median.

Tip: take a look at the existing range constraint (std::ranges::sized_range<>, but also others, such as the requirements on the range’s iterators) and range operations std::ranges::size(), std::ranges::begin(), and std::ranges::advance(). (Iinstead of std::ranges::advance(), you could also use your solution to Eexercise 21-4!).*/

import std;

// Ex 21-3
//template <typename T, std::size_t N>
//auto& medianOfSorted(std::span<T, N> span)
//{
//	static_assert(N != 0, "Empty span medium undefined...");
//	return span[N / 2];
//}
//
//template <typename T, std::size_t N> requires (N % 2 == 0)
//auto medianOfSorted(std::span<T, N> span)
//{
//	static_assert(N != 0, "Empty span medium undefined...");
//	return (span[N / 2 - 1] + span[N / 2]) / 2;
//}


// Ex 21-5

template <typename T>
concept Averagable = requires (const T x, const T y, T z, const int i)
{
    { x + y }  -> std::same_as<T>;
    { z += y } -> std::same_as<T&>;
    { x - y }  -> std::same_as<T>;
    { z -= y } -> std::same_as<T&>;
    { x / i }  -> std::same_as<T>;
    { z /= i } -> std::same_as<T&>;
    { x* i }  -> std::same_as<T>;
    { z *= i } -> std::same_as<T&>;
};

template <std::ranges::sized_range Range>
    requires std::ranges::input_range<Range>
decltype(auto) medianOfSorted(Range&& range)
{
    auto it{ std::ranges::begin(range) };
    std::ranges::advance(it, std::ranges::size(range) / 2);
    return *it;
}

template <std::ranges::sized_range Range>
    requires std::ranges::forward_range<Range>&& Averagable<std::ranges::range_value_t<Range>>
auto medianOfSorted(Range&& range)
{
    const auto N{ std::ranges::size(range) };
    auto it{ std::ranges::begin(range) };
    if (N % 2 == 0)
    {
        std::ranges::advance(it, N / 2 - 1);
        const auto& value1{ *it };
        std::ranges::advance(it, 1);
        return (value1 + *it) / 2;
    }
    else
    {
        std::ranges::advance(it, N / 2);
        return *it;
    }
}