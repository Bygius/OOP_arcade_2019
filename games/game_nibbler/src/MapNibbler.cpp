/*
** EPITECH PROJECT, 2020
** map
** File description:
** Map
*/

#include "MapNibbler.hpp"

MapNibbler::MapNibbler()
{
    this->_blocks.push_back(Block(152, 88, 8, 328));
    this->_blocks.push_back(Block(152, 88, 328, 8));
    this->_blocks.push_back(Block(152, 408, 328, 8));
    this->_blocks.push_back(Block(472, 88, 8, 328));
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