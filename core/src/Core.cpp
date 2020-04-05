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
            _game_module->setPlayerName(_player_name);
            status = false;
        }
    } else if (_display_module->switchToPreviousGame()) {
        if (status) { // 0
            loadPreviousLibrary(_game_module_loader, _game_module);
            _game_module->setPlayerName(_player_name);
            status = false;
        }
    } else
        status = true;
}

void Core::displayButton(std::vector<std::string> list, int cursor_x, int cursor_y, int max_y, int column)
{
    size_t cut;
    for (int i = 1; i <= max_y; i++) {
        cut = list[i-1].find("_arcade_") + strlen("_arcade_");
        if (((column == 1) ? _display_module_loader->getLibName(): _game_module_loader->getLibName()) == list[i-1])
            _display_module->setColor(IDisplayModule::GREEN);
        if (cursor_x == column && cursor_y == i)
            _display_module->setColor(IDisplayModule::RED);
        _display_module->putText(list[i-1].substr(cut, list[i-1].length() - (cut + 3)), 20, ((column == 1) ? 30 : 250), 120 + (30 * i));
        _display_module->setColor(IDisplayModule::WHITE);
    }
}

void Core::actionButton(std::vector<std::string> liblist, std::vector<std::string> gamelist, int cursor_x, int cursor_y)
{
    static bool load_status = false;
    if (_display_module->isKeyPressed(IDisplayModule::ENTER)) {
        if (load_status) {
            if (cursor_x == 1) {
                try {
                    load_status = false;
                    _display_module->close();
                    reloadLibrary(_display_module_loader, _display_module, liblist[cursor_y - 1].data());
                    _display_module->open();
                } catch (const std::exception &e) {
                    throw LibError(e.what());
                }
            } else {
                load_status = false;
                try {
                    reloadLibrary(_game_module_loader, _game_module, gamelist[cursor_y - 1].data());
                    _game_module->setPlayerName(_player_name);
                    //_game_module->loadFromFile();
                } catch (const std::exception &e) {
                    throw GameError(e.what());
                }
            }
        }
    } else
        load_status = true;
}

void Core::displayScores(void)
{
    int i = 0;
    std::vector<std::pair<std::string, int>> bestscore;
    if (!_game_module->loadFromFile())
        return;
    try {
        bestscore = _game_module->getBestScores();
    } catch (const std::exception &e) {
        throw CoreError("Cannot load best score");
    }
    _display_module->setColor(IDisplayModule::WHITE);
    for (std::vector<std::pair<std::string, int>>::const_iterator it = bestscore.begin(); it != bestscore.end(); it++)
        _display_module->putText(std::to_string(it->second) , 15, 450, 150 + (i++ * 20));

}

void Core::menu(void)
{
    static int x_pos = 1;
    static int y_pos = 1;
    static bool status = false;
    static clock_t elapsed = clock();

    std::vector<std::string> libList = getLiblist("./lib/");
    std::vector<std::string> gameList = getLiblist("./games/");

    int nb_lib = libList.size();
    int nb_game = gameList.size();

    _display_module->setColor(IDisplayModule::WHITE);
    _display_module->putText("Coronarcade" , 40, 200, 20);
    _display_module->putText("Select a lib" , 25, 30, 100);
    _display_module->putText("Select a game" , 25, 250, 100);
    _display_module->putText("High scores" , 25, 450, 100);

    displayButton(libList, x_pos, y_pos, (int)libList.size(), 1);
    displayButton(gameList, x_pos, y_pos, (int)gameList.size(), 2);

    std::string previous_game = _game_module_loader->getLibName(); // manage the case when an error occur when the new game is running

    try {
        actionButton(libList, gameList, x_pos, y_pos);
    } catch (const LibError &e) {
        std::cout << e.what() << std::endl;
        try {
            reloadLibrary(_display_module_loader, _display_module, _display_module_loader->getLibName().c_str());
        } catch (LibError &e) {
            throw CoreError("CoreError : No functional lib");
        }
        _display_module->open();
    } catch (const GameError &e) {
        std::cout << e.what() << std::endl;
        try {
            reloadLibrary(_game_module_loader, _game_module, previous_game.c_str());
        } catch (LibError &e) {
            throw CoreError("CoreError : No functional lib");
        }
    }
    if (x_pos == 1 && y_pos >= nb_lib)
        y_pos = nb_lib;
    else if (x_pos == 2 && y_pos >= nb_game)
        y_pos = nb_game;

    if (_display_module->isKeyPressed(IDisplayModule::UP)) {
        if (status) {
            if (y_pos == 1)
                y_pos = (x_pos == 1) ? nb_lib : nb_game;
            else
                y_pos--;
            status = false;
            elapsed = clock();
        }
    }
    else if (_display_module->isKeyPressed(IDisplayModule::DOWN)) {
        if (status) {
            if (x_pos == 1 && y_pos == nb_lib)
                y_pos = 1;
            else if (x_pos == 2 && y_pos == nb_game)
                y_pos = 1;
            else
                y_pos++;
            status = false;
            elapsed = clock();
        }
    } else if (_display_module->isKeyPressed(IDisplayModule::RIGHT)) {
        if (status) {
            if (x_pos == 2) {
                x_pos = 1;
                if (y_pos > nb_lib)
                    y_pos = nb_lib;
            } else {
                if (y_pos > nb_game)
                    y_pos = nb_game;
                x_pos++;
            }
            status = false;
            elapsed = clock();
        }
    } else if (_display_module->isKeyPressed(IDisplayModule::LEFT)) {
        if (status) {
            if (x_pos == 1) {
                x_pos = 2;
                if (y_pos > nb_game)
                    y_pos = nb_game;
            } else {
                if (y_pos > nb_lib)
                    y_pos = nb_lib;
                x_pos--;
            }
            status = false;
            elapsed = clock();
        }
    }
    else
        status = true;
    if (((clock() - elapsed) * 0.00001) > 1) {
        status = true;
        elapsed = clock();
    }
    displayScores();
}

void Core::EnterPlayerName()
{
    static std::string name = " ";
    static bool is_pressed = false;

    char buff = _display_module->getKeyCode();

    _display_module->putText("Enter your Name :", 20, 10, 10);
    if (((buff >= 'A' && buff <= 'Z') || (buff >= 'a' && buff <= 'z')) && is_pressed == false) {
        name += buff;
        is_pressed = true;
    } else if (_display_module->isKeyPressed(IDisplayModule::BACKSPACE)) {
        if (name.size() > 1)
            name = name.substr(0, name.size()-1);
        is_pressed = true;
    } else {
        is_pressed = false;
    }
    _display_module->setColor(IDisplayModule::WHITE);
    _display_module->putText(name, 20, 20, 50);
    if (_display_module->isKeyPressed(IDisplayModule::ENTER) && name.size() > 1) {
         _set_name  = false;
         _player_name = name.substr(1, name.size());
    }
    // _display_module->putText(_player_name.c_str() , 20, 450, 70);
}

void Core::run(void)
{
    _display_module->open();
    while (_display_module->isOpen()) {
        _display_module->update();
        _display_module->clear();
        if (_display_module->shouldExit())
            break;
        if (_set_name)
            EnterPlayerName();
        else {
            updateLibrary();
            if (_display_module->shouldGoToMenu())
                _menu = true;
            if (_menu && _display_module->isKeyPressed(IDisplayModule::SPACE))
                _menu = false;
            if (_menu)
                menu();
            else {
                _game_module->update(*_display_module);
                _game_module->render(*_display_module);
            }
        }
        try {
            _display_module->render();
        } catch (const std::exception &e) {
            _display_module->close();
            throw Error(e.what());
        }
    }
    _display_module->close();
}

Core::Core(std::string dipslay_module_path)
{
    std::vector<std::string> gameList = getLiblist("./games/");
    if (gameList.size() == 0)
        throw CoreError("Arcade need a least one game to run");
    _set_name = true;
    _display_module_loader = std::make_unique<DLLoader<IDisplayModule>>("./lib/", dipslay_module_path);
    _game_module_loader = std::make_unique<DLLoader<IGameModule>>("./games/", gameList[0]);
    std::cout << "Default game loaded : " << gameList[0] << std::endl;
    _display_module = _display_module_loader->getInstance();
    _game_module = _game_module_loader->getInstance();
    _menu = true;
}

Core::~Core()
{

}
