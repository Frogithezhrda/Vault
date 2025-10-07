#include "RSA.h"
#include "BigInt.hpp"

BigInt hexStringToBigInt(const std::string& hex);

std::string encrypt(const std::string& encrypt)
{
    std::string passwordHex = stringToHex(encrypt);
    auto passwd = hexStringToBigInt(passwordHex);
    auto modulus = BigInt::BigInt(std::string(MODULUS));
    return BigInt::modPow(passwd, BigInt::BigInt(EXPONENT), modulus).to_string();
}

std::string decrypt(const std::string& decrypt, const std::string& key)
{
    auto encPasswd = BigInt::BigInt(decrypt);
    auto modulus = BigInt::BigInt(std::string(MODULUS));
    auto decrypted = BigInt::modPow(encPasswd, BigInt::BigInt(key), modulus).to_string();
    auto asciiNumber = decimalToHex(decrypted);
    return hexToAscii(asciiNumber);
}

std::string stringToHex(const std::string & input)
{
    std::stringstream stream;

    for (unsigned char chr : input)
    {
        stream << std::hex << int(chr);
    }
    return stream.str();
}

BigInt hexStringToBigInt(const std::string& hex)
{
    BigInt value = 0;
    unsigned int digit = 0;
    for (char ch : hex)
    {
        if (ch >= '0' && ch <= '9') digit = ch - '0';
        else if (ch >= 'a' && ch <= 'f') digit = ch - 'a' + 10;
        else if (ch >= 'A' && ch <= 'F') digit = ch - 'A' + 10;
        else continue;

        value = value * 16 + digit;
    }
    return value;
}

std::string decimalToHex(const std::string& input)
{
    if (input == "0") return "0";
    BigInt value(input);

    std::string hexStr;
    BigInt sixteen(16);

    while (value > 0)
    {
        BigInt remainder = value % sixteen;    
        int digit = remainder.to_int();         
        if (digit < 10) hexStr = char('0' + digit) + hexStr;
        else hexStr = char('A' + digit - 10) + hexStr; //for example for F = it would be 15 % 16 = 15 which would be 5 + 'A' which is F

        value /= sixteen;
    }
    return hexStr;
}
std::string hexToAscii(const std::string& hex)
{
    std::string output = "";
    //each 2 hex chars = 1 byte
    for (int i = 0; i < hex.length(); i += 2)
    {
        std::string byteString = hex.substr(i, 2);
        char byte = static_cast<char>(std::stoul(byteString, nullptr, 16));
        output.push_back(byte);
    }
    return output;
}