/*
** EPITECH PROJECT, 2020
** lib_one
** File description:
** libsfml
*/

#include "Libsfml.hpp"

Libsfml::Libsfml()
{
    this->_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), "My window");
    this->_color = sf::Color::White;
}

void Libsfml::reset()
{
}

bool Libsfml::isOpen() const
{
    return (this->_window->isOpen());
}

bool Libsfml::switchToNext_lib() const
{
}

bool Libsfml::switchToPrevious_lib() const
{
}

bool Libsfml::switchToNext_game() const
{
}

bool Libsfml::switchToPrevious_game() const
{
}

bool Libsfml::shouldBeRestarted() const
{
}

bool Libsfml::shouldGoToMenu() const
{
}

bool Libsfml::shouldExit() const
{
}

bool Libsfml::isKeyPressed(IDisplayModule::Keys) const
{
}

bool Libsfml::isKeyPressedOnce(IDisplayModule::Keys) const
{
}

float Libsfml::getDelta() const
{
}

void Libsfml::clear() const
{
    this->_window->clear();
}

void Libsfml::update()
{
}

void Libsfml::render() const
{
    this->_window->display();
}

char Libsfml::getKeyCode() const
{
}

void Libsfml::setColor(IDisplayModule::Colors color)
{
    switch (color)
    {
        case (DEFAULT):
            this->_color = sf::Color::White;
            break;
        case (BLACK):
            this->_color = sf::Color::Black;
            break;
        case (RED):
            this->_color = sf::Color::Red;
            break;
        case (GREEN):
            this->_color = sf::Color::Green;
            break;
        case (YELLOW):
            this->_color = sf::Color::Yellow;
            break;
        case (BLUE):
            this->_color = sf::Color::Blue;
            break;
        case (MAGENTA):
            this->_color = sf::Color::Magenta;
            break;
        case (CYAN):
            this->_color = sf::Color::Cyan;
            break;
        case (LIGHT_GRAY):
            this->_color = sf::Color::White;
            break;
        case (DARK_GRAY):
            this->_color = sf::Color::White;
            break;
        case (LIGHT_RED):
            this->_color = sf::Color::White;
            break;
        case (LIGHT_GREEN):
            this->_color = sf::Color::White;
            break;
        case (LIGHT_YELLOW):
            this->_color = sf::Color::White;
            break;
        case (LIGHT_BLUE):
            this->_color = sf::Color::White;
            break;
        case (LIGHT_MAGENTA):
            this->_color = sf::Color::White;
            break;
        case (LIGHT_CYAN):
            this->_color = sf::Color::White;
            break;
        default:
            printf("Bad color\n");
            break;
    }
}

void Libsfml::putPixel(float x, float y) const
{
    sf::VertexArray vertex(sf::Points, 1);
    vertex[0].position = sf::Vector2f(x, y);
    vertex[0].color = this->_color; 
    this->_window->draw(vertex);
}

void Libsfml::putLine(float x1, float y1, float x2, float y2) const
{
    sf::VertexArray vertex(sf::Lines, 2);
    vertex[0].position = sf::Vector2f(x1, y1);
    vertex[1].position = sf::Vector2f(x2, y2);
    vertex[0].color = this->_color;
    vertex[1].color = this->_color;
    this->_window->draw(vertex);
}

void Libsfml::putRect(float x, float y, float w, float h) const
{
}

void Libsfml::putFillRect(float x, float y, float w, float h) const
{
}

void Libsfml::putCircle(float x, float y, float rad) const
{
}

void Libsfml::putFillCircle(float x, float y, float rad) const
{
}

void Libsfml::putText(const std::string &text, unsigned int size, float x, float y) const
{
}

const std::string &Libsfml::getLibName() const
{

}

extern "C" std::unique_ptr<IDisplayModule> createLib(void)
{
    return std::make_unique<Libsfml>();
}