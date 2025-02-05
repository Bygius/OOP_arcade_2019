/*
** EPITECH PROJECT, 2020
** map
** File description:
** Map
*/

#ifndef MAPNIBBLER_HPP_
#define MAPNIBBLER_HPP_

#include "Block.hpp"
#include "Candy.hpp"
#include <memory>

class MapNibbler {
    public:
        MapNibbler();
        ~MapNibbler();
        void initBlocks();
        void initCandies();
        void draw_blocks(IDisplayModule &lib) const;
        void draw_candies(IDisplayModule &lib) const;
        bool checkCollisions(int posX, int posY, int width, int height);
        void checkCandies(int posX, int posY, int width, int height);
        int getEat();
        void reset();

    private:
        std::vector<std::unique_ptr<Block>> _blocks;
        std::vector<std::unique_ptr<Candy>> _candies;
};

#endif /* !MAP_HPP_ */