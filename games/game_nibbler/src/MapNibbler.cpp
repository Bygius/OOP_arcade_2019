/*
** EPITECH PROJECT, 2020
** map
** File description:
** Map
*/

#include "MapNibbler.hpp"

MapNibbler::MapNibbler()
{
    this->_blocks.push_back(Block(150, 100, 8, 300));
    this->_blocks.push_back(Block(150, 100, 300, 8));
    this->_blocks.push_back(Block(150, 385, 300, 8));
    this->_blocks.push_back(Block(435, 100, 8, 300));
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