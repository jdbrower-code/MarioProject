#include "..\Headers\LvlOne.h"


LvlOne::LvlOne(std::string Player_FilePath, std::string BackgroundFilePath, sf::Vector2f& PlayerPos, sf::Vector2f& BackgrounPos)
    :m_MarioPosistion(PlayerPos), m_BackGroundPosition(BackgrounPos)
{
    //Player Creation
        //Load file into Texture                                        
        MarioSheet.loadFromFile(Player_FilePath);
        //Set Texture for Sprite                                        
        MarioSprite.setTexture(MarioSheet);
        //Mark Sprite location on texture                               
        MarioSprite.setTextureRect(sf::IntRect(0, 0, 20, 16));
        //Set Sprite Scale                                              
        MarioSprite.setScale(2.0f, 2.0f);
        //Set Sprite Initial Location                                   
        MarioSprite.setPosition(m_MarioPosistion);
    //Background Creation
        //Load file into Texture
        BackGroundSheet.loadFromFile(BackgroundFilePath);
        //Set Texture for Sprite
        BackGroundSprite.setTexture(BackGroundSheet);
        //Set Sprite Scale
        BackGroundSprite.setScale(2.0f, 2.0f);
        //Set Sprite Initial Location
        BackGroundSprite.setPosition(m_BackGroundPosition);
}

void LvlOne::SetDirection(sf::Vector2f& dir)
{
    Velocity = Speed * dir;
}

void LvlOne::Update(float dt)
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

void LvlOne::Draw(sf::RenderTarget& rt) const
    {
        rt.draw(BackGroundSprite);
        rt.draw(MarioSprite);
    }