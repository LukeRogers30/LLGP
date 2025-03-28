#include "Player.h"

Player::Player()
{
	
}

Player::~Player()
{
}

void Player::setStats(Player& XWing)                                                                        //Stats
{
	// Movement
	m_accel = 10.0f;
	m_currentVelocX = 0.0f;
	m_maxVelocX = 100.0f;
	m_timeToMaxVeloc = (m_maxVelocX - m_currentVelocX) / m_accel;
	m_currentVelocY = 0.f;
	m_maxVelocY = 100.0f;

	m_directionX;
	m_directionY;
	m_isFacingRight;



	// Health 
	m_maxHP = 100.0f;
	m_currentHP = m_maxHP;
	m_regenStrength = 1.0f;
	m_regenRate = 0.25f;

	m_maxLives = 3.f;
	m_currentLives = m_maxLives;

	// Damage
	m_contactDamage = 1.f;
	m_laserDamage = 20.f;
	m_bombDamage = 200.f;
}

void setSprite(Player& XWing)                                                                                   //Sprite
{
    const Image playerImage("assets/XWingSprites.png");
    Texture playerText;

    bool result = playerText.loadFromImage(playerImage, false, IntRect({ 0, 0 }, { 32, 64 }));
    Sprite playerSprite(playerText);
    playerSprite.scale({ 4.f, 4.f });
    XWing.m_eSprite = playerSprite;
}

void Player::Input(Player& XWing)                                                                               //Input
{
    if (Keyboard::isKeyPressed(Keyboard::Key::D))
    {
        m_directionX = -1;
        m_isFacingRight = true;
        m_currentVelocX = m_currentVelocX + m_accel;
        if (m_currentVelocX > m_maxVelocX)
        {
            m_currentVelocX = m_maxVelocX;
        }
    }
    else if (Keyboard::isKeyPressed(Keyboard::Key::A))
    {
        m_directionX = 1;
        m_currentVelocX = m_currentVelocX - m_accel;
        m_isFacingRight = false;
        if (m_currentVelocX < m_maxVelocX * -1.f)
        {
            m_currentVelocX = m_maxVelocX * -1.f;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Key::W))
    {
        m_directionY = -1;
        m_currentVelocY = m_currentVelocY + m_accel;
        if (m_currentVelocY > m_maxVelocY)
        {
            m_currentVelocY = m_maxVelocY;
        }
    }
    else if (Keyboard::isKeyPressed(Keyboard::Key::S))
    {
        m_directionY = 1;
        m_currentVelocY = m_currentVelocY - m_accel;
        if (m_currentVelocY < m_maxVelocY * -1.f)
        {
            m_currentVelocY = m_maxVelocY * -1.f;
        }
    }



    XWing.move({ m_currentVelocX, m_currentVelocY});
}
