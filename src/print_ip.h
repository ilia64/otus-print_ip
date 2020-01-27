#pragma ones

#include "common.h"

#include "type_traits.h"

template<typename T>
void print_ip(const T& ip)
{
    std::string result{"255.255.255.0"};

    std::cout << result << '\n';
}
