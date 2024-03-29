/*Ex 21-2: Unlike the algorithms in the std namespace, the algorithms in the std::ranges namespace allow the type of the second iterator of an iterator pair to be different from that of the first iterator. Tthis second iterator is called the sentinel in the Standard Library. Aas said, these same algorithms also support an optional projection parameter. Generalize findOptimum<>() (seen earlier in this chapter) accordingly. Ddo not forget to constrain your template type parameters (see the hint that follows). Tthe <iterator> module is again a good place to start.*/

import std;

template <std::forward_iterator Iterator,
    std::sentinel_for<Iterator> Sentinel,
    typename Projection = std::identity,
    std::indirect_strict_weak_order<std::projected<Iterator, Projection>> Comparison = std::ranges::less>
Iterator findOpt(Iterator begin, Sentinel end, Comparison comp = {}, Projection proj = {})
{
    if (begin == end) return begin;

    Iterator optimum{ begin };
    for (auto iter{ ++begin }; iter != end; ++iter)
    {
        if (std::invoke(comp, std::invoke(proj, *iter), std::invoke(proj, *optimum)))
            optimum = iter;
    }
    return optimum;
}

int main()
{
    return 0;
}