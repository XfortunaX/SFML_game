#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include "basic_funcs.h"

class Object
{
    public:
        Object(std::string, int, int);

        void SetPosition(double, double);
        void SetSize(int, int);

        int GetNum();
        int GetSizeH();
        int GetSizeW();
        double GetPosX();
        double GetPosY();
        sf::Sprite GetSprite();

        virtual ~Object();

    private:
        int type;
        int name;
        int num;
        int h, w;

        sf::Texture texture;
        sf::Sprite sprite;

};

#endif // OBJECT_H
