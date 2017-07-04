#include "characteristics.h"

Characteristics::Characteristics()
{
}



void Characteristics::Load(std::string path)
{
    std::string buff;
    std::ifstream fin(path);
    fin >> buff >> move >> buff >> health_max >> buff >> mana_max;
    fin.close();

    health = health_max;
    mana = mana_max;
}



void Characteristics::SetHealth(int _health)
{
    health = _health;
}

void Characteristics::SetMana(int _mana)
{
    mana = _mana;
}



int Characteristics::GetMaxHealth()
{
    return health_max;
}

int Characteristics::GetMaxMana()
{
    return mana_max;
}

int Characteristics::GetHealth()
{
    return health;
}

int Characteristics::GetMana()
{
    return mana;
}

Characteristics::~Characteristics()
{
    //dtor
}
