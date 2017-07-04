#include "game.h"

Game::Game()
{
    map_global.FCreate();
}

void Game::Work()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::Vector2i v2i;
    v2i.x = 400; v2i.y = 200;
    window.setPosition(v2i);
 // window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(300);

    sf::Texture texture;
    texture.loadFromFile("resource/backgrounds/background_1/image.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::Clock clock;
    int fps;

	// Start the game loop
    while (window.isOpen())
    {

//      float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
//      clock.restart(); //перезагружает время
//      // time = time/800; //скорость игры
//      //   if(time > 18000)
//      fps = 1000000 / time;
//      std::cout << fps << "\n";
        // Process events

        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        map_global.HeroMove();
        window.setView(*(map_global.GetCamera()->GetView()));
        window.clear();

        window.draw(sprite);
        window.draw(map_global.GetSprite());
        window.draw(map_global.GetHero()->GetSprite());
        for(int i = 0; i < map_global.GetNumObj(); i++)
        {
            window.draw(map_global.GetObject(i)->GetSprite());
        }
        for(int i = 0; i < map_global.GetNumEnemSquad(); i++)
        {
            window.draw(map_global.GetEnemSquad(i)->GetSprite());
        }

        window.display();
    }
}

Game::~Game()
{
    //dtor
}
