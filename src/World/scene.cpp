#include "scene.h"


Scene::Scene(unsigned int window_w, unsigned int window_h, std::string scene_data)
{
	std::vector<std::string> lines = getFileLines("../data/Games/Game0/Scenes/"+scene_data);
	for (int i = 0; i < lines.size(); i++)
	{
		std::vector<std::string> attributes = split(lines[i], ' ');
		if (attributes.size() >= 2)
		{
			if (attributes[0].compare("Scene_data") == 0) {
				if (attributes[0].compare("-interaction-indicators:") == 0)
					continue; // This is for the style of button indicators
			}
			else if (attributes[0].compare("create") == 0)
			{
				if (attributes[1].compare("camera") == 0)
					camera = readCamera(window_w, window_h, lines, &i);

				else if (attributes[1].compare("platform") == 0)
					blocks.push_back(readPlatform(lines, &i));
				
				else if (attributes[1].compare("player") == 0)
					player = readPlayer(lines, &i);

				else if (attributes[1].compare("slice") == 0)
					slices.push_back(readSlice(lines, &i));
				
				else if (attributes[1].compare("npc") == 0)
					npcs.push_back(readNPC(lines, &i));
				
				else if (attributes[1].compare("block") == 0)
					invisibles.push_back(readBarrier(lines, &i));
				
				else if (attributes[1].compare("item") == 0)
					items.push_back(readItem(lines, &i));
			}
		}
	}
}

void Scene::render(sf::RenderWindow* window)
{
	std::vector<StaticBody> bodies(blocks.begin(), blocks.end());
	bodies.insert(bodies.end(), invisibles.begin(), invisibles.end());

	if (!camera.pop_up) player.move();
	player.update(bodies);
	for (int i = 0; i < npcs.size(); i++) {
		npcs[i].update(bodies); // need to get block where im standing and get ist width
		if (npcs[i].type == enemy)
			npcs[i].attack(&player);
		else
			npcs[i].wander();
	}

	camera.draw(player.position.x, player.position.y, window);

	for (auto slice : slices)
		slice.draw(camera, window);

	for (int i = 0; i < npcs.size(); i++) {
		if (npcs[i].type == chatter)
			npcs[i].chat(&player, &camera, window);
		npcs[i].draw(window);
	}
	for (auto block : blocks)
		block.draw(window);
	player.draw(window);

	for (int i = 0; i < items.size(); i++) {
		items[i].update(bodies);
		items[i].getPicket(&player);
		items[i].draw(window);
	}
}
