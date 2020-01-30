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

template<int N, typename ...Args>
std::string tuple_to_string(const std::tuple<Args...>&ip)
{
    if constexpr (N > 0)
    {
        return tuple_to_string<N - 1, Args...>(ip) + "." + std::to_string(std::get<N - 1>(ip));
    }
    else
    {
        return std::to_string(std::get<0>(ip));
    }
}

template <typename ...Args>
std::enable_if_t<is_all_of_v<Args...>, std::string>
to_string(const std::tuple<Args...> ip)
{
    const auto size = std::tuple_size_v<std::tuple<Args...>>;
    return tuple_to_string<size, Args...>(ip);
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
