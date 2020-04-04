/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include <memory>

static int ghst = 1;

Pacman::Pacman() : _lib_name("lib_arcade_pacman.so")
{
    this->_player =  new Player(240, 216);
    this->_map = new MapPacman();
    this->x1 = 0;
    this->y1 = 0;
    this->_ghosts.push_back(Ghosts(IDisplayModule::Colors::MAGENTA, 240));
    this->_ghosts.push_back(Ghosts(IDisplayModule::Colors::RED, 217));
    this->_ghosts.push_back(Ghosts(IDisplayModule::Colors::BLUE, 264));
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
    std::vector<std::pair<std::string, int>> bestscore;
    return (bestscore);
}

void Pacman::update(const IDisplayModule &lib)
{
    clock_t end = clock();

    _player->setDirection(lib);
    _player->checkFood(_map);
    _player->movePlayer(_map);
    if (this->checkTest() == true) {
        _player->setHealth(-1);
        _player->resetPos(240, 216);
        this->_begin = clock();
        this->_ghosts.erase(this->_ghosts.begin(), this->_ghosts.end());
        this->_ghosts.push_back(Ghosts(IDisplayModule::Colors::MAGENTA, 240));
        this->_ghosts.push_back(Ghosts(IDisplayModule::Colors::RED, 217));
        this->_ghosts.push_back(Ghosts(IDisplayModule::Colors::BLUE, 264));
    }
    
    double duration = (end - this->_begin)/(double)CLOCKS_PER_SEC;

    for (std::vector<Ghosts>::iterator it = this->_ghosts.begin(); it != this->_ghosts.end(); it++) {
        if ((duration > 2.0)  && (ghst == 1) && (it->getFree() == false)) {
            it->setFree(true);
            it->setPosY(144, 136);
            it->setFuturDirection(1);
        }
        if ((duration > 5.0)  && (ghst == 2) && (it->getFree() == false)) {
            it->setFree(true);
            it->setPosY(144, 136);
            it->setPosX(240, 240);
            it->setFuturDirection(0);
        }
        if ((duration > 8.0)  && (ghst == 3) && (it->getFree() == false)) {
            it->setFree(true);
            it->setPosY(144, 136);
            it->setPosX(240, 240);
            it->setFuturDirection(1);
        }
        if (it->getFree() == true) {
            it->setDirection(_map);
            it->moveGhost(_map);
        }
        ghst++;
    }
    ghst = 1;

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
    for (std::vector<Ghosts>::const_iterator it = this->_ghosts.begin(); it != this->_ghosts.end(); it++)
        it->draw(lib);
}

const std::string &Pacman::getLibName() const
{
    return (this->_lib_name);
}

extern "C" std::unique_ptr<IGameModule> createLib(void)
{
    return std::make_unique<Pacman>();
}

bool Pacman::checkTest(void)
{
    for (std::vector<Ghosts>::iterator it = this->_ghosts.begin(); it != this->_ghosts.end(); it++) {
        if (it->checkCollision(_player->getPosX(), _player->getPosY(), _player->getWidth(), _player->getHeight()) == true)
            return true;
    }
    return false;
}