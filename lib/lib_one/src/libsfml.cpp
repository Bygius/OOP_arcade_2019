/*
** EPITECH PROJECT, 2020
** lib_one
** File description:
** libsfml
*/

#include "libsfml.hpp"

Display::Display(size_t width, size_t height)
{
    this->window.create(sf::VideoMode(width, height), "My window");
    this->texture.create(width, height);
}

Display::~Display()
{

}

void Display::reset()
{

}
        
bool Display::is_open()
{
    return (this->window.isOpen());
}


void Display::clear()
{

    this->window.clear();
}

void Display::update()
{
    return;
}

void Display::render()
{
    this->window.display();
}