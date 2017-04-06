#include"Player.h"
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>
using namespace std;
Player::Player()
{
	
	if(!font.loadFromFile("fontfile.ttf"))
	{
		cout << "Error loading font file in Player.h" << endl;
	}
	if(!font_two.loadFromFile("fontfile3.ttf"))
	{
		cout << "Error loading font file in Player.h" << endl;
	}
	// Set money
	money = 10000;
	now_money = to_string(money);
	money_text.setCharacterSize(40);
	money_text.setColor(sf::Color(0,191,255));
	money_text.setString('$'+now_money);
	money_text.setFont(font_two);
	// Set happiness
	happiness = 0;
	now_happiness = to_string(happiness);
	happiness_text.setCharacterSize(40);
	happiness_text.setColor(sf::Color(0,191,255));
	happiness_text.setString("Hpy: "+now_happiness);
	happiness_text.setFont(font);
	
	//Set Status
	now_Grid = 1; // in the start
	status = 0;
	
	now_status  = "Now Status : Alive";
	cout << now_status << endl;
	status_text.setCharacterSize(18);
	status_text.setColor(sf::Color::Cyan);
	status_text.setString(now_status);
	status_text.setFont(font);
	// Add pointer 2016 06 18
	if(!pointer.loadFromFile("pointer.jpg"))
	{
		cout << "load pointer error" << endl;
	}
	pointerSpr.setTexture(pointer);
	
	// Various skill
	guitar_skill = false;
	drum_skill = false;
	sing_skill = false;
	guitar_club_member = false;
	
}
void  Player::create(float width, float height,const string &playername,int ID)
{
	//
	this->ID = ID;
	this->player_name = playername;
	// Text
	
	text_name.setCharacterSize(45);
	text_name.setColor(sf::Color::White);
	text_name.setString(playername);
	text_name.setFont(font);
	text_name.setPosition((width/6)*(4+ID-1), height/4);
	
	// Show Image
	switch(ID)
	{
		case 1:
			pTexture.loadFromFile("Player1.jpg");
			pChessTxt.loadFromFile("Player1chessman.jpg");
			pChessSpr.setPosition(8,736);
			pointerSpr.setPosition(955,378);
		break;
		case 2:
			pTexture.loadFromFile("Player2.jpg");
			pChessTxt.loadFromFile("Player2chessman.jpg");
			pChessSpr.setPosition(99,745);
			pointerSpr.setPosition(1131,378);
		break;
		case 3:
			pTexture.loadFromFile("Player3.jpg");
			pChessTxt.loadFromFile("Player3chessman.jpg");
			pChessSpr.setPosition(8,821);
			pointerSpr.setPosition(1332,378);
		break;
		case 4:
			pTexture.loadFromFile("Player4.jpg");
			pChessTxt.loadFromFile("Player4chessman.jpg");
			pChessSpr.setPosition(102,827);
			pointerSpr.setPosition(1523,378);
		break;
	}
	//Set Sprite
	pSprite.setTexture(pTexture);
	pSprite.setScale(0.2,0.2);
	//Set chessman
	pChessSpr.setTexture(pChessTxt);
	pChessSpr.setScale(0.2,0.2);
	// Pointer
	pointerSpr.setScale(0.5,0.5);
}
Player::~Player()
{
	
}

void Player::draw(sf::RenderWindow &window, int now_player)
{
	// We need to adjust the money now
	money_text.setString('$'+ to_string(money));
	happiness_text.setString("Hpy: "+to_string(happiness));
	window.draw(text_name);
	window.draw(pSprite);
	window.draw(money_text);
	window.draw(happiness_text);
	window.draw(status_text);
	if(now_player == ID)
		window.draw(pointerSpr);
}
void Player::setPosition(sf::Sprite &GameBoard)
{
	//ぐ或璶ID-1把计琌
	// 北瓜砆竚琌ち霍筳纠!!!! 
	text_name.setPosition(GameBoard.getGlobalBounds().width + (pSprite.getGlobalBounds().width*(ID-1)), 0);
	pSprite.setPosition(GameBoard.getGlobalBounds().width + (pSprite.getGlobalBounds().width*(ID-1)), text_name.getGlobalBounds().top+text_name.getGlobalBounds().height+3);
	money_text.setPosition(GameBoard.getGlobalBounds().width + (pSprite.getGlobalBounds().width*(ID-1)),pSprite.getGlobalBounds().top+pSprite.getGlobalBounds().height);
	happiness_text.setPosition(GameBoard.getGlobalBounds().width + (pSprite.getGlobalBounds().width*(ID-1)), money_text.getGlobalBounds().top + money_text.getGlobalBounds().height);
	status_text.setPosition(GameBoard.getGlobalBounds().width + (pSprite.getGlobalBounds().width*(ID-1)), happiness_text.getGlobalBounds().top + happiness_text.getGlobalBounds().height);
	
}
void Player::setPosition(sf::Sprite &GameBoard, sf::Sprite &previousSprite)
{
	text_name.setPosition(GameBoard.getGlobalBounds().width + (pSprite.getGlobalBounds().width*(ID-1)), 0);
	pSprite.setPosition(GameBoard.getGlobalBounds().width + (pSprite.getGlobalBounds().width*(ID-1)), previousSprite.getPosition().y);
	money_text.setPosition(GameBoard.getGlobalBounds().width + (pSprite.getGlobalBounds().width*(ID-1)),pSprite.getGlobalBounds().top+pSprite.getGlobalBounds().height);
	happiness_text.setPosition(GameBoard.getGlobalBounds().width + (pSprite.getGlobalBounds().width*(ID-1)), money_text.getGlobalBounds().top + money_text.getGlobalBounds().height);
	status_text.setPosition(GameBoard.getGlobalBounds().width + (pSprite.getGlobalBounds().width*(ID-1)), happiness_text.getGlobalBounds().top + happiness_text.getGlobalBounds().height);
}
void Player::draw_playerChessman(sf::RenderWindow &window){
	window.draw(pChessSpr);
}

void Player::move_playerChessman(const int dice_number, const sf::Vector2f vector[17], const int now_playing){
		// First change Grid int
		if(now_Grid+dice_number <= 16)
		{
			now_Grid += dice_number;
		}
		else
		{
			now_Grid = (now_Grid+dice_number) % 16;
		}
		
		
		// Second change chessman Position on Game Board
		switch(ID)
		{
			case 1:
				pChessSpr.setPosition(vector[now_Grid]);
			break;
			case 2:
				pChessSpr.setPosition(vector[now_Grid].x + 80,vector[now_Grid].y);
			break;
			case 3:
				pChessSpr.setPosition(vector[now_Grid].x, vector[now_Grid].y + 80);
			break;
			case 4:
				pChessSpr.setPosition(vector[now_Grid].x + 100, vector[now_Grid].y + 60);
			break; 
			
		}
	}
