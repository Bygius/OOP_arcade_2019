/*
** EPITECH PROJECT, 2020
** map
** File description:
** Map
*/

#ifndef MAPNIBBLER_HPP_
#define MAPNIBBLER_HPP_

#include <vector>
#include "Block.hpp"

class MapNibbler {
    public:
        MapNibbler();
        ~MapNibbler();
        void draw_blocks(IDisplayModule &lib) const;
        bool checkCollisions(int posX, int posY, int width, int height);
    private:
        std::vector<Block> _blocks;
};

#endif /* !MAP_HPP_ */