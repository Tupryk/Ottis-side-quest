#include "background.h"


Slice::Slice(float pos_x, float pos_y, float pos_z, std::string ImageDrirectory, float w, float h, float x, float y)
{
	position.x = pos_x;
	position.y = pos_y;
	position.z = pos_z;
	size.x = w;
	size.y = h;
	image.load(ImageDrirectory, w, h, x, y);
}

void Slice::draw(Camera camera, sf::RenderWindow* window)
{
	float relative_x = position.x+(camera.position.x*position.z);
	float relative_y = position.y+(camera.position.y*position.z);

	image.draw(relative_x, relative_y, window);

	const int camera_end_x = camera.position.x+(camera.window_w*0.5);
	int slice_end_x = position.x+(size.x*0.5);

	while (slice_end_x < camera_end_x) {
		relative_x += size.x;
		slice_end_x += size.x;
		image.draw(relative_x, relative_y, window);
	}
}
