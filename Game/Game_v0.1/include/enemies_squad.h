#ifndef ENEMIES_SQUAD_H
#define ENEMIES_SQUAD_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include "enemy.h"
#include "basic_funcs.h"

class EnemiesSquad
{
    public:
        EnemiesSquad(int, int);

        void Create();

        void SetNumTile(int);
        void SetPos(int, int);
        void SetSprPos(double, double);

        int GetNum();
        int GetMap();
        int GetNumTile();
        int GetSizeH();
        int GetSizeW();
        int GetPosX();
        int GetPosY();
        double GetSprX();
        double GetSprY();
        int GetNumBattle();
        int GetNumEnem();
        Enemy* GetEnem(int);
        sf::Sprite GetSprite();

        virtual ~EnemiesSquad();

    private:
        int type;

        int num_map;
        int num;
        int num_map_battle;
        int h, w;
        int num_tile;
        int pos_x, pos_y;

        int num_enem;
        Enemy** enemies;

        sf::Texture texture;
        sf::Sprite sprite;
};

#endif // ENEMIES_SQUAD_H
