/*
** EPITECH PROJECT, 2020
** caterpillar
** File description:
** caterpillar
*/

#ifndef CATERPILLAR_HPP_
#define CATERPILLAR_HPP_

#include "Square.hpp"
#include "Arcade_interfaces.hpp"
#include <vector>

class Caterpillar
{
    enum Direction {
        UP,
        DOWN,
        RIGHT,
        LEFT
    };
    public:
        Caterpillar();
        ~Caterpillar();
        void displayCaterpillar(IDisplayModule &lib) const;
        void moveCaterpillar();
        void setDirection(const IDisplayModule &lib);
    private:
        Direction _direction;
        int _speed;
        int _posX;
        int _posY;
        std::vector<Square> _queue;
};

#endif /* !CATERPILLAR_HPP_ */