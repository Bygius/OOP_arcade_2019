/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Libncurses
*/

#include "Libncurses.hpp"

Libncurses::Libncurses()
{
    initscr();
    nodelay(stdscr, true);
    curs_set(0);
}

Libncurses::~Libncurses()
{
    endwin();
}

void Libncurses::reset()
{
    endwin();
    initscr();
    nodelay(stdscr, true);
    curs_set(0);
}
        
bool Libncurses::isOpen() const
{
    bool value;

    if (stdscr == NULL)
        value = false;
    else
        value = true;
    return (value);
}

bool Libncurses::switchToNext_lib() const
{

}

bool Libncurses::switchToPrevious_lib() const
{

}

bool Libncurses::switchToNext_game() const
{

}

bool Libncurses::switchToPrevious_game() const
{

}

bool Libncurses::shouldBeRestarted() const
{

}

bool Libncurses::shouldGoToMenu() const
{

}

bool Libncurses::shouldExit() const
{

}

bool Libncurses::isKeyPressed(IDisplayModule::Keys) const
{

}

bool Libncurses::isKeyPressedOnce(IDisplayModule::Keys) const
{

}

float Libncurses::getDelta() const
{

}

void Libncurses::clear() const
{
    clear();
}

void Libncurses::update()
{
    refresh();
}

void Libncurses::render() const
{
}

char Libncurses::getKeyCode() const
{
    
}

void Libncurses::_init_pair(size_t obj, size_t color, size_t back)
{
    init_pair(obj, color, back);
}

void Libncurses::_attron(size_t obj)
{
    attron(COLOR_PAIR(obj));
}

void Libncurses::_attroff(size_t obj)
{
    attroff(COLOR_PAIR(obj));
}

void Libncurses::setColor(IDisplayModule::Colors color)
{
    start_color();
    switch (color)
    {
        case (DEFAULT):
            this->_init_pair(0, 7, 0);
            break;
        case (BLACK):
            this->_init_pair(0, 0, 0);
            break;
        case (RED):
            this->_init_pair(0, 1, 0);
            break;
        case (GREEN):
            this->_init_pair(0, 2, 0);
            break;
        case (YELLOW):
            this->_init_pair(0, 3, 0);
            break;
        case (BLUE):
            this->_init_pair(0, 4, 0);
            break;
        case (MAGENTA):
            this->_init_pair(0, 5, 0);
            break;
        case (CYAN):
            this->_init_pair(0, 6, 0);
            break;
        case (LIGHT_GRAY):
            this->_init_pair(0, 7, 0);
            break;
        case (DARK_GRAY):
            this->_init_pair(0, 7, 0);
            break;
        case (LIGHT_RED):
            this->_init_pair(0, 7, 0);
            break;
        case (LIGHT_GREEN):
            this->_init_pair(0, 7, 0);
            break;
        case (LIGHT_YELLOW):
            this->_init_pair(0, 7, 0);
            break;
        case (LIGHT_BLUE):
            this->_init_pair(0, 7, 0);
            break;
        case (LIGHT_MAGENTA):
            this->_init_pair(0, 7, 0);
            break;
        case (LIGHT_CYAN):
            this->_init_pair(0, 7, 0);
            break;
        default:
            printf("Bad color\n");
            break;
    }
}

void Libncurses::putPixel(float x, float y) const
{
    mvprintw(x, y, ".");
}

void Libncurses::putLine(float x1, float y1, float x2, float y2) const
{
    int sign = 0;
    (int) x1;
    (int) x2;
    (int) y1;
    (int) y2;
    int n = 0;

    if (y2 != y1 && x1 == x2) {
        if (y1 < y2)
            n = y2 - y1;
        else
            n = y1 - y2;
        mvvline(y1, x1, '|', n);
    } else if (x1 != x2 && y1 == y2) {
        if (x1 < x2)
            n = x2 - x1;
        else
            n = x1 - x2;
        mvhline(y1, x1, '_', n);
    } else {
        printf("Bad coord");
    }
    return;
}


void Libncurses::putRect(float x, float y, float w, float h) const
{
    mvhline(y, x + 1, '_', w);
    mvvline(y + 1, x, '|', h);
    mvvline(y + 1, x + w + 1, '|', h);
    mvhline(y + h, x + 1, '_', w);
    return;
}

void Libncurses::putFillRect(float x, float y, float w, float h) const
{
    int i = 0;

    for (i = y; i <= h ; i ++)
        mvhline(i, x, 'X', w);
}

void Libncurses::putCircle(float x, float y, float rad) const
{
    printw("o");
}

void Libncurses::putFillCircle(float x, float y, float rad) const
{
}

void Libncurses::putText(const std::string &text, unsigned int size, float x, float y) const
{
    (void) size;
    mvprintw(y, x, text.c_str());
}

const std::string &Libncurses::getLibName() const
{
    return ("nCurses");
}