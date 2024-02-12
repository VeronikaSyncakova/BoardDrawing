#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "ScreenSize.h"

class Marker
{
public:
	Marker(sf::Color t_color, sf::Vector2f t_position);
	sf::Color getColor();
	sf::RectangleShape getBody();
	bool chosen(sf::Vector2i t_mousePos);

private:
	sf::RectangleShape m_body;
	sf::Vector2f m_position;
	sf::Vector2f m_size;
	sf::Color m_color;
};

class Board
{
public:
	Board();

	void init();
	void processMouseEvent(sf::Event& t_event, sf::RenderWindow& t_window);
	void draw(sf::RenderWindow& t_window);

private:
	std::vector <sf::Vertex> lines;
	sf::Texture texture;
	//sf::Sprite sprite;
	bool canDraw;
	//sf::Color lineColor;
	Marker* currentMarker;
	Marker blackMarker;
	Marker redMarker;
	Marker blueMarker;
	Marker greenMarker;
};