#pragma ones
#include "common.h"
#include "type_traits.h"

///     STRING

template<typename T>
std::enable_if_t<is_string_v<T>, std::string>
to_string(const T& ip)
{
    return ip;
}

///     CONTAINER

template<typename T>
std::enable_if_t<is_container_v<T>, std::string>
to_string(const T& ip)
{
    std::stringstream ss;
    for (auto iter = ip.begin();  iter != ip.end();)
    {
        if (iter != ip.begin()) { ss << '.'; }
        ss << *iter;
        iter = std::next(iter);
    }
    return ss.str();
}

///     TUPLE

/*

template<int N, typename... Args>
std::string get_tuple_item(const std::tuple<Args...>&ip)
{
    return "." + std::to_string(std::get<N - 1>(ip)) + get_tuple_item<N - 1, Args...>(ip);
}

template<typename... Args>
std::string get_tuple_item<0, Args...>(const std::tuple<Args...>& ip)
{
    return "0"; //std::to_string((size_t)std::get<0>(ip));
}
*/


template<typename T>
std::enable_if_t<is_tuple_v<T>, std::string>
to_string(const T& ip)
{
    const auto len = std::tuple_size<T>::value;
    return tuple_to_str<len - 1, const T&>(ip);
}

///     DIGIT

template<typename T>
std::enable_if_t<std::is_integral_v<T>, std::string>
to_string(const T& ip)
{
    const size_t size = sizeof(ip);
    const auto* start = reinterpret_cast<const Octet *>(&ip);

    std::list<int> result;
    for (int i = 0; i < size; ++i)
    {
        result.push_front(*(start + i));
    }
    return to_string(result);
}

template<typename T>
void print_ip(const T& ip)
{
    std::string result = to_string(ip);
    std::cout << result << '\n';
}
