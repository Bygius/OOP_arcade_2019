/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Ghosts.hpp"
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
        void reset(int x, int y);

        void displayPlayer(IDisplayModule &lib) const;
        void setDirection(const IDisplayModule &lib);
        void movePlayer(std::unique_ptr<MapPacman> &map);
        void checkFood(std::unique_ptr<MapPacman> &map);
        void setHealth(int i);
        int getHealth(void) const;
        bool checkGhosts(void);
        int getWidth(void) const;
        int getHeight(void) const;
        void drawHealth(IDisplayModule &lib);
        void resetPos(int x, int y);

        

    protected:
    private:
        int _posX;
        int _posY;
        int _width;
        int _height;
        int _size;
        int _speed;
        int _health;
        Direction _direction;
        Direction _futurDirection;
        std::vector<std::unique_ptr<Ghosts>> _ghosts;
};

#endif /* !PLAYER_HPP_ */
