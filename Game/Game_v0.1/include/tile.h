#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include "basic_funcs.h"

class Tile
{
    public:
        Tile(std::string, int, int, int);

        void CreateCom(int);
        int CheckCom(int);
        void Print();

        void SetPosition(double, double);
        void SetSize(int, int);
        void SetHero(int);
        void SetEnemy(int);
        void SetNps(int);
        void SetObject(int);

        int CheckHero();
        int CheckEnemy();
        int CheckNps();
        int CheckObject();
        int GetNum();
        int GetSizeH();
        int GetSizeW();
        double GetPosX();
        double GetPosY();
        int GetMoveAbil();
        sf::Sprite GetSprite();

        virtual ~Tile();

    private:
        int type;
        int name;
        int num;
        int h, w;
        double pos_x, pos_y;

        int** com;
        int num_com;
        int cur_com;
        int move_abil;
        int busy[2];

        sf::Texture texture;
        sf::Sprite sprite;

};

#endif // TILE_H
