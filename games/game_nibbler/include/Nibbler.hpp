/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "Arcade_interfaces.hpp"

class Nibbler : public IGameModule
{
    private:
        int x1;
        int y1;
        IDisplayModule &_lib;
    public:
        Nibbler(IDisplayModule &);
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

#endif /* !Nibbler_HPP_ */