#pragma once
#include "Core.h"

class Mario
{
public:
    Mario(std::string FilePath, sf::Vector2f& Pos);

    void SetDirection(sf::Vector2f& dir);

    void Update(float dt);

    void Draw(sf::RenderTarget& rt) const;

private:
    
    static constexpr float Speed = 0.05f;
    sf::Vector2f Velocity = { 0.0f, 0.0f };
    sf::Vector2f m_MarioPosistion;
    //Create Texture                                                
    sf::Texture MarioSheet;
    sf::Sprite MarioSprite;

};