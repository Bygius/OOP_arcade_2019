/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Pacman
*/

#include "Pacman.hpp"

Pacman::Pacman(IDisplayModule &lib) : _lib(lib)
{
    this->x1 = 0;
    this->y1 = 0;
}

void Pacman::reset()
{

}

bool Pacman::loadFromFile(const std::string &filepath)
{
    return false;
}

bool Pacman::loadFromFile()
{
    return false;
}

bool Pacman::saveToFile(const std::string &filepath) const
{
    return false;
}

bool Pacman::saveToFile() const
{
    return false;
}

void Pacman::setPlayerName(const std::string &name)
{

}

std::pair<std::string, int> Pacman::getScore() const
{

}

std::vector<std::pair<std::string, int>> Pacman::getBestScores() const
{

}

void Pacman::update(const IDisplayModule &lib)
{

}

void Pacman::render(IDisplayModule &lib) const
{
    lib.putRect(this->x1, this->y1, 50, 50);
}

const std::string &Pacman::getLibName() const
{

}