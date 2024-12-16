#include "..\Headers\LvlOne.h"
#include "..\Headers\Player.h"





int main()
{
/////////////////////////////////////////////////Flags and Variable////////////////////////////////////////////////////////////////
    sf::Clock dt_time;
    
    sf::Vector2f PlayerStartingPosition = { 0, 505 };
    sf::Vector2f BackgroundStartingPosition = { 0, -117 };
    sf::Vector2f dir = { 0.0f, 0.0f };
    //int Pose = 0;
    bool Moving = false;

    bool inverted = true; // Direction flag
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////Create Window////////////////////////////////////////////////////////////////////

    sf::RenderWindow window(sf::VideoMode(800, 600), "Mario Bros");     ///////////////////////////////////////////////////////////
 
    window.setFramerateLimit(240);
/////////////////////////////////////////////////Create Mario Sprite///////////////////////////////////////////////////////////////
                                                                

 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    LvlOne One("Textures\\Mario Bros-World 1-1.png", BackgroundStartingPosition);
    Player Mario("Textures\\PlayerSheet.png", PlayerStartingPosition);
/////////////////////////////////////////////Game Loop/////////////////////////////////////////////////////////////////////////////



    while (window.isOpen())
    {
        float dt = dt_time.restart().asSeconds();

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
            inverted = true;
            dir.x += 1.0f;
            Moving = true;
            

;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            inverted = false;
            dir.x -= 1.0f;
            Moving = true;
            

        }
        else
        {
            dir.x = 0.0;
            Moving = false;
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            Mario.Jump();
        }
        

        One.SetDirection(dir);
        Mario.SetDirection(dir);
        
        Mario.Update(dt, Moving, inverted, One);
        

        window.clear();
        One.Draw(window);
        Mario.Draw(window);
        window.display();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();

    }

    return 0;
}