#pragma once
#include "Core.h"

class LvlOne
{
public:
    LvlOne(std::string Player_FilePath, std::string BackgroundFilePath, sf::Vector2f& PlayerPos, sf::Vector2f& BackgrounPos);

    void SetDirection(sf::Vector2f& dir);

    void Update(float dt, int Pose);

    void Draw(sf::RenderTarget& rt, int Pose) const;

private:
    int FrameWidth = 20;
    int FrameHeight = 16;

    static constexpr float Speed = 5.0f;
    sf::Vector2f Velocity = { 0.0f, 0.0f };
    sf::Vector2f m_MarioPosistion;
    sf::Vector2f m_BackGroundPosition;
    //Create Texture                                                
    sf::Texture MarioSheet;
    sf::Texture BackGroundSheet;


    sf::Sprite MarioSprite;
    std::vector<sf::Sprite> WalkingAnimation;

    sf::Sprite BackGroundSprite;

};