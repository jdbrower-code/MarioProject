#pragma once
#include "Core.h"

class LvlOne
{
public:
    LvlOne(std::string Player_FilePath, std::string BackgroundFilePath, sf::Vector2f& PlayerPos, sf::Vector2f& BackgrounPos);

    void SetDirection(sf::Vector2f& dir);

    void Update(float dt);

    void Draw(sf::RenderTarget& rt) const;

private:
    
    static constexpr float Speed = 5.0f;
    sf::Vector2f Velocity = { 0.0f, 0.0f };
    sf::Vector2f m_MarioPosistion;
    sf::Vector2f m_BackGroundPosition;
    //Create Texture                                                
    sf::Texture MarioSheet;
    sf::Texture BackGroundSheet;
    sf::Sprite MarioSprite;
    sf::Sprite BackGroundSprite;

};