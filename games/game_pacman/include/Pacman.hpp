/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "Arcade_interfaces.hpp"
#include "Player.hpp"
#include "MapPacman.hpp"
#include "Ghosts.hpp"
#include "GameHandling.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


class Pacman : public IGameModule
{
    private:
        int x1;
        int y1;
        std::string _name;
        const std::string _lib_name;
        std::unique_ptr<Player> _player;
        std::unique_ptr<MapPacman> _map;
        std::unique_ptr<GameHandling> _game;
        std::vector<std::unique_ptr<Ghosts>> _ghosts;
        clock_t _begin;
        int ghst;
        bool loose;
        std::string _score;
        std::vector<std::pair<std::string, int>> _bestscore;

    public:
        Pacman();
        virtual ~Pacman() = default;
        bool checkHit(void);

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
        void win(void);
        void draw_loose(IDisplayModule &lib) const;
        void freeGhosts(void);
};

#endif /* !Pacman_HPP_ */