#ifndef GAME_H
#define GAME_H
#include "main_menu.h"
#include "map_global.h"
#include "map_battle.h"

class Game
{
    public:
        Game();
        void Work();
        virtual ~Game();

    private:
        MapGlobal map_global;
};

#endif // GAME_H
