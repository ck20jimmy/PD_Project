#include"Menu2.h"
#include <SFML/Graphics.hpp>
Menu2::Menu2(float width, float height)
{
	
	if(!font.loadFromFile("fontfile.ttf"))
	{
		//handle error
	}
	menu[0].setCharacterSize(40);
	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Blue);
	menu[0].setString("the first to reach 100 happiness");
	menu[0].setPosition(width/2.5 -200, height/(5 + 1) * 1.5 +180);
	//
	menu[1].setCharacterSize(40);
	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("most happiness at 300 seconds");
	menu[1].setPosition(width/2.5 -200, height/(5 + 1) * 2 +220);
	
	// set selected index
	selectedItemIndex = 0;
 } 
void Menu2::draw(sf::RenderWindow &window)
{
	for(int i = 0; i < MAX_NUMBER_OF_ITEMS_Menu2;i++)
	{
		window.draw(menu[i]);
	}
}
Menu2::~Menu2()
{
}
void Menu2::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Blue);
	}
}
void Menu2::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS_Menu2)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Blue);
	}
}
