/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Collision
*/

#include "Collision.hpp"

Collision::Collision(int x, int y, int width, int height)
{
    this->_posX = x;
    this->_posY = y;
    this->_width = width;
    this->_height = height;
}

Collision::~Collision()
{
}

void Collision::draw(IDisplayModule &lib) const
{
    lib.setColor(IDisplayModule::Colors::BLUE);
    lib.putRect(this->_posX, this->_posY, this->_width, this->_height);
}
bool Collision::checkCollision(int x, int y, int width, int height)
{
    if (((x >= this->_posX) && (x <= (this->_posX + this->_width)))
        && ((y >= this->_posY) && (y <= (this->_posY + this->_height))))
        return true;
    if ((((x + width) >= this->_posX)
            && (x <= (this->_posX + this->_width)))
        && (((y + height) >= this->_posY)
            && (y <= (this->_posY + this->_height))))
        return true;
    return false;
}