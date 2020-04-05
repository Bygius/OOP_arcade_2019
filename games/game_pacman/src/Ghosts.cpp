/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ghosts
*/

#include "Ghosts.hpp"

Ghosts::Ghosts(IDisplayModule::Colors color, int x, int speed)
{
    this->_color = color;
    this->x_body = x;
    this->y_body = 184;
    this->w_body = 16;
    this->h_body = 8;
    this->x_head = x;
    this->y_head = 176;
    this->_radius = 8;
    this->_size = 16;
    this->_speed = speed;
    this->_free = false;
}

Ghosts::~Ghosts()
{
}

void Ghosts::draw(IDisplayModule &lib) const
{
    lib.setColor(this->_color);
    lib.putFillCircle(this->x_head, this->y_head, this->_radius);
    lib.putFillRect(this->x_body, this->y_body, this->w_body, this->h_body);
}

bool Ghosts::getFree(void) const
{
    return (this->_free);
}

void Ghosts::setFree(bool value)
{
    this->_free = value;
}

void Ghosts::setPosX(int body, int head)
{
    this->x_body = body;
    this->x_head = head;
}

void Ghosts::setPosY(int body, int head)
{
    this->y_body = body;
    this->y_head = head;
}

void Ghosts::moveGhost(std::unique_ptr<MapPacman> &map)
{
    if (this->_futurDirection != UNKNOWN) {
        if (this->_futurDirection == UP && map->PlayerCollision(this->x_head, this->y_head - this->_speed, this->_size, this->_size) == false) {
            this->_futurDirection = UNKNOWN;
            this->_direction = UP;
        }
        if (this->_futurDirection == DOWN && map->PlayerCollision(this->x_head, this->y_head + this->_speed, this->_size, this->_size) == false) {
            this->_futurDirection = UNKNOWN;
            this->_direction = DOWN;
        }
        if (this->_futurDirection == LEFT && map->PlayerCollision(this->x_head - this->_speed , this->y_head, this->_size, this->_size) == false) {
            this->_futurDirection = UNKNOWN;
            this->_direction = LEFT;
        }
        if (this->_futurDirection == RIGHT && map->PlayerCollision(this->x_head + this->_speed , this->y_head, this->_size, this->_size) == false) {
            this->_futurDirection = UNKNOWN;
            this->_direction = RIGHT;
        }
    }
    if (this->_direction == UP && map->PlayerCollision(this->x_head, this->y_head - this->_speed, this->_size, this->_size) == false) {
        this->y_body -= this->_speed;
        this->y_head -= this->_speed;
    }
    if (this->_direction == DOWN && map->PlayerCollision(this->x_head, this->y_head + this->_speed, this->_size, this->_size) == false) {
        this->y_body += this->_speed;
        this->y_head += this->_speed;
    }
    if (this->_direction == LEFT && map->PlayerCollision(this->x_head - this->_speed , this->y_head, this->_size, this->_size) == false) {
        this->x_body -= this->_speed;
        this->x_head -= this->_speed;
    }
    if (this->_direction == RIGHT && map->PlayerCollision(this->x_head + this->_speed , this->y_head, this->_size, this->_size) == false) {
        this->x_body += this->_speed;
        this->x_head += this->_speed;
    }
}

void Ghosts::setDirection(std::unique_ptr<MapPacman> &map)
{
    int value = rand() % 4 + 1;

    if (map->PlayerCollision(this->x_head, this->y_head - this->_speed, this->_size, this->_size) == true && this->_futurDirection == UP) {
        this->_futurDirection = UNKNOWN;
        value = 2;
    }
    if (map->PlayerCollision(this->x_head, this->y_head + this->_speed, this->_size, this->_size) == true && this->_futurDirection == DOWN) {
        this->_futurDirection = UNKNOWN;
        value = 1;
    }   
    if (map->PlayerCollision(this->x_head + this->_speed, this->y_head, this->_size, this->_size) == true && this->_futurDirection == RIGHT) {
        this->_futurDirection = UNKNOWN;
        value = 4;
    }
    if (map->PlayerCollision(this->x_head - this->_speed, this->y_head, this->_size, this->_size) == true && this->_futurDirection == LEFT) {
        this->_futurDirection = UNKNOWN;
        value = 3;
    }
    if (this->_futurDirection != UNKNOWN)
        return;
    if (value == 1) {
        this->_futurDirection = UP;
    }
    if (value == 2) {
        this->_futurDirection = DOWN;        
    }
    if (value == 3) {
        this->_futurDirection = RIGHT;
    }
    if (value == 4) {
        this->_futurDirection = LEFT;
    }       
}

void Ghosts::setFuturDirection(bool value)
{
    if (value == 1)
        this->_futurDirection = RIGHT;
    else
        this->_futurDirection = LEFT;
}

bool Ghosts::checkCollision(int posX, int posY, int width, int height)
{
    if (((posX >= this->x_head) && (posX <= (this->x_head + this->_size))) &&
    ((posY >= this->y_head) && (posY <= (this->y_head + this->_size)))) {
        return true;
    }
    if ((((posX + width) >= this->x_head) && (posX <= (this->x_head + this->_size))) &&
    (((posY + height) >= this->y_head) && (posY <= (this->y_head + this->_size)))) {
        return true;
    }
    return false;
}