#include "Libsfml.hpp"

int main(void)
{
    Libsfml lol;

    while(1) {
        lol.render();
        lol.putPixel(50, 50);
        lol.setColor(IDisplayModule::Colors::GREEN);
        lol.putLine(100, 100, 150, 150);
    }
}