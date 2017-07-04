#include "map_global.h"

MapGlobal::MapGlobal()
{
    //ctor
}

void MapGlobal::FCreate()
{
    size_tile_h = 72;
    size_tile_w = 72;
    hero.Create();
    Create(int_to_str(hero.GetMap()));
}

void MapGlobal::Create(std::string map_name)
{
    int n, _x, _y;
    std::string buff, str, str2;

    num = str_to_int(map_name);

//---------------------------Загрузка структуры карты------------------------------------
    std::ifstream fin2("resource/maps_global/map_" + map_name + "/map_" + map_name + "_d");
    fin2 >> type >> h >> w;

//------------------------------Загрузка связей тайлов-----------------------------------
    std::ifstream fin("resource/maps_global/map_" + map_name + "/map_" + map_name);
    fin >> num_tiles;

    tiles = new Tile*[num_tiles];

    for(int i = 0; i < num_tiles; i++)
    {
        fin >> buff >> str >> buff >> str2;
        n = str_to_int(str2);
        tiles[i] = new Tile(str, type, n, i + 1);
        tiles[i]->SetSize(size_tile_h, size_tile_w);
        fin >> buff;

        for(int j = 0; j < n; j++)
        {
            fin >> str;
            tiles[i]->CreateCom(str_to_int(str));
        }
    }

    fin.close();
//---------------------------------------------------------------------------------------

    map_gl = new int*[h];

    //-------------------------  Если клетки 4-хугольники  ---------------------------
    if(type == 4)
    {
        for(int i = 0; i < h; i++)
        {
            map_gl[i] = new int[w];

            for(int j = 0; j < w; j++)
            {
                fin2 >> map_gl[i][j];
                if(map_gl[i][j] > 0)
                {
                    tiles[map_gl[i][j] - 1]->SetPosition(j * tiles[map_gl[i][j] - 1]->GetSizeW(),
                        i *  tiles[map_gl[i][j] - 1]->GetSizeH());
                }
            }
        }
    }
    //--------------------------Если клетки 6-тиугольники-------------------------------
    if(type == 6)
    {
        for(int i = 0; i < h; i++)
        {
            map_gl[i] = new int[w - i % 2];

            for(int j = 0; j < w - i % 2; j++)
            {
                fin2 >> map_gl[i][j];
                if(map_gl[i][j] > 0)
                {
                    if(i % 2 == 0)
                    {
                        tiles[map_gl[i][j] - 1]->SetPosition((1.5 * j) * tiles[map_gl[i][j] - 1]->GetSizeW(),
                            ((h - i) / 2 + 1) * tiles[map_gl[i][j] - 1]->GetSizeH());
                    }
                    if(i % 2 == 1)
                    {
                        tiles[map_gl[i][j] - 1]->SetPosition((0.75 + 1.5 * j) * tiles[map_gl[i][j] - 1]->GetSizeW(),
                            (0.5 + (h - i) / 2) * tiles[map_gl[i][j] - 1]->GetSizeH());
                    }
                }
            }
        }
    }
    //-------------------------------------------------------------------------------
    fin2.close();

    //------------------------Загрузка объектов карты--------------------------------
    std::ifstream fin3("resource/maps_global/map_" + map_name + "/map_" + map_name + "_obj");
    fin3 >> num_obj;
    n = 0;

    if(num_obj)
    {
        objects = new Object*[num_obj];

        if(type == 4)
        {
            for(int i = 0; i < h; i++)
                for(int j = 0; j < w; j++)
                {
                    fin3 >> str;
                    if(str_to_int(str))
                    {
                        objects[n] = new Object(str, type, n);
                        objects[n]->SetPosition(tiles[map_gl[i][j] - 1]->GetPosX(), tiles[map_gl[i][j] - 1]->GetPosY());
                        n++;
                    }
                }
        }
    }

    fin3.close();
    //--------------------------------------------------------------------------------

    //-----------------------Загрузка врагов------------------------------------------
    std::ifstream fin4("resource/enemies/enemies_squad/map_" + map_name + "/info");
    fin4 >> buff >> num_enem_squad;
    fin4.close();

    enemies_squad = new EnemiesSquad*[num_enem_squad];

    for(int i = 0; i < num_enem_squad; i++)
    {
        enemies_squad[i] = new EnemiesSquad(num, i + 1);
        _x = tiles[enemies_squad[i]->GetNumTile() - 1]->GetPosX();
        _y = tiles[enemies_squad[i]->GetNumTile() - 1]->GetPosY();
        enemies_squad[i]->SetSprPos(_x, _y);
        tiles[enemies_squad[i]->GetNumTile() - 1]->SetEnemy(enemies_squad[i]->GetNum());
    }

    fin4.close();
    //--------------------------------------------------------------------------------

    //------------------------Формирование связей между картами-----------------------
    std::ifstream fin5("resource/maps_global/map_" + map_name + "/map_" + map_name + "_c");
    fin5 >> num_com;

    map_com = new MapCom[num_com];

    for(int i = 0; i < num_com; i++)
    {
        fin5 >> buff >> map_com[i].tile_in >> buff >> map_com[i].map >> buff >> map_com[i].tile_out;
    }

    fin5.close();
    //---------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------

    hero.SetSprPos(tiles[hero.GetNumTile() - 1]->GetPosX(), tiles[hero.GetNumTile() - 1]->GetPosY());

    DrawMap();
}

void MapGlobal::DrawMap()
{
    if(type == 4)
    {
        map_texture.create(w * tiles[0]->GetSizeW(), h * tiles[0]->GetSizeH());
        global_texture.create(w * tiles[0]->GetSizeW(), h * tiles[0]->GetSizeH());
    }
    if(type == 6)
    {
        map_texture.create(w * tiles[0]->GetSizeW(), h / 1.5 * tiles[0]->GetSizeH());
        global_texture.create(w * tiles[0]->GetSizeW(), h / 1.5 * tiles[0]->GetSizeH());
    }

    map_texture.clear();

    for(int i = 0; i < num_tiles; i++)
    {
        map_texture.draw(tiles[i]->GetSprite());
    }

    map_texture.display();

    const sf::Texture& texture = map_texture.getTexture();

    map_sprite.setTexture(texture);
}

void MapGlobal::Draw()
{
    global_texture.clear();

    global_texture.draw(map_sprite);
    global_texture.draw(hero.GetSprite());

    global_texture.display();

    const sf::Texture& texture = global_texture.getTexture();

    global_sprite.setTexture(texture);
}

void MapGlobal::HeroMove()
{
    double speed = 1;
    double x = hero.GetSprX() + tiles[0]->GetSizeW() / 2;
    double y = hero.GetSprY() + tiles[0]->GetSizeH() / 2;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        y -= speed;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        y += speed;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        x -= speed;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        x += speed;

    if(CheckMoveHero(x, y))
    {
        x -= tiles[0]->GetSizeW() / 2;
        y -= tiles[0]->GetSizeH() / 2;
        hero.SetPos(x / tiles[0]->GetSizeW(), y / tiles[0]->GetSizeH());
        hero.SetSprPos(x, y);
    }

    if(CheckBattle(hero.GetPosX(), hero.GetPosY()))
    {

    }

    camera.CheckPos(hero.GetSprX() + tiles[0]->GetSizeW() / 2, hero.GetSprY() + tiles[0]->GetSizeH() / 2,
        w * tiles[0]->GetSizeW(), h * tiles[0]->GetSizeH());

    for(int i = 0; i < num_com; i++)
    {
        if(hero.GetNumTile() == map_com[i].tile_in)
        {
            hero.SetNumTile(map_com[i].tile_out);
            Create(int_to_str(map_com[i].map));
        }
    }

  //  Draw();
}

int MapGlobal::CheckMoveHero(double _x, double _y)
{
    int map_x = _x / tiles[0]->GetSizeW();
    int map_y = _y / tiles[0]->GetSizeH();

    if(_x >= tiles[0]->GetSizeW() / 2 && _y >= tiles[0]->GetSizeH() / 2 &&
        _x < w * tiles[0]->GetSizeW() - tiles[0]->GetSizeW() / 2 && _y < h * tiles[0]->GetSizeH() - tiles[0]->GetSizeH() / 2)
    {
        int num_tile = map_gl[map_y][map_x];
        if(num_tile != hero.GetNumTile())
        {
            if(tiles[hero.GetNumTile() - 1]->CheckCom(num_tile))
            {
                hero.SetNumTile(num_tile);
                return 1;
            }
            return 0;
        }
        return 1;
    }

    return 0;
}

int MapGlobal::CheckBattle(int _x, int _y)
{
    std::cout << "\n" << _x << "  " << _y;
    for(int i = -1; i < 2; i++)
    {
        for(int j = -1; j < 2; j++)
        {
            if(_x + j >= 0 && _y + i >= 0 && _x + j < w && _y + i < h)
            {
                if(tiles[map_gl[_y + i][_x + j] - 1]->CheckEnemy())
                {
                    std::cout << "\n" << "enem  " << hero.GetNumTile();
                    return 1;
                }
            }
        }
    }

    return 0;
}



Hero* MapGlobal::GetHero()
{
    return &hero;
}

Camera* MapGlobal::GetCamera()
{
    return &camera;
}

Tile* MapGlobal::GetTile(int _num)
{
    return tiles[_num];
}

int MapGlobal::GetNumObj()
{
    return num_obj;
}

Object* MapGlobal::GetObject(int _num)
{
    return objects[_num];
}

int MapGlobal::GetNumEnemSquad()
{
    return num_enem_squad;
}

EnemiesSquad* MapGlobal::GetEnemSquad(int _num)
{
    return enemies_squad[_num];
}

sf::Sprite MapGlobal::GetSprite()
{
    return map_sprite;
}

MapGlobal::~MapGlobal()
{
    //dtor
}
