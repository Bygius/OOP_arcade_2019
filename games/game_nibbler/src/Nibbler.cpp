/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include <memory>

Nibbler::Nibbler()
{
    this->x1 = 0;
    this->y1 = 0;
}

void Nibbler::reset()
{

}

bool Nibbler::loadFromFile(const std::string &filepath)
{
    (void)filepath;
    return false;
}

bool Nibbler::loadFromFile()
{
    return false;
}

bool Nibbler::saveToFile(const std::string &filepath) const
{
    (void)filepath;
    return false;
}

bool Nibbler::saveToFile() const
{
    return false;
}

void Nibbler::setPlayerName(const std::string &name)
{
    (void)name;
}

std::pair<std::string, int> Nibbler::getScore() const
{

}

std::vector<std::pair<std::string, int>> Nibbler::getBestScores() const
{

}

void Nibbler::update(const IDisplayModule &lib)
{
    if (lib.isKeyPressed(IDisplayModule::SPACE))
        this->x1 +=10;
}

void Nibbler::render(IDisplayModule &lib) const
{
    lib.putText("jeu", 30, this->x1, 0);
}

const std::string &Nibbler::getLibName() const
{

}

extern "C" std::unique_ptr<IGameModule> createLib(void)
{
    return std::make_unique<Nibbler>();
}