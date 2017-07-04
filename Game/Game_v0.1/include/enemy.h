#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include "basic_funcs.h"
#include "characteristics.h"

class Enemy
{
    public:
        Enemy(int, int);

        void Create();

        void SetNumTile(int);
        void SetPos(int, int);
        void SetSprPos(double, double);

        std::string GetName();
        int GetMapBattle();
        int GetNumTile();
        int GetSizeH();
        int GetSizeW();
        int GetPosX();
        int GetPosY();
        double GetSprX();
        double GetSprY();
        sf::Sprite GetSprite();

        virtual ~Enemy();

    private:
        int type;

        int num_map_battle;
        int num;
        int h, w;
        int num_tile;
        int pos_x, pos_y;
        std::string name;
        Characteristics characteristics;

        int num_enem;

        sf::Texture texture;
        sf::Sprite sprite;
};

#endif // ENEMY_H
