/*
** EPITECH PROJECT, 2020
** candy
** File description:
** candy
*/

#ifndef CANDY_HPP_
#define CANDY_HPP_

#include "Arcade_interfaces.hpp"

class Candy {
    public:
        Candy(int posX, int posY, int width, int height);
        ~Candy();
        void draw(IDisplayModule &lib) const;
        bool checkCollision(int posX, int posY, int width, int height);
        bool isFeed();
        void setFeed();

    private:
        int _posX;
        int _posY;
        int _width;
        int _height;
        int _eat;
};

#endif /* !CANDY_HPP_ */