/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include <memory>
#include <ctime>

Nibbler::Nibbler()
{
    this->_caterpillar = new Caterpillar();
    this->_map = new MapNibbler();
    this-> _scorelevel = 0;
    this->_score = 0;
    this->_time = 990;
    this->_level = 1;
}

void Nibbler::reset()
{
    this->_caterpillar->reset();
    this->_map->reset();
    this->_score = 0;
    this->_time = 990;
    this->_level = 1;
    this->_scorelevel = 0;
}

bool Nibbler::loadFromFile(const std::string &filepath)
{
    (void)filepath;
    return false;
}

bool Nibbler::loadFromFile()
{
    return false;
}

bool Nibbler::saveToFile(const std::string &filepath) const
{
    (void)filepath;
    return false;
}

bool Nibbler::saveToFile() const
{
    return false;
}

void Nibbler::setPlayerName(const std::string &name)
{
    this->_name = name;
}

std::pair<std::string, int> Nibbler::getScore() const
{

}

std::vector<std::pair<std::string, int>> Nibbler::getBestScores() const
{

}

static float count_second(clock_t backup_clock)
{
    double result = 0;
    result = clock() - backup_clock;
    result *= 0.000001;
    return (result);
}

void Nibbler::update(const IDisplayModule &lib)
{
    static std::clock_t start = std::clock();
    if (count_second(start) > 0.5) {
        start = std::clock();
        this->_time -= 10;
    }
    if (this->_map->getEat() * 10 != this->_scorelevel) {
        this->_scorelevel += 10;
        this->_score += 10;
    }
    if (this->_caterpillar->isWin() == false && this->_caterpillar->isLose() == false) {
        this->_caterpillar->moveCaterpillar(_map);
        this->_caterpillar->checkCandies(_map);
        this->_caterpillar->setDirection(lib);
        this->_caterpillar->checkWin(_map);
        this->_caterpillar->checkLose();
    }
    if (this->_caterpillar->isWin() == true)
    {
        this->_caterpillar->reset();
        this->_map->reset();
        this->_score += this->_time;
        this->_scorelevel = 0;
        this->_time = 990;
        this->_level++;
        this->_caterpillar->incSpeed();
    }
    if (this->_caterpillar->isLose()) {
        if (lib.isKeyPressed(IDisplayModule::Keys::SPACE)) {
            reset();
        }
    }
}

void Nibbler::render(IDisplayModule &lib) const
{
    lib.setColor(IDisplayModule::RED);
    lib.putText("NIBBLER", 30, 250, 0);
    
    
    if (this->_caterpillar->isWin() == false && this->_caterpillar->isLose() == false) {
        lib.setColor(IDisplayModule::Colors::YELLOW);
        lib.putText("SCORE :", 24, 150, 50);
        lib.setColor(IDisplayModule::Colors::WHITE);
        lib.putText(std::to_string(this->_score), 24, 250, 50);
        lib.setColor(IDisplayModule::Colors::YELLOW);
        lib.putText("LEVEL :", 24, 150, 400);
        lib.setColor(IDisplayModule::Colors::WHITE);
        lib.putText(std::to_string(this->_level), 24, 250, 400);
        lib.setColor(IDisplayModule::Colors::YELLOW);
        lib.putText("TIME :", 24, 320, 50);
        lib.setColor(IDisplayModule::Colors::WHITE);
        lib.putText(std::to_string(this->_time), 24, 400, 50);
        lib.setColor(IDisplayModule::Colors::WHITE);
        this->_map->draw_blocks(lib);
        this->_map->draw_candies(lib);
        this->_caterpillar->displayCaterpillar(lib);
    }
    if (this->_caterpillar->isLose() == true)
    {
        lib.setColor(IDisplayModule::RED);
        lib.putText("YOU LOSE !!!", 30, 220, 160);
        lib.setColor(IDisplayModule::Colors::YELLOW);
        lib.putText("SCORE :", 24, 240, 195);
        lib.setColor(IDisplayModule::Colors::WHITE);
        lib.putText(std::to_string(this->_score), 24, 350, 195);
        lib.setColor(IDisplayModule::WHITE);
        lib.putText("PRESS 'SPACE' TO REPLAY", 30, 130, 300);
    }
    
}

const std::string &Nibbler::getLibName() const
{

}

extern "C" std::unique_ptr<IGameModule> createLib(void)
{
    return std::make_unique<Nibbler>();
}