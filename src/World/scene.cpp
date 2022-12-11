#include "scene.h"


Scene::Scene(unsigned int window_w, unsigned int window_h, int scene_w, int scene_h) :
camera(window_w, window_h, scene_w, scene_h),
player("../data/Games/Game0/Assets/Img/ottiface.png", 64, 64),
slice(-100, -100, 0.5, "../data/Games/Game0/Assets/Img/beach.png", 100, 32)
{
	// scene_w and scene_h should be read from the data file
	std::vector<std::string> lines = getFileLines("../data/Games/Game0/scene1.txt");
	for (int i = 0; i < lines.size(); i++)
	{
		std::vector<std::string> attributes = split(lines[i], ' ');
		if (attributes.size() >= 2)
		{
			if (attributes[0].compare("create") == 0) {
				if (attributes[1].compare("block") == 0) {
					Block new_block("../data/Games/Game0/Assets/Img/ottiface.png", 64, 64);
					new_block.position.y = 100;
					blocks.push_back(new_block);
				}
			}
		}
	}
	Block new_block0("../data/Games/Game0/Assets/Img/ottiface.png", 64, 64);
	new_block0.position.x += 69;
	new_block0.position.y += 69;
	blocks.push_back(new_block0);
}

void Scene::render(sf::RenderWindow* window)
{	
	std::vector<StaticBody> bodies(blocks.begin(), blocks.end());

	player.move();
	player.update(bodies);

	camera.draw(player.position.x, player.position.y, window);

	slice.draw(camera, window);
	for (auto block : blocks)
		block.draw(window);
	player.draw(window);
}
