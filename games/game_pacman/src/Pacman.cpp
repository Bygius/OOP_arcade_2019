/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include <memory>

Pacman::Pacman() : _lib_name("Pacman")
{
    this->_player = std::make_unique<Player>(240, 216);
    this->_map = std::make_unique<MapPacman>();
    this->x1 = 0;
    this->y1 = 0;
    this->lvl = 1;
    this->_ghosts.push_back(std::make_unique<Ghosts>(IDisplayModule::Colors::MAGENTA, 240, this->lvl));
    this->_ghosts.push_back(std::make_unique<Ghosts>(IDisplayModule::Colors::RED, 217, this->lvl));
    this->_ghosts.push_back(std::make_unique<Ghosts>(IDisplayModule::Colors::BLUE, 264, this->lvl));
    this->_begin = clock();
}

void Pacman::reset()
{
    this->_player->reset(240, 216);
    this->_map->reset();
    this->_begin = clock();
    this->_ghosts.erase(this->_ghosts.begin(), this->_ghosts.end());
    this->_ghosts.push_back(std::make_unique<Ghosts>(IDisplayModule::Colors::MAGENTA, 240, this->lvl));
    this->_ghosts.push_back(std::make_unique<Ghosts>(IDisplayModule::Colors::RED, 217, this->lvl));
    this->_ghosts.push_back(std::make_unique<Ghosts>(IDisplayModule::Colors::BLUE, 264, this->lvl));
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
    std::vector<std::pair<std::string, int>> bestscore;
    return (bestscore);
}

void Pacman::freeGhosts(void)
{
    clock_t end = clock();
    double duration = (end - this->_begin)/(double)CLOCKS_PER_SEC;

    for (std::vector<std::unique_ptr<Ghosts>>::iterator it = this->_ghosts.begin(); it != this->_ghosts.end(); it++) {
        if ((duration > 1.0)  && (ghst == 1) && (it->get()->getFree() == false)) {
            it->get()->setFree(true);
            it->get()->setPosY(144, 136);
            it->get()->setFuturDirection(1);
        }
        if ((duration > 2.0)  && (ghst == 2) && (it->get()->getFree() == false)) {
            it->get()->setFree(true);
            it->get()->setPosY(144, 136);
            it->get()->setPosX(240, 240);
            it->get()->setFuturDirection(0);
        }
        if ((duration > 3.0)  && (ghst == 3) && (it->get()->getFree() == false)) {
            it->get()->setFree(true);
            it->get()->setPosY(144, 136);
            it->get()->setPosX(240, 240);
            it->get()->setFuturDirection(1);
        }
        if (it->get()->getFree() == true) {
            it->get()->setDirection(_map);
            it->get()->moveGhost(_map);
        }
        ghst++;
    }
    ghst = 1;
}

void Pacman::update(const IDisplayModule &lib)
{
    

    _player->setDirection(lib);
    _player->checkFood(_map);
    _player->movePlayer(_map);
    if (this->checkHit() == true) {
        _player->setHealth(-1);
        _player->resetPos(240, 216);
        this->_begin = clock();
        this->_ghosts.erase(this->_ghosts.begin(), this->_ghosts.end());
        this->_ghosts.push_back(std::make_unique<Ghosts>(IDisplayModule::Colors::MAGENTA, 240, this->lvl));
        this->_ghosts.push_back(std::make_unique<Ghosts>(IDisplayModule::Colors::RED, 217, this->lvl));
        this->_ghosts.push_back(std::make_unique<Ghosts>(IDisplayModule::Colors::BLUE, 264, this->lvl));
    }
    this->freeGhosts();
    this->win();
}

void Pacman::render(IDisplayModule &lib) const
{
    std::string score = std::to_string(this->getScore().second);

    lib.setColor(IDisplayModule::Colors::YELLOW);
    lib.putText("PACMAN", 30, 250, 0);
    lib.putText("SCORE : ", 30, 100, 300);
    lib.putText(score, 30, 240, 300);
    _player->drawHealth(lib);
    _map->display_collisions(lib);
    _map->draw_food(lib);
    lib.setColor(IDisplayModule::YELLOW);
    _player->displayPlayer(lib);
    for (std::vector<std::unique_ptr<Ghosts>>::const_iterator it = this->_ghosts.begin(); it != this->_ghosts.end(); it++)
        it->get()->draw(lib);
}

const std::string &Pacman::getLibName() const
{
    return (this->_lib_name);
}

extern "C" std::unique_ptr<IGameModule> createLib(void)
{
    return std::make_unique<Pacman>();
}

bool Pacman::checkHit(void)
{
    for (std::vector<std::unique_ptr<Ghosts>>::iterator it = this->_ghosts.begin(); it != this->_ghosts.end(); it++) {
        if (it->get()->checkCollision(_player->getPosX(), _player->getPosY(), _player->getWidth(), _player->getHeight()) == true)
            return true;
    }
    return false;
}

void Pacman::win(void)
{
    if (_map->winFood() == true) {
        this->reset();
        this->lvl *= 2;
    }
}