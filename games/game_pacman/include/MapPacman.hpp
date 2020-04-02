/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Map
*/

#ifndef MAPPACMAN
#define MAPPACMAN

#include "Collision.hpp"
#include "Arcade_interfaces.hpp"

class MapPacman {
    public:
        MapPacman();
        ~MapPacman();

        // void displayWall(IDisplayModule &lib) const;
        void display_collisions(IDisplayModule &lib) const;
        bool PlayerCollision(int x, int y, int width, int height);
    protected:
    private:
        std::vector<Collision> _collisions;
};

#endif /* !MAPPACMAN */
