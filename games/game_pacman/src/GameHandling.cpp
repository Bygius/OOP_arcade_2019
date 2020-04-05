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
    this->loose = false;
}

GameHandling::~GameHandling()
{
}

void GameHandling::reset(void)
{
    this->loose = false;
    this->_score = 0;
    this->lvl = 1;
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

void GameHandling::set_loose(bool value)
{
    this->loose = value;
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

bool GameHandling::check_loose(std::unique_ptr<Player> &player)
{
    if (player->getHealth() == 1) {
        this->loose = true;
        return (true);
    }
        
    return (false);
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
    lib.putText("GAME OVER", 60, 140, 150);
    lib.putText("YOUR SCORE : ", 30, 190, 250);
    lib.putText(new_score, 30, 410, 250);
    lib.putText("(press space to restart)", 20, 210, 400);
    lib.render();
}