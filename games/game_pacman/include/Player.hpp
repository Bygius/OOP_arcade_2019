/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Arcade_interfaces.hpp"
#include "MapPacman.hpp"

class Player 
{
    public:
        Player(int x, int y);
        ~Player();
        enum Direction { UP, DOWN, RIGHT, LEFT, UNKNOWN };

        int getPosX() const;
        int getPosY() const;
        int getSize() const;
        void setPosX(int x);
        void setPosY(int y);

        void displayPlayer(IDisplayModule &lib) const;
        void setDirection(const IDisplayModule &lib);
        void movePlayer(MapPacman Map);

    protected:
    private:
        int _posX;
        int _posY;
        int _width;
        int _height;
        int _size;
        int _speed;
        Direction _direction;
        Direction _futurDirection;
};

#endif /* !PLAYER_HPP_ */
