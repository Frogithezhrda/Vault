#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <intrin.h>



constexpr const unsigned long long MODULUS = 9396514342775577803;
constexpr const int EXPONENT = 127;
// n = 9396514342775577803
// totinet = 9396514336303870680
// primes = 4272306133, 2199400991
// d = 5322887721486818251
// e = 127
std::string encrypt(const std::string& encrypt);
unsigned long long stringToHex(const std::string& input);
