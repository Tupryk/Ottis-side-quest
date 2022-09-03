// TROUBLESHOOTING

void drawSquare(StaticBody2D staticBody, sf::Color color)
{
	sf::RectangleShape rectangle(sf::Vector2f(staticBody.size.x, staticBody.size.y));
	rectangle.setFillColor(color);
	rectangle.setPosition(staticBody.position.x - staticBody.size.x*0.5, staticBody.position.y - staticBody.size.y*0.5);
	window.draw(rectangle);
}