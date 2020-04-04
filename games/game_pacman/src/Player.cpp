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
    this->_height = 16;
    this->_width = 16;
    this->_speed = 1;
    this->_direction = UP;
    this->_futurDirection = UNKNOWN;
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

void Player::movePlayer(MapPacman *map)
{
    if (this->_futurDirection != UNKNOWN) {
        if (this->_futurDirection == UP && map->PlayerCollision(this->_posX, this->_posY - this->_speed, this->_width, this->_height) == false) {
            this->_futurDirection = UNKNOWN;
            this->_direction = UP;
        }
        if (this->_futurDirection == DOWN && map->PlayerCollision(this->_posX, this->_posY + this->_speed, this->_width, this->_height) == false) {
            this->_futurDirection = UNKNOWN;
            this->_direction = DOWN;
        }
        if (this->_futurDirection == LEFT && map->PlayerCollision(this->_posX - this->_speed , this->_posY, this->_width, this->_height) == false) {
            this->_futurDirection = UNKNOWN;
            this->_direction = LEFT;
        }
        if (this->_futurDirection == RIGHT && map->PlayerCollision(this->_posX + this->_speed , this->_posY, this->_width, this->_height) == false) {
            this->_futurDirection = UNKNOWN;
            this->_direction = RIGHT;
        }
    }
    if (this->_direction == UP && map->PlayerCollision(this->_posX, this->_posY - this->_speed, this->_width, this->_height) == false)
        this->_posY -= this->_speed;
    if (this->_direction == DOWN && map->PlayerCollision(this->_posX, this->_posY + this->_speed, this->_width, this->_height) == false)
        this->_posY += this->_speed;
    if (this->_direction == LEFT && map->PlayerCollision(this->_posX - this->_speed , this->_posY, this->_width, this->_height) == false)
        this->_posX -= this->_speed;
    if (this->_direction == RIGHT && map->PlayerCollision(this->_posX + this->_speed , this->_posY, this->_width, this->_height) == false)
        this->_posX += this->_speed;
}

void Player::setDirection(const IDisplayModule &lib)
{
    if (lib.isKeyPressed(IDisplayModule::Z))
        this->_futurDirection = UP;
    if (lib.isKeyPressed(IDisplayModule::S))
        this->_futurDirection = DOWN;
    if (lib.isKeyPressed(IDisplayModule::D))
        this->_futurDirection = RIGHT;
    if (lib.isKeyPressed(IDisplayModule::Q))
        this->_futurDirection = LEFT;
}


bool Player::checkFood(MapPacman *map)
{
    if (map->checkFood(this->_posX, this->_posY, this->_width, this->_height) == false)
        incQueue();
    return false;
}

void Player::incQueue()
{
    
}
