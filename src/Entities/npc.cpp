#include "npc.h"


void NPC::init()
{
	size.x = 16;
	size.y = 16;

	Gravity = -0.5;
	Friction = 0.1;
	AirResistance = 0.01;

	conversation.load("conversation_gon_1.txt");
}

void NPC::chat(StaticBody* body, Camera* camera, sf::RenderWindow* window)
{
	conversation.chatting = &chatting;
	if (overLap(body)) {
		/*
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !button.buffer) {
			chatting = !chatting;
			button.buffer = true;
		} else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
			button.buffer = false;
		}
		if (!chatting)
			button.draw(position.x, position.y-size.y, window);
		else
			conversation.draw(camera, window);
		*/
	} else {
		chatting = false;
	}
}

void NPC::follow(StaticBody* body)
{
	if (!overLap(body)) {
		if (toTheRight(body))
			acceleration.x = -speed;
		else
			acceleration.x = speed;
	} else {
		acceleration.x = 0;
	}
}

void NPC::attack(Character* character)
{
	if (!overLap(character) && state != attacking) {
		if (character->position.x > position.x)
			acceleration.x = speed;
		else
			acceleration.x = -speed;
	} else if (overLap(character)) {
		acceleration.x = 0;
		state = attacking;
		if (attack_anim.finished)
			hurt(character);
	} else if (!overLap(character) && state == attacking) {
		state = idle;
	}
}

void NPC::wander()
{
	if (!chatting) {
		sf::Time lastUpdate = Timer.getElapsedTime();
		if (lastUpdate.asMilliseconds() >= 1000) {
			int go = rand()%5;
			if (go == 0) {
				acceleration.x = speed;
			} else if (go == 1) {
				acceleration.x = -speed;
			} else {
				acceleration.x = 0;
			}
			Timer.restart();
		}
	} else {
		acceleration.x = 0;
	}
}
