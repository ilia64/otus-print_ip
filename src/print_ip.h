#pragma ones
#include "common.h"
#include "type_traits.h"

template<typename T>
std::enable_if_t<std::is_integral_v<T>, std::string>
to_string(const T& ip)
{
    return "is_integral";
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
