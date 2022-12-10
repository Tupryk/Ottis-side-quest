#include "scene.h"

Scene::Scene(unsigned int window_w, unsigned int window_h, int scene_w, int scene_h)
: camera(window_w, window_h, scene_w, scene_h)
{
	// scene_w and scene_h should be read from the data file
	Block new_block("../data/Games/Game0/Assets/Img/ottiface.png", 0, 0, 64, 64);
	blocks.push_back(new_block);
	Block new_block0("../data/Games/Game0/Assets/Img/ottiface.png", 0, 0, 64, 64);
	new_block0.position.x += 69;
	new_block0.position.y += 69;
	blocks.push_back(new_block0);
}

void Scene::render(sf::RenderWindow* window)
{	
	for (auto block : blocks)
		block.draw(window);

	blocks[0].position.x += 1;
	camera.draw(blocks[0].position.x, blocks[0].position.y, window);
}
