#include"Menu.h"
#include <SFML/Graphics.hpp>
Menu::Menu(float width, float height)
{
	
	if(!font.loadFromFile("fontfile.ttf"))
	{
		//handle error
	}
	menu[0].setCharacterSize(40);
	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Blue);
	menu[0].setString("Start (no music)");
	menu[0].setPosition(width/2.5 -50, height/(MAX_NUMBER_OF_ITEMS + 1) * 1.5 +120);
	//
	menu[1].setCharacterSize(40);
	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Counting Stars");
	menu[1].setPosition(width/2.5 -50, height/(MAX_NUMBER_OF_ITEMS + 1) * 2 +120);
	
	menu[2].setCharacterSize(40);
 	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Demons");
	menu[2].setPosition(width/2.5 -50, height/(MAX_NUMBER_OF_ITEMS + 1) * 2.5 +120); 	
	 //
 	menu[3].setCharacterSize(40);
 	menu[3].setFont(font);
	menu[3].setColor(sf::Color::White);
	menu[3].setString("Illusiom Cover");
	menu[3].setPosition(width/2.5 -50, height/(MAX_NUMBER_OF_ITEMS + 1) * 3 +120);	 
	 
 	menu[4].setCharacterSize(40);
 	menu[4].setFont(font);
	menu[4].setColor(sf::Color::White);
	menu[4].setString("Exit");
	menu[4].setPosition(width/2.5 -50, height/(MAX_NUMBER_OF_ITEMS + 1) * 3.5 +120);
	// set selected index
	selectedItemIndex = 0;
 } 
void Menu::draw(sf::RenderWindow &window)
{
	for(int i = 0; i < MAX_NUMBER_OF_ITEMS;i++)
	{
		window.draw(menu[i]);
	}
}
Menu::~Menu()
{
}
void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Blue);
	}
}
void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Blue);
	}
}
