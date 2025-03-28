#pragma once
#include "Entity.h"
class Player : public Entity
{
	Entity XWing;

public:

	Player();
	virtual ~Player();

	void setStats(Player&);
	void setSprite(Player&);
	void Input(Player&);



private:




};

