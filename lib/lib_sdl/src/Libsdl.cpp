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
    this->_window = SDL_CreateWindow("My Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    // this->_window = std::make_unique<SDL_Window>(SDL_CreateWindow("My Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0));
    this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
}

Libsdl::~Libsdl()
{
    SDL_DestroyWindow(this->_window);
    SDL_DestroyRenderer(this->_renderer);
    TTF_Quit();
    SDL_Quit();
}

void Libsdl::reset()
{
}
        
bool Libsdl::isOpen() const
{
    bool value = false;
    if (this->_renderer)
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
    if (this->_event.type == SDL_QUIT)
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
    if (key == ESCAPE && _event.key.keysym.sym == SDLK_ESCAPE)
        return true;
    if (key == J && _event.key.keysym.sym == SDLK_j)
        return true;
    if (key == K && _event.key.keysym.sym == SDLK_k)
        return true;
    if (key == U && _event.key.keysym.sym == SDLK_u)
        return true;
    if (key == I && _event.key.keysym.sym == SDLK_i)
        return true;
    if (key == M && _event.key.keysym.sym == SDLK_m)
        return true;
    if (key == R && _event.key.keysym.sym == SDLK_r)
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
    this->shouldExit();
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
            SDL_SetRenderDrawColor(this->_renderer, 255, 255, 255, 0.9);
            break;
        case (BLACK):
            SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);
            break;
        case (RED):
            SDL_SetRenderDrawColor(this->_renderer, 255, 0, 0, 0.9);
            break;
        case (GREEN):
            SDL_SetRenderDrawColor(this->_renderer, 0, 12, 0, 0.9);
            break;
        case (YELLOW):
            SDL_SetRenderDrawColor(this->_renderer, 234, 255, 0, 0.9);
            break;
        case (BLUE):
            SDL_SetRenderDrawColor(this->_renderer, 0, 0, 255, 0.9);
            break;
        case (MAGENTA):
            SDL_SetRenderDrawColor(this->_renderer, 255, 0, 255, 0.9);
            break;
        case (CYAN):
            SDL_SetRenderDrawColor(this->_renderer, 0, 255, 255, 0.9);
            break;
        case (LIGHT_GRAY):
            SDL_SetRenderDrawColor(this->_renderer, 0, 255, 0, 0.9);
            break;
        case (DARK_GRAY):
            SDL_SetRenderDrawColor(this->_renderer, 211, 211, 211, 0.9);
            break;
        case (LIGHT_RED):
            SDL_SetRenderDrawColor(this->_renderer, 240, 52, 52, 0.9);
            break;
        case (LIGHT_GREEN):
            SDL_SetRenderDrawColor(this->_renderer, 0, 255, 0, 0.9);
            break;
        case (LIGHT_YELLOW):
            SDL_SetRenderDrawColor(this->_renderer, 255, 250, 205, 0.9);
            break;
        case (LIGHT_BLUE):
            SDL_SetRenderDrawColor(this->_renderer, 0, 191, 255, 0.9);
            break;
        case (LIGHT_MAGENTA):
            SDL_SetRenderDrawColor(this->_renderer, 238, 130, 238, 0.9);
            break;
        case (LIGHT_CYAN):
            SDL_SetRenderDrawColor(this->_renderer, 175, 238, 238, 0.9);
            break;
        default:
            printf("Bad color\n");
            break;
    }  
}

void Libsdl::putPixel(float x, float y) const
{
    SDL_SetRenderDrawColor(this->_renderer, 255, 255, 255, 0.9);
    SDL_RenderDrawPoint(this->_renderer, x, y);
}

void Libsdl::putLine(float x1, float y1, float x2, float y2) const
{
    SDL_SetRenderDrawColor(this->_renderer, 255, 255, 255, 0.9);
    SDL_RenderDrawLine(this->_renderer, x1, y1, x2, y2);
}

void Libsdl::putRect(float x, float y, float w, float h) const
{
    SDL_Rect srcrect;

    srcrect.x = x;
    srcrect.y = y;
    srcrect.w = w;
    srcrect.h = h;

    SDL_SetRenderDrawColor(this->_renderer, 255, 255, 255, 0.9);
    SDL_RenderDrawRect(this->_renderer, &srcrect);
}

void Libsdl::putFillRect(float x, float y, float w, float h) const
{
    SDL_Rect srcrect;

    srcrect.x = x;
    srcrect.y = y;
    srcrect.w = w;
    srcrect.h = h;

    SDL_SetRenderDrawColor(this->_renderer, 255, 255, 255, 0.9);
    SDL_RenderFillRect(this->_renderer, &srcrect);
}

void Libsdl::putCircle(float x, float y, float rad) const
{
    int d = rad * 2;
    int tx = 1;
    int ty = 1;
    int error = (tx - d);
    int x2 = rad - 1;
    int y2 = 0;

    SDL_SetRenderDrawColor(this->_renderer, 255, 255, 255, 0.9);
    while (x2 >= y2) {
        SDL_RenderDrawPoint(this->_renderer, x + x2, y - y2);
        SDL_RenderDrawPoint(this->_renderer, x + x2, y + y2);
        SDL_RenderDrawPoint(this->_renderer, x - x2, y - y2);
        SDL_RenderDrawPoint(this->_renderer, x - x2, y + y2);
        SDL_RenderDrawPoint(this->_renderer, x + y2, y - x2);
        SDL_RenderDrawPoint(this->_renderer, x + y2, y + x2);
        SDL_RenderDrawPoint(this->_renderer, x - y2, y - x2);
        SDL_RenderDrawPoint(this->_renderer, x - y2, y + x2);
        if (error <= 0) {
            ++y2;
            error += ty;
            ty += 2;
        }
        if (error > 0) {
            --x2;
            tx += 2;
            error += (tx - d);
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

    TTF_Font *font = TTF_OpenFont("include/arial.ttf", size);
    if (!font)
        return;
    SDL_Color color = { 255, 255, 255 };
    SDL_Surface * surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(this->_renderer, surface);
    SDL_QueryTexture(texture, NULL, NULL, &texture_w, &texture_h);
    SDL_Rect dstrect = { 0, 0, texture_w, texture_h};
    SDL_RenderCopy(this->_renderer, texture, NULL, &dstrect);
    SDL_RenderPresent(this->_renderer);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
}

const std::string &Libsdl::getLibName() const
{
    return this->_lib_name;
}

extern "C" std::unique_ptr<IDisplayModule> createLib(void)
{
    return std::make_unique<Libsdl>();
}