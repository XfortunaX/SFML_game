#ifndef CHARACTERISTICS_H
#define CHARACTERISTICS_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include "basic_funcs.h"

class Characteristics
{
    public:
        Characteristics();

        void Load(std::string);

        void SetHealth(int);
        void SetMana(int);

        int GetMaxHealth();
        int GetMaxMana();
        int GetHealth();
        int GetMana();

        virtual ~Characteristics();

    private:
        int health_max;
        int mana_max;
        int move_max;

        int health;
        int mana;
        int move;
};

#endif // CHARACTERISTICS_H
