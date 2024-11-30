#include "..\Headers\LvlOne.h"





int main()
{
/////////////////////////////////////////////////Flags and Variable////////////////////////////////////////////////////////////////

    float dt = (1.0f / 60.0f);
    sf::Vector2f PlayerStartingPosition = { 0, 505 };
    sf::Vector2f BackgroundStartingPosition = { 0, -117 };
    sf::Vector2f dir = { 0.0f, 0.0f };

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////Create Window////////////////////////////////////////////////////////////////////

    sf::RenderWindow window(sf::VideoMode(800, 600), "Mario Bros");     ///////////////////////////////////////////////////////////
 
/////////////////////////////////////////////////Create Mario Sprite///////////////////////////////////////////////////////////////
                                                                

 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    LvlOne One("Textures\\PlayerSheet.png", "Textures\\Mario Bros-World 1-1.png", PlayerStartingPosition, BackgroundStartingPosition);
/////////////////////////////////////////////Game Loop/////////////////////////////////////////////////////////////////////////////

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        dir.x = 0.0f;

        //Handle Input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            dir.x += 1.0f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            dir.x -= 1.0f;
        }
        

        One.SetDirection(dir);
        One.Update(dt);
        

        window.clear();
        One.Draw(window);
        window.display();
    }

    return 0;
}