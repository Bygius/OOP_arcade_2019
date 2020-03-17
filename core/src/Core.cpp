/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "../include/Core.hpp"

Core::Core(std::string lib)
{
    this->_library = lib;
}

Core::~Core()
{
}

void Core::start_arcade()
{
    std::cout << "loading " << this->_library << std::endl;
    return;
}