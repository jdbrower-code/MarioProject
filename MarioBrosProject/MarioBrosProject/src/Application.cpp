#include <SFML/Graphics.hpp>


class Mario
{
public:
    Mario(std::string FilePath, sf::Vector2f& Pos)
        :m_MarioPosistion(Pos)
    {
                                                 
        //Load file into Texture                                        
        MarioSheet.loadFromFile(FilePath);                                                          
        //Set Texture for Sprite                                        
        MarioSprite.setTexture(MarioSheet);
        //Mark Sprite location on texture                               
        MarioSprite.setTextureRect(sf::IntRect(0, 0, 20, 16));
        //Set Sprite Scale                                              
        MarioSprite.setScale(2.0f, 2.0f);
        //Set Sprite Initial Location                                   
        MarioSprite.setPosition(m_MarioPosistion);
    }

    void Draw(sf::RenderTarget& rt) const
    {
        rt.draw(MarioSprite);
    }
private:
    sf::Vector2f dir = { 0.0f, 0.0f };
    static constexpr float Speed = 0.005f;
    sf::Vector2f Velocity = { 0.0f, 0.0f };
    sf::Vector2f m_MarioPosistion;
    //Create Texture                                                
    sf::Texture MarioSheet;
    sf::Sprite MarioSprite;
    
};


int main()
{
/////////////////////////////////////////////////Flags and Variable////////////////////////////////////////////////////////////////

    float dt = (1.0f / 60.0f);
    sf::Vector2f StartingPosition = { 0, 505 };

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////Create Window////////////////////////////////////////////////////////////////////

    sf::RenderWindow window(sf::VideoMode(800, 600), "Mario Bros");     ///////////////////////////////////////////////////////////
 
/////////////////////////////////////////////////Create Mario Sprite///////////////////////////////////////////////////////////////
                                                                
                                          ///////////////////////////////////////////////////////////
                                                                        ///////////////////////////////////////////////////////////
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
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        //{
        //    dir.x += 1.0f;
        //}
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        //{
        //    dir.x -= 1.0f;
        //}

        
        
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
        

        window.clear();
        //window.draw(Mario);
        mario.Draw(window);
        window.display();
    }

    return 0;
}