/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "Arcade_interfaces.hpp"

class Snake : public IGameModule
{
    private:
        int x1;
        int y1;
        IDisplayModule &_lib;
    public:
        Snake(IDisplayModule &);
        virtual ~Snake() = default;

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

#endif /* !SNAKE_HPP_ */