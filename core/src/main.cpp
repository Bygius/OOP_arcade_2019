/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/
#include <dlfcn.h>
#include "../include/Core.hpp"
#include "../../include/Arcade_interfaces.hpp"
#include <unistd.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include "Lib.hpp"
#include "dirent.h"
#include "DLLoader.hpp"

std::vector<std::string> getLiblist(const char *path)
{
    struct dirent *entry;
    std::vector<std::string> list;
    DIR *dir = opendir(path);

    if (dir == NULL)
        return list;
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, "lib_arcade_") && strstr(entry->d_name, ".so"))
            list.push_back(std::string(path) + std::string(entry->d_name));
    }
    closedir(dir);
    return list;
}

template <typename T>
void reloadLibrary(std::unique_ptr<DLLoader<T>> &loader, std::unique_ptr<T> &module, const char *lib_name)
{
    module.reset();
    module.release();
    loader->loadLibrary(lib_name);
    module = loader->getInstance();
}

template <typename T>
void loadNextLibrary(std::unique_ptr<DLLoader<T>> &loader, std::unique_ptr<T> &module)
{
    std::vector<std::string> list = getLiblist("./lib/");
    auto pos = std::find(list.begin(), list.end(), loader->_lib_name);

    if (list.size() == 0)
        return;
    if (pos == list.end()-1 || pos == list.end()) {
        reloadLibrary(loader, module, list.front().c_str());
        std::cout << list.front().c_str() << "\n";
    } else {
        pos++;
        reloadLibrary(loader, module, pos->c_str());
        std::cout << "--> " << pos->c_str() << "\n";

    }

}

template <typename T>
void loadPreviousLibrary(std::unique_ptr<DLLoader<T>> loader, std::unique_ptr<T> module, const char *lib_name)
{

}

int main(int ac, char **av)
{
    if (av[1] == NULL)
         return 84;

    std::unique_ptr<DLLoader<IDisplayModule>> display_loader = std::make_unique<DLLoader<IDisplayModule>>("./lib/lib_arcade_ncurses.so");
    std::unique_ptr<DLLoader<IGameModule>> game_loader = std::make_unique<DLLoader<IGameModule>>("./games/lib_arcade_snake.so");
    std::unique_ptr<IDisplayModule> d = display_loader->getInstance();

    while (1) {
        d->clear();
        d->putLine(20, 30, 20, 50);
        d->update();
        d->render();
        if (d->isKeyPressed(IDisplayModule::D) == true) {
            loadNextLibrary(display_loader, d);
        }
        if (d->shouldExit() == true) {
            break;
        }
    }
    //     //sleep(1);
    //     //d_loader->loadLibrary("./lib/lib_arcade_ncurses.so");
    //     //d = d_loader->getInstance();
    // }
    //     d.putLine(20, 30, 20, 50);
    //     d.putPixel(120, 120);
    //     d.putRect(100, 10, 50, 50);
    //     d.putFillRect(200, 200, 100, 50);
    //     // d.putText("a", 5, 10, 10);
    //     if (d.isKeyPressed(IDisplayModule::Keys::A))
    //         d.LoadNextLib();
    //     //     break;
    //     d.render();
    //     if (d.shouldExit() == true)
    //         break;
    // }
    // return 0;
    //DLLoader<IDisplayModule> *libLoader = std::make_unique DLLoader<IDisplayModule>("test"); // (DLLoader<IDisplayModule>("./lib/lib_arcade_sfml.so"))
    //std::unique_ptr<DLLoader<IDisplayModule>> loader = std::make_unique<DLLoader<IDisplayModule>>("test");


    //DLLoader<IDisplayModule>("test");
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