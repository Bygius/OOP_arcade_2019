/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Libsdl
*/

#include "Libsdl.hpp"
#include <memory>
#include <math.h>

Libsdl::Libsdl()
{
}

Libsdl::~Libsdl()
{
}

void Libsdl::reset()
{
}
        
bool Libsdl::isOpen() const
{
    bool value = false;
    return (value);
}

bool Libsdl::switchToNext_lib() const
{
    return (false);
}

bool Libsdl::switchToPrevious_lib() const
{
    return (false);
}

bool Libsdl::switchToNext_game() const
{
    return (false);
}

bool Libsdl::switchToPrevious_game() const
{
    return (false);
}

bool Libsdl::shouldBeRestarted() const
{
    return (false);
}

bool Libsdl::shouldGoToMenu() const
{
    return (false);
}

bool Libsdl::shouldExit() const
{
    return (false);
}

bool Libsdl::isKeyPressed(IDisplayModule::Keys) const
{
    return (false);
}

bool Libsdl::isKeyPressedOnce(IDisplayModule::Keys) const
{
    return (false);
}

float Libsdl::getDelta() const
{
    return (0.00);
}

void my_clear()
{
    return;
}

void Libsdl::clear() const
{
    return;
}

void Libsdl::update()
{
    return;
}

void Libsdl::render() const
{
}

char Libsdl::getKeyCode() const
{
    return ('a');
}

void Libsdl::setColor(IDisplayModule::Colors color)
{
    
}

void Libsdl::putPixel(float x, float y) const
{
}

void Libsdl::putLine(float x1, float y1, float x2, float y2) const
{
}

void Libsdl::putRect(float x, float y, float w, float h) const
{

}

void Libsdl::putFillRect(float x, float y, float w, float h) const
{

}

void Libsdl::putCircle(float x, float y, float rad) const
{

}

void Libsdl::putFillCircle(float x, float y, float rad) const
{
    (void) x;
    (void) y;
    (void) rad;
}

void Libsdl::putText(const std::string &text, unsigned int size, float x, float y) const
{
}

const std::string &Libsdl::getLibName() const
{
    return (this->_name);
}
extern "C" std::unique_ptr<IDisplayModule> createLib(void)
{
    return std::make_unique<Libsdl>();
}