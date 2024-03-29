/*Ex 21-6: In Chapter 18, we created move_assign_if_noexcept<>() using some basic template metaprogramming techniques. As is often the case, concepts allow you to accomplish the same thing in a much more accessible way.Ddefine an appropriate concept and use it to create a version of move_assign_if_noexcept<>() that does not use any type traits. */

import std;

template <typename T>
concept NoThrowMoveAssignable =
	requires (T left, T right) { { left = std::move(right) } noexcept -> std::same_as<T&>; };

// lvalue refs.
auto& move_assign_if_noexcept(auto& x) noexcept { return x; }
// rvalue refs.
auto&& move_assign_if_noexcept(NoThrowMoveAssignable auto& x) noexcept { return std::move(x); }