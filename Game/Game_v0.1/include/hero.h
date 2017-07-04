#ifndef HERO_H
#define HERO_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include "basic_funcs.h"

class Hero
{
    public:
        Hero();

        void Create();

        void SetNumTile(int);
        void SetPos(int, int);
        void SetSprPos(double, double);

        int GetMap();
        int GetNumTile();
        int GetSizeH();
        int GetSizeW();
        int GetPosX();
        int GetPosY();
        double GetSprX();
        double GetSprY();
        sf::Sprite GetSprite();

        virtual ~Hero();

    private:
        int type;

        int num_map;
        int h, w;
        int num_tile;
        int pos_x, pos_y;

        sf::Texture texture;
        sf::Sprite sprite;
};

#endif // HERO_H
