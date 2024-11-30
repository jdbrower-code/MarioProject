#include "..\Headers\Mario.h"





int main()
{
/////////////////////////////////////////////////Flags and Variable////////////////////////////////////////////////////////////////

    float dt = (1.0f / 60.0f);
    sf::Vector2f StartingPosition = { 0, 505 };
    sf::Vector2f dir = { 0.0f, 0.0f };

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////Create Window////////////////////////////////////////////////////////////////////

    sf::RenderWindow window(sf::VideoMode(800, 600), "Mario Bros");     ///////////////////////////////////////////////////////////
 
/////////////////////////////////////////////////Create Mario Sprite///////////////////////////////////////////////////////////////
                                                                

 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Mario mario("Textures\\PlayerSheet.png", StartingPosition);
/////////////////////////////////////////////Game Loop/////////////////////////////////////////////////////////////////////////////

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Handle Input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            dir.x += 1.0f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            dir.x -= 1.0f;
        }
        else
        {
            dir.x = 0.0f;
        }

        
        
        //if (dir.x > 0)
        //{
        //    
        //    mario_Posistion.x += dir.x/dt;
        //    Mario.setPosition(mario_Posistion.x, Mario.getPosition().y);
        //}
        //if (dir.x < 0)
        //{
        //    mario_Posistion.x += dir.x/dt;
        //    Mario.setPosition(mario_Posistion.x, Mario.getPosition().y);
        //}

        mario.SetDirection(dir);
        mario.Update(dt);
        

        window.clear();
        //window.draw(Mario);
        mario.Draw(window);
        window.display();
    }

    return 0;
}