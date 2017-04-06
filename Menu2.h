#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS_Menu2 2
#pragma once
class Menu2
{
public:
	Menu2(float width, float height);
	~Menu2();
	
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS_Menu2];
};
