#pragma once
#include <cassert>
#include <spdlog/spdlog.h>

namespace operations
{
    template<typename T>
    T sum(T const& a, T const& b) {
        SPDLOG_DEBUG("a={} b={}", a, b);
        return a + b;
    }

    template<typename T>
    T sub(T const& a, T const& b) {
        SPDLOG_DEBUG("a={} b={}", a, b);
        return a - b;
    }

    template<typename T>
    T mul(T const& a, T const& b) {
        SPDLOG_DEBUG("a={} b={}", a, b);
        return a * b;
    }

    template<typename T>
    T div(T const& a, T const& b) {
        SPDLOG_DEBUG("a={} b={}", a, b);
        assert(b != 0.0);
        return a / b;
    }
}