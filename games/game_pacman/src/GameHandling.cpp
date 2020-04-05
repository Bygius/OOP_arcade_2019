/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameHandling
*/

#include "GameHandling.hpp"

GameHandling::GameHandling(int lvl)
{
    this->lvl = lvl;
    this->_score = 0;
}

GameHandling::~GameHandling()
{
}

int GameHandling::get_lvl(void) const
{
    return (this->lvl);
}

int GameHandling::get_score(void) const
{
    return (this->_score);
}

void GameHandling::set_score(int score)
{
    this->_score = score;
}

bool GameHandling::get_loose(void) const
{
    return (this->loose);
}

bool GameHandling::check_win(std::unique_ptr<MapPacman> &map, int score)
{
    if (map->winFood() == true) {
        this->lvl *= 2;
        this->_score += score;
        return (true);
    }
    return (false);
        
}

void GameHandling::check_loose(std::unique_ptr<Player> &player)
{
    if (player->getHealth() == 1)
        this->loose = true;
    return;
}

void GameHandling::save_score(int score)
{
    this->_score += score;
}

void GameHandling::draw_loose(IDisplayModule &lib)
{
    std::string new_score = std::to_string(this->_score);

    lib.clear();
    lib.setColor(IDisplayModule::Colors::YELLOW);
    lib.putText("PACMAN", 30, 250, 0);
    lib.setColor(IDisplayModule::Colors::RED);
    lib.putText("GAME OVER", 60, 170, 150);
    lib.putText("YOUR SCORE : ", 30, 150, 300);
    lib.putText(new_score, 30, 370, 300);
    lib.putText("(press space to restart)", 20, 230, 400);
    lib.render();
}