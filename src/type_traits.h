#pragma ones

#include <type_traits>

//      is_container
//      solution from: https://stackoverflow.com/questions/12042824/how-to-write-a-type-trait-is-container-or-is-vector

template<typename T, typename _ = void>
struct is_container : std::false_type {};

template<typename... Ts>
struct is_container_helper {};

template<typename T>
struct is_container<
        T,
        std::conditional_t<
                false,
                is_container_helper<
                        typename T::value_type,
                        typename T::size_type,
                        typename T::allocator_type,
                        typename T::iterator,
                        typename T::const_iterator,
                        decltype(std::declval<T>().size()),
                        decltype(std::declval<T>().begin()),
                        decltype(std::declval<T>().end()),
                        decltype(std::declval<T>().cbegin()),
                        decltype(std::declval<T>().cend())
                >,
                void
        >
> : public std::true_type {};

template<typename T>
constexpr bool is_container_v = is_container<T>::value;

//      is_string

template <typename T>
using string_type = std::basic_string<T, std::char_traits<T>, std::allocator<T>>;

template <typename T>
struct is_string : public std::false_type {};

template <typename T>
struct is_string<string_type<T>> : public std::true_type {};

template<typename T>
constexpr bool is_string_v = is_string<T>::value;
