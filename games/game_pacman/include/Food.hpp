/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Food
*/

#ifndef FOOD_HPP_
#define FOOD_HPP_

#include "Arcade_interfaces.hpp"

class Food {
    public:
        Food(int posX, int posY, int width, int height);
        ~Food();
        void draw(IDisplayModule &lib) const;
        bool checkCollision(int posX, int posY, int width, int height);
        bool getEat(void) const;
        void setEat(void);

    private:
        int _posX;
        int _posY;
        int _width;
        int _height;
        int _eat;
};

#endif /* !FOOD_HPP_ */
