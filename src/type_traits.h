#pragma ones
#include <type_traits>

///     is_all_of

template<typename T, typename... Args>
struct is_all_of;

template<typename T>
struct is_all_of<T> : std::true_type {};

template <typename T, typename U, typename... Args>
struct is_all_of<T, U, Args...> : std::false_type {};

template<typename T, typename... Args>
struct is_all_of<T, T, Args...> : is_all_of<T, Args...> {};

template<typename T, typename... Args>
constexpr bool is_all_of_v = is_all_of<T>::value;

///      is_string

template <typename T>
using string_type = std::basic_string<T, std::char_traits<T>, std::allocator<T>>;

template <typename T>
struct is_string : std::false_type {};

template <typename T>
struct is_string<string_type<T>> : std::true_type {};

template<typename T>
constexpr bool is_string_v = is_string<T>::value;

///      is_container

template <typename Container>
struct is_container : std::false_type {};

template <typename T>
struct is_container<std::list<T>> : std::true_type {};

template <typename T>
struct is_container<std::vector<T>> : std::true_type {};

template<typename T>
constexpr bool is_container_v = is_container<T>::value;

///      is_tuple

/*
template<typename... Args>
struct is_tuple : std::false_type {};

template<typename... Args>
struct is_tuple<std::tuple<Args...>> : std::true_type {};

template<typename... Args>
constexpr bool is_tuple_v = is_tuple<Args...>::value;

///      is_tuple_equal_args

template<typename... Args>
constexpr bool is_tuple_equal_args_v = is_all_of_v<std::true_type {}, is_tuple<Args...>, is_all_of<Args...>>;
*/