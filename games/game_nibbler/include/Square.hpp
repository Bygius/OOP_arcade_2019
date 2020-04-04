/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Square
*/

#ifndef SQUARE_HPP_
#define SQUARE_HPP_

#include "Arcade_interfaces.hpp"

class Square {
    public:
        Square(int posX, int posY);
        ~Square();
        int getPosX();
        int getPosY();
        void setPosX(int posX);
        void setPosY(int posY);
        void display(IDisplayModule &lib) const;
        bool checkMove(int posX, int posY, int width, int height);

    private:
        int _posX;
        int _posY;
        int _width;
        int _height;
};

#endif /* !SQUARE_HPP_ */