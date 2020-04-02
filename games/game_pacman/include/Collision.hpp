/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Collision
*/

#ifndef COLLISION_HPP_
#define COLLISION_HPP_

#include "Arcade_interfaces.hpp"


class Collision {
    public:
        Collision(int x, int y, int width, int height);
        ~Collision();

        void draw(IDisplayModule &lib) const;
        bool checkCollision(int x, int y, int width, int height);
    protected:
    private:
        int _posX;
        int _posY;
        int _width;
        int _height;
};

#endif /* !COLLISION_HPP_ */
