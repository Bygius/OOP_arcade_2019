/*
** EPITECH PROJECT, 2020
** cndy
** File description:
** candy
*/

#include "Candy.hpp"

Candy::Candy(int posX, int posY, int width, int height)
{
    this->_posX = posX;
    this->_posY = posY;
    this->_width = width;
    this->_height = height;
    this->_eat = false;
}

Candy::~Candy()
{
}

void Candy::draw(IDisplayModule &lib) const
{
    if (this->_eat == false) {
        lib.setColor(IDisplayModule::Colors::MAGENTA);
        lib.putFillRect(this->_posX, this->_posY, this->_width, this->_height);
        lib.setColor(IDisplayModule::Colors::CYAN);
        lib.putFillRect(this->_posX + 2, this->_posY + 2, 4, 4);
    }
}

bool Candy::checkCollision(int posX, int posY, int width, int height)
{
    posX -= 5;
    posY -= 5;
    width += 10;
    height += 10;

    //reglage pour taille de 8
    // posX -= 5;
    // posY -= 5;
    // width += 10;
    // height += 10;
    
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