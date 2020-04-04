/*
** EPITECH PROJECT, 2020
** map
** File description:
** Map
*/

#include "MapNibbler.hpp"

MapNibbler::MapNibbler()
{
    initBlocks();
    initCandies();   
}

MapNibbler::~MapNibbler()
{
}

void MapNibbler::initBlocks()
{
    this->_blocks.push_back(Block(152, 88, 8, 296));
    this->_blocks.push_back(Block(152, 88, 296, 8));
    this->_blocks.push_back(Block(152, 376, 296, 8));
    this->_blocks.push_back(Block(440, 88, 8, 296));

    this->_blocks.push_back(Block(184, 120, 40, 8));
    this->_blocks.push_back(Block(184, 152, 40, 8));
    this->_blocks.push_back(Block(184, 120, 8, 40));
    this->_blocks.push_back(Block(216, 120, 8, 40));

    this->_blocks.push_back(Block(184, 280, 40, 8));
    this->_blocks.push_back(Block(184, 312, 40, 8));
    this->_blocks.push_back(Block(184, 280, 8, 40));
    this->_blocks.push_back(Block(216, 280, 8, 40));

    this->_blocks.push_back(Block(376, 120, 40, 8));
    this->_blocks.push_back(Block(376, 152, 40, 8));
    this->_blocks.push_back(Block(376, 120, 8, 40));
    this->_blocks.push_back(Block(408, 120, 8, 40));

    this->_blocks.push_back(Block(376, 280, 40, 8));
    this->_blocks.push_back(Block(376, 312, 40, 8));
    this->_blocks.push_back(Block(376, 280, 8, 40));
    this->_blocks.push_back(Block(408, 280, 8, 40));

    this->_blocks.push_back(Block(280, 312, 40, 8));
    this->_blocks.push_back(Block(280, 344, 40, 8));
    this->_blocks.push_back(Block(280, 312, 8, 40));
    this->_blocks.push_back(Block(312, 312, 8, 40));

    this->_blocks.push_back(Block(280, 248, 40, 8));
    this->_blocks.push_back(Block(280, 280, 40, 8));
    this->_blocks.push_back(Block(280, 248, 8, 40));
    this->_blocks.push_back(Block(312, 248, 8, 40));

    this->_blocks.push_back(Block(184, 344, 72, 8));
    this->_blocks.push_back(Block(248, 280, 8, 72));

    this->_blocks.push_back(Block(344, 344, 72, 8));
    this->_blocks.push_back(Block(344, 280, 8, 72));

    this->_blocks.push_back(Block(184, 248, 72, 8));
    this->_blocks.push_back(Block(344, 248, 72, 8));

    this->_blocks.push_back(Block(216, 216, 72, 8));
    this->_blocks.push_back(Block(312, 216, 72, 8));

    this->_blocks.push_back(Block(184, 184, 72, 8));
    this->_blocks.push_back(Block(184, 184, 8, 40));
    this->_blocks.push_back(Block(248, 120, 8, 72));

    this->_blocks.push_back(Block(344, 184, 72, 8));
    this->_blocks.push_back(Block(408, 184, 8, 40));
    this->_blocks.push_back(Block(344, 120, 8, 72));
    
    this->_blocks.push_back(Block(280, 152, 8, 40));
    this->_blocks.push_back(Block(312, 152, 8, 40));

    this->_blocks.push_back(Block(280, 120, 40, 8));
}

void MapNibbler::initCandies()
{
    this->_candies.push_back(Candy(200, 104, 8, 8));
    this->_candies.push_back(Candy(264, 104, 8, 8));
    this->_candies.push_back(Candy(328, 104, 8, 8));
    this->_candies.push_back(Candy(392, 104, 8, 8));

    this->_candies.push_back(Candy(232, 136, 8, 8));
    this->_candies.push_back(Candy(360, 136, 8, 8));

    this->_candies.push_back(Candy(264, 168, 8, 8));
    this->_candies.push_back(Candy(328, 168, 8, 8));

    this->_candies.push_back(Candy(216, 200, 8, 8));
    this->_candies.push_back(Candy(376, 200, 8, 8));
    this->_candies.push_back(Candy(168, 200, 8, 8));
    this->_candies.push_back(Candy(424, 200, 8, 8));

    this->_candies.push_back(Candy(296, 216, 8, 8));

    this->_candies.push_back(Candy(216, 232, 8, 8));
    this->_candies.push_back(Candy(376, 232, 8, 8));

    this->_candies.push_back(Candy(264, 248, 8, 8));
    this->_candies.push_back(Candy(328, 248, 8, 8));

    this->_candies.push_back(Candy(200, 264, 8, 8));
    this->_candies.push_back(Candy(392, 264, 8, 8));

    this->_candies.push_back(Candy(296, 296, 8, 8));

    this->_candies.push_back(Candy(232, 312, 8, 8));
    this->_candies.push_back(Candy(360, 312, 8, 8));
    this->_candies.push_back(Candy(264, 312, 8, 8));
    this->_candies.push_back(Candy(328, 312, 8, 8));
    this->_candies.push_back(Candy(168, 312, 8, 8));
    this->_candies.push_back(Candy(424, 312, 8, 8));

    this->_candies.push_back(Candy(168, 344, 8, 8));
    this->_candies.push_back(Candy(424, 344, 8, 8));
}


void MapNibbler::draw_blocks(IDisplayModule &lib) const
{
    for (std::vector<Block>::const_iterator it = this->_blocks.begin(); it != this->_blocks.end(); it++)
        it->draw(lib);
}

void MapNibbler::draw_candies(IDisplayModule &lib) const
{
    for (std::vector<Candy>::const_iterator it = this->_candies.begin(); it != this->_candies.end(); it++)
        it->draw(lib);
}

bool MapNibbler::checkCollisions(int posX, int posY, int width, int height)
{
    for (std::vector<Block>::iterator it = this->_blocks.begin(); it != this->_blocks.end(); it++) {
        if (it->checkCollision(posX, posY, width, height) == false)
            return false;
    }
    return true;
}

void MapNibbler::checkCandies(int posX, int posY, int width, int height)
{
    for (std::vector<Candy>::iterator it = this->_candies.begin(); it != this->_candies.end(); it++)
        it->checkCollision(posX, posY, width, height);
}

int MapNibbler::getEat()
{
    int ret = 0;

    for (std::vector<Candy>::iterator it = this->_candies.begin(); it != this->_candies.end(); it++)
        if (it->isFeed())
            ret++;
    return ret;
}

void MapNibbler::reset()
{
    for (std::vector<Candy>::iterator it = this->_candies.begin(); it != this->_candies.end(); it++)
        it->setFeed();
}