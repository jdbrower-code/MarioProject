#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mario Bros");

    sf::Texture MarioSheet;
    MarioSheet.loadFromFile("Textures\\PlayerSheet.png");
    sf::Sprite Mario;
    Mario.setTexture(MarioSheet);
    Mario.setTextureRect(sf::IntRect(0, 0, 20, 16));
    Mario.setScale(2.0f, 2.0f);
    Mario.setPosition(0, 505);
     


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(Mario);
        window.display();
    }

    return 0;
}