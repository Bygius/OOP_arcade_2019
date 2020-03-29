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
    this->window = SDL_CreateWindow("My Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
}

Libsdl::~Libsdl()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
}

void Libsdl::reset()
{
}
        
bool Libsdl::isOpen() const
{
    bool value = false;
    if (this->renderer)
        value = true;
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
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return (true);
    }
    return (false);
}

bool Libsdl::isKeyPressed(IDisplayModule::Keys key) const
{
    SDL_Event event;

    SDL_PollEvent(&event);
    if (!event.key.keysym.sym)
        return (false);
    if (key == RIGHT && event.key.keysym.sym == SDLK_RIGHT)
        return true;
    if (key == LEFT && event.key.keysym.sym == SDLK_LEFT)
            return true;
    if (key == UP && event.key.keysym.sym == SDLK_UP)
        return true;
    if (key == DOWN && event.key.keysym.sym == SDLK_DOWN)
        return true;
    if (key == Z && event.key.keysym.sym == SDLK_z)
        return true;
    if (key == Q && event.key.keysym.sym == SDLK_q)
        return true;
    if (key == S && event.key.keysym.sym == SDLK_s)
        return true;
    if (key == D && event.key.keysym.sym == SDLK_d)
        return true;
    if (key == A && event.key.keysym.sym == SDLK_a)
        return true;        
    if (key == E && event.key.keysym.sym == SDLK_e)
        return true;
    if (key == W && event.key.keysym.sym == SDLK_w)
        return true;
    if (key == X && event.key.keysym.sym == SDLK_x)
        return true;
    if (key == SPACE && event.key.keysym.sym == SDLK_SPACE)
        return true;
    if (key == ESCAPE && event.key.keysym.sym == SDLK_ESCAPE)
        return true;
    if (key == J && event.key.keysym.sym == SDLK_j)
        return true;
    if (key == K && event.key.keysym.sym == SDLK_k)
        return true;
    if (key == U && event.key.keysym.sym == SDLK_u)
        return true;
    if (key == I && event.key.keysym.sym == SDLK_i)
        return true;
    if (key == M && event.key.keysym.sym == SDLK_m)
        return true;
    if (key == R && event.key.keysym.sym == SDLK_r)
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
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer);
}

void Libsdl::update()
{
    SDL_PollEvent(&event);
}

void Libsdl::render() const
{
    SDL_RenderPresent(this->renderer);
}

char Libsdl::getKeyCode() const
{
    return ('a');
}

void Libsdl::setColor(IDisplayModule::Colors color)
{
    switch (color)
    {
        case (DEFAULT):
            SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 0.9);
            break;
        case (BLACK):
            SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
            break;
        case (RED):
            SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 0.9);
            break;
        case (GREEN):
            SDL_SetRenderDrawColor(this->renderer, 0, 12, 0, 0.9);
            break;
        case (YELLOW):
            SDL_SetRenderDrawColor(this->renderer, 234, 255, 0, 0.9);
            break;
        case (BLUE):
            SDL_SetRenderDrawColor(this->renderer, 0, 0, 255, 0.9);
            break;
        case (MAGENTA):
            SDL_SetRenderDrawColor(this->renderer, 255, 0, 255, 0.9);
            break;
        case (CYAN):
            SDL_SetRenderDrawColor(this->renderer, 0, 255, 255, 0.9);
            break;
        case (LIGHT_GRAY):
            SDL_SetRenderDrawColor(this->renderer, 0, 255, 0, 0.9);
            break;
        case (DARK_GRAY):
            SDL_SetRenderDrawColor(this->renderer, 211, 211, 211, 0.9);
            break;
        case (LIGHT_RED):
            SDL_SetRenderDrawColor(this->renderer, 240, 52, 52, 0.9);
            break;
        case (LIGHT_GREEN):
            SDL_SetRenderDrawColor(this->renderer, 0, 255, 0, 0.9);
            break;
        case (LIGHT_YELLOW):
            SDL_SetRenderDrawColor(this->renderer, 255, 250, 205, 0.9);
            break;
        case (LIGHT_BLUE):
            SDL_SetRenderDrawColor(this->renderer, 0, 191, 255, 0.9);
            break;
        case (LIGHT_MAGENTA):
            SDL_SetRenderDrawColor(this->renderer, 238, 130, 238, 0.9);
            break;
        case (LIGHT_CYAN):
            SDL_SetRenderDrawColor(this->renderer, 175, 238, 238, 0.9);
            break;
        default:
            printf("Bad color\n");
            break;
    }  
}

void Libsdl::putPixel(float x, float y) const
{
    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 0.9);
    SDL_RenderDrawPoint(this->renderer, x, y);
}

void Libsdl::putLine(float x1, float y1, float x2, float y2) const
{
    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 0.9);
    SDL_RenderDrawLine(this->renderer, x1, y1, x2, y2);
}

void Libsdl::putRect(float x, float y, float w, float h) const
{
    SDL_Rect srcrect;

    srcrect.x = x;
    srcrect.y = y;
    srcrect.w = w;
    srcrect.h = h;

    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 0.9);
    SDL_RenderDrawRect(this->renderer, &srcrect);
}

void Libsdl::putFillRect(float x, float y, float w, float h) const
{
    SDL_Rect srcrect;

    srcrect.x = x;
    srcrect.y = y;
    srcrect.w = w;
    srcrect.h = h;

    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 0.9);
    SDL_RenderFillRect(this->renderer, &srcrect);
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
    TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);
    SDL_Color White = {255, 255, 255};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "put your text here", White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
}

const std::string &Libsdl::getLibName() const
{
    return this->_lib_name;
}

extern "C" std::unique_ptr<IDisplayModule> createLib(void)
{
    return std::make_unique<Libsdl>();
}