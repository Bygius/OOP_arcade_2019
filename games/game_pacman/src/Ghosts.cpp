/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ghosts
*/

#include "Ghosts.hpp"

Ghosts::Ghosts(IDisplayModule::Colors color, int x)
{
    this->_color = color;
    // this->x_body = 240;
    this->x_body = x;
    this->y_body = 184;
    this->w_body = 16;
    this->h_body = 8;
    // this->x_head = 240;
    this->x_head = x;
    this->y_head = 176;
    this->_radius = 8;
    this->_size = 16;
    this->_speed = 1;
}

Ghosts::~Ghosts()
{
}

void Ghosts::draw(IDisplayModule &lib) const
{
    lib.setColor(this->_color);
    lib.putCircle(this->x_head, this->y_head, this->_radius);
    lib.putFillRect(this->x_body, this->y_body, this->w_body, this->h_body);
}

// void Ghosts::setPosX_body(int x)
// {
//     this->x_body = x;
// }

// void Ghosts::setPosY_body(int y)
// {
//     this->_posY = y;
// }

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

void Ghosts::moveFantom(MapPacman *map)
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

void Ghosts::setDirection(MapPacman *map)
{
    int value = rand() % 4 + 1;

    if (value == 1) {
        while (map->PlayerCollision(this->x_head, this->y_head - this->_speed, this->_size, this->_size) == true)
            return;;
        this->_futurDirection = UP;
    }
    if (value == 2) {
        while (map->PlayerCollision(this->x_head, this->y_head + this->_speed, this->_size, this->_size) == true)
            return;
        this->_futurDirection = DOWN;        
    }
    if (value == 3) {
        while (map->PlayerCollision(this->x_head - this->_speed , this->y_head, this->_size, this->_size) == true)
            return;
        this->_futurDirection = RIGHT;
    }
    if (value == 4) {
        while (map->PlayerCollision(this->x_head + this->_speed , this->y_head, this->_size, this->_size) == false)
            return;
        this->_futurDirection = LEFT;
    }
        
}