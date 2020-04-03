/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MapPacman
*/

#include "MapPacman.hpp"

// WIDTH 640
// HEIGHT 480
// hitbox = 32 / 32

MapPacman::MapPacman()
{
    // WALL
    this->_collisions.push_back(Collision(56, 88, 8, HEIGHT - 288));
    this->_collisions.push_back(Collision(432, 88, 8, HEIGHT - 288));
    this->_collisions.push_back(Collision(56, 80, 384, 8));
    this->_collisions.push_back(Collision(56, 280, 384, 8));

    // LEFT
    this->_collisions.push_back(Collision(96, 120, 8, 48));
    this->_collisions.push_back(Collision(96, 120, 32, 8));
    this->_collisions.push_back(Collision(96, 200, 8, 48));
    this->_collisions.push_back(Collision(96, 240, 32, 8));
    this->_collisions.push_back(Collision(160, 88, 8, 40));
    this->_collisions.push_back(Collision(160, 240, 8, 40));
    this->_collisions.push_back(Collision(136, 160, 32, 8));
    this->_collisions.push_back(Collision(136, 200, 32, 8));

    //MID
    this->_collisions.push_back(Collision(200, 120, 96, 8));
    this->_collisions.push_back(Collision(200, 240, 96, 8));
    this->_collisions.push_back(Collision(200, 200, 96, 8));
    this->_collisions.push_back(Collision(200, 160, 8, 40));
    this->_collisions.push_back(Collision(200, 160, 24, 8));
    this->_collisions.push_back(Collision(288, 160, 8, 40));
    this->_collisions.push_back(Collision(272, 160, 24, 8));

    //RIGHT
    this->_collisions.push_back(Collision(328, 88, 8, 40));
    this->_collisions.push_back(Collision(328, 240, 8, 40));
    this->_collisions.push_back(Collision(328, 160, 32, 8));
    this->_collisions.push_back(Collision(328, 200, 32, 8));

    this->_collisions.push_back(Collision(392, 120, 8, 48));
    this->_collisions.push_back(Collision(368, 120, 32, 8));
    this->_collisions.push_back(Collision(392, 200, 8, 48));
    this->_collisions.push_back(Collision(368, 240, 32, 8));
}

MapPacman::~MapPacman()
{
}

void MapPacman::display_collisions(IDisplayModule &lib) const
{
    for (std::vector<Collision>::const_iterator it = this->_collisions.begin(); it != this->_collisions.end(); it++)
        it->draw(lib);
}

bool MapPacman::PlayerCollision(int x, int y, int width, int height)
{
    x -= 7;
    y -= 7;
    width += 14;
    height += 14;

    for (std::vector<Collision>::iterator it = this->_collisions.begin(); it != this->_collisions.end(); it++) {
        if (it->checkCollision(x, y, width, height) == true)
            return (true);
    }
    return (false);
}
