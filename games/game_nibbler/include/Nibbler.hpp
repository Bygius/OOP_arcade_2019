/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "Arcade_interfaces.hpp"
#include "Caterpillar.hpp"
#include "MapNibbler.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

class Nibbler : public IGameModule
{
    private:
        std::unique_ptr<Caterpillar> _caterpillar;
        std::unique_ptr<MapNibbler> _map;
        std::string _name;
        int _score;
        int _time;
        int _level;
        int _scorelevel;
        const std::string _libname;
        std::vector<std::pair<std::string, int>> _bestscore;

    public:
        Nibbler();
        virtual ~Nibbler() = default;

        void reset();
        bool loadFromFile(const std::string &filepath);
        bool loadFromFile();
        bool saveToFile(const std::string &filepath) const;
        bool saveToFile() const;
        void setPlayerName(const std::string &name);
        std::pair<std::string, int> getScore() const;
        std::vector<std::pair<std::string, int>> getBestScores() const;
        void update(const IDisplayModule &lib);
        void render(IDisplayModule &lib) const;
        const std::string &getLibName() const;
};

static bool compare(const std::pair<std::string, int>&i, const std::pair<std::string, int>&j);

#endif /* !Nibbler_HPP_ */