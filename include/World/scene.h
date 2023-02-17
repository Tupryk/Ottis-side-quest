#pragma once

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "../Graphics/camera.h"
#include "../Entities/objects.h"
#include "../Entities/player.h"
#include "../Entities/block.h"
#include "../Entities/items.h"
#include "../Entities/background.h"
#include "../Entities/npc.h"
#include "../utils.h"
#include "../ReadObjects/read_objs.h"


class Scene
{
	Camera camera;
	Player player;
	std::vector<Item> items;
	std::vector<Slice> slices;
	std::vector<Block> blocks;
	std::vector<StaticBody> invisibles;
	std::vector<NPC> npcs;

public:
	Scene(unsigned int window_w, unsigned int window_h, std::string scene_data);
	void render(sf::RenderWindow* window);
};
