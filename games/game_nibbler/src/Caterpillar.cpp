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
    this->_posX = 326;
    this->_posY = 358;
    this->_width = 12;
    this->_height = 12;
    this->_feed = false;
    this->_len = 0;
    this->_lose = false;
    this->_win = false;

    this->_queue.emplace_back(Square(this->_posX - 14, this->_posY));
    this->_queue.emplace_back(Square(this->_posX - 28, this->_posY));
    this->_queue.emplace_back(Square(this->_posX - 42, this->_posY));
}

Caterpillar::~Caterpillar()
{
}

void Caterpillar::displayCaterpillar(IDisplayModule &lib) const
{
    displayQueue(lib);
    lib.setColor(IDisplayModule::Colors::RED);
    lib.putFillRect(this->_posX, this->_posY, this->_width, this->_height);
}

void Caterpillar::moveCaterpillar(MapNibbler *map)
{
    if (this->_futurDirection != UNKNOWN) {
        if (this->_futurDirection == UP && map->checkCollisions(this->_posX, this->_posY - this->_speed, this->_width, this->_height)) {
            this->_futurDirection = UNKNOWN;
            this->_direction = UP;
        }
        if (this->_futurDirection == DOWN && map->checkCollisions(this->_posX, this->_posY + this->_speed, this->_width, this->_height)) {
            this->_futurDirection = UNKNOWN;
            this->_direction = DOWN;
        }
        if (this->_futurDirection == LEFT && map->checkCollisions(this->_posX - this->_speed , this->_posY, this->_width, this->_height)) {
            this->_futurDirection = UNKNOWN;
            this->_direction = LEFT;
        }
        if (this->_futurDirection == RIGHT && map->checkCollisions(this->_posX + this->_speed , this->_posY, this->_width, this->_height)) {
            this->_futurDirection = UNKNOWN;
            this->_direction = RIGHT;
        }
    }
    if (this->_direction == UP && map->checkCollisions(this->_posX, this->_posY - this->_speed, this->_width, this->_height))
        this->_posY -= this->_speed;
    if (this->_direction == DOWN && map->checkCollisions(this->_posX, this->_posY + this->_speed, this->_width, this->_height))
        this->_posY += this->_speed;
    if (this->_direction == LEFT && map->checkCollisions(this->_posX - this->_speed , this->_posY, this->_width, this->_height))
        this->_posX -= this->_speed;
    if (this->_direction == RIGHT && map->checkCollisions(this->_posX + this->_speed , this->_posY, this->_width, this->_height))
        this->_posX += this->_speed;
    moveQueue(map);
}

void Caterpillar::setDirection(const IDisplayModule &lib)
{
    if (lib.isKeyPressed(IDisplayModule::Z) && this->_direction != DOWN)
        this->_futurDirection = Direction::UP;
    if (lib.isKeyPressed(IDisplayModule::S) && this->_direction != UP)
        this->_futurDirection = Direction::DOWN;
    if (lib.isKeyPressed(IDisplayModule::D) && this->_direction != LEFT)
        this->_futurDirection = Direction::RIGHT;
    if (lib.isKeyPressed(IDisplayModule::Q)&& this->_direction != RIGHT)
        this->_futurDirection = Direction::LEFT;
}

void Caterpillar::checkCandies(MapNibbler *map)
{
    map->checkCandies(this->_posX, this->_posY, this->_width, this->_height);
}

void Caterpillar::displayQueue(IDisplayModule &lib) const
{
    for (std::vector<Square>::const_iterator it = this->_queue.begin(); it != this->_queue.end(); it++)
        it->display(lib);
}

void Caterpillar::moveQueue(MapNibbler *map)
{
    if (map->getEat() != this->_len) {
        this->_len++;
        this->_queue.emplace_back(Square(-100, -100));
    }
    if (this->_queue.begin()->checkMove(this->_posX, this->_posY, this->_width, this->_height)) {
        std::rotate(this->_queue.begin(),this->_queue.begin() + 1, this->_queue.end());
        this->_queue.begin()->setPosX(this->_posX);
        this->_queue.begin()->setPosY(this->_posY);
    }
}

bool Caterpillar::isLose()
{
    return this->_lose;
}

bool Caterpillar::isWin()
{
    return this->_win;
}

void Caterpillar::checkWin(MapNibbler *map)
{
    if (map->getEat() == 28)
        this->_win = true;
}

void Caterpillar::checkLose()
{
    for (std::vector<Square>::iterator it = this->_queue.begin()+2; it != this->_queue.end(); it++)
        if (it->checkMove(this->_posX, this->_posY, this->_width, this->_height) == false)
            this->_lose = true;
}