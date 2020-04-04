/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "Core.hpp"
#include "Error.hpp"

int main(int ac, char **av)
{
    if (av[1] == NULL) {
        std::cout << "USAGE:" << std::endl;
        std::cout << "      " << av[0] << " [graphical library]" << std::endl;
        return 84;
    }
    Core *core;
    try {
        core = new Core(av[1]);
    } catch (const Error &e) {
        std::cout << e.what() << std::endl;
        return 84;
    }
    try {
        core->run();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return 84;
    }
    delete core;
}


// d.LoadPreviousLib();

// d->setColor(IDisplayModule::Colors::BLUE);
// d->putRect(10, 10, 40, 40);
// d->setColor(IDisplayModule::Colors::GREEN);
// d->putFillRect(100, 10, 10, 30);
// d->setColor(IDisplayModule::Colors::YELLOW);
// d->putPixel(200, 10);
// d->setColor(IDisplayModule::Colors::RED);
// d->putCircle(300, 300, 60);
// d->setColor(IDisplayModule::Colors::MAGENTA);
// d->putLine(100, 200, 100, 150);
// d->setColor(IDisplayModule::CYAN);
// d->putText("TA MERE LOL", 40, 300, 100);