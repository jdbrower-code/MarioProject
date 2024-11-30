#pragma once
#include "Core.h"

class Mario
{
public:
    Mario(std::string FilePath, sf::Vector2f& Pos);

    void Draw(sf::RenderTarget& rt) const;
private:
    sf::Vector2f dir = { 0.0f, 0.0f };
    static constexpr float Speed = 0.005f;
    sf::Vector2f Velocity = { 0.0f, 0.0f };
    sf::Vector2f m_MarioPosistion;
    //Create Texture                                                
    sf::Texture MarioSheet;
    sf::Sprite MarioSprite;

};