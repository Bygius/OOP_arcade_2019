/*
** EPITECH PROJECT, 2020
** lib_one
** File description:
** libsfml
*/

#ifndef LIBSFML_HPP_
#define LIBSFML_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Arcade_interfaces.hpp"

class Display: public IDisplayModule {
    public:
        Display(size_t width, size_t height);
        ~Display();

        void reset();
        bool is_open();

        bool switch_to_next_lib();
        bool switch_to_previous_lib();
        bool switch_to_next_game();
        bool switch_to_previous_game();

        bool should_be_restarted();
        bool should_go_to_menu();
        bool should_exit();

        bool is_key_pressed(IDisplayModule::Keys);
        bool is_key_pressed_once(IDisplayModule::Keys);

        float get_delta();

        void clear();
        void update();
        void render();

        virtual std::string get_player_name();
        void set_player_name(std::string);

        void set_color(IDisplayModule::Colors col);
        void put_pixel(float x, float y);
        void put_line(float x1, float y1, float x2, float y2);
        void put_rect(float , float y, float w, float h);
        void put_fill_rect(float x, float y, float w, float h);
        void put_circle(float x, float y, float rad);
        void put_fill_circle(float x, float y, float rad);
        void put_text(std::string text, float size, int x, int y);

        std::string getLibName();
    protected:
    private:
        sf::RenderWindow window;
        sf::Texture texture;
} ;

#endif /* !LIBSFML_HPP_ */
