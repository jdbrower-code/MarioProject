#include "..\Headers\LvlOne.h"





int main()
{
/////////////////////////////////////////////////Flags and Variable////////////////////////////////////////////////////////////////

    float dt = (1.0f / 60.0f);
    sf::Vector2f PlayerStartingPosition = { 0, 505 };
    sf::Vector2f BackgroundStartingPosition = { 0, -117 };
    sf::Vector2f dir = { 0.0f, 0.0f };
    int Pose = 0;

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
            if (Pose > 3)
                Pose = 0;
            else
                Pose++;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            dir.x -= 1.0f;
            if (Pose > 3)
                Pose = 0;
            else
                Pose++;
        }
        
        

        One.SetDirection(dir);
        One.Update(dt, Pose);
        

        window.clear();
        One.Draw(window, Pose);
        window.display();


    }

    return 0;
}