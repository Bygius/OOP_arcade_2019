/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Error
*/

#include "Error.hpp"
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>

Error::Error(const std::string &msg = "")
{
    this->error_msg = msg;
}

const char *Error::what() const throw()
{
    return this->error_msg.c_str();
}

LibError::LibError(const std::string &msg) : Error(msg)
{
    std::ostringstream buff;
    buff << "LibError : " << msg;
    this->error_msg = buff.str();
}

const char *LibError::what() const throw()
{
    return this->error_msg.c_str();
}

CoreError::CoreError(const std::string &msg) : Error(msg)
{
    std::ostringstream buff;
    buff << "CoreError : " << msg;
    this->error_msg = buff.str();
}

const char *CoreError::what() const throw()
{
    return this->error_msg.c_str();
}


