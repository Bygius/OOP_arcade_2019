/*
** EPITECH PROJECT, 2020
** caterpillar
** File description:
** caterpillar
*/

#ifndef CATERPILLAR_HPP_
#define CATERPILLAR_HPP_

#include "Square.hpp"
#include "MapNibbler.hpp"
#include "Arcade_interfaces.hpp"
#include <vector>

class Caterpillar
{
    enum Direction {
        UP,
        DOWN,
        RIGHT,
        LEFT,
        UNKNOWN
    };
    public:
        Caterpillar();
        ~Caterpillar();
        void displayCaterpillar(IDisplayModule &lib) const;
        void moveCaterpillar(MapNibbler map);
        void setDirection(const IDisplayModule &lib);
        bool checkCandies(MapNibbler map);
        void incQueue();

    private:
        Direction _direction;
        Direction _futurDirection;
        int _speed;
        int _posX;
        int _posY;
        int _width;
        int _height;
        std::vector<Square> _queue;
};

#endif /* !CATERPILLAR_HPP_ */