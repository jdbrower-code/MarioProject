#pragma once

#include "Core.h"

#include "..\Headers\LvlOne.h"

class Player
{
public:
	Player(std::string Player_FilePath, sf::Vector2f& PlayerPos);

	void SetDirection(sf::Vector2f& dir);

	void Update(float dt, bool Moving, bool inverted, LvlOne& BG);

	void Draw(sf::RenderTarget& rt) const;

	void InvertSprite(bool a);

	void ConstrainPosition();

	void Jump();

	sf::Vector2f GetPlayerPos();
private:
	int FrameWidth = 20;
	int FrameHeight = 16;


	static constexpr float Speed = 250.0f;
	sf::Vector2f Velocity = { 0.0f, 0.0f };
	sf::Vector2f m_MarioPosistion;

	sf::Texture MarioSheet;

	sf::Sprite MarioSprite;
	std::vector<sf::Sprite> WalkingAnimation;


	sf::Clock animationClock; // Clock to control frame updates
	float frameDelay = 0.08f; // Delay between frames in seconds
	int currentFrame = 0; // Current frame index

	float initialYPos = 0.0f;
	bool isJumping = false;

	const float gravity = 700.0f; // Acceleration due to gravity (pixels per second^2)
	const float initialJumpVelocity = -550.0f; // Initial upward velocity (negative for upward motion)
	float verticalVelocity = 0.0f; // Current vertical velocity
	const float groundLevel = 505.0f; // Y-position of the ground
};