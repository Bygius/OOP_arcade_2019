/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Libncurses
*/

#ifndef LIBNCURSES_HPP_
#define LIBNCURSES_HPP_

#include <time.h>
#include <curses.h>
#include "Arcade_interfaces.hpp"

class Libncurses : public IDisplayModule
{
    public:
        Libncurses();
        ~Libncurses();

        void reset();
        void open();
        void close();
        bool isOpen() const;

        bool switchToNextLib() const;
        bool switchToPreviousLib() const;
        bool switchToNextGame() const;
        bool switchToPreviousGame() const;
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
        const std::string _lib_name;
        WINDOW *_win;
        bool _exit;
        int _input;
};

void my_clear();
int resize(int x, char c);
void print_circle(int x, int y, int radius);
void my_sleep();

#endif /* !LIBNCURSES_HPP_ */
