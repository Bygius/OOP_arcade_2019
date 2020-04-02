/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "Arcade_interfaces.hpp"

class Map {
    public:
        Map();
        ~Map();

        void displayWall(IDisplayModule &lib) const;
    protected:
    private:
};

#endif /* !MAP_HPP_ */
