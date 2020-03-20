/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/
#include <dlfcn.h>
#include "../include/Core.hpp"
#include "../../lib/lib_one/include/Libsfml.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(int ac, char **av)
{

    // Libsfml *lib = new Libsfml(200, 200);
    // if (ac != 2)
    //     return(84);
    // Core core(av[1]);
    // core.start_arcade();

    void *handle;
    handle = dlopen("lib/lib_one/lib_arcade_sfml.so", RTLD_LAZY);

    if (!handle)
        std::cout << "Cannot open library: " << dlerror() << '\n';
    std::unique_ptr<IDisplayModule> *(*create)();
    create = (std::unique_ptr<IDisplayModule> * (*)())dlsym(handle, "createLib");

    std::unique_ptr<IDisplayModule> *ptr = create();

    IDisplayModule *lib = ptr->get();
    while (1) {
        lib->render();
        lib->putPixel(50, 50);
        lib->setColor(IDisplayModule::Colors::GREEN);
        lib->putLine(100, 100, 150, 150);
    }
    return (0);
}