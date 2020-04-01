/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Libsdl
*/

#ifndef LIBSDL_HPP_
#define LIBSDL_HPP_

#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "Arcade_interfaces.hpp"
#include <SDL2/SDL_ttf.h>

class Libsdl : public IDisplayModule
{
    public:
        Libsdl();

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

        void set_exit(bool value);
    protected:
    private:
        // std::unique_ptr<SDL_Window> _window;
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        SDL_Event _event;
        SDL_Color _color;
        bool _exit;
        const std::string _lib_name;
};


#endif /* !Libsdl_HPP_ */
