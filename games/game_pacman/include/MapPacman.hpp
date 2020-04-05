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
#include <memory>

class MapPacman {
    public:
        MapPacman();
        ~MapPacman();

        void initCollisions();
        void initFood();
        void display_collisions(IDisplayModule &lib) const;
        bool PlayerCollision(int x, int y, int width, int height);

        void draw_food(IDisplayModule &lib) const;
        bool checkFood(int posX, int posY, int width, int height);
        bool winFood(void);
        int countScore(void);
        void reset();
    protected:
    private:
        std::vector<std::unique_ptr<Collision>> _collisions;
        std::vector<std::unique_ptr<Food>> _foods;
};

#endif /* !MAPPACMAN */
