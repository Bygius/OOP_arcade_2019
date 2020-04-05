/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include <memory>
#include <ctime>

Nibbler::Nibbler() : _libname("Nibbler")
{
    this->_caterpillar = std::make_unique<Caterpillar>();
    this->_map = std::make_unique<MapNibbler>();
    this-> _scorelevel = 0;
    this->_score = 0;
    this->_time = 990;
    this->_level = 1;
}

void Nibbler::reset()
{
    this->_caterpillar->reset();
    this->_caterpillar->resetSpeed();
    this->_map->reset();
    this->_score = 0;
    this->_time = 990;
    this->_level = 1;
    this->_scorelevel = 0;
}

bool compare(const std::pair<std::string, int>&i, const std::pair<std::string, int>&j)
{
    return (i.second > j.second);
}

bool Nibbler::loadFromFile(const std::string &filepath)
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

bool Nibbler::loadFromFile()
{
    std::ifstream file;
    std::string delimiter = ":";
    std::string line;
    size_t index;
    std::string name = "";
    int score;

    file.open("./games/.saves/Nibbler");
    if (!file)
        return (false);
    while (std::getline(file, line)) {
        index = line.find(delimiter);
        name = line.substr(0, index);
        std::istringstream(line.substr(index + 1, line.length() - index)) >> score;
        this->_bestscore.push_back(make_pair(name, score));
    }
    std::sort(this->_bestscore.begin(), this->_bestscore.end(), compare);
    return (true);}

bool Nibbler::saveToFile(const std::string &filepath) const
{
    std::ofstream file;
    std::string new_score = "\n" + this->_name + ":" + std::to_string(this->_score);

    file.open(filepath, std::ios::app);
    if (!file)
        return (false);
    file << new_score;
    file.close();
    return true;
}

bool Nibbler::saveToFile() const
{
    std::ofstream file;
    std::string new_score = "\n" + this->_name + ":" + std::to_string(this->_score);

    file.open("games/.saves/Nibbler", std::ios::app);
    if (!file)
        return (false);
    file << new_score;
    file.close();
    return true;
}

void Nibbler::setPlayerName(const std::string &name)
{
    this->_name = name;
}

std::pair<std::string, int> Nibbler::getScore() const
{
    std::pair <std::string, int> ret;
    ret.first = this->_name;
    ret.second = this->_score;
    return ret;
}

std::vector<std::pair<std::string, int>> Nibbler::getBestScores() const
{
    return (this->_bestscore);
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
    if (this->_caterpillar->isLose() || this->_time <= 0) {
        if (lib.isKeyPressed(IDisplayModule::Keys::SPACE)) {
            this->saveToFile();
            reset();
        }
    }
}

void Nibbler::render(IDisplayModule &lib) const
{
    lib.setColor(IDisplayModule::RED);
    lib.putText(this->_libname, 30, 250, 0);
    
    
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
    return this->_libname;
}

extern "C" std::unique_ptr<IGameModule> createLib(void)
{
    return std::make_unique<Nibbler>();
}