/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Square
*/

#include "Square.hpp"

Square::Square(int posX, int posY)
{
    this->_posX = posX;
    this->_posY = posY;
    this->_width = 12;
    this->_height = 12;
}

Square::~Square()
{
}

int Square::getPosX()
{
    return this->_posX;
}

int Square::getPosY()
{
    return this->_posY;
}

void Square::setPosX(int posX)
{
    this->_posX = posX;
}

void Square::setPosY(int posY)
{
    this->_posY = posY;
}

void Square::display(IDisplayModule &lib) const
{
    lib.setColor(IDisplayModule::Colors::RED);
    lib.putFillRect(this->_posX, this->_posY, this->_width, this->_height);
    lib.setColor(IDisplayModule::Colors::WHITE);
    lib.putFillRect(this->_posX + 4, this->_posY + 4, 4, 4);
}

bool Square::checkMove(int posX, int posY, int width, int height)
{

    //reglage pour taille de 8
    // posX -= 5;
    // posY -= 5;
    // width += 10;
    // height += 10;

    if (((posX >= this->_posX) && (posX <= (this->_posX + this->_width))) &&
    ((posY >= this->_posY) && (posY <= (this->_posY + this->_height))))
        return false;
    if ((((posX + width) >= this->_posX) && (posX <= (this->_posX + this->_width))) &&
    (((posY + height) >= this->_posY) && (posY <= (this->_posY + this->_height))))
        return false;
    return true;
}