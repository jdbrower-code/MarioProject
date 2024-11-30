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
    m_MarioPosistion += Velocity * dt;
    MarioSprite.setPosition(m_MarioPosistion);
}

void Mario::Draw(sf::RenderTarget& rt) const
    {
        rt.draw(MarioSprite);
    }