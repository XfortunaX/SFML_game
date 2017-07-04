#include "enemy.h"

Enemy::Enemy(int _num_map_battle, int _num)
{
    num_map_battle = _num_map_battle;
    num = _num;
    std::string buff;
    std::ifstream fin("resource/enemies/units/enemy_" + int_to_str(num) + "/info");
    fin >> buff >> name >> buff >> h >> buff >> w;
    fin.close();

    texture.loadFromFile("resource/enemies/units/enemy_" + int_to_str(num) + "/image.png");
    sprite.setTexture(texture);
}

void Enemy::Create()
{
//    std::string buff;
//    std::ifstream fin("resource/heroes/hero_1/hero_1");
//    fin >> h >> w;
//    fin.close();
//
//    std::ifstream fin2("resource/heroes/hero_1/location");
//    fin2 >> buff >> num_map >> buff >> num_tile;
//    fin2.close();
//
//    texture.loadFromFile("resource/heroes/hero_1/image.png");
//    sprite.setTexture(texture);
}



void Enemy::SetNumTile(int _tile)
{
    num_tile = _tile;
}

void Enemy::SetPos(int _x, int _y)
{
    pos_x = _x;
    pos_y = _y;
}

void Enemy::SetSprPos(double _x, double _y)
{
    sprite.setPosition(_x, _y);
}



int Enemy::GetMapBattle()
{
    return num_map_battle;
}

int Enemy::GetNumTile()
{
    return num_tile;
}

int Enemy::GetSizeH()
{
    return h;
}

int Enemy::GetSizeW()
{
    return w;
}

int Enemy::GetPosX()
{
    return pos_x;
}

int Enemy::GetPosY()
{
    return pos_y;
}

double Enemy::GetSprX()
{
    return sprite.getPosition().x;
}

double Enemy::GetSprY()
{
    return sprite.getPosition().y;
}

std::string Enemy::GetName()
{
    return name;
}

sf::Sprite Enemy::GetSprite()
{
    return sprite;
}

Enemy::~Enemy()
{
    //dtor
}
