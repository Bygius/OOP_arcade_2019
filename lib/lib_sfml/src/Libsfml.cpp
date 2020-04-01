/*
** EPITECH PROJECT, 2020
** lib_sfml
** File description:
** libsfml
*/

#include "Libsfml.hpp"

Libsfml::Libsfml() : _lib_name("lib_arcade_sfml.so")
{
    this->_color = sf::Color::White;
}

void Libsfml::reset()
{
    this->_color = sf::Color::White;
}

void Libsfml::open()
{
    this->_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), "My window");
    this->_window->setFramerateLimit(60);
}

void Libsfml::close()
{
    this->_window->close();
}

bool Libsfml::isOpen() const
{
    return (this->_window->isOpen());
}

bool Libsfml::switchToNextLib() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
        return true;
    return false;
}

bool Libsfml::switchToPreviousLib() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        return true;
    return false;
}

bool Libsfml::switchToNextGame() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        return true;
    return false;
}

bool Libsfml::switchToPreviousGame() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
        return true;
    return false;
}

bool Libsfml::shouldBeRestarted() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        return true;
    return false;
}

bool Libsfml::shouldGoToMenu() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        return true;
    return false;
}

bool Libsfml::shouldExit() const
{
    if (this->_event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        return true;
    }
    return false;
}

bool Libsfml::isKeyPressed(IDisplayModule::Keys key) const
{
    if (key == A && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        return true;
    if (key == RIGHT && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        return true;
    if (key == LEFT && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            return true;
    if (key == UP && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        return true;
    if (key == DOWN && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        return true;
    if (key == Z && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        return true;
    if (key == Q && sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        return true;
    if (key == S && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        return true;
    if (key == D && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        return true;
    if (key == A && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        return true;
    if (key == E && sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        return true;
    if (key == W && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        return true;
    if (key == X && sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        return true;
    if (key == SPACE && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        return true;
    if (key == J && sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        return true;
    if (key == K && sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        return true;
    if (key == U && sf::Keyboard::isKeyPressed(sf::Keyboard::U))
        return true;
    if (key == I && sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        return true;
    if (key == ENTER && sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        return true;
    if (key == BACKSPACE && sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
        return true;
    if (key == KEYS_END && sf::Keyboard::isKeyPressed(sf::Keyboard::End))
        return true;
    return false;
}

bool Libsfml::isKeyPressedOnce(IDisplayModule::Keys key) const
{
    return false;
}

float Libsfml::getDelta() const
{
    return 0.00;
}

void Libsfml::clear() const
{
    this->_window->clear();
}

void Libsfml::update()
{
    this->_window->pollEvent(this->_event);
    this->shouldExit();
}

void Libsfml::render() const
{
    this->_window->display();
}

char Libsfml::getKeyCode() const
{
    if (this->_event.type == sf::Event::TextEntered)
    {
        if (this->_event.text.unicode < 128)
            return (static_cast<char>(this->_event.text.unicode));
    }
    return '\0';
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
    sf::VertexArray vertex(sf::LinesStrip, 5);
    vertex[0].position = sf::Vector2f(x, y);
    vertex[1].position = sf::Vector2f(x, y + h);
    vertex[2].position = sf::Vector2f(x + w, y + h);
    vertex[3].position = sf::Vector2f(x + w, y);
    vertex[4].position = sf::Vector2f(x, y);
    vertex[0].color = this->_color;
    vertex[1].color = this->_color;
    vertex[2].color = this->_color;
    vertex[3].color = this->_color;
    vertex[4].color = this->_color;
    this->_window->draw(vertex);
}

void Libsfml::putFillRect(float x, float y, float w, float h) const
{
    sf::VertexArray vertex(sf::Quads, 4);
    vertex[0].position = sf::Vector2f(x, y);
    vertex[1].position = sf::Vector2f(x, y + h);
    vertex[2].position = sf::Vector2f(x + w, y + h);
    vertex[3].position = sf::Vector2f(x + w, y);
    vertex[0].color = this->_color;
    vertex[1].color = this->_color;
    vertex[2].color = this->_color;
    vertex[3].color = this->_color;
    this->_window->draw(vertex);
}

void Libsfml::putCircle(float x, float y, float rad) const
{
    sf::CircleShape circle(rad);
    circle.setPosition(sf::Vector2f(x, y));
    circle.setOutlineThickness(1);
    circle.setOutlineColor(this->_color);
    circle.setFillColor(sf::Color::Transparent);
    this->_window->draw(circle);
}

void Libsfml::putFillCircle(float x, float y, float rad) const
{
    sf::CircleShape circle(rad);
    circle.setPosition(sf::Vector2f(x, y));
    circle.setOutlineThickness(1);
    circle.setOutlineColor(this->_color);
    circle.setFillColor(this->_color);
    this->_window->draw(circle);
}

void Libsfml::putText(const std::string &text, unsigned int size, float x, float y) const
{
    sf::Font font;
    font.loadFromFile("include/arial.ttf");
    sf::Text str;
    str.setFont(font);
    str.setString(text);
    str.setCharacterSize(size);
    str.setFillColor(this->_color);
    str.setPosition(sf::Vector2f(x, y));
    this->_window->draw(str);
}

const std::string &Libsfml::getLibName() const
{
    return this->_lib_name;
}

extern "C" std::unique_ptr<IDisplayModule> createLib(void)
{
    return std::make_unique<Libsfml>();
}