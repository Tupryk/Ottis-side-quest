#ifndef NPCS_H
#define NPCS_H

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"
#include "../Interactions/indicators.h"
#include "../Interactions/chat.h"
#include "character.h"
#include "player.h"


enum NPC_Type {chatter, enemy, walker};

class NPC : public Character
{
	sf::Clock Timer;
	PressButton button;
	std::vector<std::string> chats;
	Conversation conversation;
	bool chatting = false;

public:
	NPC_Type type;

	void init();
	void chat(StaticBody* body, Camera* camera, sf::RenderWindow* window);
	void wander();
	void follow(StaticBody* body);
	void attack(Character* character);
};


#endif
