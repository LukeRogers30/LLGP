#include "Character.h"

float Character::moveChar(CircleShape& character)
{

    if (Keyboard::isKeyPressed(Keyboard::Key::D))
    {
        m_directionX = -1;
        m_currentVelocX = m_currentVelocX + m_accel;
        m_isFacingRight = true;
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
        if (m_currentVelocX < (m_maxVelocX * -1.f))
        {
            m_currentVelocX = (m_maxVelocX * -1.f);
        }
    }
    else
    {
        if (m_currentVelocX > 0)
        {
            m_currentVelocX -= (m_accelDecay * dt.asSeconds());
        }
        else if (m_currentVelocX < 0)
        {
            m_currentVelocX += (m_accelDecay * dt.asSeconds());
        }
        else { m_currentVelocX = 0.f; }
    }


    if (Keyboard::isKeyPressed(Keyboard::Key::Space))
    {
        if (m_jumpCount < m_maxJumps && m_jumpTimer < m_maxJumpTime)
        {
            for (m_jumpTimer; m_jumpTimer < m_maxJumpTime;)
            {
                m_currentVelocY += (m_jumpForce * dt.asSeconds());
                m_jumpTimer += dt.asSeconds();
                cout << m_jumpTimer;

                if (m_currentVelocY > m_maxVelocY)
                {
                    m_currentVelocY = m_maxVelocY;
                }
                if (m_jumpTimer > m_maxJumpTime)
                {
                    m_jumpCount++;
                
                }
            }

            //if (m_currentVelocY < m_maxVelocY)
            //{
            //    m_currentVelocY = m_maxVelocY;
            //}
        }
        //else
        //{
        //    m_currentVelocY += m_gravity;
        //    if (m_currentVelocY > m_maxVelocY)
        //    {
        //        m_currentVelocY = m_maxVelocY;
        //    }
        //}
    }
    //else
    //{
    //    m_jumpTimer = 0.f;
    //    m_currentVelocY += m_gravity;
    //    if (m_currentVelocY > m_maxVelocY)
    //    {
    //        m_currentVelocY = m_maxVelocY;
    //    }
    //}


    character.move({ m_currentVelocX * dt.asSeconds(), m_currentVelocY * dt.asSeconds()});
	return 0;
}
