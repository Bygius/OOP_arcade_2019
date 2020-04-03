/*
** EPITECH PROJECT, 2020
** map
** File description:
** Map
*/

#include "MapNibbler.hpp"

MapNibbler::MapNibbler()
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

MapNibbler::~MapNibbler()
{
}

void MapNibbler::draw_blocks(IDisplayModule &lib) const
{
    for (std::vector<Block>::const_iterator it = this->_blocks.begin(); it != this->_blocks.end(); it++)
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