#include "..\Headers\LvlOne.h"


LvlOne::LvlOne(std::string BackgroundFilePath, sf::Vector2f& BackgrounPos)
    :m_BackGroundPosition(BackgrounPos)
{


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

        

        if (BackGroundSprite.getPosition().x > 0)
        {
            m_BackGroundPosition.x = 0.0f;
            BackGroundSprite.setPosition(0.0f, BackGroundSprite.getPosition().y);
            
        }
        else
        {
            if (BackGroundSprite.getPosition().x > -5952)
            {
                m_BackGroundPosition -= (Velocity * 2.0f * dt);
                BackGroundSprite.setPosition(m_BackGroundPosition);
            }
                   
        }
    


        
}

void LvlOne::Draw(sf::RenderTarget& rt) const
{
        rt.draw(BackGroundSprite);
}






// New method to trigger the jump


sf::Sprite LvlOne::GetBackground()
{
    return BackGroundSprite;
}

