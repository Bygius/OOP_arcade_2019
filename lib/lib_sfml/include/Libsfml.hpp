/*
** EPITECH PROJECT, 2020
** lib_sfml
** File description:
** libsfml
*/

#ifndef LIBSFML_HPP_
#define LIBSFML_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Arcade_interfaces.hpp"
#include <memory>

class Libsfml : public IDisplayModule
{
    private:
        std::unique_ptr<sf::RenderWindow> _window;
        sf::Color _color;

    public:
        Libsfml();
        
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
};

#endif /* !LIBSFML_HPP_ */
