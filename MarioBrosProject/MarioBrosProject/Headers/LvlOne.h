#pragma once
#include "Core.h"

class LvlOne
{
public:
    LvlOne(std::string BackgroundFilePath, sf::Vector2f& BackgrounPos);

    void SetDirection(sf::Vector2f& dir);

    void Update(float dt);

    void Draw(sf::RenderTarget& rt) const;

    sf::Sprite GetBackground();

    sf::Sprite SetBackground(float a, float b);

    sf::Vector2f Set_m_BackgroundPosition(float x, float y);


private:


    static constexpr float Speed = 250.0f;
    sf::Vector2f Velocity = { 0.0f, 0.0f };
;
    sf::Vector2f m_BackGroundPosition;
    //Create Texture                                                

    sf::Texture BackGroundSheet;




    sf::Sprite BackGroundSprite;


   // float jumpProgress = 0.0f; // Current jump height
    //static constexpr float gravity = 0.3f; // Gravity constant


};