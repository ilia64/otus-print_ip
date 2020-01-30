#pragma ones
#include <type_traits>

//      is_string

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

template<typename... Args>
struct is_tuple : std::false_type {};

template<typename... Args>
struct is_tuple<std::tuple<Args...>> : std::true_type {};

template<typename... Args>
constexpr bool is_tuple_v = is_tuple<Args...>::value;

/*

template<int N, typename T>
struct tuple_to_str {
    std::string  operator()(const T& tuple)
    {
        return tuple_to_str<N - 1, T>{}(tuple) +  "." + std::to_string(std::get<N>(tuple));
    }
};


template<typename T>
struct tuple_to_str<0, const T&>
{
    std::string  operator()(const T& tuple)
    {
        return std::to_string(std::get<0>(tuple));
    }
};*/
