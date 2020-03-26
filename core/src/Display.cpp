/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Libncurses
*/

#include "Display.hpp"
#include <memory>

Display::Display(const std::string lib_path) : lib_path(lib_path)
{

}

Display::~Display()
{

}

void Display::reset()
{
    this->actual_lib->reset();
}

bool Display::isOpen() const
{
    return this->actual_lib->isOpen();
}

bool Display::switchToNext_lib() const
{
    return this->actual_lib->switchToNext_lib();
}

bool Display::switchToPrevious_lib() const
{
    return this->actual_lib->switchToPrevious_lib();
}

bool Display::switchToNext_game() const
{
    return this->actual_lib->switchToNext_game();

}

bool Display::switchToPrevious_game() const
{
    return this->actual_lib->switchToPrevious_game();
}

bool Display::shouldBeRestarted() const
{
    return this->actual_lib->shouldBeRestarted();
}

bool Display::shouldGoToMenu() const
{
    return this->actual_lib->shouldGoToMenu();
}

bool Display::shouldExit() const
{
    return this->actual_lib->shouldExit();
}

bool Display::isKeyPressed(IDisplayModule::Keys k) const
{
    return this->actual_lib->isKeyPressed(k);
}

bool Display::isKeyPressedOnce(IDisplayModule::Keys k) const
{
    return this->actual_lib->isKeyPressed(k);
}

float Display::getDelta() const
{
    return this->actual_lib->getDelta();
}

void Display::clear() const
{
    this->actual_lib->clear();
}

void Display::update()
{
    this->actual_lib->update();
}

void Display::render() const
{
    this->actual_lib->render();
}

char Display::getKeyCode() const
{
    return this->actual_lib->getKeyCode();
}

void Display::setColor(IDisplayModule::Colors color)
{
    this->actual_lib->setColor(color);
}

void Display::putPixel(float x, float y) const
{
    this->actual_lib->putPixel(x, y);
}

void Display::putLine(float x1, float y1, float x2, float y2) const
{
    this->actual_lib->putLine(x1, y1, x2, y2);
}


void Display::putRect(float x, float y, float w, float h) const
{
    this->actual_lib->putRect(x, y, w, h);
}

void Display::putFillRect(float x, float y, float w, float h) const
{
    this->actual_lib->putFillRect(x, y, w, h);
}


void Display::putCircle(float x, float y, float rad) const
{
    this->actual_lib->putCircle(x, y, rad);
}

void Display::putFillCircle(float x, float y, float rad) const
{
    this->actual_lib->putFillCircle(x, y, rad);
}

void Display::putText(const std::string &text, unsigned int size, float x, float y) const
{
    this->actual_lib->putText(text, size, x, y);
}

const std::string &Display::getLibName() const
{
    return this->actual_lib->getLibName();
}