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
    this->_direction = RIGHT;
    this->_futurDirection = UNKNOWN;
    this->_posX = 168;
    this->_posY = 104;
    this->_width = 8;
    this->_height = 8;
}

Caterpillar::~Caterpillar()
{
}

void Caterpillar::displayCaterpillar(IDisplayModule &lib) const
{
    lib.setColor(IDisplayModule::Colors::RED);
    lib.putFillRect(this->_posX, this->_posY, this->_width, this->_height);
}

void Caterpillar::moveCaterpillar(MapNibbler map)
{
    if (this->_futurDirection != UNKNOWN) {
        if (this->_futurDirection == UP && map.checkCollisions(this->_posX, this->_posY - this->_speed, this->_width, this->_height)) {
            this->_futurDirection = UNKNOWN;
            this->_direction = UP;
        }
        if (this->_futurDirection == DOWN && map.checkCollisions(this->_posX, this->_posY + this->_speed, this->_width, this->_height)) {
            this->_futurDirection = UNKNOWN;
            this->_direction = DOWN;
        }
        if (this->_futurDirection == LEFT && map.checkCollisions(this->_posX - this->_speed , this->_posY, this->_width, this->_height)) {
            this->_futurDirection = UNKNOWN;
            this->_direction = LEFT;
        }
        if (this->_futurDirection == RIGHT && map.checkCollisions(this->_posX + this->_speed , this->_posY, this->_width, this->_height)) {
            this->_futurDirection = UNKNOWN;
            this->_direction = RIGHT;
        }
    }
    if (this->_direction == UP && map.checkCollisions(this->_posX, this->_posY - this->_speed, this->_width, this->_height))
        this->_posY -= this->_speed;
    if (this->_direction == DOWN && map.checkCollisions(this->_posX, this->_posY + this->_speed, this->_width, this->_height))
        this->_posY += this->_speed;
    if (this->_direction == LEFT && map.checkCollisions(this->_posX - this->_speed , this->_posY, this->_width, this->_height))
        this->_posX -= this->_speed;
    if (this->_direction == RIGHT && map.checkCollisions(this->_posX + this->_speed , this->_posY, this->_width, this->_height))
        this->_posX += this->_speed;
}

void Caterpillar::setDirection(const IDisplayModule &lib)
{
    if (lib.isKeyPressed(IDisplayModule::Z))
        this->_futurDirection = Direction::UP;
    if (lib.isKeyPressed(IDisplayModule::S))
        this->_futurDirection = Direction::DOWN;
    if (lib.isKeyPressed(IDisplayModule::D))
        this->_futurDirection = Direction::RIGHT;
    if (lib.isKeyPressed(IDisplayModule::Q))
        this->_futurDirection = Direction::LEFT;
}