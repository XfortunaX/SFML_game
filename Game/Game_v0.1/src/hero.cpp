#include "hero.h"

Hero::Hero()
{

}

void Hero::Create()
{
    std::string buff;
    std::ifstream fin("resource/heroes/hero_1/hero_1");
    fin >> h >> w;
    fin.close();

    std::ifstream fin2("resource/heroes/hero_1/location");
    fin2 >> buff >> num_map >> buff >> num_tile;
    fin2.close();

    texture.loadFromFile("resource/heroes/hero_1/image.png");
    sprite.setTexture(texture);
}



void Hero::SetNumTile(int _tile)
{
    num_tile = _tile;
}

void Hero::SetPos(int _x, int _y)
{
    pos_x = _x;
    pos_y = _y;
}

void Hero::SetSprPos(double _x, double _y)
{
    sprite.setPosition(_x, _y);
}



int Hero::GetMap()
{
    return num_map;
}

int Hero::GetNumTile()
{
    return num_tile;
}

int Hero::GetSizeH()
{
    return h;
}

int Hero::GetSizeW()
{
    return w;
}

int Hero::GetPosX()
{
    return pos_x;
}

int Hero::GetPosY()
{
    return pos_y;
}

double Hero::GetSprX()
{
    return sprite.getPosition().x;
}

double Hero::GetSprY()
{
    return sprite.getPosition().y;
}

sf::Sprite Hero::GetSprite()
{
    return sprite;
}

Hero::~Hero()
{
    //dtor
}
