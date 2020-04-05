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
    this->_health = 3;
}

Player::~Player()
{
}

void Player::reset(int x, int y)
{
    this->_posX = x;
    this->_posY = y;
    this->_size = 8;
    this->_height = 16;
    this->_width = 16;
    this->_speed = 1;
    this->_direction = UP;
    this->_futurDirection = UNKNOWN;
    this->_health = 3;
}

void Player::resetPos(int x, int y)
{
    this->_posX = x;
    this->_posY = y;
    this->_direction = UP;
    this->_futurDirection = UNKNOWN;
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

void Player::setHealth(int i)
{
    this->_health += i;
}

int Player::getHealth(void) const
{
    return (this->_health);
}

int Player::getHeight(void) const
{
    return (this->_height);
}

int Player::getWidth(void) const
{
    return (this->_width);
}

void Player::displayPlayer(IDisplayModule &lib) const
{
    lib.putFillCircle(this->_posX, this->_posY, this->_size);
}

void Player::movePlayer(std::unique_ptr<MapPacman> &map)
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


void Player::checkFood(std::unique_ptr<MapPacman> &map)
{
    map->checkFood(this->_posX, this->_posY, this->_width, this->_height);
}


bool Player::checkGhosts(void)
{
    for (std::vector<std::unique_ptr<Ghosts>>::iterator it = this->_ghosts.begin(); it != this->_ghosts.end(); it++) {
        if (it->get()->checkCollision(this->_posX, this->_posY, this->_width, this->_height) == false)
            return true;
    }
    return false;
}

void Player::drawHealth(IDisplayModule &lib)
{
    int x = 340;

    lib.setColor(IDisplayModule::Colors::YELLOW);
    for (int i = 0; i < this->_health; i++) {
        lib.putFillCircle(x, 312, 8);
        x += 32;
    }
}
