#include "..\Headers\Mario.h"


Mario::Mario(std::string FilePath, sf::Vector2f& Pos)
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

void Mario::SetDirection(sf::Vector2f& dir)
{
    Velocity = Speed * dir;
}

void Mario::Update(float dt)
{
    
    

    if (MarioSprite.getPosition().x < 0)
    {
        MarioSprite.setPosition(0.0f, MarioSprite.getPosition().y);
        m_MarioPosistion.x = 0.0; // Ensure the internal position is updated to avoid continuous flicker
    }
    else if (MarioSprite.getPosition().x > 768)
    {
        MarioSprite.setPosition(768.0f, MarioSprite.getPosition().y);
        m_MarioPosistion.x = 768.0f;
    }
    else
    {
        m_MarioPosistion += Velocity * dt;
        MarioSprite.setPosition(m_MarioPosistion);
    }
        
}

void Mario::Draw(sf::RenderTarget& rt) const
    {
        rt.draw(MarioSprite);
    }