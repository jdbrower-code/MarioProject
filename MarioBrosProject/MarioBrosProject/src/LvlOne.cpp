#include "..\Headers\LvlOne.h"


LvlOne::LvlOne(std::string Player_FilePath, std::string BackgroundFilePath, sf::Vector2f& PlayerPos, sf::Vector2f& BackgrounPos)
    :m_MarioPosistion(PlayerPos), m_BackGroundPosition(BackgrounPos)
{
    //Player Creation
        //Load file into Texture                                        
        MarioSheet.loadFromFile(Player_FilePath);
        for (int i = 0; i < 6; i++)
        {
            MarioSprite.setTexture(MarioSheet);
            MarioSprite.setTextureRect(sf::IntRect(i * FrameWidth, 0, FrameWidth, FrameHeight));
            MarioSprite.setScale(2.0f, 2.0f);
            WalkingAnimation.push_back(MarioSprite);
            WalkingAnimation[i].setPosition(m_MarioPosistion);
        }

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

void LvlOne::Update(float dt, bool Moving)
{
    // Animation logic inside the game loop
    if(Moving)
    {
        if (animationClock.getElapsedTime().asSeconds() > frameDelay)
        {
            currentFrame = (currentFrame + 1) % 4; // Cycle through frames 0 to 3
            MarioSprite = WalkingAnimation[currentFrame]; // Update sprite
            animationClock.restart(); // Reset the clock
        }
    }
    else
    {
        MarioSprite = WalkingAnimation[0];
    }

    
    std::cout << "Clock: " << animationClock.getElapsedTime().asSeconds() << std::endl;
    std::cout << "Frame Delay: " << frameDelay << std::endl;

    if (MarioSprite.getPosition().x < 0)
    {
        MarioSprite.setPosition(0, MarioSprite.getPosition().y);
        m_MarioPosistion.x = 0.0;
    }
    else if (MarioSprite.getPosition().x > 400.0f && BackGroundSprite.getPosition().x > -5952)
    {
        MarioSprite.setPosition(400, MarioSprite.getPosition().y);
        m_MarioPosistion.x = 400;
        if (BackGroundSprite.getPosition().x > 0)
        {
            BackGroundSprite.setPosition(0.0f, BackGroundSprite.getPosition().y);
            m_BackGroundPosition.x = 0.0f;
        }
        else
        {
            m_BackGroundPosition -= (Velocity * 3.5f) * dt;
            BackGroundSprite.setPosition(m_BackGroundPosition);
        }
    }
    else if (MarioSprite.getPosition().x > 575.0f)
    {
        MarioSprite.setPosition(575.0f, MarioSprite.getPosition().y);
        m_MarioPosistion.x = 575.0f;
    
    }
    else
    {
        
        MarioSprite.setPosition(m_MarioPosistion);
        m_MarioPosistion += Velocity * dt;
    }

    //if (WalkingAnimation[Pose].getPosition().x < 0)
    //{
    //    WalkingAnimation[Pose].setPosition(0.0f, WalkingAnimation[Pose].getPosition().y);
    //    m_MarioPosistion.x = 0.0; // Ensure the internal position is updated to avoid continuous flicker
    //}
    //else if (WalkingAnimation[Pose].getPosition().x > 400.0f && BackGroundSprite.getPosition().x > -5952)
    //{
    //    WalkingAnimation[Pose].setPosition(400.0f, WalkingAnimation[Pose].getPosition().y);
    //    m_MarioPosistion.x = 400.0f;

    //    if (BackGroundSprite.getPosition().x > 0)
    //    {
    //        BackGroundSprite.setPosition(0.0f, BackGroundSprite.getPosition().y);
    //        m_BackGroundPosition.x = 0.0f;
    //    }
    //    else
    //    {
    //        m_BackGroundPosition -= (Velocity * 1.5f) * dt;
    //        BackGroundSprite.setPosition(m_BackGroundPosition);
    //    }


    //    std::cout << WalkingAnimation[Pose].getPosition().x << std::endl;
    //}
    //else if (WalkingAnimation[Pose].getPosition().x > 575.0f)
    //{
    //    WalkingAnimation[Pose].setPosition(575.0f, WalkingAnimation[Pose].getPosition().y);
    //    m_MarioPosistion.x = 575.0f;

    //}
    //else
    //{
    //    
    //    WalkingAnimation[Pose].setPosition(m_MarioPosistion);
    //    m_MarioPosistion += Velocity * dt;
    //}
        
}

void LvlOne::Draw(sf::RenderTarget& rt) const
{

    if (MarioSprite.getPosition().x < 575)
    {
        rt.draw(BackGroundSprite);
        rt.draw(MarioSprite);
    }
    else
        rt.draw(BackGroundSprite);


}