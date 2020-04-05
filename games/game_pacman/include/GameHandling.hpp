/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameHandling
*/

#ifndef GAMEHANDLING_HPP_
#define GAMEHANDLING_HPP_

#include "Arcade_interfaces.hpp"
#include <memory>
#include "Player.hpp"
#include "MapPacman.hpp"

class GameHandling {
    public:
        GameHandling(int lvl);
        ~GameHandling();

        bool check_win(std::unique_ptr<MapPacman> &map, int score);
        int get_lvl(void) const;
        int get_score(void) const;
        void set_score(int score);
        void check_loose(std::unique_ptr<Player> &player);
        bool get_loose() const;
        void save_score(int score);
        void draw_loose(IDisplayModule &lib);


    protected:
    private:
        int lvl;
        int _score;
        bool loose;
};

#endif /* !GAMEHANDLING_HPP_ */
