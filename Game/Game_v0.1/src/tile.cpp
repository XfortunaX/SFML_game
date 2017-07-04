#include "tile.h"

Tile::Tile(std::string name_tile, int _type, int n_com, int n_tile)
{
    std::string buff;

    type = _type;
    name = str_to_int(name_tile);
    num = n_tile;

    std::ifstream fin2;

    if(type == 4)
        fin2.open("resource/tiles/tiles_quad/tile_" + name_tile + "/info");
    if(type == 6)
        fin2.open("resource/tiles/tiles_hex/tile_" + name_tile + "/info");
    fin2 >> buff >> h >> buff >> w >> buff >> move_abil;
    fin2.close();

    num_com = n_com;
    cur_com = 0;

    com = new int*[num_com];
    for(int i = 0; i < num_com; i++)
        com[i] = new int[2];

    if(type == 4)
        texture.loadFromFile("resource/tiles/tiles_quad/tile_" + name_tile + "/image.png");
    if(type == 6)
        texture.loadFromFile("resource/tiles/tiles_hex/tile_" + name_tile + "/image.png");
    sprite.setTexture(texture);

    pos_x = 0; pos_y = 0;
    busy[0] = 0; busy[1] = 0;
}

void Tile::CreateCom(int _com)
{
    com[cur_com][0] = _com;
    com[cur_com][1] = 1;
    cur_com++;
}

int Tile::CheckCom(int num_tile)
{
    for(int i = 0; i < num_com; i++)
    {
        if(num_tile == com[i][0] && com[i][1] == 1)
            return 1;
    }
    return 0;
}



void Tile::SetPosition(double _x, double _y)
{
    pos_x = _x;
    pos_y = _y;

    sprite.setPosition(pos_x, pos_y);
}

void Tile::SetSize(int _h, int _w)
{
    h *= _h;
    w *= _w;
}

void Tile::SetHero(int _hero)
{
    busy[0] = 1;
    busy[1] = _hero;
}

void Tile::SetEnemy(int _enem)
{
    busy[0] = 2;
    busy[1] = _enem;
}

void Tile::SetNps(int _nps)
{
    busy[0] = 3;
    busy[1] = _nps;
}

void Tile::SetObject(int _obj)
{
    busy[0] = 4;
    busy[1] = _obj;
}



int Tile::CheckHero()
{
    if(busy[0] == 1)
        return busy[1];
    return 0;
}

int Tile::CheckEnemy()
{
    if(busy[0] == 2)
        return busy[1];
    return 0;
}

int Tile::CheckNps()
{
    if(busy[0] == 3)
        return busy[1];
    return 0;
}

int Tile::CheckObject()
{
    if(busy[0] == 4)
        return busy[1];
    return 0;
}

int Tile::GetNum()
{
    return num;
}

int Tile::GetSizeH()
{
    return h;
}

int Tile::GetSizeW()
{
    return w;
}

double Tile::GetPosX()
{
    return pos_x;
}

double Tile::GetPosY()
{
    return pos_y;
}

int Tile::GetMoveAbil()
{
    return move_abil;
}

sf::Sprite Tile::GetSprite()
{
    return sprite;
}

void Tile::Print()
{
    std::cout << "\n" << num_com << "  ";
    for(int i = 0; i < num_com; i++)
        std::cout << com[i][0] << " ";
}

Tile::~Tile()
{
    //dtor
}
