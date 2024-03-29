#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "ScreenSize.h"

/// <summary>
/// markers can have different colors and they have body which can be touched and "chosen"
/// </summary>
class Marker
{
public:
	Marker(sf::Color t_color, sf::Vector2f t_position);
	sf::Color getColor();
	sf::RectangleShape getBody();
	bool chosen(sf::Vector2i t_mousePos); //if the mouse clicked on the body

private:
	sf::RectangleShape m_body;
	sf::Vector2f m_position;
	sf::Vector2f m_size;
	sf::Color m_color;
};

/// <summary>
/// board, currently handling everything
/// </summary>
class Board
{
public:
	Board();

	void init();
	void processMouseEvent(sf::Event& t_event, sf::RenderWindow& t_window);
	void draw(sf::RenderWindow& t_window);

private:
	std::vector <sf::Vertex> lines;
	//sf::Texture texture;
	//sf::Sprite sprite;
	bool canDraw; //drawing flag
	Marker* currentMarker; //points to current marker
	//all the markers that the user can choose from
	Marker blackMarker;
	Marker redMarker;
	Marker blueMarker;
	Marker greenMarker;
};