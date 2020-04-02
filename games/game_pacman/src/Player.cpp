/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(int x, int y)
{
    this->_posX = x;
    this->_posY = y;
    this->_size = 8;
    this->_speed = 1;
    this->_direction = UP;
}

Player::~Player()
{
}

int Player::getPosX() const
{
    return (this->_posX);
}

int Player::getPosY() const
{
    return (this->_posY);
}

int Player::getSize() const
{
    return (this->_size);
}

void Player::setPosX(int x)
{
    this->_posX = x;
}

void Player::setPosY(int y)
{
    this->_posY = y;
}

void Player::displayPlayer(IDisplayModule &lib) const
{
    lib.putCircle(this->_posX, this->_posY, this->_size);
}

void Player::movePlayer(void)
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

void Player::setDirection(const IDisplayModule &lib)
{
    if (lib.isKeyPressed(IDisplayModule::Z))
        this->_direction = UP;
    if (lib.isKeyPressed(IDisplayModule::S))
        this->_direction = DOWN;
    if (lib.isKeyPressed(IDisplayModule::D))
        this->_direction = RIGHT;
    if (lib.isKeyPressed(IDisplayModule::Q))
        this->_direction = LEFT;
}