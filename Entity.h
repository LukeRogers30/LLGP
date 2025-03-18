#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class Entity
{

	// Sprite and Animation?
    const Image m_eImage;
    Texture m_eTexture;

    bool result = m_eTexture.loadFromImage(m_eImage, false, IntRect({ 0, 0 }, { 32, 64 }));
    Sprite m_eSprite;

    // Movement
	float m_accel;
	float m_currentVelocX = 0.0f;
	float m_maxVelocX;
	float m_accelDecay;
	float m_timeToMaxVeloc = (m_maxVelocX - m_currentVelocX) / m_accel;

	float m_jumpForce;
	int m_jumpCount;
	int m_maxJumps;
	float m_jumpTimer;
	float m_maxJumpTime;
	float m_gravity = 5.f;
	float m_currentVelocY = 0.f;
	float m_maxVelocY;

	int m_directionX;
	bool m_isFacingRight;

	bool m_isGrounded;

    // Health 
	float m_maxHP;
	float m_currentHP;
	float m_regenStrength;
	float m_regenRate;
	
	float m_maxLives;
	float m_currentLives;

    // Damage
	float m_contactDamage;


};

