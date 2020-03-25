/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Lib
*/

#ifndef LIB_HPP_
#define LIB_HPP_

#include <string>
#include <vector>
#include "../../include/Arcade_interfaces.hpp"
#include <memory>

class Lib {
    public:
        void PrintAllLib(void) const;
        bool RefreshLibList(void);
        bool SetCurrentLib(const std::string lib_name);
        Lib(const std::string lib_dir);
        ~Lib();
    std::unique_ptr<IDisplayModule> actual_lib;

    protected:
    private:
        const std::string lib_path;
        std::vector<std::string> lib_list;
        std::string current_lib_name;

};

#endif /* !LIB_HPP_ */
