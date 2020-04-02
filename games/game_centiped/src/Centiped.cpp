/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Centiped
*/

#include "Centiped.hpp"
#include <memory>

Centiped::Centiped()
{
    this->x1 = 0;
    this->y1 = 0;
}

void Centiped::reset()
{

}

bool Centiped::loadFromFile(const std::string &filepath)
{
    (void)filepath;
    return false;
}

bool Centiped::loadFromFile()
{
    return false;
}

bool Centiped::saveToFile(const std::string &filepath) const
{
    (void)filepath;
    return false;
}

bool Centiped::saveToFile() const
{
    return false;
}

void Centiped::setPlayerName(const std::string &name)
{
    this->_name = name;
}

std::pair<std::string, int> Centiped::getScore() const
{

}

std::vector<std::pair<std::string, int>> Centiped::getBestScores() const
{

}

void Centiped::update(const IDisplayModule &lib)
{
    (void)lib;
}

void Centiped::render(IDisplayModule &lib) const
{
    lib.setColor(IDisplayModule::BLUE);
    lib.putText("CENTIPED", 30, 250, 0);
    lib.putText(this->_name, 24, 10, 20);
}

const std::string &Centiped::getLibName() const
{

}

extern "C" std::unique_ptr<IGameModule> createLib(void)
{
    return std::make_unique<Centiped>();
}