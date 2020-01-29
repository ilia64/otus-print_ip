#pragma ones
#include <type_traits>

//      is_string

template <typename T>
using string_type = std::basic_string<T, std::char_traits<T>, std::allocator<T>>;

template <typename T>
struct is_string : public std::false_type {};

template <typename T>
struct is_string<string_type<T>> : public std::true_type {};

template<typename T>
constexpr bool is_string_v = is_string<T>::value;

//      is_container
//      solution from: https://stackoverflow.com/questions/12042824/how-to-write-a-type-trait-is-container-or-is-vector

template <typename Container>
struct is_container : std::false_type {};

template <typename... Ts>
struct is_container<std::list<Ts...> > : std::true_type {};

template <typename... Ts>
struct is_container<std::vector<Ts...> > : std::true_type {};

template<typename T>
constexpr bool is_container_v = is_container<T>::value;
