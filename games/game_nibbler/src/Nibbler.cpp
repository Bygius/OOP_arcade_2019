/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

Nibbler::Nibbler(IDisplayModule &lib) : _lib(lib)
{
    this->x1 = 0;
    this->y1 = 0;
}

void Nibbler::reset()
{

}

bool Nibbler::loadFromFile(const std::string &filepath)
{
    return false;
}

bool Nibbler::loadFromFile()
{
    return false;
}

bool Nibbler::saveToFile(const std::string &filepath) const
{
    return false;
}

bool Nibbler::saveToFile() const
{
    return false;
}

void Nibbler::setPlayerName(const std::string &name)
{

}

std::pair<std::string, int> Nibbler::getScore() const
{

}

std::vector<std::pair<std::string, int>> Nibbler::getBestScores() const
{

}

void Nibbler::update(const IDisplayModule &lib)
{

}

void Nibbler::render(IDisplayModule &lib) const
{
    lib.putRect(this->x1, this->y1, 50, 50);
}

const std::string &Nibbler::getLibName() const
{

}