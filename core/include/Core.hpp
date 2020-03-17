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

class Core {
    public:
        Core(std::string lib);
        ~Core();

        void start_arcade();
    protected:
    private:
        std::string _library;
};

#endif /* !CORE_HPP_ */
