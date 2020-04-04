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

class Pacman : public IGameModule
{
    private:
        int x1;
        int y1;
        std::string _name;
        Player *_player;
        MapPacman *_map;
        std::vector<Ghosts> _ghosts;
        clock_t _begin;

    public:
        Pacman();
        virtual ~Pacman() = default;

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

#endif /* !Pacman_HPP_ */