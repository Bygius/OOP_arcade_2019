/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Map
*/

#include "Map.hpp"

Map::Map()
{
}

Map::~Map()
{
}

void Map::displayWall(IDisplayModule &lib) const
{
    for (int i = 0; i < WIDTH; i++)
        lib.putPixel(i, 0);
    for (int i = 0; i < WIDTH; i++)
        lib.putPixel(i, HEIGHT);

    for (int i = 0; i < HEIGHT; i++)
        lib.putPixel(0, i);
    for (int i = 0; i < HEIGHT; i++)
        lib.putPixel(WIDTH, i);
}