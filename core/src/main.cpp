/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/
#include <dlfcn.h>
#include "../include/Core.hpp"
//#include "../../lib/lib_one/include/Libsfml.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include "Lib.hpp"
#include "Display.hpp"
#include "../../games/game_one/include/Snake.hpp"

int main(int ac, char **av)
{
    if (av[1] == NULL)
        return 84;

    Display d("./lib/");
    d.Load("lib_arcade_ncurses.so");
    
    size_t i = 0;
    d.open();
    while (d.isOpen()) {
        d.clear();
        d.update();
        d.setColor(IDisplayModule::Colors::BLUE);
        d.putRect(10, 10, 40, 40);
        d.setColor(IDisplayModule::Colors::GREEN);
        d.putFillRect(100, 10, 10, 30);
        d.setColor(IDisplayModule::Colors::YELLOW);
        d.putPixel(200, 10);
        d.setColor(IDisplayModule::Colors::RED);
        d.putCircle(300, 300, 60);
        d.setColor(IDisplayModule::Colors::MAGENTA);
        d.putLine(100, 200, 100, 150);
        if (d.isKeyPressed(IDisplayModule::RIGHT)) {
            d.close();
            d.LoadNextLib();
            d.open();
        }
        d.render();
    }
    d.close();
    return 0;
}


// d.LoadPreviousLib();