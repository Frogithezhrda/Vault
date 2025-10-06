#include "RSA.h"
#include "BigInt.hpp"

std::string encrypt(const std::string& encrypt)
{
    long long int passwordHex = stringToHex(encrypt);
    std::cout << passwordHex << std::endl;
    auto passwd = BigInt::BigInt(passwordHex);
    auto modulus = BigInt::BigInt(std::to_string(MODULUS));
    return BigInt::modPow(passwd, BigInt::BigInt(EXPONENT), modulus).to_string();
}
std::string decrypt(const std::string& decrypt, const std::string& key)
{
    auto encPasswd = BigInt::BigInt(decrypt);
    auto modulus = BigInt::BigInt(std::to_string(MODULUS));
    auto decrypted = BigInt::modPow(encPasswd, BigInt::BigInt(key), modulus).to_string();
    auto asciiNumber = decimalToHex(decrypted);
    return hexToAscii(asciiNumber);
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

std::string decimalToHex(const std::string& input)
{
    unsigned long long value = 0;
    std::stringstream ss(input);
    ss >> value; //read as decimal

    std::stringstream hexStream;
    hexStream << std::hex << std::uppercase << value; //convert to hex

    return hexStream.str();
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