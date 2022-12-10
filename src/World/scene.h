#ifndef SCENE
#define SCENE

#include <SFML/Graphics.hpp>
#include <vector>

#include "../Graphics/camera.h"
#include "../Entities/block.h"


class Scene
{
	Camera camera;
	std::vector<Block> blocks;

public:
	Scene(unsigned int window_w, unsigned int window_h, int scene_w = 0, int scene_h = 0);
	void render(sf::RenderWindow* window);
};


#endif
