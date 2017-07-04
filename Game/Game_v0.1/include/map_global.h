#ifndef MAP_GLOBAL_H
#define MAP_GLOBAL_H
#include <fstream>
#include "tile.h"
#include "view.h"
#include "hero.h"
#include "enemies_squad.h"
#include "object.h"

struct MapCom
{
    int tile_in;
    int map;
    int tile_out;
};

class MapGlobal
{
    public:
        MapGlobal();

        void FCreate();
        void Create(std::string);
        void DrawMap();
        void Draw();
        void HeroMove();
        int CheckMoveHero(double, double);
        int CheckBattle(int, int);

        Hero* GetHero();
        Camera* GetCamera();
        int GetNumObj();
        Object* GetObject(int);
        int GetNumEnemSquad();
        EnemiesSquad* GetEnemSquad(int);
        Tile* GetTile(int);
        sf::Sprite GetSprite();

        virtual ~MapGlobal();

    private:
        Hero hero;
        Camera camera;

        int num_obj;
        Object** objects;

        int num_enem_squad;
        EnemiesSquad** enemies_squad;

        int type;
        int num;

        int h, w;
        int** map_gl;
        int size_tile_h;
        int size_tile_w;
        int num_tiles;
        Tile** tiles;

        int num_com;
        MapCom* map_com;

        sf::RenderTexture map_texture;
        sf::RenderTexture global_texture;
        sf::Sprite map_sprite;
        sf::Sprite global_sprite;
};

#endif // MAP_GLOBAL_H
