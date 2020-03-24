/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Libncurses
*/

#ifndef LIBNCURSES_HPP_
#define LIBNCURSES_HPP_

#include <curses.h>
#include "Arcade_interfaces.hpp"

class Libncurses : public IDisplayModule
{
    public:
        Libncurses();
        ~Libncurses();

        void reset();
        bool isOpen() const;

        bool switchToNext_lib() const;
        bool switchToPrevious_lib() const;
        bool switchToNext_game() const;
        bool switchToPrevious_game() const;
        bool shouldBeRestarted() const;
        bool shouldGoToMenu() const;
        bool shouldExit() const;

        bool isKeyPressed(IDisplayModule::Keys) const;
        bool isKeyPressedOnce(IDisplayModule::Keys) const;
        float getDelta() const;
        void clear() const;
        void update();
        void render() const;
        char getKeyCode() const;

        void setColor(IDisplayModule::Colors col);
        void putPixel(float x, float y) const;
        void putLine(float x1, float y1, float x2, float y2) const;
        void putRect(float x, float y, float w, float h) const;
        void putFillRect(float x, float y, float w, float h) const;
        void putCircle(float x, float y, float rad) const;
        void putFillCircle(float x, float y, float rad) const;
        void putText(const std::string &text, unsigned int size, float x, float y) const;
        const std::string &getLibName() const;


    protected:
    private:
};

void my_clear();
int resize(int x);

#endif /* !LIBNCURSES_HPP_ */
