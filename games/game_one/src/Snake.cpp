/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Snake
*/

#include "Snake.hpp"

Snake::Snake()
{
    this->x1 = 0;
    this->y1 = 0;
}

void Snake::reset()
{

}

bool Snake::loadFromFile(const std::string &filepath)
{
    return false;
}

bool Snake::loadFromFile()
{
    return false;
}

bool Snake::saveToFile(const std::string &filepath) const
{
    return false;
}

bool Snake::saveToFile() const
{
    return false;
}

void Snake::setPlayerName(const std::string &name)
{

}

std::pair<std::string, int> Snake::getScore() const
{

}

std::vector<std::pair<std::string, int>> Snake::getBestScores() const
{

}

void Snake::update(const IDisplayModule &lib)
{

}

void Snake::render(IDisplayModule &lib) const
{
    lib.putRect(this->x1, this->y1, 50, 50);
}

const std::string &Snake::getLibName() const
{

}