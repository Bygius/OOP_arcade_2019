/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Libsdl
*/

#include "Libsdl.hpp"
#include <memory>
#include <math.h>

Libsdl::Libsdl() : _lib_name("lib_arcade_sdl.so")
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    this->_font = TTF_OpenFont("include/arial.ttf", 24);
    this->_color = { 255, 255, 255, 1};
    this->_exit = false;
}

Libsdl::~Libsdl()
{
    TTF_CloseFont(this->_font);
    SDL_DestroyWindow(this->_window);
    SDL_DestroyRenderer(this->_renderer);
    TTF_Quit();
    SDL_Quit();
}

void Libsdl::reset()
{
}

void Libsdl::open()
{
    this->_window = SDL_CreateWindow("My Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    // this->_window = std::make_unique<SDL_Window>(SDL_CreateWindow("My Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0));
    this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
}
        
bool Libsdl::isOpen() const
{
    bool value = true;

    if (this->_exit == true)
        value = false;
    return (value);
}

bool Libsdl::switchToNextLib() const
{
    if (_event.key.keysym.sym == SDLK_n)
        return (true);
    return (false);
}

bool Libsdl::switchToPreviousLib() const
{
    if (_event.key.keysym.sym == SDLK_b)
        return (true);
    return (false);
}

bool Libsdl::switchToNextGame() const
{
    if (_event.key.keysym.sym == SDLK_p)
        return (true);
    return (false);
}

bool Libsdl::switchToPreviousGame() const
{
    if (_event.key.keysym.sym == SDLK_o)
        return (true);
    return (false);
}

bool Libsdl::shouldBeRestarted() const
{
    if (_event.key.keysym.sym == SDLK_r)
        return (true);
    return (false);
}

bool Libsdl::shouldGoToMenu() const
{
    if (_event.key.keysym.sym == SDLK_m)
        return (true);
    return (false);
}

bool Libsdl::shouldExit() const
{
    if (this->_event.type == SDL_QUIT || _event.key.keysym.sym == SDLK_ESCAPE)
        return (true);
    return (false);
}

bool Libsdl::isKeyPressed(IDisplayModule::Keys key) const
{
    if (!_event.key.keysym.sym)
        return (false);
    if (key == RIGHT && _event.key.keysym.sym == SDLK_RIGHT)
        return true;
    if (key == LEFT && _event.key.keysym.sym == SDLK_LEFT)
            return true;
    if (key == UP && _event.key.keysym.sym == SDLK_UP)
        return true;
    if (key == DOWN && _event.key.keysym.sym == SDLK_DOWN)
        return true;
    if (key == Z && _event.key.keysym.sym == SDLK_z)
        return true;
    if (key == Q && _event.key.keysym.sym == SDLK_q)
        return true;
    if (key == S && _event.key.keysym.sym == SDLK_s)
        return true;
    if (key == D && _event.key.keysym.sym == SDLK_d)
        return true;
    if (key == A && _event.key.keysym.sym == SDLK_a)
        return true;        
    if (key == E && _event.key.keysym.sym == SDLK_e)
        return true;
    if (key == W && _event.key.keysym.sym == SDLK_w)
        return true;
    if (key == X && _event.key.keysym.sym == SDLK_x)
        return true;
    if (key == SPACE && _event.key.keysym.sym == SDLK_SPACE)
        return true;
    if (key == J && _event.key.keysym.sym == SDLK_j)
        return true;
    if (key == K && _event.key.keysym.sym == SDLK_k)
        return true;
    if (key == U && _event.key.keysym.sym == SDLK_u)
        return true;
    if (key == I && _event.key.keysym.sym == SDLK_i)
        return true;
    if (key == ENTER && _event.key.keysym.sym == SDLK_RETURN)
        return true;
    if (key == BACKSPACE && _event.key.keysym.sym == SDLK_BACKSPACE)
        return true;
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

void Libsdl::clear() const
{
    SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->_renderer);
}

void Libsdl::update()
{
    SDL_PollEvent(&this->_event);
    if (this->shouldExit())
        this->_exit = true;

}

void Libsdl::render() const
{
    SDL_RenderPresent(this->_renderer);
}

char Libsdl::getKeyCode() const
{
    return (_event.key.keysym.sym);
}

void Libsdl::setColor(IDisplayModule::Colors color)
{
    switch (color)
    {
        case (DEFAULT):
            this->_color = {255, 255, 255, 1};
            break;
        case (BLACK):
            this->_color = {0, 0, 0, 1};
            break;
        case (RED):
            this->_color = {255, 0, 0, 1};
            break;
        case (GREEN):
            this->_color = {0, 128, 0, 1};
            break;
        case (YELLOW):
            this->_color = {234, 255, 0, 1};
            break;
        case (BLUE):
            this->_color = {0, 0, 255, 1};
            break;
        case (MAGENTA):
            this->_color = {255, 0, 255, 1};
            break;
        case (CYAN):
            this->_color = {0, 255, 255, 1};
            break;
        case (LIGHT_GRAY):
            this->_color = {0, 255, 0, 1};
            break;
        case (DARK_GRAY):
            this->_color = {211, 211, 211, 1};
            break;
        case (LIGHT_RED):
            this->_color = {240, 52, 52, 1};
            break;
        case (LIGHT_GREEN):
            this->_color = {0, 255, 0, 1};
            break;
        case (LIGHT_YELLOW):
            this->_color = {255, 250, 205, 1};
            break;
        case (LIGHT_BLUE):
            this->_color = {0, 191, 255, 1};
            break;
        case (LIGHT_MAGENTA):
            this->_color = {238, 130, 238, 1};
            break;
        case (LIGHT_CYAN):
            this->_color = {175, 238, 238, 1};
            break;
        default:
            printf("Bad color\n");
            break;
    }  
    SDL_SetRenderDrawColor(this->_renderer, this->_color.r, this->_color.g, this->_color.b, this->_color.a);
}

void Libsdl::putPixel(float x, float y) const
{
    SDL_RenderDrawPoint(this->_renderer, x, y);
}

void Libsdl::putLine(float x1, float y1, float x2, float y2) const
{
    SDL_RenderDrawLine(this->_renderer, x1, y1, x2, y2);
}

void Libsdl::putRect(float x, float y, float w, float h) const
{
    SDL_Rect srcrect;

    srcrect.x = x;
    srcrect.y = y;
    srcrect.w = w;
    srcrect.h = h;

    SDL_RenderDrawRect(this->_renderer, &srcrect);
}

void Libsdl::putFillRect(float x, float y, float w, float h) const
{
    SDL_Rect srcrect;

    srcrect.x = x;
    srcrect.y = y;
    srcrect.w = w;
    srcrect.h = h;

    // SDL_SetRenderDrawColor(this->_renderer, 255, 255, 255, 0.9);
    SDL_RenderFillRect(this->_renderer, &srcrect);
}

void Libsdl::putCircle(float x, float y, float rad) const
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
        SDL_RenderDrawPoint(this->_renderer, x + xValue, y - yValue);
        SDL_RenderDrawPoint(this->_renderer, x + xValue, y + yValue);
        SDL_RenderDrawPoint(this->_renderer, x - xValue, y - yValue);
        SDL_RenderDrawPoint(this->_renderer, x - xValue, y + yValue);
        SDL_RenderDrawPoint(this->_renderer, x + yValue, y - xValue);
        SDL_RenderDrawPoint(this->_renderer, x + yValue, y + xValue);
        SDL_RenderDrawPoint(this->_renderer, x - yValue, y - xValue);
        SDL_RenderDrawPoint(this->_renderer, x - yValue, y + xValue);
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

void Libsdl::putFillCircle(float x, float y, float rad) const
{
    (void) x;
    (void) y;
    (void) rad;
}

void Libsdl::putText(const std::string &text, unsigned int size, float x, float y) const
{
    int texture_w = 0;
    int texture_h = 0;

    // TTF_Font *_fonta = TTF_OpenFont("include/arial.ttf", 24);;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Color test = { 255, 255, 255};

    surface = TTF_RenderText_Solid(this->_font, text.c_str(), test);
    texture = SDL_CreateTextureFromSurface(this->_renderer, surface);

    SDL_QueryTexture(texture, NULL, NULL, &texture_w, &texture_h);
    SDL_Rect dstrect = { 0, 0, texture_w, texture_h};

    SDL_FreeSurface(surface);
    SDL_RenderCopy(this->_renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);
    // TTF_CloseFont(_fonta);
    // SDL_RenderPresent(this->_renderer);

}

const std::string &Libsdl::getLibName() const
{
    return this->_lib_name;
}

extern "C" std::unique_ptr<IDisplayModule> createLib(void)
{
    return std::make_unique<Libsdl>();
}