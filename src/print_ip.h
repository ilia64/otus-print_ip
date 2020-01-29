#pragma ones
#include "common.h"
#include "type_traits.h"

template<typename T>
std::enable_if_t<is_container_v<T>, std::string>
to_string(const std::list<int>& ip)
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
std::enable_if_t<is_string_v<T>, std::string>
to_string(const T& ip)
{
    return ip;
}

template<typename T>
void print_ip(const T& ip)
{
    std::string result = to_string(ip);
    std::cout << result << '\n';
}
