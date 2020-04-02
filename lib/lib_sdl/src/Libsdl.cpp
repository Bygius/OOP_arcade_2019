/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Libsdl
*/

#include "Libsdl.hpp"
#include <memory>
#include <math.h>

Libsdl::Libsdl() : _lib_name("lib_arcade_sdl.so"), _window(nullptr, SDL_DestroyWindow), _renderer(nullptr, SDL_DestroyRenderer)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    this->_color = { 255, 255, 255, 1};
    this->_exit = false;
    this->_delta = 0;
}

Libsdl::~Libsdl()
{
    close();
}

void Libsdl::reset()
{
    this->_color = { 255, 255, 255, 1};
    this->_exit = false;
    this->_delta = 0;
}

void Libsdl::open()
{
    this->_window.reset(SDL_CreateWindow("My Window SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0));
    this->_renderer.reset(SDL_CreateRenderer(this->_window.get(), -1, SDL_RENDERER_ACCELERATED));
    SDL_PollEvent(&this->_event);
}

void Libsdl::close()
{
    SDL_DestroyWindow(this->_window.get());
    SDL_DestroyRenderer(this->_renderer.get());
    TTF_Quit();
    SDL_Quit();
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
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_N])
        return (true);
    return (false);
}

bool Libsdl::switchToPreviousLib() const
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_B])
        return (true);
    return (false);
}

bool Libsdl::switchToNextGame() const
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_P])
        return (true);
    return (false);
}

bool Libsdl::switchToPreviousGame() const
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_O])
        return (true);
    return (false);
}

bool Libsdl::shouldBeRestarted() const
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_R])
        return (true);
    return (false);
}

bool Libsdl::shouldGoToMenu() const
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_M])
        return (true);
    return (false);
}

bool Libsdl::shouldExit() const
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (this->_event.type == SDL_QUIT || state[SDL_SCANCODE_ESCAPE])
        return (true);
    return (false);
}

bool Libsdl::isKeyPressed(IDisplayModule::Keys key) const
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (key == SPACE && state[SDL_SCANCODE_SPACE])
        return true;
    if (key == RIGHT && state[SDL_SCANCODE_RIGHT])
        return true;
    if (key == LEFT && state[SDL_SCANCODE_LEFT])
            return true;
    if (key == UP && state[SDL_SCANCODE_UP])
        return true;
    if (key == DOWN && state[SDL_SCANCODE_DOWN])
        return true;
    if (key == Z && state[SDL_SCANCODE_W])
        return true;
    if (key == Q && state[SDL_SCANCODE_A])
        return true;
    if (key == S && state[SDL_SCANCODE_S])
        return true;
    if (key == D && state[SDL_SCANCODE_D])
        return true;
    if (key == A && state[SDL_SCANCODE_Q])
        return true;        
    if (key == E && state[SDL_SCANCODE_E])
        return true;
    if (key == W && state[SDL_SCANCODE_Z])
        return true;
    if (key == X && state[SDL_SCANCODE_X])
        return true;
    if (key == SPACE && state[SDL_SCANCODE_SPACE])
        return true;
    if (key == J && state[SDL_SCANCODE_J])
        return true;
    if (key == K && state[SDL_SCANCODE_K])
        return true;
    if (key == U && state[SDL_SCANCODE_U])
        return true;
    if (key == I && state[SDL_SCANCODE_I])
        return true;
    if (key == ENTER && state[SDL_SCANCODE_RETURN])
        return true;
    if (key == BACKSPACE && state[SDL_SCANCODE_BACKSPACE])
        return true;
    return (false);
}

bool Libsdl::isKeyPressedOnce(IDisplayModule::Keys) const
{
    return (false);
}

float Libsdl::getDelta() const
{
    return this->_delta;
}

void Libsdl::clear() const
{
    SDL_SetRenderDrawColor(this->_renderer.get(), 0 , 0, 0, 255);
    SDL_RenderClear(this->_renderer.get());
    SDL_SetRenderDrawColor(this->_renderer.get(), this->_color.r, this->_color.g, this->_color.b, this->_color.a);
}

void Libsdl::frame_rate_limit()
{
    static Uint32 startTime = 0;
    static Uint32 endTime = 0;

    if (!startTime)
        startTime = SDL_GetTicks();
    else
        this->_delta = endTime - startTime;
    if (this->_delta < 16)
        SDL_Delay(16 - this->_delta);
    startTime = endTime;
    endTime = SDL_GetTicks();
}
void Libsdl::update()
{
    SDL_PollEvent(&this->_event);
    if (this->shouldExit())
        this->_exit = true;
    frame_rate_limit();
}

void Libsdl::render() const
{
    SDL_RenderPresent(this->_renderer.get());
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
    SDL_SetRenderDrawColor(this->_renderer.get(), this->_color.r, this->_color.g, this->_color.b, this->_color.a);
}

void Libsdl::putPixel(float x, float y) const
{
    SDL_RenderDrawPoint(this->_renderer.get(), x, y);
}

void Libsdl::putLine(float x1, float y1, float x2, float y2) const
{
    SDL_RenderDrawLine(this->_renderer.get(), x1, y1, x2, y2);
}

void Libsdl::putRect(float x, float y, float w, float h) const
{
    SDL_Rect srcrect;

    srcrect.x = x;
    srcrect.y = y;
    srcrect.w = w;
    srcrect.h = h;

    SDL_RenderDrawRect(this->_renderer.get(), &srcrect);
}

void Libsdl::putFillRect(float x, float y, float w, float h) const
{
    SDL_Rect srcrect;

    srcrect.x = x;
    srcrect.y = y;
    srcrect.w = w;
    srcrect.h = h;
    SDL_RenderFillRect(this->_renderer.get(), &srcrect);
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
        SDL_RenderDrawPoint(this->_renderer.get(), x + xValue, y - yValue);
        SDL_RenderDrawPoint(this->_renderer.get(), x + xValue, y + yValue);
        SDL_RenderDrawPoint(this->_renderer.get(), x - xValue, y - yValue);
        SDL_RenderDrawPoint(this->_renderer.get(), x - xValue, y + yValue);
        SDL_RenderDrawPoint(this->_renderer.get(), x + yValue, y - xValue);
        SDL_RenderDrawPoint(this->_renderer.get(), x + yValue, y + xValue);
        SDL_RenderDrawPoint(this->_renderer.get(), x - yValue, y - xValue);
        SDL_RenderDrawPoint(this->_renderer.get(), x - yValue, y + xValue);
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
    TTF_Font *_font = TTF_OpenFont("include/arial.ttf", size);

    surface = TTF_RenderText_Solid(_font, text.c_str(), this->_color);
    texture = SDL_CreateTextureFromSurface(this->_renderer.get(), surface);

    SDL_QueryTexture(texture, NULL, NULL, &texture_w, &texture_h);
    SDL_Rect dstrect = {(int)x, (int)y, texture_w, texture_h};

    SDL_FreeSurface(surface);
    SDL_RenderCopy(this->_renderer.get(), texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(_font);

}

const std::string &Libsdl::getLibName() const
{
    return this->_lib_name;
}

extern "C" std::unique_ptr<IDisplayModule> createLib(void)
{
    return std::make_unique<Libsdl>();
}