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
#include "Food.hpp"

class MapPacman {
    public:
        MapPacman();
        ~MapPacman();

        void initCollisions();
        void initFood();
        // void displayWall(IDisplayModule &lib) const;
        void display_collisions(IDisplayModule &lib) const;
        bool PlayerCollision(int x, int y, int width, int height);

        void draw_food(IDisplayModule &lib) const;
        bool checkFood(int posX, int posY, int width, int height);
        int countScore(void);
        void reset();
    protected:
    private:
        std::vector<Collision> _collisions;
        std::vector<Food> _foods;
};

#endif /* !MAPPACMAN */
