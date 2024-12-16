#include "..\Headers\Player.h"



Player::Player(std::string Player_FilePath, sf::Vector2f& PlayerPos)
	:m_MarioPosistion(PlayerPos)
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
}

void Player::SetDirection(sf::Vector2f& dir)
{
    Velocity = Speed * dir;
}

void Player::Update(float dt, bool Moving, bool inverted, LvlOne& BG)
{
    Player::ConstrainPosition();

    if (isJumping)
    {
        // Apply vertical velocity to Mario's position
        m_MarioPosistion.y += verticalVelocity * dt;

        // Apply gravity to the vertical velocity
        verticalVelocity += gravity * dt;




        // Check if Mario has landed (or reached the ground)
        if (m_MarioPosistion.y >= groundLevel)
        {
            m_MarioPosistion.y = groundLevel; // Snap to ground
            isJumping = false;                // End the jump
            verticalVelocity = 0.0f;          // Reset velocity

        }
    }

    // Animation logic inside the game loop
    if (Moving)
    {
        if (animationClock.getElapsedTime().asSeconds() > frameDelay)
        {
            currentFrame = (currentFrame + 1) % 4; // Cycle through frames 0 to 3
            MarioSprite = WalkingAnimation[currentFrame]; // Update sprite
            Player::InvertSprite(inverted);
            animationClock.restart(); // Reset the clock

            if (isJumping)
            {
                MarioSprite = WalkingAnimation[5];
                Player::InvertSprite(inverted);
            }

        }
    }
    else
    {
        MarioSprite = WalkingAnimation[0];
    }

    if (MarioSprite.getPosition().x > 400 && BG.GetBackground().getPosition().x > -5952)
    {
        MarioSprite.setPosition(400, MarioSprite.getPosition().y);
        m_MarioPosistion.x = 400;

        BG.Update(dt);
    }
    else
    {

        MarioSprite.setPosition(m_MarioPosistion);
        m_MarioPosistion.x += Velocity.x * dt;
    }

    
}

void Player::Draw(sf::RenderTarget& rt) const
{
    if (MarioSprite.getPosition().x < 575)
        rt.draw(MarioSprite);
}

void Player::InvertSprite(bool a)
{
    float scale = a ? 2.0f : -2.0f;

    // Adjust origin for proper flipping
    if (scale < 0)
        MarioSprite.setOrigin(FrameWidth, 0); // Set origin to the right edge when inverted
    else
        MarioSprite.setOrigin(0, 0); // Default origin for normal direction

    MarioSprite.setScale(scale, 2.0f);
}

void Player::ConstrainPosition()
{
    if (m_MarioPosistion.x < 0)
        m_MarioPosistion.x = 0.0f;
    else if (m_MarioPosistion.x > 575.0f)
        m_MarioPosistion.x = 575.0f;

    MarioSprite.setPosition(m_MarioPosistion);
}

void Player::Jump()
{
    if (!isJumping)
    {
        isJumping = true;
        verticalVelocity = initialJumpVelocity; // Set initial upward velocity
    }
}

sf::Vector2f Player::GetPlayerPos()
{
    return MarioSprite.getPosition();
}