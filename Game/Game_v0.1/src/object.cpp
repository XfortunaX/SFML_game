#include "object.h"

Object::Object(std::string name_obj, int _type, int n_obj)
{
    std::string buff;

    type = _type;
    name = str_to_int(name_obj);
    num = n_obj;

    std::ifstream fin2;

    if(type == 4)
        fin2.open("resource/objects/objects_quad/object_" + name_obj + "/info");
    if(type == 6)
        fin2.open("resource/objects/objects_hex/object_" + name_obj + "/info");
    fin2 >> buff >> h >> buff >> w;
    fin2.close();

    if(type == 4)
        texture.loadFromFile("resource/objects/objects_quad/object_" + name_obj + "/image.png");
    if(type == 6)
        texture.loadFromFile("resource/objects/objects_hex/object_" + name_obj + "/image.png");
    sprite.setTexture(texture);
}



void Object::SetPosition(double _x, double _y)
{
    sprite.setPosition(_x, _y);
}

void Object::SetSize(int _h, int _w)
{
    h *= _h;
    w *= _w;
}



int Object::GetNum()
{
    return num;
}

int Object::GetSizeH()
{
    return h;
}

int Object::GetSizeW()
{
    return w;
}

sf::Sprite Object::GetSprite()
{
    return sprite;
}

Object::~Object()
{
    //dtor
}
