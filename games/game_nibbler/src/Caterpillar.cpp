/*
** EPITECH PROJECT, 2020
** caterpillar
** File description:
** caterpillar
*/

#include "Caterpillar.hpp"

Caterpillar::Caterpillar()
{
    this->_speed = 1;
    this->_direction = UP;
    this->_posX = 200;
    this->_posY = 200;
}

Caterpillar::~Caterpillar()
{
}

void Caterpillar::displayCaterpillar(IDisplayModule &lib) const
{
    lib.putFillRect(this->_posX, this->_posY, 8, 8);
}

void Caterpillar::moveCaterpillar()
{
    if (this->_direction == UP)
        this->_posY -= this->_speed;
    if (this->_direction == DOWN)
        this->_posY += this->_speed;
    if (this->_direction == LEFT)
        this->_posX -= this->_speed;
    if (this->_direction == RIGHT)
        this->_posX += this->_speed;
}

void Caterpillar::setDirection(const IDisplayModule &lib)
{
    if (lib.isKeyPressed(IDisplayModule::Z))
        this->_direction = Direction::UP;
    if (lib.isKeyPressed(IDisplayModule::S))
        this->_direction = Direction::DOWN;
    if (lib.isKeyPressed(IDisplayModule::D))
        this->_direction = Direction::RIGHT;
    if (lib.isKeyPressed(IDisplayModule::Q))
        this->_direction = Direction::LEFT;
}