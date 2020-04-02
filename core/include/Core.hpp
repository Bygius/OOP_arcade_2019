/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include <iostream>
#include "../../include/Arcade_interfaces.hpp"
#include <memory>
#include "DLLoader.hpp"

class Core {
    public:
        Core(std::string display_module_path);
        ~Core();
        void run(void);
        void updateLibrary(void);

    protected:
    private:
        template <typename T> void loadNextLibrary(std::unique_ptr<DLLoader<T>> &loader, std::unique_ptr<T> &module);
        template <typename T> void loadPreviousLibrary(std::unique_ptr<DLLoader<T>> &loader, std::unique_ptr<T> &module);
        template <typename T> void reloadLibrary(std::unique_ptr<DLLoader<T>> &loader, std::unique_ptr<T> &module, const char *lib_name);

        std::unique_ptr<DLLoader<IDisplayModule>> _display_module_loader;
        std::unique_ptr<DLLoader<IGameModule>> _game_module_loader;
        std::unique_ptr<IDisplayModule> _display_module;
        std::unique_ptr<IGameModule> _game_module;
};

#endif /* !CORE_HPP_ */
