/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include <memory>

Nibbler::Nibbler() : _caterpillar(), _map()
{
    
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
    this->_name = name;
}

std::pair<std::string, int> Nibbler::getScore() const
{

}

std::vector<std::pair<std::string, int>> Nibbler::getBestScores() const
{

}

void Nibbler::update(const IDisplayModule &lib)
{
    this->_caterpillar.moveCaterpillar(_map);
    this->_caterpillar.setDirection(lib);
}

void Nibbler::render(IDisplayModule &lib) const
{
    lib.setColor(IDisplayModule::RED);
    lib.putText("NIBBLER", 30, 250, 0);
    lib.putText(this->_name, 24, 10, 20);
    
    this->_map.draw_blocks(lib);
    this->_caterpillar.displayCaterpillar(lib);
}

const std::string &Nibbler::getLibName() const
{

}

extern "C" std::unique_ptr<IGameModule> createLib(void)
{
    return std::make_unique<Nibbler>();
}