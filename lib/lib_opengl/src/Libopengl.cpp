/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Libopengl
*/

#include "Libopengl.hpp"
#include <memory>
#include <math.h>

    // glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // do{
    //     // Ne dessine rien, on se voit dans le tutoriel 2 !

    //     // Swap buffers
    //     glfwSwapBuffers(window);
    //     glfwPollEvents();

    // } // Vérifie si on a appuyé sur la touche échap (ESC) ou si la fenêtre a été fermée
    // while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 );


Libopengl::Libopengl()
{
    glfwInit();
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // On veut OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // On ne veut pas l'ancien OpenGL

    window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);
    glfwMakeContextCurrent(window); // Initialise GLEW
    // glewExperimental=true; // Nécessaire dans le profil de base

    this->_name = "OpenGL";
}

Libopengl::~Libopengl()
{
}

void Libopengl::reset()
{
}
        
bool Libopengl::isOpen() const
{
    bool value = false;
    return (value);
}

bool Libopengl::switchToNext_lib() const
{
    return (false);
}

bool Libopengl::switchToPrevious_lib() const
{
    return (false);
}

bool Libopengl::switchToNext_game() const
{
    return (false);
}

bool Libopengl::switchToPrevious_game() const
{
    return (false);
}

bool Libopengl::shouldBeRestarted() const
{
    return (false);
}

bool Libopengl::shouldGoToMenu() const
{
    return (false);
}

bool Libopengl::shouldExit() const
{
    return (false);
}

bool Libopengl::isKeyPressed(IDisplayModule::Keys) const
{
    return (false);
}

bool Libopengl::isKeyPressedOnce(IDisplayModule::Keys) const
{
    return (false);
}

float Libopengl::getDelta() const
{
    return (0.00);
}

void my_clear()
{
    return;
}

void Libopengl::clear() const
{
    return;
}

void Libopengl::update()
{
    return;
}

void Libopengl::render() const
{
}

char Libopengl::getKeyCode() const
{
    return ('a');
}

void Libopengl::setColor(IDisplayModule::Colors color)
{
    
}

void Libopengl::putPixel(float x, float y) const
{
}

void Libopengl::putLine(float x1, float y1, float x2, float y2) const
{
}

void Libopengl::putRect(float x, float y, float w, float h) const
{

}

void Libopengl::putFillRect(float x, float y, float w, float h) const
{

}

void Libopengl::putCircle(float x, float y, float rad) const
{

}

void Libopengl::putFillCircle(float x, float y, float rad) const
{
    (void) x;
    (void) y;
    (void) rad;
}

void Libopengl::putText(const std::string &text, unsigned int size, float x, float y) const
{
}

const std::string &Libopengl::getLibName() const
{
    return (this->_name);
}
extern "C" std::unique_ptr<IDisplayModule> createLib(void)
{
    return std::make_unique<Libopengl>();
}