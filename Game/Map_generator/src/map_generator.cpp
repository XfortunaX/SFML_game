#include "map_generator.h"

MapGenerator::MapGenerator(std::string num)
{
    std::string buff;
    int h_obj, w_obj;
    int m_abil;

    std::ifstream fin("resource/map_" + num + "/map_" + num + "_i");
    fin >> type_tile >> h >> w;

    map = new int*[h];
    for(int i = 0; i < w; i++)
        map[i] = new int[w];

    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            fin >> map[i][j];

    fin.close();

    std::ifstream fin_obj("resource/map_" + num + "/map_" + num + "_obj");
    fin_obj >> buff;

    int** map_obj = new int*[h];
    for(int i = 0; i < w; i++)
        map_obj[i] = new int[w];

    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            fin_obj >> map_obj[i][j];

    fin_obj.close();

    map_obj_m = new int*[h];
    for(int i = 0; i < w; i++)
        map_obj_m[i] = new int[w];

    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            map_obj_m[i][j] = 1;

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(map_obj[i][j] != 0)
            {
                std::ifstream fin_o;
                if(type_tile == 4)
                    fin_o.open("resource/objects/objects_quad/object_" + int_to_str(map_obj[i][j]) + "/info");
                if(type_tile == 6)
                    fin_o.open("resource/objects/objects_hex/object_" + int_to_str(map_obj[i][j]) + "/info");
                fin_o >> buff >> h_obj >> buff >> w_obj;

                for(int i1 = 0; i1 < h_obj; i1++)
                {
                    for(int j1 = 0; j1 < w_obj; j1++)
                    {
                        fin_o >> m_abil;
                        if(!m_abil)
                            map_obj_m[i + i1][j + j1] = 0;
                    }
                }

                fin_o.close();
            }
        }
    }

    ComGenerate(num);
}

void MapGenerator::ComGenerate(std::string num)
{
    int cur_tile = 1;
    int num_com = 0;
    int num_tiles = h * w;
    int** map_tile;

    map_tile = new int*[h];
    for(int i = 0; i < h; i++)
        map_tile[i] = new int[w];

//--------------------------------Нумерование тайлов карты----------------------------------
    std::ofstream fout_d("resource/map_" + num + "/map_" + num + "_d");

    fout_d << type_tile << "\n" << h << " " << w << "\n";

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(type_tile == 4)
            {
                if(map[i][j] > 0)
                {
                    fout_d << cur_tile;
                    map_tile[i][j] = cur_tile;
                    if(cur_tile < 10)
                        fout_d << "   ";
                    if(cur_tile < 100 && cur_tile > 9)
                        fout_d << "  ";
                    if(cur_tile < 1000 && cur_tile > 99)
                        fout_d << " ";
                    cur_tile++;
                }
                else
                {
                    fout_d << "0   ";
                    map_tile[i][j] = 0;
                }
            }
        }
        fout_d << "\n";
    }

    fout_d.close();
//-------------------------------------------------------------------------------------------

//---------------------------------Формирование связей тайлов--------------------------------
    std::ofstream fout("resource/map_" + num + "/map_" + num);

    fout << num_tiles << "\n";

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(map_tile[i][j] > 0)
            {
                fout << map_tile[i][j] << ")  " << map[i][j] << " comm ";

                if(type_tile == 4)
                {
                    num_com = 0;
                    if(i - 1 > -1 && map_tile[i - 1][j] > 0)
                        if(CheckTileMove(map[i - 1][j]) && map_obj_m[i - 1][j])
                            num_com++;
                    if(i + 1 < h && map_tile[i + 1][j] > 0)
                        if(CheckTileMove(map[i + 1][j]) && map_obj_m[i + 1][j])
                            num_com++;
                    if(j - 1 > -1 && map_tile[i][j - 1] > 0)
                        if(CheckTileMove(map[i][j - 1]) && map_obj_m[i][j - 1])
                            num_com++;
                    if(j + 1 < w && map_tile[i][j + 1] > 0)
                        if(CheckTileMove(map[i][j + 1]) && map_obj_m[i][j + 1])
                            num_com++;

                    fout << num_com << " - ";

                    if(i - 1 > -1 && map_tile[i - 1][j] > 0)
                        if(CheckTileMove(map[i - 1][j]) && map_obj_m[i - 1][j])
                            fout << map_tile[i - 1][j] << " ";
                    if(i + 1 < h && map_tile[i + 1][j] > 0)
                        if(CheckTileMove(map[i + 1][j])  && map_obj_m[i + 1][j])
                            fout << map_tile[i + 1][j] << " ";
                    if(j - 1 > -1 && map_tile[i][j - 1] > 0)
                        if(CheckTileMove(map[i][j - 1]) && map_obj_m[i][j - 1])
                            fout << map_tile[i][j - 1] << " ";
                    if(j + 1 < w && map_tile[i][j + 1] > 0)
                        if(CheckTileMove(map[i][j + 1]) && map_obj_m[i][j + 1])
                            fout << map_tile[i][j + 1] << " ";

                    fout << "\n";
                }
            }
        }
    }

    fout.close();
//--------------------------------------------------------------------------------------------

}

int MapGenerator::CheckTileMove(int _tile)
{
    std::ifstream fin;
    std::string buff;
    int move_abil = 1;

    if(type_tile == 4)
        fin.open("resource/tiles/tiles_quad/tile_" + int_to_str(_tile) + "/info");

    fin >> buff >> buff >> buff >> buff >> buff >> move_abil;

    return move_abil;
}

MapGenerator::~MapGenerator()
{
    //dtor
}
