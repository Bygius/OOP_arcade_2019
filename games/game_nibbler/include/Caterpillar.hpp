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
#include <algorithm>

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
        void displayQueue(IDisplayModule &lib) const;
        void moveCaterpillar(std::unique_ptr<MapNibbler> &map);
        void moveQueue(std::unique_ptr<MapNibbler> &map);
        void setDirection(const IDisplayModule &lib);
        void checkCandies(std::unique_ptr<MapNibbler> &map);
        void checkWin(std::unique_ptr<MapNibbler> &map);
        void checkLose();
        bool isWin();
        bool isLose();
        void reset();
        void resetSpeed();
        void incSpeed();

    private:
        Direction _direction;
        Direction _futurDirection;
        int _speed;
        int _posX;
        int _posY;
        int _width;
        int _height;
        std::vector<std::unique_ptr<Square>> _queue;
        bool _feed;
        int _len;
        bool _win;
        bool _lose;
};

#endif /* !CATERPILLAR_HPP_ */