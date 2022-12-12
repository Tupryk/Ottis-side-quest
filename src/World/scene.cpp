#include "scene.h"


Scene::Scene(unsigned int window_w, unsigned int window_h, std::string scene_data)
{
	std::vector<std::string> lines = getFileLines("../data/Games/Game0/"+scene_data);
	for (int i = 0; i < lines.size(); i++)
	{
		std::vector<std::string> attributes = split(lines[i], ' ');
		if (attributes.size() >= 2)
		{
			if (attributes[0].compare("Scene_data") == 0) {
				int scene_w = -1;
				int scene_h = -1;
				i++;
				attributes = split(lines[i], ' ');
				while (attributes.size() >= 1 && attributes[0] != "}")
				{
					if (attributes.size() >= 2)
					{
						if (attributes[0].compare("	width:") == 0)
							scene_w = std::stoi(attributes[1]);
						if (attributes[0].compare("	height:") == 0)
							scene_h = std::stoi(attributes[1]);
					}
					i++;
					attributes = split(lines[i], ' ');
				}
				camera.init(window_w, window_h, scene_w, scene_h);
			}
			else if (attributes[0].compare("create") == 0) {
				if (attributes[1].compare("block") == 0)
				{
					std::string texture = "";
					int width = -1;
					int height = -1;
					float x_pos = 0;
					float y_pos = 0;
					i++;
					attributes = split(lines[i], ' ');
					while (attributes.size() >= 1 && attributes[0] != "}")
					{
						if (attributes.size() >= 2)
						{
							if (attributes[0].compare("	texture:") == 0)
								texture = attributes[1];
							if (attributes[0].compare("	width:") == 0)
								width = std::stoi(attributes[1]);
							if (attributes[0].compare("	height:") == 0)
								height = std::stoi(attributes[1]);
							if (attributes[0].compare("	x_pos:") == 0)
								x_pos = std::stof(attributes[1]);
							if (attributes[0].compare("	y_pos:") == 0)
								y_pos = std::stof(attributes[1]);
						}
						i++;
						attributes = split(lines[i], ' ');
					}
					if (texture.compare("") != 0 && width >= 0 && height >= 0) {
						Block new_block(texture, width, height);
						new_block.position.x = x_pos;
						new_block.position.y = y_pos;
						blocks.push_back(new_block);
					}
				}
				else if (attributes[1].compare("player") == 0)
				{
					std::string texture = "";
					int width = -1;
					int height = -1;
					float x_pos = 0;
					float y_pos = 0;
					i++;
					attributes = split(lines[i], ' ');
					while (attributes.size() >= 1 && attributes[0] != "}")
					{
						if (attributes.size() >= 2)
						{
							if (attributes[0].compare("	texture:") == 0)
								texture = attributes[1];
							if (attributes[0].compare("	width:") == 0)
								width = std::stoi(attributes[1]);
							if (attributes[0].compare("	height:") == 0)
								height = std::stoi(attributes[1]);
							if (attributes[0].compare("	x_pos:") == 0)
								x_pos = std::stof(attributes[1]);
							if (attributes[0].compare("	y_pos:") == 0)
								y_pos = std::stof(attributes[1]);
						}
						i++;
						attributes = split(lines[i], ' ');
					}
					if (texture.compare("") != 0 && width >= 0 && height >= 0) {
						player.init(texture, width, height);
						player.position.x = x_pos;
						player.position.y = y_pos;
					}
				}
				else if (attributes[1].compare("slice") == 0)
				{
					std::string texture = "";
					int width = -1;
					int height = -1;
					float x_pos = 0;
					float y_pos = 0;
					float z_pos = 0;
					i++;
					attributes = split(lines[i], ' ');
					while (attributes.size() >= 1 && attributes[0] != "}")
					{
						if (attributes.size() >= 2)
						{
							if (attributes[0].compare("	texture:") == 0)
								texture = attributes[1];
							if (attributes[0].compare("	width:") == 0)
								width = std::stoi(attributes[1]);
							if (attributes[0].compare("	height:") == 0)
								height = std::stoi(attributes[1]);
							if (attributes[0].compare("	x_pos:") == 0)
								x_pos = std::stof(attributes[1]);
							if (attributes[0].compare("	y_pos:") == 0)
								y_pos = std::stof(attributes[1]);
							if (attributes[0].compare("	z_pos:") == 0)
								z_pos = std::stof(attributes[1]);
						}
						i++;
						attributes = split(lines[i], ' ');
					}
					if (texture.compare("") != 0 && width >= 0 && height >= 0) {
						Slice new_slice;
						new_slice.init(x_pos, y_pos, z_pos, texture, width, height);
						slices.push_back(new_slice);
					}
				}
				else if (attributes[1].compare("npc") == 0)
				{
					NPC new_npc;
					new_npc.init();
					std::string texture = "";
					int width = -1;
					int height = -1;
					float x_pos = 0;
					float y_pos = 0;
					float speed = 0.02;
					bool chatter = false;
					bool evil = false;
					i++;
					attributes = split(lines[i], ' ');
					while (attributes.size() >= 1 && attributes[0] != "}")
					{
						if (attributes.size() >= 2)
						{
							if (attributes[0].compare("	texture:") == 0)
								texture = attributes[1];
							if (attributes[0].compare("	width:") == 0)
								width = std::stoi(attributes[1]);
							if (attributes[0].compare("	height:") == 0)
								height = std::stoi(attributes[1]);
							if (attributes[0].compare("	x_pos:") == 0)
								x_pos = std::stof(attributes[1]);
							if (attributes[0].compare("	y_pos:") == 0)
								y_pos = std::stof(attributes[1]);
							if (attributes[0].compare("	chatter:") == 0)
								chatter = true;
							if (attributes[0].compare("	evil:") == 0)
								evil = true;
							if (attributes[0].compare("	speed:") == 0)
								speed = std::stof(attributes[1]);
							if (attributes[0].compare("	walk_anim:") == 0)
								new_npc.walk_anim.load(attributes[1], std::stoi(attributes[2]), std::stoi(attributes[3]), std::stoi(attributes[4]), std::stoi(attributes[5]), std::stoi(attributes[6]), std::stoi(attributes[7]));
							if (attributes[0].compare("	idle_anim:") == 0)
								new_npc.idle_anim.load(attributes[1], std::stoi(attributes[2]), std::stoi(attributes[3]), std::stoi(attributes[4]), std::stoi(attributes[5]), std::stoi(attributes[6]), std::stoi(attributes[7]));
						}
						i++;
						attributes = split(lines[i], ' ');
					}
					new_npc.size.x = width;
					new_npc.size.y = height;
					new_npc.position.x = x_pos;
					new_npc.position.y = y_pos;
					new_npc.chatter = chatter;
					new_npc.evil = evil;
					new_npc.speed = speed;
					npcs.push_back(new_npc);
				}
			}
		}
	}
}

void Scene::render(sf::RenderWindow* window)
{
	std::vector<StaticBody> bodies(blocks.begin(), blocks.end());

	player.move();
	player.update(bodies);
	for (int i = 0; i < npcs.size(); i++) {
		if (npcs[i].evil)
			npcs[i].follow(player);
		else
			npcs[i].wander();
		npcs[i].update(bodies);
	}

	camera.draw(player.position.x, player.position.y, window);

	for (auto slice : slices)
		slice.draw(camera, window);
	for (int i = 0; i < npcs.size(); i++) {
		if (npcs[i].chatter)
			npcs[i].chat(player, window);
		npcs[i].draw(window);
	}
	for (auto block : blocks)
		block.draw(window);
	player.draw(window);
}
