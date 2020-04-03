/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "../include/Core.hpp"
#include "dirent.h"
#include <string.h>
#include <algorithm>
#include "Error.hpp"

static std::vector<std::string> getLiblist(const char *path)
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
void Core::reloadLibrary(std::unique_ptr<DLLoader<T>> &loader, std::unique_ptr<T> &module, const char *lib_name)
{
    module.reset();
    module.release();
    loader->loadLibrary(lib_name);
    module = loader->getInstance();
}

template <typename T>
void Core::loadNextLibrary(std::unique_ptr<DLLoader<T>> &loader, std::unique_ptr<T> &module)
{
    std::vector<std::string> list = getLiblist(loader->getLibPath().c_str());
    auto pos = std::find(list.begin(), list.end(), loader->getLibName());

    if (list.size() == 0)
        return;
    if (pos == list.end()-1 || pos == list.end())
        reloadLibrary(loader, module, list.front().c_str());
    else {
        pos++;
        reloadLibrary(loader, module, pos->c_str());
    }
}

template <typename T>
void Core::loadPreviousLibrary(std::unique_ptr<DLLoader<T>> &loader, std::unique_ptr<T> &module)
{
    std::vector<std::string> list = getLiblist(loader->getLibPath().c_str());
    auto pos = std::find(list.begin(), list.end(), loader->getLibName());

    if (list.size() == 0)
        return;
    if (pos == list.begin() || pos == list.end())
        reloadLibrary(loader, module, list.back().c_str());
    else {
        pos--;
        reloadLibrary(loader, module, pos->c_str());
    }
}

void Core::updateLibrary(void)
{
    static bool status = false;

    if (_display_module->switchToNextLib()) {
        if (status) { // N
            _display_module->close();
            loadNextLibrary(_display_module_loader, _display_module);
            _display_module->open();
            status = false;
        }
    } else if (_display_module->switchToPreviousLib()) {
        if (status) { // B
            _display_module->close();
            loadPreviousLibrary(_display_module_loader, _display_module);
            _display_module->open();
            status = false;
        }
    } else if (_display_module->switchToNextGame()) {
        if (status) { // P
            loadNextLibrary(_game_module_loader, _game_module);
            status = false;
        }
    } else if (_display_module->switchToPreviousGame()) {
        if (status) { // 0
            loadPreviousLibrary(_game_module_loader, _game_module);
            status = false;
        }
    } else
        status = true;
}

void Core::run(void)
{
    _display_module->open();
    while (_display_module->isOpen()) {
        _display_module->clear();
        _display_module->update();
        updateLibrary();
        if (_display_module->shouldExit())
            break;
        _game_module->update(*_display_module);
        _game_module->render(*_display_module);
        _display_module->render();
    }
    _display_module->close();
}

Core::Core(std::string dipslay_module_path)
{
    try {
        _display_module_loader = std::make_unique<DLLoader<IDisplayModule>>("./lib/", "./lib/lib_arcade_sfml.so");
        _game_module_loader = std::make_unique<DLLoader<IGameModule>>("./games/", "./games/lib_arcade_pacman.so");
        _display_module = _display_module_loader->getInstance();
        _game_module = _game_module_loader->getInstance();
    } catch (Error const &e) {
        throw CoreError(std::string(e.what()));
    }
}

Core::~Core()
{
}
