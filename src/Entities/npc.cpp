#include "npc.h"


void NPC::init()
{
	size.x = 16;
	size.y = 16;

	Gravity = -0.5;
	Friction = 0.1;
	AirResistance = 0.01;

	button.init('e');
	conversation.load("conversation_gon_1.txt");
}

void NPC::chat(StaticBody body, Camera* camera, sf::RenderWindow* window)
{
	conversation.chatting = &chatting;
	if (overLap(body)) {
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
	} else {
		chatting = false;
	}
}

void NPC::follow(StaticBody body)
{
	if (!overLap(body)) {
		if (body.position.x > position.x)
			acceleration.x = speed;
		else
			acceleration.x = -speed;
	} else {
		acceleration.x = 0;
	}
}

void NPC::attack(Character* character)
{
	if (!overLap(*character)) {
		if (character->position.x > position.x)
			acceleration.x = speed;
		else
			acceleration.x = -speed;
	} else {
		acceleration.x = 0;
		state = attacking;
		std::cout << "going to hurt" << std::endl;
		std::cout << "attack index " << attack_anim.frameIndex << std::endl;
		std::cout << "attack frames " << attack_anim.frames << std::endl;
		std::cout << "state " << state << std::endl;
		if (attack_anim.frameIndex == attack_anim.frames-1) {
			std::cout << "hurt" << std::endl;
			hurt(character);
		}
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
