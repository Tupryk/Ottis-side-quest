#include "indicators.h"

/*
void ButtonIndicator::init(char c)
{
	if (c == 'e') {
		appearing.load("InteractionButton.png", 3, 6, 16, 25);
		staying.load("InteractionButton.png", 8, 6, 16, 25, 48);
	} else {
		appearing.load("InteractionButton.png", 3, 6, 16, 25);
		staying.load("InteractionButton.png", 8, 6, 16, 25, 48);
	}
}

void ButtonIndicator::draw_self(float x, float y, sf::RenderWindow* window, bool draw)
{
	// this code doesn't work exactly how it should
	if (draw && appearing.frameIndex < appearing.frames-1)
		appearing.draw(x, y, window);
	else if (draw && appearing.frameIndex >= appearing.frames-1)
		staying.draw(x, y, window);
	else if (!draw && appearing.frameIndex > 0)
		appearing.draw(x, y, window, true);
}
*/