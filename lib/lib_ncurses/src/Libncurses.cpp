/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Libncurses
*/

#include "Libncurses.hpp"
#include <math.h>
#include <memory>

Libncurses::Libncurses() : _lib_name("lib_arcade_ncurses.so")
{
    this->_exit = false;
    this->_input = '\0';
}

void Libncurses::reset()
{
    this->_exit = false;
    this->_input = '\0';
    // endwin();
    // initscr();
    // this->_win = newwin(HEIGHT, WIDTH, 0, 0);
    // curs_set(0);
}

void Libncurses::open()
{
    initscr();
    nodelay(stdscr, 1);
    curs_set(0);
    keypad(stdscr, TRUE);
    wresize(stdscr, HEIGHT, WIDTH);
    // resizeterm(HEIGHT, WIDTH);

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
}

void Libncurses::close()
{
    endwin();
}

bool Libncurses::isOpen() const
{
    bool value;

    if (stdscr == NULL || this->_exit == true)
        value = false;
    else
        value = true;
    return (value);
}

bool Libncurses::switchToNextLib() const
{
    if (this->_input == 110)
        return (true);
    return (false);
}

bool Libncurses::switchToPreviousLib() const
{
    if (this->_input == 98)
        return (true);
    return (false);
}

bool Libncurses::switchToNextGame() const
{
    if (this->_input == 112)
        return (true);
    return (false);
}

bool Libncurses::switchToPreviousGame() const
{
    if (this->_input == 11)
        return (true);
    return (false);
}

bool Libncurses::shouldBeRestarted() const
{
    if (this->_input == 114)
        return (true);
    return (false);
}

bool Libncurses::shouldGoToMenu() const
{
    if (this->_input == 109)
        return (true);
    return (false);
}

bool Libncurses::shouldExit() const
{
    if (this->_input == 27)
        return (true);
    return (false);
}

bool Libncurses::isKeyPressed(IDisplayModule::Keys key) const
{
    if (key == RIGHT && this->_input == KEY_RIGHT)
        return true;
    if (key == LEFT && this->_input == KEY_LEFT)
        return true;
    if (key == UP && this->_input == KEY_UP)
        return true;
    if (key == DOWN && this->_input == KEY_DOWN)
        return true;
    if (key == Z && this->_input == 122)
        return true;
    if (key == Q && this->_input == 113)
        return true;
    if (key == S && this->_input == 115)
        return true;
    if (key == D && this->_input == 100)
        return true;
    if (key == A && this->_input == 97)
        return true;
    if (key == E && this->_input == 101)
        return true;
    if (key == W && this->_input == 119)
        return true;
    if (key == X && this->_input == 120)
        return true;
    if (key == SPACE && this->_input == 32)
        return true;
    if (key == J && this->_input == 106)
        return true;
    if (key == K && this->_input == 107)
        return true;
    if (key == U && this->_input == 117)
        return true;
    if (key == I && this->_input == 105)
        return true;
    if (key == ENTER && this->_input == 8)
        return true;
    if (key == BACKSPACE && this->_input == 10)
        return true;
    if (key == KEYS_END && this->_input == 27)
        return true;
    return (false);
}

bool Libncurses::isKeyPressedOnce(IDisplayModule::Keys key) const
{
    if (key == RIGHT && this->_input == KEY_RIGHT)
        return true;
    if (key == LEFT && this->_input == KEY_LEFT)
        return true;
    if (key == UP && this->_input == KEY_UP)
        return true;
    if (key == DOWN && this->_input == KEY_DOWN)
        return true;
    if (key == Z && this->_input == 122)
        return true;
    if (key == Q && this->_input == 113)
        return true;
    if (key == S && this->_input == 115)
        return true;
    if (key == D && this->_input == 100)
        return true;
    if (key == A && this->_input == 97)
        return true;
    if (key == E && this->_input == 101)
        return true;
    if (key == W && this->_input == 119)
        return true;
    if (key == X && this->_input == 120)
        return true;
    if (key == SPACE && this->_input == 32)
        return true;
    if (key == J && this->_input == 106)
        return true;
    if (key == K && this->_input == 107)
        return true;
    if (key == U && this->_input == 117)
        return true;
    if (key == I && this->_input == 105)
        return true;
    if (key == ENTER && this->_input == 8)
        return true;
    if (key == BACKSPACE && this->_input == 10)
        return true;
    if (key == KEYS_END && this->_input == 27)
        return true;
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

static float count_second(clock_t backup_clock)
{
    double result = 0;
    result = clock() - backup_clock;
    result *= 0.000001;
    return (result);
}

void Libncurses::clear() const
{
    static clock_t _clock = clock();
    if (count_second(_clock) >= 0.1) {
        my_clear();
        _clock = clock();
    }
}

void Libncurses::update()
{
    noecho();
    this->_input = getch();
    this->_exit = this->shouldExit();
    refresh();
}

void Libncurses::render() const
{
}

char Libncurses::getKeyCode() const
{
    return this->_input;
}

void Libncurses::setColor(IDisplayModule::Colors color)
{
    switch (color) {
        case (DEFAULT): attron(COLOR_PAIR(DEFAULT)); break;
        case (BLACK): attron(COLOR_PAIR(BLACK)); break;
        case (RED): attron(COLOR_PAIR(RED)); break;
        case (GREEN): attron(COLOR_PAIR(GREEN)); break;
        case (YELLOW): attron(COLOR_PAIR(YELLOW)); break;
        case (BLUE): attron(COLOR_PAIR(BLUE)); break;
        case (MAGENTA): attron(COLOR_PAIR(MAGENTA)); break;
        case (CYAN): attron(COLOR_PAIR(CYAN)); break;
        case (LIGHT_GRAY): attron(COLOR_PAIR(LIGHT_GRAY)); break;
        case (DARK_GRAY): attron(COLOR_PAIR(DARK_GRAY)); break;
        case (LIGHT_RED): attron(COLOR_PAIR(LIGHT_RED)); break;
        case (LIGHT_GREEN): attron(COLOR_PAIR(LIGHT_GREEN)); break;
        case (LIGHT_YELLOW): attron(COLOR_PAIR(LIGHT_YELLOW)); break;
        case (LIGHT_BLUE): attron(COLOR_PAIR(LIGHT_BLUE)); break;
        case (LIGHT_MAGENTA): attron(COLOR_PAIR(LIGHT_MAGENTA)); break;
        case (LIGHT_CYAN): attron(COLOR_PAIR(LIGHT_CYAN)); break;
        default: printf("Bad color\n"); break;
    }
}

void Libncurses::putPixel(float x, float y) const
{
    mvprintw(resize(y) / 2, resize(x), "X");
}

void Libncurses::putLine(float x1, float y1, float x2, float y2) const
{
    bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
    float dx, dy, error;
    int ystep, y, max;

    if (steep) {
        std::swap(x1, y1);
        std::swap(x2, y2);
    }
    if (x1 > x2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }
    dx = x2 - x1;
    dy = fabs(y2 - y1);
    error = dx / 2.0;
    ystep = (y1 < y2) ? 1 : -1;
    y = (int) y1;
    max = (int) x2;
    for (int x = (int) x1; x <= max; x++) {
        if (steep) {
            putPixel(y, x);
        } else {
            putPixel(x, y);
        }

        error -= dy;
        if (error < 0) {
            y += ystep;
            error += dx;
        }
    }
}

void Libncurses::putRect(float x, float y, float w, float h) const
{
    x = resize(x);
    y = resize(y) / 2;
    w = resize(w);
    h = resize(h) / 2;

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
    y = resize(y) / 2;
    w = resize(w);
    h = resize(h) / 2;
    for (i = y; i <= y + h; i++)
        mvhline(i, x, 'X', w);
}

void Libncurses::putCircle(float x, float y, float rad) const
{
    int diameter = (rad * 2);
    int xValue = rad - 1;
    int yValue = 0;
    int tx = 1;
    int ty = 0;
    int error = (tx - diameter);
    x = x + rad;
    y = y + rad;
    while (xValue >= yValue) {
        putPixel(x + xValue, y - yValue);
        putPixel(x + xValue, y + yValue);
        putPixel(x - xValue, y - yValue);
        putPixel(x - xValue, y + yValue);
        putPixel(x + yValue, y - xValue);
        putPixel(x + yValue, y + xValue);
        putPixel(x - yValue, y - xValue);
        putPixel(x - yValue, y + xValue);
        if (error <= 0) {
            ++yValue;
            error += ty;
            ty += 2;
        }
        if (error > 0) {
            --xValue;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

void Libncurses::putFillCircle(float x, float y, float rad) const
{
    (void) x;
    (void) y;
    (void) rad;
}

void Libncurses::putText(
    const std::string &text, unsigned int size, float x, float y) const
{
    (void) size;

    mvprintw(resize(y), resize(x), text.c_str());
}

const std::string &Libncurses::getLibName() const
{
    return this->_lib_name;
}

int resize(int x)
{
    return (x / 8);
}

extern "C" std::unique_ptr<IDisplayModule> createLib(void)
{
    return std::make_unique<Libncurses>();
}