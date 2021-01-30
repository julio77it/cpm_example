#include <iostream>
#include <string>
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
#include <spdlog/spdlog.h>

#include <operation.h>
#include "version.h"

template<typename T>
void test(T const& a, T const& b) {
    namespace op = operations;
    T r = op::sum(a,b);
    std::cout << a << " + " << b << " = " << r << std::endl;
    r = op::sub(a,b);
    std::cout << a << " - " << b << " = " << r << std::endl;
    r = op::mul(a,b);
    std::cout << a << " * " << b << " = " << r << std::endl;
    r = op::div(a,b);
    std::cout << a << " / " << b << " = " << r << std::endl;
}

int main(int argc, char** argv)
{
    spdlog::set_pattern("%Y/%m/%d %T.%e | %^%l%$ | %t | %@ | %! | %v");
    spdlog::flush_on(spdlog::level::debug);
    spdlog::set_level(spdlog::level::debug);    

    if (argc < 2)
    {
        std::cout << "Usage: binary <num1> <num2>" << std::endl;
        return -1;
    }
    std::string a = argv[1];
    std::string b = argv[2];

    if ((a.find(".") != std::string::npos)
     || (b.find(".") != std::string::npos)) {
        test(atof(a.c_str()), atof(b.c_str()));
    }
    else
        test(atoi(a.c_str()), atoi(b.c_str()));
}