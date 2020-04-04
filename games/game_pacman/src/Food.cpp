/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Food
*/

#include "Food.hpp"

Food::Food(int posX, int posY, int width, int height)
{
    this->_posX = posX;
    this->_posY = posY;
    this->_width = width;
    this->_height = height;
    this->_eat = false;
}

Food::~Food()
{
}

void Food::draw(IDisplayModule &lib) const
{
    if (this->_eat == false) {
        lib.setColor(IDisplayModule::Colors::DARK_GRAY);
        lib.putFillRect(this->_posX + 2, this->_posY + 2, 4, 4);
    }
}

bool Food::getEat(void) const
{
    return (this->_eat);
}

bool Food::checkCollision(int posX, int posY, int width, int height)
{
    posX -= 5;
    posY -= 5;
    width += 10;
    height += 10;

    if (((posX >= this->_posX) && (posX <= (this->_posX + this->_width))) &&
    ((posY >= this->_posY) && (posY <= (this->_posY + this->_height)))) {
        this->_eat = true;
        return false;
    }
    if ((((posX + width) >= this->_posX) && (posX <= (this->_posX + this->_width))) &&
    (((posY + height) >= this->_posY) && (posY <= (this->_posY + this->_height)))) {
        this->_eat = true;
        return false;
    }
    return true;
}

void Food::setEat(void)
{
    this->_eat = false;
}