#pragma once

#include <vector>

#include "scene.h"


class Chapter
{
	unsigned int currentScene = 1;
	std::vector<Scene> scenes;
};
