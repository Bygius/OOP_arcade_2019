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
    initCollisions();
    initFood();
}

void MapPacman::initCollisions()
{
    // WALL
    this->_collisions.push_back(std::make_unique<Collision>(56, 88, 8, HEIGHT - 288));
    this->_collisions.push_back(std::make_unique<Collision>(432, 88, 8, HEIGHT - 288));
    this->_collisions.push_back(std::make_unique<Collision>(56, 80, 384, 8));
    this->_collisions.push_back(std::make_unique<Collision>(56, 280, 384, 8));

    // LEFT
    this->_collisions.push_back(std::make_unique<Collision>(96, 120, 8, 48));
    this->_collisions.push_back(std::make_unique<Collision>(96, 120, 32, 8));
    this->_collisions.push_back(std::make_unique<Collision>(96, 200, 8, 48));
    this->_collisions.push_back(std::make_unique<Collision>(96, 240, 32, 8));
    this->_collisions.push_back(std::make_unique<Collision>(160, 88, 8, 40));
    this->_collisions.push_back(std::make_unique<Collision>(160, 240, 8, 40));
    this->_collisions.push_back(std::make_unique<Collision>(136, 160, 32, 8));
    this->_collisions.push_back(std::make_unique<Collision>(136, 200, 32, 8));

    //MID
    this->_collisions.push_back(std::make_unique<Collision>(200, 120, 96, 8));
    this->_collisions.push_back(std::make_unique<Collision>(200, 240, 96, 8));
    this->_collisions.push_back(std::make_unique<Collision>(200, 200, 96, 8));
    this->_collisions.push_back(std::make_unique<Collision>(200, 160, 8, 40));
    this->_collisions.push_back(std::make_unique<Collision>(200, 160, 24, 8));
    this->_collisions.push_back(std::make_unique<Collision>(288, 160, 8, 40));
    this->_collisions.push_back(std::make_unique<Collision>(272, 160, 24, 8));
    this->_collisions.push_back(std::make_unique<Collision>(224, 160, 48, 4));

    //RIGHT
    this->_collisions.push_back(std::make_unique<Collision>(328, 88, 8, 40));
    this->_collisions.push_back(std::make_unique<Collision>(328, 240, 8, 40));
    this->_collisions.push_back(std::make_unique<Collision>(328, 160, 32, 8));
    this->_collisions.push_back(std::make_unique<Collision>(328, 200, 32, 8));

    this->_collisions.push_back(std::make_unique<Collision>(392, 120, 8, 48));
    this->_collisions.push_back(std::make_unique<Collision>(368, 120, 32, 8));
    this->_collisions.push_back(std::make_unique<Collision>(392, 200, 8, 48));
    this->_collisions.push_back(std::make_unique<Collision>(368, 240, 32, 8));
}

void MapPacman::initFood() // x + 32 et y + 40
{
    // LEFT
    this->_foods.push_back(std::make_unique<Food>(76, 100, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(108, 100, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(140, 100, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(76, 140, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(108, 140, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(140, 140, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(76, 180, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(108, 180, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(140, 180, 8, 8));    
    this->_foods.push_back(std::make_unique<Food>(76, 220, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(108, 220, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(140, 220, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(76, 260, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(108, 260, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(140, 260, 8, 8));


    // MID
    this->_foods.push_back(std::make_unique<Food>(180, 100, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(212, 100, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(244, 100, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(180, 140, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(212, 140, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(244, 140, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(180, 180, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(180, 220, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(212, 220, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(244, 220, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(180, 260, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(212, 260, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(244, 260, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(272, 100, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(304, 100, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(272, 140, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(304, 140, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(304, 180, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(272, 220, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(304, 220, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(272, 260, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(304, 260, 8, 8));


    // RIGHT
    this->_foods.push_back(std::make_unique<Food>(348, 100, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(380, 100, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(412, 100, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(348, 140, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(380, 140, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(412, 140, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(348, 180, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(380, 180, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(412, 180, 8, 8));    
    this->_foods.push_back(std::make_unique<Food>(348, 220, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(380, 220, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(412, 220, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(348, 260, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(380, 260, 8, 8));
    this->_foods.push_back(std::make_unique<Food>(412, 260, 8, 8));
}

MapPacman::~MapPacman()
{
}

void MapPacman::display_collisions(IDisplayModule &lib) const
{
    for (std::vector<std::unique_ptr<Collision>>::const_iterator it = this->_collisions.begin(); it != this->_collisions.end(); it++)
        it->get()->draw(lib);
}

bool MapPacman::PlayerCollision(int x, int y, int width, int height)
{
    x -= 7;
    y -= 7;
    width += 14;
    height += 14;

    for (std::vector<std::unique_ptr<Collision>>::iterator it = this->_collisions.begin(); it != this->_collisions.end(); it++) {
        if (it->get()->checkCollision(x, y, width, height) == true)
            return (true);
    }
    return (false);
}

void MapPacman::draw_food(IDisplayModule &lib) const
{
    for (std::vector<std::unique_ptr<Food>>::const_iterator it = this->_foods.begin(); it != this->_foods.end(); it++)
        it->get()->draw(lib);
}

bool MapPacman::checkFood(int posX, int posY, int width, int height)
{
    for (std::vector<std::unique_ptr<Food>>::iterator it = this->_foods.begin(); it != this->_foods.end(); it++) {
        if (it->get()->checkCollision(posX, posY, width, height) == false)
            return false;
    }
    return true;
}

int MapPacman::countScore(void)
{
    int score = 0;

    for (std::vector<std::unique_ptr<Food>>::iterator it = this->_foods.begin(); it != this->_foods.end(); it++) {
        if (it->get()->getEat() == true)
            score += 1;
    }
    return (score);
}

void MapPacman::reset()
{
    for (std::vector<std::unique_ptr<Food>>::iterator it = this->_foods.begin(); it != this->_foods.end(); it++)
        it->get()->setEat();
}

bool MapPacman::winFood()
{
    for (std::vector<std::unique_ptr<Food>>::iterator it = this->_foods.begin(); it != this->_foods.end(); it++) {
        if (it->get()->getEat() == false)
            return (false);
    }
    return (true);
}