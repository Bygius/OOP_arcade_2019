#include "Libsfml.hpp"

int main(void)
{
    Libsfml lol(WIDTH, HEIGHT);

    while(1) {
        lol.render();
    }
}