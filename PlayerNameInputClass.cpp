#include "PlayerNameInputClass.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include<string>
using namespace std;
PlayerNameInputClass::PlayerNameInputClass(float width, float height)
{
	
	if(!font.loadFromFile("fontfile.ttf"))
	{
		//handle error
	}
	if(!font2.loadFromFile("fontfile2.ttf"))
	{
		//handle error
	}
	// Set slogan on the top of input text box
	slogan.setCharacterSize(40);
	slogan.setFont(font);
	slogan.setColor(sf::Color::White);
	slogan.setPosition(width/20, height/5);
	slogan2.setString("After input your name, Press enter to continue");
	slogan2.setCharacterSize(20);
	slogan2.setFont(font2);
	slogan2.setColor(sf::Color::White);
	slogan2.setPosition(width/9, height/5 * 4);
	slogan3.setString("Please input your player name( You can use backspace)");
	slogan3.setCharacterSize(20);
	slogan3.setFont(font2);
	slogan3.setColor(sf::Color::Cyan);
	slogan3.setPosition(width/100, height/5 * 3.5);
	// Display box
	inputtextbox.setCharacterSize(40);
	inputtextbox.setFont(font);
	inputtextbox.setColor(sf::Color::White);
	inputtextbox.setPosition(width/19,height/2.4) ;
	// Box Rectangle
	box.setSize(sf::Vector2f(560,60));
	box.setFillColor(sf::Color(255,127,80));
	box.setPosition(width/20,height/2.4);
	//
	if(!pTexture[1].loadFromFile("Player1.jpg"))
	{
		cout <<"Load Player error." << endl;
	}
	if(!pTexture[2].loadFromFile("Player2.jpg"))
	{
		cout <<"Load Player error." << endl;
	}
	if(!pTexture[3].loadFromFile("Player3.jpg"))
	{
		cout <<"Load Player error." << endl;
	}
	if(!pTexture[4].loadFromFile("Player4.jpg"))
	{
		cout <<"Load Player error." << endl;
	}
	/*
	pSprite[1].setTexture(pTexture[1]);
	pSprite[1].setPosition((width/4)*3, (height/2.5));
	pSprite[1].setScale(0.16,0.16);
	*/
	for(int i = 1; i <= 4; i++)
	{
		pSprite[i].setTexture(pTexture[i]);
		pSprite[i].setPosition((width/4)*3, (height/2.5));
		pSprite[i].setScale(0.16,0.16);
	}
	
}


void PlayerNameInputClass::draw(sf::RenderWindow &window, int which_player, string inputstr)
{

	//Slogan
	switch(which_player)
	{
		case 1:
			slogan.setString("Input Player 1 (Max character 8)");
			
		break;
		case 2:
			slogan.setString("Input Player 2 (Max character 8)");
			
		break;
		case 3:
			slogan.setString("Input Player 3 (Max character 8)");
		break;
		case 4:
			slogan.setString("Input Player 4 (Max character 8)");
		break;
	}
	// Set player image
	
	// Display box
	inputtextbox.setString(inputstr);
	//
	window.draw(slogan);
	window.draw(slogan2);
	window.draw(slogan3);
	window.draw(box);
	window.draw(inputtextbox);
	window.draw(pSprite[which_player]);
	
}
PlayerNameInputClass::~PlayerNameInputClass()
{
}
