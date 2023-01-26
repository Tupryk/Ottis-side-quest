#ifndef READ_OBJS
#define READ_OBJS

#include <string>
#include <vector>

#include "../utils.h"
#include "../Physics/physics.h"
#include "../Graphics/camera.h"
#include "../Entities/player.h"
#include "../Entities/npc.h"
#include "../Entities/items.h"
#include "../Entities/background.h"
#include "../Entities/block.h"


// This code is VERY ugly, please ignore for now

Player readPlayer(std::vector<std::string> data, int* i);
Item readItem(std::vector<std::string> data, int* i);
StaticBody readBarrier(std::vector<std::string> data, int* i);
NPC readNPC(std::vector<std::string> data, int* i);
Slice readSlice(std::vector<std::string> data, int* i);
Block readPlatform(std::vector<std::string> data, int* i);
Camera readCamera(int window_w, int window_h, std::vector<std::string> data, int* i);


#endif
