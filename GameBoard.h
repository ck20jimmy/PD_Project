#include <SFML/Graphics.hpp>
#pragma once
class GameGrid 
{
public:
	GameBoard(float width, float height);
	~GameBoard();
	void draw(sf::RenderWindow &window);
private:
};
