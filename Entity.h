#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class Entity : public Transformable
{
public:


	void setStats();
	//void moveEntity(Entity);



	// Sprite and Animation?
    Image m_eImage;
    Texture m_eTexture;
	Sprite m_eSprite;

    bool result = m_eTexture.loadFromImage(m_eImage, false, IntRect({ 0, 0 }, { 32, 64 }));
    //Sprite m_eSprite;

    // Movement
	float m_accel;
	float m_currentVelocX = 0.0f;
	float m_maxVelocX;
	float m_accelDecay;
	float m_timeToMaxVeloc = (m_maxVelocX - m_currentVelocX) / m_accel;
	float m_currentVelocY = 0.f;
	float m_maxVelocY;

	int m_directionX;
	int m_directionY;
	bool m_isFacingRight;


    // Health 
	float m_maxHP;
	float m_currentHP;
	float m_regenStrength;
	float m_regenRate;
	
	int m_maxLives;
	int m_currentLives;

    // Damage
	float m_contactDamage;
	float m_laserDamage;
	float m_bombDamage;

};


