#ifndef MAP_GENERATOR_H
#define MAP_GENERATOR_H
#include <string>
#include <fstream>
#include <iostream>
#include "basic_funcs.h"

class MapGenerator
{
    public:
        MapGenerator(std::string);
        void ComGenerate(std::string);
        int CheckTileMove(int);
        virtual ~MapGenerator();

    private:
        int type_tile;
        int h, w;
        int** map;
        int** map_obj_m;
};

#endif // MAP_GENERATOR_H
