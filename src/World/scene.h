#ifndef SCENE
#define SCENE

#include <SFML/Graphics.hpp>
#include <vector>

#include "../Graphics/camera.h"
#include "../Entities/player.h"
#include "../Entities/block.h"
#include "../Entities/background.h"
#include "../utils.h"


class Scene
{
	Camera camera;
	Player player;
	Slice slice;
	std::vector<Block> blocks;

public:
	Scene(unsigned int window_w, unsigned int window_h, int scene_w = 0, int scene_h = 0);
	void render(sf::RenderWindow* window);
};


#endif
