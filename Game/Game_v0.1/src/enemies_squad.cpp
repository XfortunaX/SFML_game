#include "enemies_squad.h"

EnemiesSquad::EnemiesSquad(int _num_map, int _num)
{
    num_map = _num_map;
    num = _num;
    std::string buff;
    int enem;
    std::ifstream fin("resource/enemies/enemies_squad/map_" + int_to_str(num_map) + "/squad_" + int_to_str(num) + "/info");
    fin >> buff >> num_tile >> buff >> num_map_battle >> buff >> num_enem >> buff;

    enemies = new Enemy*[num_enem];

    for(int i = 0; i < num_enem; i++)
    {
        fin >> enem;
        enemies[i] = new Enemy(num_map_battle, enem);
    }

    fin.close();

    sprite = enemies[0]->GetSprite();
}


void EnemiesSquad::Create()
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



void EnemiesSquad::SetNumTile(int _tile)
{
    num_tile = _tile;
}

void EnemiesSquad::SetPos(int _x, int _y)
{
    pos_x = _x;
    pos_y = _y;
}

void EnemiesSquad::SetSprPos(double _x, double _y)
{
    sprite.setPosition(_x, _y);
}



int EnemiesSquad::GetNum()
{
    return num;
}

int EnemiesSquad::GetMap()
{
    return num_map;
}

int EnemiesSquad::GetNumTile()
{
    return num_tile;
}

int EnemiesSquad::GetSizeH()
{
    return h;
}

int EnemiesSquad::GetSizeW()
{
    return w;
}

int EnemiesSquad::GetPosX()
{
    return pos_x;
}

int EnemiesSquad::GetPosY()
{
    return pos_y;
}

double EnemiesSquad::GetSprX()
{
    return sprite.getPosition().x;
}

double EnemiesSquad::GetSprY()
{
    return sprite.getPosition().y;
}

int EnemiesSquad::GetNumEnem()
{
    return num_enem;
}

Enemy* EnemiesSquad::GetEnem(int _num)
{
    return enemies[_num];
}

sf::Sprite EnemiesSquad::GetSprite()
{
    return sprite;
}

EnemiesSquad::~EnemiesSquad()
{
    //dtor
}
