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

void LvlOne::Update(float dt, bool Moving, bool inverted)
{

    LvlOne::ConstrainPosition();

    // Jump logic
    if (isJumping)
    {
        // Increase jump progress over time
        jumpProgress += dt * 900.0f; // Jump speed, you can adjust it

        // Move the sprite up and then back down
        if (jumpProgress <= 300.0f)
        {
            // Ascend
            m_MarioPosistion.y -= 500.0f * dt; // Move up 10 pixels (adjust if needed)
        }
        else if (jumpProgress <= 2000.0f && MarioSprite.getPosition().y < 505)
        {
            // Descend back to original position
            m_MarioPosistion.y += 350.0f * dt; // Move down 10 pixels (adjust if needed)
        }
        else
        {
            // End of the jump, reset
            isJumping = false;
            jumpProgress = 0.0f;
        }
    }

    // Animation logic inside the game loop
    if(Moving)
    {
        if (animationClock.getElapsedTime().asSeconds() > frameDelay)
        {
            currentFrame = (currentFrame + 1) % 4; // Cycle through frames 0 to 3
            MarioSprite = WalkingAnimation[currentFrame]; // Update sprite
            LvlOne::InvertSprite(inverted);
            animationClock.restart(); // Reset the clock
        }
    }
    else
    {
        MarioSprite = WalkingAnimation[0];
    }

    
    std::cout << MarioSprite.getPosition().y << std::endl;

    if (MarioSprite.getPosition().x > 400.0f && BackGroundSprite.getPosition().x > -5952)
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
    else
    {
        
        MarioSprite.setPosition(m_MarioPosistion);
        m_MarioPosistion.x += Velocity.x * dt;
    }

        
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

void LvlOne::InvertSprite(bool a)
{
    float scale = a ? 2.0f : -2.0f;

    // Adjust origin for proper flipping
    if (scale < 0)
        MarioSprite.setOrigin(FrameWidth, 0); // Set origin to the right edge when inverted
    else
        MarioSprite.setOrigin(0, 0); // Default origin for normal direction

    MarioSprite.setScale(scale, 2.0f);
}

void LvlOne::ConstrainPosition()
{
    if (m_MarioPosistion.x < 0)
        m_MarioPosistion.x = 0.0f;
    else if (m_MarioPosistion.x > 575.0f)
        m_MarioPosistion.x = 575.0f;

    MarioSprite.setPosition(m_MarioPosistion);
}


// New method to trigger the jump
void LvlOne::Jump()
{
    if (!isJumping)
    {
        isJumping = true;
        jumpProgress = 0.0f;
    }
}