#include <SFML/Graphics.hpp>
#include "include/map_generator.h"


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    MapGenerator map_gen("3");

   // sf::Image map_image;
	//map_image.loadFromFile("cb.bmp");
//	sf::Texture map;
//	map.loadFromFile("cb.bmp");
//	sf::Sprite s_map;
//	s_map.setTexture(map);

    sf::Clock clock;
    int fps = 0;

	// Start the game loop
    while (window.isOpen())
    {
//        float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
//        clock.restart(); //перезагружает время
//      // time = time/800; //скорость игры
//      // if(time > 18000)
//        fps = 1000000 / time;
//        std::cout << fps << "\n";

        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen
        window.clear();

        // Draw the sprite
      //  window.draw(s_map);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
