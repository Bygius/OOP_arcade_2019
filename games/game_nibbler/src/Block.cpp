/*
** EPITECH PROJECT, 2020
** Block
** File description:
** Block
*/

#include "Block.hpp"

Block::Block(int posX, int posY, int width, int height)
{
    this->_posX = posX;
    this->_posY = posY;
    this->_width = width;
    this->_height = height;
}

Block::~Block()
{
}

void Block::draw(IDisplayModule &lib) const
{
    lib.setColor(IDisplayModule::Colors::WHITE);
    lib.putRect(this->_posX, this->_posY, this->_width, this->_height);
}

bool Block::checkCollision(int posX, int posY, int width, int height)
{
    posX -= 7;
    posY -= 7;
    width += 14;
    height += 14;

    if (((posX >= this->_posX) && (posX <= (this->_posX + this->_width))) &&
    ((posY >= this->_posY) && (posY <= (this->_posY + this->_height))))
        return false;
    if ((((posX + width) >= this->_posX) && (posX <= (this->_posX + this->_width))) &&
    (((posY + height) >= this->_posY) && (posY <= (this->_posY + this->_height))))
        return false;
    return true;
}