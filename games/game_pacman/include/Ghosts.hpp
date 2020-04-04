/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ghosts
*/

#ifndef GHOSTS_HPP_
#define GHOSTS_HPP_

#include "Arcade_interfaces.hpp"
#include "MapPacman.hpp"


class Ghosts {
    public:
        Ghosts(IDisplayModule::Colors color, int x);
        ~Ghosts();
        enum Direction { UP, DOWN, RIGHT, LEFT, UNKNOWN };
        void draw(IDisplayModule &lib) const;
        void setPosX(int body, int head);
        void setPosY(int body, int head);
        void moveGhost(MapPacman *map);
        void setDirection(MapPacman *map);
        bool getFree(void) const;
        void setFree(bool value);
        void setFuturDirection(bool value);
        bool checkCollision(int posX, int posY, int width, int height);

    protected:
    private:
        int x_body;
        int y_body;
        int w_body;
        int h_body;
        int x_head; 
        int y_head;
        int _radius;
        int _speed;
        int _size;
        bool _free;
        Direction _direction;
        Direction _futurDirection;

        IDisplayModule::Colors _color;
};

#endif /* !Ghosts_HPP_ */
