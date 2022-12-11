#ifndef SCENE
#define SCENE

#include <SFML/Graphics.hpp>
#include <vector>

#include "../Graphics/camera.h"
#include "../Entities/player.h"
#include "../Entities/block.h"
#include "../Entities/background.h"
#include "../Entities/npc.h"
#include "../utils.h"


class Scene
{
	Camera camera;
	Player player;
	std::vector<Slice> slices;
	std::vector<Block> blocks;
	std::vector<NPC> npcs;

public:
	Scene(unsigned int window_w, unsigned int window_h, std::string scene_data);
	void render(sf::RenderWindow* window);
};


#endif
