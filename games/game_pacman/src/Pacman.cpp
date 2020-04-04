/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include <memory>

static bool first = true;

Pacman::Pacman()
{
    this->_player =  new Player(240, 216);
    this->_map = new MapPacman();
    this->x1 = 0;
    this->y1 = 0;
    this->_ghosts.push_back(Ghosts(IDisplayModule::Colors::RED, 217));
    this->_ghosts.push_back(Ghosts(IDisplayModule::Colors::BLUE, 264));
    this->_ghosts.push_back(Ghosts(IDisplayModule::Colors::YELLOW, 240));
    this->_begin = clock();
}

void Pacman::reset()
{

}

bool Pacman::loadFromFile(const std::string &filepath)
{
    (void)filepath;
    return false;
}

bool Pacman::loadFromFile()
{
    return false;
}

bool Pacman::saveToFile(const std::string &filepath) const
{
    (void)filepath;
    return false;
}

bool Pacman::saveToFile() const
{
    return false;
}

void Pacman::setPlayerName(const std::string &name)
{
    this->_name = name;
}

std::pair<std::string, int> Pacman::getScore() const
{
    std::pair <std::string, int> score;
    score.first = this->_name;
    score.second = _map->countScore();
    return (score);
}

std::vector<std::pair<std::string, int>> Pacman::getBestScores() const
{

}

void Pacman::update(const IDisplayModule &lib)
{
    int i = 0;
    _player->setDirection(lib);
    _player->checkFood(_map);
    _player->movePlayer(_map);
    for (std::vector<Ghosts>::iterator it = this->_ghosts.begin(); it != this->_ghosts.end(); it++) {
        clock_t end;
        if ((end = clock())-this->_begin * 1000 > 2  && i == 0) {
            it->setDirection(_map);
            it->moveFantom(_map);
        }
        if ((end = clock())-this->_begin * 1000 > 5  && i == 1) {
            it->setDirection(_map);
            it->moveFantom(_map);
        }
        if ((end = clock())-this->_begin * 1000 > 10  && i == 2) {
            it->setDirection(_map);
            it->moveFantom(_map);
        }
        i++;
    }

}

void Pacman::render(IDisplayModule &lib) const
{
    std::string score = std::to_string(this->getScore().second);

    lib.putText("PACMAN", 30, 250, 0);
    lib.putText("SCORE : ", 30, 100, 300);
    lib.putText(score, 30, 240, 300);
    _map->display_collisions(lib);
    _map->draw_food(lib);
    lib.setColor(IDisplayModule::YELLOW);
    _player->displayPlayer(lib);
    for (std::vector<Ghosts>::const_iterator it = this->_ghosts.begin(); it != this->_ghosts.end(); it++)
        it->draw(lib);
}

const std::string &Pacman::getLibName() const
{
    return ("a");
}

extern "C" std::unique_ptr<IGameModule> createLib(void)
{
    return std::make_unique<Pacman>();
}