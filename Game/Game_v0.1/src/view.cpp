#include "view.h"

Camera::Camera()
{
    w = 800; h = 600;
    view.reset(sf::FloatRect(0, 0, w, h));
}

void Camera::CheckPos(double _x, double _y, int _w, int _h)
{
    int x = _x;
    int y = _y;

    if(_x < w / 2)
        x = w / 2;
    if(_x > _w - w / 2)
        x = _w - w / 2;
    if(_y < h / 2)
        y = h / 2;
    if(_y > _h - h / 2)
        y = _h - h / 2;

    SetCamera(x, y);
}



void Camera::SetCamera(double x, double y)
{
    view.setCenter(x, y);
}



sf::View* Camera::GetView()
{
    return &view;
}

Camera::~Camera()
{
    //dtor
}
