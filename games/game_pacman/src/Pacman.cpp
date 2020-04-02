/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include <memory>

Pacman::Pacman(): _player(320, 240)
{
    this->x1 = 0;
    this->y1 = 0;
}

void Pacman::reset()
{

}

bool Pacman::loadFromFile(const std::string &filepath)
{
    (void)filepath;
    return false;
}

bool Pacman::loadFromFile()
{
    return false;
}

bool Pacman::saveToFile(const std::string &filepath) const
{
    (void)filepath;
    return false;
}

bool Pacman::saveToFile() const
{
    return false;
}

void Pacman::setPlayerName(const std::string &name)
{
    this->_name = name;
}

std::pair<std::string, int> Pacman::getScore() const
{

}

std::vector<std::pair<std::string, int>> Pacman::getBestScores() const
{

}

void Pacman::update(const IDisplayModule &lib)
{
    _player.setDirection(lib);
    _player.movePlayer();
}

void Pacman::render(IDisplayModule &lib) const
{
    lib.setColor(IDisplayModule::YELLOW);
    lib.putText("PACMAN", 30, 250, 0);
    lib.putText(this->_name, 24, 10, 20);
    _player.displayPlayer(lib);
    _map.displayWall(lib);
}

const std::string &Pacman::getLibName() const
{
    return ("a");
}

extern "C" std::unique_ptr<IGameModule> createLib(void)
{
    return std::make_unique<Pacman>();
}