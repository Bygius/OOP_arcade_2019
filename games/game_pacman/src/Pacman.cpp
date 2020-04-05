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
    this->_game = std::make_unique<GameHandling>(1);
    this->x1 = 0;
    this->y1 = 0;
    this->_ghosts.push_back(std::make_unique<Ghosts>(IDisplayModule::Colors::MAGENTA, 240, _game->get_lvl()));
    this->_ghosts.push_back(std::make_unique<Ghosts>(IDisplayModule::Colors::RED, 217, _game->get_lvl()));
    this->_ghosts.push_back(std::make_unique<Ghosts>(IDisplayModule::Colors::BLUE, 264, _game->get_lvl()));
    this->_begin = clock();
}

void Pacman::reset()
{
    this->_player->reset(240, 216);
    this->_map->reset();
    this->_begin = clock();
    this->_ghosts.erase(this->_ghosts.begin(), this->_ghosts.end());
    this->_ghosts.push_back(std::make_unique<Ghosts>(IDisplayModule::Colors::MAGENTA, 240, _game->get_lvl()));
    this->_ghosts.push_back(std::make_unique<Ghosts>(IDisplayModule::Colors::RED, 217, _game->get_lvl()));
    this->_ghosts.push_back(std::make_unique<Ghosts>(IDisplayModule::Colors::BLUE, 264, _game->get_lvl()));
}

bool compare(const std::pair<std::string, int>&i, const std::pair<std::string, int>&j)
{
    return (i.second > j.second);
}

bool Pacman::loadFromFile(const std::string &filepath)
{
    std::ifstream file;
    std::string delimiter = ":";
    std::string line;
    size_t index;
    std::string name = "";
    int score;

    file.open(filepath);
    if (!file)
        return (false);
    while (std::getline(file, line)) {
        index = line.find(delimiter);
        name = line.substr(0, index);
        std::istringstream(line.substr(index + 1, line.length() - index)) >> score;
        this->_bestscore.push_back(make_pair(name, score));
    }
    std::sort(this->_bestscore.begin(), this->_bestscore.end(), compare);
    return (true);
}

bool Pacman::loadFromFile()
{
    std::ifstream file;
    std::string delimiter = ":";
    std::string line;
    size_t index;
    std::string name = "";
    int score;

    file.open("games/.saves/Pacman");
    if (!file)
        return (false);
    while (std::getline(file, line)) {
        index = line.find(delimiter);
        name = line.substr(0, index);
        std::istringstream(line.substr(index + 1, line.length() - index)) >> score;
        this->_bestscore.push_back(make_pair(name, score));
    }
    std::sort(this->_bestscore.begin(), this->_bestscore.end(), compare);
    return (true);
}

bool Pacman::saveToFile(const std::string &filepath) const
{
    std::ofstream file;
    std::string new_score = "\n" + this->_name + ":" + this->_score;

    file.open(filepath, std::ios::app);
    if (!file)
        return (false);
    file << new_score;
    file.close();
    return true;
}

bool Pacman::saveToFile() const
{
    std::ofstream file;
    std::string new_score = "\n" + this->_name + ":" + this->_score;

    file.open("games/.saves/Pacman", std::ios::app);
    if (!file)
        return (false);
    file << new_score;
    file.close();
    return true;
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
    return (this->_bestscore);
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
    static bool saving = false;

    _player->setDirection(lib);
    _player->checkFood(_map);
    _player->movePlayer(_map);
    if (this->checkHit() == true) {
        if (this->_game->check_loose(this->_player) == true) {
            this->_score = std::to_string(this->getScore().second + this->_game->get_score());
            this->_game->save_score(std::stoi(this->_score));
        }
        _player->setHealth(-1);
        _player->resetPos(240, 216);
        this->_begin = clock();
        this->_ghosts.erase(this->_ghosts.begin(), this->_ghosts.end());
        this->_ghosts.push_back(std::make_unique<Ghosts>(IDisplayModule::Colors::MAGENTA, 240, _game->get_lvl()));
        this->_ghosts.push_back(std::make_unique<Ghosts>(IDisplayModule::Colors::RED, 217, _game->get_lvl()));
        this->_ghosts.push_back(std::make_unique<Ghosts>(IDisplayModule::Colors::BLUE, 264, _game->get_lvl()));
    }
    if (this->_game->get_loose() == false)
        this->_score = std::to_string(this->getScore().second + this->_game->get_score());
    this->_bestscore = this->getBestScores();
    this->freeGhosts();
    if (this->_game->check_win(this->_map, std::stoi(this->_score)))
        this->reset();
    if (this->_game->get_loose()) {
        if (saving == false) {
            this->saveToFile();
            saving = true;
        }
        if (lib.isKeyPressed(IDisplayModule::Keys::SPACE)) {
            saving = false;
            _game->set_loose(false);
            _game->reset();
            reset();
        }
    }
        
}

void Pacman::render(IDisplayModule &lib) const
{
    if (this->_game->get_loose() == false) {
        lib.setColor(IDisplayModule::Colors::YELLOW);
        lib.putText("PACMAN", 30, 250, 0);
        lib.putText("SCORE : ", 30, 100, 300);
        lib.putText(_score, 30, 240, 300);
        _player->drawHealth(lib);
        _map->display_collisions(lib);
        _map->draw_food(lib);
        lib.setColor(IDisplayModule::YELLOW);
        _player->displayPlayer(lib);
        for (std::vector<std::unique_ptr<Ghosts>>::const_iterator it = this->_ghosts.begin(); it != this->_ghosts.end(); it++)
            it->get()->draw(lib);
    }
    if (this->_game->get_loose() == true) {
        this->_game->draw_loose(lib);
    }
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