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

int main(int ac, char **av)
{
    if (av[1] == NULL)
        return 84;

    Lib lib("./lib/");
    //lib.PrintAllLib();
    //return 0;
    lib.Load("lib_arcade_sfml.so");
    size_t i = 0;
    while (1) {
        
        /*if (i % 2 == 0)
            lib.Load("lib_arcade_sfml.so");
        else
            lib.Load("lib_arcade_ncurses.so");*/
        lib.actual_lib->clear();
        lib.actual_lib->putPixel(1, 20);
        lib.actual_lib->setColor(IDisplayModule::Colors::BLUE);
        lib.actual_lib->putFillRect(20, 15, 100, 100);
        lib.actual_lib->update();
        lib.actual_lib->render();
        sleep(1);
        lib.LoadNextLib();
        //i++;
    }
    return 0;
}