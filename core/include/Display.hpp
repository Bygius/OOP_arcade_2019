/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Display
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include "../../include/Arcade_interfaces.hpp"
#include <memory>
#include <vector>


class Display : public IDisplayModule{

    public:
        Display(const std::string lib_path);
        ~Display();
        void reset();
        void open();
        void close();
        bool isOpen() const;

        bool switchToNextLib() const;
        bool switchToPreviousLib() const;
        bool switchToNextGame() const;
        bool switchToPreviousGame() const;
        bool shouldBeRestarted() const;
        bool shouldGoToMenu() const;
        bool shouldExit() const;

        bool isKeyPressed(IDisplayModule::Keys) const;
        bool isKeyPressedOnce(IDisplayModule::Keys) const;
        float getDelta() const;
        void clear() const;
        void update();
        void render() const;
        char getKeyCode() const;

        void setColor(IDisplayModule::Colors col);
        void putPixel(float x, float y) const;
        void putLine(float x1, float y1, float x2, float y2) const;
        void putRect(float x, float y, float w, float h) const;
        void putFillRect(float x, float y, float w, float h) const;
        void putCircle(float x, float y, float rad) const;
        void putFillCircle(float x, float y, float rad) const;
        void putText(const std::string &text, unsigned int size, float x, float y) const;
        const std::string &getLibName() const;

        void PrintAllLib(void) const;
        bool RefreshLibList(void);
        bool Load(const std::string lib_name);
        bool LoadPreviousLib(void);
        bool LoadNextLib(void);

    public:
        std::unique_ptr<IDisplayModule> actual_lib;
        const std::string lib_path;
        std::vector<std::string> lib_list;
        std::string current_lib_name;

};

#endif /* !DISPLAY_HPP_ */
