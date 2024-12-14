#pragma once
#include "Core.h"

class LvlOne
{
public:
    LvlOne(std::string Player_FilePath, std::string BackgroundFilePath, sf::Vector2f& PlayerPos, sf::Vector2f& BackgrounPos);

    void SetDirection(sf::Vector2f& dir);

    void Update(float dt, bool Moving, bool inverted);

    void Draw(sf::RenderTarget& rt) const;

    void InvertSprite(bool a);

    void ConstrainPosition();

    void Jump();


private:
    int FrameWidth = 20;
    int FrameHeight = 16;

    static constexpr float Speed = 300.0f;
    sf::Vector2f Velocity = { 0.0f, 0.0f };
    sf::Vector2f m_MarioPosistion;
    sf::Vector2f m_BackGroundPosition;
    //Create Texture                                                
    sf::Texture MarioSheet;
    sf::Texture BackGroundSheet;


    sf::Sprite MarioSprite;
    std::vector<sf::Sprite> WalkingAnimation;

    sf::Sprite BackGroundSprite;

    sf::Clock animationClock; // Clock to control frame updates
    float frameDelay = 0.08f; // Delay between frames in seconds
    int currentFrame = 0; // Current frame index

    float initialYPos = 0.0f;
    bool isJumping = false;
    float jumpProgress = 0.0f; // Current jump height
    //static constexpr float gravity = 0.3f; // Gravity constant

    const float gravity = 900.0f; // Acceleration due to gravity (pixels per second^2)
    const float initialJumpVelocity = -500.0f; // Initial upward velocity (negative for upward motion)
    float verticalVelocity = 0.0f; // Current vertical velocity
    const float groundLevel = 505.0f; // Y-position of the ground
};