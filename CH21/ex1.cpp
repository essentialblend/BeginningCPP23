/*Ex 21-1: Compound requirements are nothing but syntactic sugar that allow you to combine multiple requirements into one using a more convenient syntax. Rrewrite the compound requirements of the RandomAccessIterator<> concept definition from Ex21_02 in terms of equivalent simple and nested requirements.*/

import std;

template <typename Iter>
concept BidirectionalIterator = true;

template<class Iterator>
concept RandomAccessIterator = BidirectionalIterator<Iterator>
&& requires(const Iterator i, const Iterator j, Iterator k, const int n)
{
    { i - n }; { i + n }; { n + i };
    requires std::same_as<decltype(i - n), Iterator>;
    requires std::same_as<decltype(i + n), Iterator>;
    requires std::same_as<decltype(n + i), Iterator>;

    { k += n }; { k -= n };
        requires std::same_as<decltype(k += n), Iterator&>;
        requires std::same_as<decltype(k -= n), Iterator&>;

    i[n];
        requires std::same_as<decltype(i[n]), decltype(*i)>;

    i < j; i > j; i <= j; i >= j;
        requires std::convertible_to<decltype(i < j), bool>
    && std::convertible_to<decltype(i > j), bool>
    && std::convertible_to<decltype(i <= j), bool>
        && std::convertible_to<decltype(i >= j), bool>;
};

int main()
{
}