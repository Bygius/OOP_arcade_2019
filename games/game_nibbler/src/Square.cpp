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