#pragma ones

#include <type_traits>


//      is_string

template <typename T>
using string_type = std::basic_string<T, std::char_traits<T>, std::allocator<T>>;

/*
template <typename T>
struct is_string : std::is_same<string_type<T>, std::remove_const_t<T>> {};
*/

template <typename T>
struct is_string : public std::false_type {};

template <typename T>
struct is_string<string_type<T>> : public std::true_type {};

template<typename T>
constexpr bool is_string_v = is_string<T>::value;
