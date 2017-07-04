#ifndef VIEW_H
#define VIEW_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Camera
{
    public:
        Camera();
        void CheckPos(double, double, int, int);

        void SetCamera(double, double);

        sf::View* GetView();

        virtual ~Camera();

    private:
        int h, w;
        sf::View view;

};

#endif // VIEW_H
