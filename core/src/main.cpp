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
#include "../../include/Arcade_interfaces.hpp"
#include <unistd.h>
#include <iostream>
#include <string.h>
#include "Lib.hpp"
#include "Display.hpp"

int main(int ac, char **av)
{
    if (av[1] == NULL)
        return 84;

    Display d("./lib/");
    d.Load("lib_arcade_sfml.so");
    size_t i = 0;
    while (1) {
        d.clear();
        d.update();
        d.putLine(1, 1, 50, 50);
        d.putPixel(120, 120);
        d.putRect(100, 10, 50, 50);
        d.putFillRect(200, 200, 100, 50);
        // d.putText("a", 5, 10, 10);
        // if (d.isKeyPressed(IDisplayModule::Keys::A))
        //     break;
        d.render();
        if (d.shouldExit() == true)
            break;
    }
    return 0;
}

// d.setColor(IDisplayModule::Colors::BLUE);
// d.putRect(10, 10, 40, 40);
// d.setColor(IDisplayModule::Colors::GREEN);
// d.putFillRect(100, 10, 10, 30);
// d.setColor(IDisplayModule::Colors::YELLOW);
// d.putPixel(200, 10);
// d.setColor(IDisplayModule::Colors::RED);
// d.putCircle(300, 300, 60);
// d.setColor(IDisplayModule::Colors::MAGENTA);
// d.putLine(100, 200, 100, 150);
// sleep(1);
// d.LoadPreviousLib();