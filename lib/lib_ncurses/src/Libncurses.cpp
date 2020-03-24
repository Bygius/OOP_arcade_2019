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

    start_color();
    init_pair(DEFAULT, COLOR_WHITE, COLOR_BLACK);
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(RED, COLOR_RED, COLOR_BLACK);
    init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(LIGHT_GRAY, COLOR_BLACK, COLOR_BLACK);
    init_pair(DARK_GRAY, COLOR_BLACK, COLOR_BLACK);
    init_pair(LIGHT_RED, COLOR_RED, COLOR_BLACK);
    init_pair(LIGHT_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(LIGHT_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(LIGHT_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(LIGHT_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(LIGHT_CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);

    this->_name = "nCurses";
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
    return (false);
}

bool Libncurses::switchToPrevious_lib() const
{
    return (false);
}

bool Libncurses::switchToNext_game() const
{
    return (false);
}

bool Libncurses::switchToPrevious_game() const
{
    return (false);
}

bool Libncurses::shouldBeRestarted() const
{
    return (false);
}

bool Libncurses::shouldGoToMenu() const
{
    return (false);
}

bool Libncurses::shouldExit() const
{
    return (false);
}

bool Libncurses::isKeyPressed(IDisplayModule::Keys) const
{
    return (false);
}

bool Libncurses::isKeyPressedOnce(IDisplayModule::Keys) const
{
    return (false);
}

float Libncurses::getDelta() const
{
    return (0.00);
}

void my_clear()
{
    clear();
}

void Libncurses::clear() const
{
    my_clear();
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
    return ('a');
}

void Libncurses::setColor(IDisplayModule::Colors color)
{
    
    switch (color)
    {
        case (DEFAULT):
            attron(COLOR_PAIR(DEFAULT));
            break;
        case (BLACK):
            attron(COLOR_PAIR(BLACK));
            break;
        case (RED):
            attron(COLOR_PAIR(RED));
            break;
        case (GREEN):
            attron(COLOR_PAIR(GREEN));
            break;
        case (YELLOW):
            attron(COLOR_PAIR(YELLOW));
            break;
        case (BLUE):
            attron(COLOR_PAIR(BLUE));
            break;
        case (MAGENTA):
            attron(COLOR_PAIR(MAGENTA));
            break;
        case (CYAN):
            attron(COLOR_PAIR(CYAN));
            break;
        case (LIGHT_GRAY):
            attron(COLOR_PAIR(LIGHT_GRAY));
            break;
        case (DARK_GRAY):
            attron(COLOR_PAIR(DARK_GRAY));
            break;
        case (LIGHT_RED):
            attron(COLOR_PAIR(LIGHT_RED));
            break;
        case (LIGHT_GREEN):
            attron(COLOR_PAIR(LIGHT_GREEN));
            break;
        case (LIGHT_YELLOW):
            attron(COLOR_PAIR(LIGHT_YELLOW));
            break;
        case (LIGHT_BLUE):
            attron(COLOR_PAIR(LIGHT_BLUE));
            break;
        case (LIGHT_MAGENTA):
            attron(COLOR_PAIR(LIGHT_MAGENTA));
            break;
        case (LIGHT_CYAN):
            attron(COLOR_PAIR(LIGHT_CYAN));
            break;
        default:
            printf("Bad color\n");
            break;
    }
    
}

void Libncurses::putPixel(float x, float y) const
{
    mvprintw(resize(y), resize(x), ".");
}

void Libncurses::putLine(float x1, float y1, float x2, float y2) const
{
    int x_one = (int) x1;
    int x_two = (int) x2;
    int y_one = (int) y1;
    int y_two = (int) y2;
    int n = 0;

    if (y_two != y_one && x_one == x_two) {
        if (y_one < y_two)
            n = y_two - y_one;
        else
            n = y_one - y_two;
        mvvline(resize(y_one), resize(x_one), '|', n);
    } else if (x_one != x_two && y_one == y_two) {
        if (x_one < x_two)
            n = x_two - x_one;
        else
            n = x_one - x_two;
        mvhline(resize((int) y_one), resize(x_one), '_', n);
    } else {
        printf("Bad coord");
    }
    return;
}


void Libncurses::putRect(float x, float y, float w, float h) const
{
    x = resize(x);
    y = resize(y);
    w = resize(w);
    h = resize(h);

    mvhline(y, x + 1, '_', w);
    mvvline(y + 1, x, '|', h);
    mvvline(y + 1, x + w + 1, '|', h);
    mvhline(y + h, x + 1, '_', w);
    return;
}

void Libncurses::putFillRect(float x, float y, float w, float h) const
{
    int i = 0;

    x = resize(x);
    y = resize(y);
    for (i = y; i <= y + h ; i ++)
        mvhline(i, x, 'X', w);
}


void Libncurses::putCircle(float x, float y, float rad) const
{
    (void) rad;
    mvprintw(resize(y), resize(x),"o");
}

void Libncurses::putFillCircle(float x, float y, float rad) const
{
    (void) x;
    (void) y;
    (void) rad;
}

void Libncurses::putText(const std::string &text, unsigned int size, float x, float y) const
{
    (void) size;

    mvprintw(resize(y), resize(x), text.c_str());
}

const std::string &Libncurses::getLibName() const
{
    return (this->_name);
}

int resize(int x)
{
    return (x / 8);
}