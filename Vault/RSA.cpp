#include "RSA.h"
#include "BigInt.hpp"

std::string encrypt(const std::string& encrypt)
{
    long long int passwordHex = stringToHex(encrypt);
    //unsigned long long poweredPasswd = modPow(passwordHex, EXPONENT, MODULUS);
    auto passwd = BigInt::BigInt(passwordHex);
    auto modulus = BigInt::BigInt(std::to_string(MODULUS));
    return BigInt::modPow(passwd, BigInt::BigInt(EXPONENT), modulus).to_string();
}
unsigned long long stringToHex(const std::string& input)
{
    unsigned long long passwd = 0;
    //54091677185334
    for (unsigned char chr : input)
    {
        //each char is one byte, that mean 8 bits
        passwd = passwd << 8;
        passwd = passwd | static_cast<unsigned char>(chr);
    }
    return passwd;
}
