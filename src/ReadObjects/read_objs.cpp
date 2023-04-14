#include "ReadObjects/read_objs.h"


Player readPlayer(std::vector<std::string> data, int* i)
{
	Player player;
	player.init();
	*i = (*i) + 1;
	std::vector<std::string> attributes = split(data[*i], ' ');
	while (attributes.size() >= 1 && attributes[0] != "}")
	{
		if (attributes.size() >= 2)
		{
			if (attributes[0].compare("-width:") == 0)
				player.size.x = std::stoi(attributes[1]);
			if (attributes[0].compare("-height:") == 0)
				player.size.y = std::stoi(attributes[1]);
			if (attributes[0].compare("-x_pos:") == 0)
				player.position.x = std::stof(attributes[1]);
			if (attributes[0].compare("-y_pos:") == 0)
				player.position.y = std::stof(attributes[1]);
			if (attributes[0].compare("-walk_anim:") == 0) {
				player.walk_anim.load(attributes[1], std::stoi(attributes[2]), std::stoi(attributes[3]), std::stoi(attributes[4]), std::stoi(attributes[5]), std::stoi(attributes[6]), std::stoi(attributes[7]));
				if (std::stoi(attributes[8]))
					player.walk_anim.flip();
			}
			if (attributes[0].compare("-idle_anim:") == 0) {
				player.idle_anim.load(attributes[1], std::stoi(attributes[2]), std::stoi(attributes[3]), std::stoi(attributes[4]), std::stoi(attributes[5]), std::stoi(attributes[6]), std::stoi(attributes[7]));
				if (std::stoi(attributes[8]))
					player.idle_anim.flip();
			}
			if (attributes[0].compare("-run_anim:") == 0) {
				player.run_anim.load(attributes[1], std::stoi(attributes[2]), std::stoi(attributes[3]), std::stoi(attributes[4]), std::stoi(attributes[5]), std::stoi(attributes[6]), std::stoi(attributes[7]));
				if (std::stoi(attributes[8]))
					player.run_anim.flip();
			}
			if (attributes[0].compare("-jump_anim:") == 0) {
				player.jump_anim.load(attributes[1], std::stoi(attributes[2]), std::stoi(attributes[3]), std::stoi(attributes[4]), std::stoi(attributes[5]), std::stoi(attributes[6]), std::stoi(attributes[7]));
				if (std::stoi(attributes[8]))
					player.jump_anim.flip();
			}
			if (attributes[0].compare("-fall_anim:") == 0) {
				player.fall_anim.load(attributes[1], std::stoi(attributes[2]), std::stoi(attributes[3]), std::stoi(attributes[4]), std::stoi(attributes[5]), std::stoi(attributes[6]), std::stoi(attributes[7]));
				if (std::stoi(attributes[8]))
					player.fall_anim.flip();
			}
			if (attributes[0].compare("-hurt_anim:") == 0) {
				player.hurt_anim.load(attributes[1], std::stoi(attributes[2]), std::stoi(attributes[3]), std::stoi(attributes[4]), std::stoi(attributes[5]), std::stoi(attributes[6]), std::stoi(attributes[7]));
				if (std::stoi(attributes[8]))
					player.hurt_anim.flip();
			}
		}
		*i = (*i) + 1;
		attributes = split(data[*i], ' ');
	}
	return player;
}

NPC readNPC(std::vector<std::string> data, int* i)
{
	NPC new_npc;
	new_npc.init();
	*i = (*i) + 1;
	std::vector<std::string> attributes = split(data[*i], ' ');
	while (attributes.size() >= 1 && attributes[0] != "}")
	{
		if (attributes.size() >= 2)
		{
			if (attributes[0].compare("-width:") == 0)
				new_npc.size.x = std::stoi(attributes[1]);
			if (attributes[0].compare("-height:") == 0)
				new_npc.size.y = std::stoi(attributes[1]);
			if (attributes[0].compare("-x_pos:") == 0)
				new_npc.position.x = std::stof(attributes[1]);
			if (attributes[0].compare("-y_pos:") == 0)
				new_npc.position.y = std::stof(attributes[1]);
			if (attributes[0].compare("-type:") == 0) {
				if (attributes[1].compare("chatter") == 0)
					new_npc.type = chatter;
				else if (attributes[1].compare("enemy") == 0)
					new_npc.type = enemy;
				else
					new_npc.type = walker;
			}
			if (attributes[0].compare("-speed:") == 0)
				new_npc.speed = std::stof(attributes[1]);
			if (attributes[0].compare("-walk_anim:") == 0) {
				new_npc.walk_anim.load(attributes[1], std::stoi(attributes[2]), std::stoi(attributes[3]), std::stoi(attributes[4]), std::stoi(attributes[5]), std::stoi(attributes[6]), std::stoi(attributes[7]));
				if (std::stoi(attributes[8]))
					new_npc.walk_anim.flip();
			}
			if (attributes[0].compare("-idle_anim:") == 0) {
				new_npc.idle_anim.load(attributes[1], std::stoi(attributes[2]), std::stoi(attributes[3]), std::stoi(attributes[4]), std::stoi(attributes[5]), std::stoi(attributes[6]), std::stoi(attributes[7]));
				if (std::stoi(attributes[8]))
					new_npc.idle_anim.flip();
			}
			if (attributes[0].compare("-attack_anim:") == 0) {
				new_npc.attack_anim.load(attributes[1], std::stoi(attributes[2]), std::stoi(attributes[3]), std::stoi(attributes[4]), std::stoi(attributes[5]), std::stoi(attributes[6]), std::stoi(attributes[7]));
				if (std::stoi(attributes[8]))
					new_npc.attack_anim.flip();
			}
		}
		*i = (*i) + 1;
		attributes = split(data[*i], ' ');
	}
	return new_npc;
}

Item readItem(std::vector<std::string> data, int* i)
{
	std::string texture = "";
	int width = -1;
	int height = -1;
	float x_pos = 0;
	float y_pos = 0;
	*i = (*i) + 1;
	std::vector<std::string> attributes = split(data[*i], ' ');
	while (attributes.size() >= 1 && attributes[0] != "}")
	{
		if (attributes.size() >= 2)
		{
			if (attributes[0].compare("-texture:") == 0)
				texture = attributes[1];
			if (attributes[0].compare("-width:") == 0)
				width = std::stoi(attributes[1]);
			if (attributes[0].compare("-height:") == 0)
				height = std::stoi(attributes[1]);
			if (attributes[0].compare("-x_pos:") == 0)
				x_pos = std::stof(attributes[1]);
			if (attributes[0].compare("-y_pos:") == 0)
				y_pos = std::stof(attributes[1]);
		}
		*i = (*i) + 1;
		attributes = split(data[*i], ' ');
	}
	Item item(texture, width, height, x_pos, y_pos);
	return item;
}

StaticBody readBarrier(std::vector<std::string> data, int* i)
{
	int width = -1;
	int height = -1;
	float x_pos = 0;
	float y_pos = 0;
	*i = (*i) + 1;
	std::vector<std::string> attributes = split(data[*i], ' ');
	while (attributes.size() >= 1 && attributes[0] != "}")
	{
		if (attributes.size() >= 2)
		{
			if (attributes[0].compare("-width:") == 0)
				width = std::stoi(attributes[1]);
			if (attributes[0].compare("-height:") == 0)
				height = std::stoi(attributes[1]);
			if (attributes[0].compare("-x_pos:") == 0)
				x_pos = std::stof(attributes[1]);
			if (attributes[0].compare("-y_pos:") == 0)
				y_pos = std::stof(attributes[1]);
		}
		*i = (*i) + 1;
		attributes = split(data[*i], ' ');
	}
	StaticBody new_body;
	new_body.position.x = x_pos;
	new_body.position.y = y_pos;
	new_body.size.x = width;
	new_body.size.y = height;
	return new_body;
}

Slice readSlice(std::vector<std::string> data, int* i)
{
	std::string texture = "";
	int width = -1;
	int height = -1;
	float x_pos = 0;
	float y_pos = 0;
	float z_pos = 0;
	*i = (*i) + 1;
	std::vector<std::string> attributes = split(data[*i], ' ');
	while (attributes.size() >= 1 && attributes[0] != "}")
	{
		if (attributes.size() >= 2)
		{
			if (attributes[0].compare("-texture:") == 0)
				texture = attributes[1];
			if (attributes[0].compare("-width:") == 0)
				width = std::stoi(attributes[1]);
			if (attributes[0].compare("-height:") == 0)
				height = std::stoi(attributes[1]);
			if (attributes[0].compare("-x_pos:") == 0)
				x_pos = std::stof(attributes[1]);
			if (attributes[0].compare("-y_pos:") == 0)
				y_pos = std::stof(attributes[1]);
			if (attributes[0].compare("-z_pos:") == 0)
				z_pos = std::stof(attributes[1]);
		}
		*i = (*i) + 1;
		attributes = split(data[*i], ' ');
	}
	Slice new_slice;
	new_slice.init(x_pos, y_pos, z_pos, texture, width, height);
	return new_slice;
}

Block readPlatform(std::vector<std::string> data, int* i)
{
	std::string texture = "";
	int width = -1;
	int height = -1;
	float x_pos = 0;
	float y_pos = 0;
	*i = (*i) + 1;
	std::vector<std::string> attributes = split(data[*i], ' ');
	while (attributes.size() >= 1 && attributes[0] != "}")
	{
		if (attributes.size() >= 2)
		{
			if (attributes[0].compare("-texture:") == 0)
				texture = attributes[1];
			if (attributes[0].compare("-width:") == 0)
				width = std::stoi(attributes[1]);
			if (attributes[0].compare("-height:") == 0)
				height = std::stoi(attributes[1]);
			if (attributes[0].compare("-x_pos:") == 0)
				x_pos = std::stof(attributes[1]);
			if (attributes[0].compare("-y_pos:") == 0)
				y_pos = std::stof(attributes[1]);
		}
		*i = (*i) + 1;
		attributes = split(data[*i], ' ');
	}
	Block new_block(texture, width, height);
	new_block.position.x = x_pos;
	new_block.position.y = y_pos;
	return new_block;
}

Camera readCamera(int window_w, int window_h, std::vector<std::string> data, int* i)
{
	int scene_w = -1;
	int scene_h = -1;
	*i = (*i) + 1;
	std::vector<std::string> attributes = split(data[*i], ' ');
	while (attributes.size() >= 1 && attributes[0] != "}")
	{
		if (attributes.size() >= 2)
		{
			if (attributes[0].compare("-width:") == 0)
				scene_w = std::stoi(attributes[1]);
			if (attributes[0].compare("-height:") == 0)
				scene_h = std::stoi(attributes[1]);
		}
		*i = (*i) + 1;
		attributes = split(data[*i], ' ');
	}
	Camera camera;
	camera.init(window_w, window_h, scene_w, scene_h);
	return camera;
}
