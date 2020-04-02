/*
** EPITECH PROJECT, 2020
** block
** File description:
** Block
*/

#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include "Arcade_interfaces.hpp"

class Block {
    public:
        Block(int posX, int posY, int width, int height);
        ~Block();
        void draw(IDisplayModule &lib) const;
        bool checkCollision(int posX, int posY, int width, int height);

    private:
        int _posX;
        int _posY;
        int _width;
        int _height;
};

#endif /* !BLOCK_HPP_ */