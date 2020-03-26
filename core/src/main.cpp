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
        d.putPixel(1, 20);
        d.setColor(IDisplayModule::Colors::BLUE);
        d.putFillRect(20, 15, 100, 100);
        d.update();
        d.render();
        sleep(1);
        d.LoadPreviousLib();
    }
    return 0;
}