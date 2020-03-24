/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/
#include <dlfcn.h>
#include "../include/Core.hpp"
#include "../../lib/lib_sfml/include/Libsfml.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(int ac, char **av)
{

    // Libsfml *lib = new Libsfml(200, 200);
    // if (ac != 2)
    //     return(84);
    // Core core(av[1]);
    // core.start_arcade();

    if (av[1] == NULL)
        return 84;
    void *handle;
    
    
    //handle = dlopen("lib/lib_ncurses/lib_arcade_ncurses.so", RTLD_NOW | RTLD_GLOBAL);
    //handle = dlopen("lib/lib_one/lib_arcade_sfml.so", RTLD_NOW | RTLD_GLOBAL);
    handle = dlopen(av[1], RTLD_NOW | RTLD_GLOBAL);

    if (!handle) {
        std::cout << "Cannot open library: " << dlerror() << '\n';
        return 84;
    }
    std::unique_ptr<IDisplayModule> *(*create)();
    create = (std::unique_ptr<IDisplayModule> * (*)())dlsym(handle, "createLib");

    std::unique_ptr<IDisplayModule> *ptr = create();
    IDisplayModule *lib = ptr->get();

    while (1)
    {
        //lib->clear();
        lib->putLine(1, 1, 50, 50);
        lib->update();
        lib->render();
    }
    //     //lib->clear();
    //     // lol.putLine(10, 10, 10, 15);
    //     lib->putPixel(1, 20);
    //     //lib->putRect(15, 10, 3, 5);
    //     //lib->putFillRect(20, 15, 3, 5);
    //     // mvprintw(10, 10, "test");
    //     lib->update();
    //     //my_sleep();
    //     for (size_t i = 0; i < 10000000000000; i++);

    // }

    // IDisplayModule *lib = ptr->get();
    // while (1) {
    //     lib->render();
    //     lib->putPixel(50, 50);
    //     lib->setColor(IDisplayModule::Colors::GREEN);
    //     lib->putLine(100, 100, 150, 150);
    // }
    // return (0);
}