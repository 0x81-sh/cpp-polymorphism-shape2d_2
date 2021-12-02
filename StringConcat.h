#pragma once
#include <string>

std::string operator+(const std::string &lhs, const std::string &rhs) {
    std::string s = lhs;
    s += rhs;
    return s;
}