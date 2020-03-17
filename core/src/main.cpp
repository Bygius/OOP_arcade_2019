/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "../include/Core.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return(84);
    Core core(av[1]);
    core.start_arcade();
    return (0);
}