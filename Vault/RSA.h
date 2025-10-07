#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <intrin.h>


constexpr const char* MODULUS = "198544433894790805761769330625518834399";
constexpr const int EXPONENT = 127;
// n = 9396514342775577803 || 198544433894790805761769330625518834399
// totinet = 9396514336303870680 || 198544433894790805733266794323563857360
// primes = 4272306133, 2199400991 || 12117208635341966521, 16385327666613010519
// d = 1331789433491887183 || 96927203948638031145374340535913064223
// e = 127
std::string encrypt(const std::string& encrypt);
std::string decrypt(const std::string& decrypt, const std::string& key);
std::string stringToHex(const std::string& input);
std::string decimalToHex(const std::string& input);
std::string hexToAscii(const std::string& hex);
