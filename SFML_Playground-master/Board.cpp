#include "Board.h"

Marker::Marker(sf::Color t_color, sf::Vector2f t_position) : m_color(t_color), m_position(t_position), m_size(sf::Vector2f(30.f, 30.f))
{
    m_body.setFillColor(m_color);
    m_body.setSize(m_size);
    m_body.setPosition(m_position);
}

sf::Color Marker::getColor()
{
    return m_color;
}

sf::RectangleShape Marker::getBody()
{
    return m_body;
}

bool Marker::chosen(sf::Vector2i t_mousePos)
{
    if (m_position.x<=t_mousePos.x && m_position.x+m_size.x>=t_mousePos.x
        && 
        m_position.y<=t_mousePos.y && m_position.y+m_size.y>=t_mousePos.y)
        return true;
    return false;
}

Board::Board(): blackMarker(sf::Color::Black,sf::Vector2f(1400.f,50.f)), redMarker(sf::Color::Red, sf::Vector2f(1400.f, 100.f)), blueMarker(sf::Color::Blue, sf::Vector2f(1400.f, 150.f)), greenMarker(sf::Color::Green, sf::Vector2f(1400.f, 200.f)), currentMarker(&blackMarker)
{
}

void Board::init()
{
	texture.create(ScreenSize::s_width, ScreenSize::s_height);
    canDraw = false;
    //lineColor = sf::Color::Black;
   
}


void Board::processMouseEvent(sf::Event& t_event, sf::RenderWindow& t_window)
{
     if (t_event.type == sf::Event::MouseButtonPressed)
     {
         sf::Vector2i mousePos = sf::Mouse::getPosition(t_window);
         if (blackMarker.chosen(mousePos))
             currentMarker = &blackMarker;
         else if (redMarker.chosen(mousePos))
             currentMarker = &redMarker;
         else if (blueMarker.chosen(mousePos))
             currentMarker = &blueMarker;
         else if (greenMarker.chosen(mousePos))
             currentMarker = &greenMarker;
         else
             canDraw = true;
     }
     else if (t_event.type == sf::Event::MouseMoved )
     {
         if(canDraw)
            lines.push_back(sf::Vertex(sf::Vector2f::Vector2(sf::Mouse::getPosition(t_window)),currentMarker->getColor()));
         else
             lines.push_back(sf::Vertex(sf::Vector2f::Vector2(sf::Mouse::getPosition(t_window)), sf::Color::White));
     }
     else if (t_event.type == sf::Event::MouseButtonReleased)
     {
         canDraw = false;
         texture.update(t_window); //found out it is not really needed
         //lines.clear();
     }
}

void Board::draw(sf::RenderWindow& t_window)
{
    //t_window.draw(sprite);
    if(lines.size()>0)
        t_window.draw(&lines[0], lines.size(), sf::LinesStrip);

    t_window.draw(blackMarker.getBody());
    t_window.draw(redMarker.getBody());
    t_window.draw(blueMarker.getBody());
    t_window.draw(greenMarker.getBody());

    //sprite.setTexture(texture);
}


