/*
** EPITECH PROJECT, 2020
** peter bessone
** File description:
** Square
*/

#ifndef SQUARE_HPP_
#define SQUARE_HPP_

class Square {
    public:
        Square(int posX, int posY);
        ~Square();
        int getPosX();
        int getPosY();
        void setPosX(int posX);
        void setPosY(int posY);

    private:
        int _posX;
        int _posY;
};

#endif /* !SQUARE_HPP_ */