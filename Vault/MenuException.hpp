#pragma once
#include <exception>
#include <string>
#include <iostream>

class MenuException : public std::exception
{
public:

    MenuException(const std::string& message)
    {
        this->m_message = "Menu Error: " + message + "\n";
    }

    virtual char const* what() const throw()
    {
        return m_message.c_str();
    }
private:
    std::string m_message;
};