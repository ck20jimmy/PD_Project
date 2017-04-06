#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cctype>
#include<cstdlib>
#include <time.h> 
#include<iostream>
#include<string>
#include <unistd.h>
#include "Menu.h"
#include "PlayerNameInputClass.h"
#include "Player.h"
#include "Set_Dice_Data.h"				//	NEW
#include "Click_The_Dice.h"				//	NEW
#include<stdlib.h>						//	NEW
#include "imageOnBoard.h"               //  NEW
#include "Tip_acronym.h"
#include "Menu2.h"
#include "qa_image.h"
#include "VictoryCondition.h" 

using namespace std;

void draw_now_playing(sf::RenderWindow &window, int now_player);
void draw_game_time(sf::RenderWindow &window, sf::Clock clock , sf::Time time_for_game);
int dice_position[2] = { 1545, 824 } ;		//	NEW			(x,y)
int dice_range[2] = { 120, 120 } ;
int timelimit = 300 ; //record as second ;
	
int main()
{
	//Set music
	sf::SoundBuffer soundbuffer1, soundbuffer2, soundbuffer3;
	sf::Sound sound;
	if(!soundbuffer1.loadFromFile("counting stars.ogg"))
	{
		cout <<"Error loading music" << endl;
	}
	if(!soundbuffer2.loadFromFile("demons.ogg"))
	{
		cout <<"Error loading music" << endl;
	}
	if(!soundbuffer3.loadFromFile("illusiom.ogg"))
	{
		cout <<"Error loading music" << endl;
	}
	sound.setLoop(true); // so it will keep playing
	sound.setVolume(20);
	//Set clock
	sf::Clock clock;
	sf::Time time_for_game;
	sf::Vector2f GameGrid_position_vector[17];
	GameGrid_position_vector[1].x = 9; GameGrid_position_vector[1].y = 735;
	GameGrid_position_vector[2].x = 190; GameGrid_position_vector[2].y = 742;
	GameGrid_position_vector[3].x = 368; GameGrid_position_vector[3].y = 744;
	GameGrid_position_vector[4].x = 557; GameGrid_position_vector[4].y = 750;
	GameGrid_position_vector[5].x = 741; GameGrid_position_vector[5].y = 756;
	GameGrid_position_vector[6].x = 743; GameGrid_position_vector[6].y = 573;
	GameGrid_position_vector[7].x = 750; GameGrid_position_vector[7].y = 393;
	GameGrid_position_vector[8].x = 746; GameGrid_position_vector[8].y = 217;
	GameGrid_position_vector[9].x = 744; GameGrid_position_vector[9].y = 32;
	GameGrid_position_vector[10].x = 562; GameGrid_position_vector[10].y = 25;
	GameGrid_position_vector[11].x = 380; GameGrid_position_vector[11].y = 30;
	GameGrid_position_vector[12].x = 202; GameGrid_position_vector[12].y = 27;
	GameGrid_position_vector[13].x = 24; GameGrid_position_vector[13].y = 37;
	GameGrid_position_vector[14].x = 25; GameGrid_position_vector[14].y = 218;
	GameGrid_position_vector[15].x = 33; GameGrid_position_vector[15].y = 397;
	GameGrid_position_vector[16].x = 26; GameGrid_position_vector[16].y = 565;
	sf::Font font; font.loadFromFile("fontfile.ttf");
    sf::RenderWindow Window;
    sf::RenderWindow GameStartWindow;
    sf::Vector2i vector(100,50);
    Window.create(sf::VideoMode(800,800),"Monopoly Copyright for JL PZ NW ZH",sf::Style::Titlebar| sf::Style::Close);
    
	Menu menu(Window.getSize().x,Window.getSize().y);
	Menu2 menu2(Window.getSize().x,Window.getSize().y);	
	sf::Texture menuTexture;
	sf::Sprite menuImage;
	
	sf::Texture menuTexture2;
	sf::Sprite menuImage2;
	
	if(!menuTexture.loadFromFile("Monopoly.png"))
	{
		cout << "Error!"<< endl;
		return -1;
	}
	if(!menuTexture2.loadFromFile("menuText.jpg"))
	{
		cout << "GG";
	}
	menuImage.setTexture(menuTexture);	
	menuImage2.setTexture(menuTexture2);
	//put image in appropriate place
	menuImage.setPosition(Window.getSize().x /4.5,Window.getSize().y/12);
	menuImage2.setPosition(500,700);
	//
	Window.setKeyRepeatEnabled(false);
    //
    bool isStart = false;
    //
	bool judge_by_happiness = false;
    bool judge_by_time = false; 
    // 
	while(Window.isOpen())
    {
    	sf::Event event;
    	while(Window.pollEvent(event))
    	{
    		if(event.type == sf::Event::Closed)
    			Window.close();
    		
			switch (event.type)
			{
				case sf::Event::KeyPressed:
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
						menu.MoveUp();
						break;	
	
					case sf::Keyboard::Down:
						menu.MoveDown();
						break;
	
					case sf::Keyboard::Return:
						switch (menu.GetPressedItem())
						{
						case 0:
							isStart = true;
							Window.clear(sf::Color::Black);
							std::cout << "Play button has been pressed" << std::endl;							
							break;
						case 1:
							sound.setBuffer(soundbuffer1);
							sound.play();
							std::cout << "Music button has been pressed" << std::endl;
							break;
						case 2:
							sound.setBuffer(soundbuffer2);
							sound.play();
							std::cout << "Music button has been pressed" << std::endl;
							break;
						case 3:
							sound.setBuffer(soundbuffer3);
							sound.play();
							std::cout << "Music button has been pressed" << std::endl;
							break;						
						case 4:
							Window.close();
							break;
						}
					}
					break;
			
				case sf::Event::GainedFocus:
					cout << "Window Active" << endl;
					break;
			}
			
		}
		Window.clear();
		Window.draw(menuImage);
		Window.draw(menuImage2);
		menu.draw(Window);
			
		Window.display();
		if(isStart == true)
			Window.close();
	}
	
	//即時or回合制
  	sf::RenderWindow MenuWindow2;
    MenuWindow2.create(sf::VideoMode(800,800),"Which winning condition",sf::Style::Titlebar| sf::Style::Close);	
    if(isStart == true)
	while(MenuWindow2.isOpen())
    {
    	sf::Event event;
    	while(MenuWindow2.pollEvent(event))
    	{
    		if(event.type == sf::Event::Closed)
    		{
    			isStart = false;
    			MenuWindow2.close();
			}
			
 			switch (event.type)
			{
				case sf::Event::KeyPressed:
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
						menu2.MoveUp();
						break;	
	
					case sf::Keyboard::Down:
						menu2.MoveDown();
						break;
	
					case sf::Keyboard::Return:
						switch (menu2.GetPressedItem())
						{
						case 0:
							judge_by_happiness = true;
							MenuWindow2.clear(sf::Color::Black);							
							break;
						case 1:
							judge_by_time = true;
							MenuWindow2.clear(sf::Color::Black);							
							break;
						}
					}
			}
			
		}
		MenuWindow2.clear();
		MenuWindow2.draw(menuImage);
		MenuWindow2.draw(menuImage2);
		menu2.draw(MenuWindow2);
			
		MenuWindow2.display();
		if (judge_by_happiness || judge_by_time)
			MenuWindow2.close();

	}
	
	if (judge_by_happiness)
		cout << "judge by happiness";
	if (judge_by_time)
		cout << "judge by time";		
	// Textfield window
	sf::RenderWindow Textfieldwindow(sf::VideoMode(800,300), "How many Player?", sf::Style::Titlebar| sf::Style::Close);
	string input_number;
	int number_player = 0;
	sf::RectangleShape textbox(sf::Vector2f(710,60));
	textbox.setFillColor(sf::Color(255,127,80));
	textbox.setPosition(Textfieldwindow.getSize().x/20,Textfieldwindow.getSize().y/2.4);
	if(isStart == true)
		while(Textfieldwindow.isOpen())
		{
			sf::Event event;
			sf::Font font;
			sf::Text inputtext;
			sf::Text slogan("How many players you want (2~4) ?", font, 40);
			if(!font.loadFromFile("fontfile.ttf"))
			{
				cout << "error of font loaded" << endl; 
				//handle error
			}
			while(Textfieldwindow.pollEvent(event))
			{
				switch(event.type)
				{
					case sf::Event::Closed:
						Textfieldwindow.close();
					break;	
					
					case sf::Event::TextEntered:
						cout <<"Text Entered"<<endl;
				        cout << static_cast<char>(event.text.unicode) << endl;
				        cout << static_cast<int>(event.text.unicode) << endl;
				        cout << input_number << endl;
				        if(input_number.length() == 0)
				        	input_number += static_cast<char>(event.text.unicode);
				        else if(event.text.unicode == 8 && input_number.length() == 1) // 8 is backspace
				        {
				        	input_number.pop_back();
						}
						else if(event.text.unicode == 13 && input_number.length() == 1) // 13 is return value
						{
							if(isdigit(static_cast<int>(input_number[0])) != 0 &&atoi(input_number.c_str()) >= 2 && atoi(input_number.c_str()) <= 4)
							{
								number_player = atoi(input_number.c_str());
								Textfieldwindow.close();
								cout << "There are "<<number_player <<" going to play" << endl;
							}
							else
							{
								// if player input wrong number
								input_number.clear();
							}
						}
					break;
				}
			}
			//Set Display String
			inputtext.setFont(font);
			inputtext.setCharacterSize(40);
			inputtext.setString(input_number);
			inputtext.setColor(sf::Color::White);
			inputtext.setPosition(Textfieldwindow.getSize().x/2,Textfieldwindow.getSize().y/2.4);
			// Set "how many players you want (1~4)"
			slogan.setPosition(Textfieldwindow.getSize().x/20,Textfieldwindow.getSize().y/5);
			slogan.setColor(sf::Color::White);
			Textfieldwindow.clear(sf::Color::Black);
			//Set a Rectangle
			Textfieldwindow.draw(textbox);
			Textfieldwindow.draw(inputtext);
			Textfieldwindow.draw(slogan);
			Textfieldwindow.display();
		}
	// Input Player Name
	sf::RenderWindow Input_Player_Name_Window(sf::VideoMode(800,300), "Player Name", sf::Style::Titlebar| sf::Style::Close);
	PlayerNameInputClass playernameinputclass_variable(Input_Player_Name_Window.getSize().x, Input_Player_Name_Window.getSize().y); 
	string player_name[5]; // for index from 1 ~ 4 represent 4 player name
	int which_player = 1;
	if(isStart == true)
		while(Input_Player_Name_Window.isOpen())
		{
			sf::Event event;
			while(Input_Player_Name_Window.pollEvent(event))
			{
				switch(event.type)
				{
					case sf::Event::Closed:
						Input_Player_Name_Window.close();
					break;
					case sf::Event::TextEntered:
						if(player_name[which_player].length() <= 8 && event.text.unicode != 8 && event.text.unicode != 13){
				        	player_name[which_player] += static_cast<char>(event.text.unicode);
				        	cout << player_name[which_player] << endl;
						}
				        else if(event.text.unicode == 8) // 8 is backspace
				        {
				        	if(player_name[which_player].length() >= 1)
								player_name[which_player].pop_back();
						}
						else if(event.text.unicode == 13) // 13 is return value
						{
							if(which_player < number_player)
								which_player++;
							else
								Input_Player_Name_Window.close();
						}
					break;	
				}	
			}
			Input_Player_Name_Window.clear();
			// Draw Image below this row
			playernameinputclass_variable.draw(Input_Player_Name_Window,which_player,player_name[which_player]);
			Input_Player_Name_Window.display();		
		}	
	// GameBoard Mode
	sf::Texture GameBoardText;
	sf::Sprite GameBoardSpr;
	if(!GameBoardText.loadFromFile("GameBoard.jpg"))
	{
		cout <<"Can't load image" << endl;
		return -1;
	}
	GameBoardSpr.setTexture(GameBoardText);
	GameBoardSpr.setPosition(0,0);
	GameBoardSpr.setScale(0.6,0.6);
	Player player[5];
	
	for(int i = 1; i < number_player;i++)
		cout << player_name[i] << endl;
	
	//	NEW	!!!
	//input Dice image
	sf::Texture image[7] ;
	sf::Sprite dice[7] ;
	srand (time(NULL));
	set_Dice_Data(dice[0], image[0], 1, dice_position, dice_range ) ;

	for( int i = 1 ; i <= 6 ; i++  )
		set_Dice_Data( dice[i] ,image[i], i, dice_position, dice_range ) ;
	//Save now dice number
	int index = 0 ;
	int now_playing = 1;  //who is player????
	
	if(isStart == true)
	{
		// Reset the clock!!!
		clock.restart();
		GameStartWindow.setPosition(sf::Vector2i(200,100));
		GameStartWindow.create(sf::VideoMode(1700,950),"Monopoly : Copyright for JL PJ NW ZG",sf::Style::Titlebar| sf::Style::Close);
			// Declare GameWinningCondition 20160612 22:40 write
		sf::Texture GameWinningCondition_Txt;
		sf::Sprite GameWinningCondition_Spr;
		if(!GameWinningCondition_Txt.loadFromFile("GameWinningCondition.jpg"))
		{
			cout << "GameWinningCondition.jpg loadfile error" << endl;
		}
		GameWinningCondition_Spr.setTexture(GameWinningCondition_Txt);
		GameWinningCondition_Spr.setPosition(966,823);
		//Declare Player Class
		for(int i = 1; i <= number_player;i++)
		{
			player[i].create(GameStartWindow.getSize().x,GameStartWindow.getSize().y,player_name[i],i);
		}
		
		//Set Position
		for(int i = 1; i <= number_player;i++)
		{
			if(i == 1)
				player[i].setPosition(GameBoardSpr);
			else
				player[i].setPosition(GameBoardSpr, player[i-1].getSprite());
		}
		//GameStartWindow.setPosition(vector);
		
		sf::Sprite image_on_board;
		sf::Texture image_on_board_texture[13];
		
		// to call image on the gameboard
		string imageOnBoard = "imageonboard";
		string jpg = ".jpg";
		string nameOfimage;
		for (int i=0; i<=12 ; i++)
		{
			nameOfimage = imageOnBoard + to_string(i) + jpg;
			image_on_board_texture[i].loadFromFile(nameOfimage);
		}
		bool anyImage = false;
		bool is_dice_release = false;
		bool is_dice_click = false;
		
		sf::Sprite qa;
		sf::Texture qa_texture[6];
		string nameOfqa;
		string QA = "qa";
		for(int i = 1 ; i <= 5 ; i++)
		{
			nameOfqa = QA + to_string(i) + jpg ;
			qa_texture[i].loadFromFile(nameOfqa);
		}
		
		while(GameStartWindow.isOpen())
		{
			sf::Event event;
			// try to check if there is any one press dice
			
			
			//NEW!!!
			//dice
			if(click_the_dice( dice, GameStartWindow, dice_position, dice_range, event,index ))
			{
				is_dice_click = true;
				cout << index << endl;
			}
			while(GameStartWindow.pollEvent(event))
			{
				switch(event.type)
				{
				case sf::Event::MouseButtonReleased:
					//if(event.mouseButton.button == sf::Mouse::Left)
					if(sf::Mouse::getPosition(GameStartWindow).x>1544 and sf::Mouse::getPosition(GameStartWindow).x <1660
					 and sf::Mouse::getPosition(GameStartWindow).y >827 and sf::Mouse::getPosition(GameStartWindow).y<935)
					{
						is_dice_release = true;	
						cout << "is dice release " << endl;
					}
				break; 
				case sf::Event::Closed:
					GameStartWindow.close();
				break;		
				
				case sf::Event::MouseMoved:
					chooseImageToShow(event, image_on_board, image_on_board_texture, anyImage);
				break;
				
				case sf::Event::MouseButtonPressed:
					
					if(event.mouseButton.button == sf::Mouse::Left)
					{
						cout << "x: " << event.mouseButton.x << "y: " <<event.mouseButton.y << endl;
					}
					
				break;
				
				case sf::Event::TextEntered:
					cout <<"Text Entered"<<endl;
					if(event.text.unicode == 65)
					{
						cout <<"Capital A" << endl;
					}
				break;
				
				}
			}
			// Clear Game Board
			GameStartWindow.clear();
			//Set time board
			draw_game_time(GameStartWindow, clock, time_for_game);
			for(int i = 1; i <= number_player;i++)
			{		
				player[i].draw(GameStartWindow, now_playing); // Add pointer sign
			}
			GameStartWindow.draw(GameBoardSpr);
			
			
			if (anyImage == true)
				GameStartWindow.draw(image_on_board);
		
			//click_the_dice( dice, GameStartWindow, dice_position, dice_range, event,index )
			GameStartWindow.draw(dice[0]);
			draw_now_playing(GameStartWindow,now_playing);
			//Draw GameWinningCondition
			GameStartWindow.draw(GameWinningCondition_Spr);
			//STARTGGGGGGGGGGGGGGGGGGGGGGGGGGGame!!!
			
			
			for(int i = 1; i <= number_player; i++){
				player[i].draw_playerChessman(GameStartWindow);
			}
			
			
			
			//if dice is release
			if(is_dice_release && is_dice_click)
			{
				// first paramater is dice index number 
				// Second paramater is Vector for Chessman position
				// Third paramater is to put now_playing player in right position
				player[now_playing].move_playerChessman(index, GameGrid_position_vector,now_playing);
				// Draw three times of player new position
				int drawcount = 0;
			
				for(int i = 1; i <= number_player; i++){
					player[i].draw_playerChessman(GameStartWindow);
				}
				GameStartWindow.display();
				// Stop for a while!!!
				sleep(1);
				// Let player to input something
				sf::RenderWindow EventWindow;
				Tip_acronym showInstruction;
				char answer;
				switch(player[now_playing].getGrid())
				{
					case 1:
						is_dice_release = false;
						is_dice_click = false;
						break;
					case 2:
						if (player[now_playing].getguitarskill()==false)
						{
							EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
							showInstruction.setString("Want to learn guitar with guitar club","leader?", "Cost: $2000","(Y) Yes! (N) No...");
							while(EventWindow.isOpen())
							{
								sf::Event gameevent;
								while(EventWindow.pollEvent(gameevent))
								{							
									//說明 
									if(gameevent.type == sf::Event::TextEntered && (gameevent.text.unicode == 'Y' || gameevent.text.unicode == 'y'))
									{
										/* 
										if (player[i].learn_to_play_guitar == false)
  										是否要和炫神學吉他
										Yes -> $ -2000， <3 +10，player[i].learn_to_play_guitar = true
										No  -> nothing
										*/
										player[now_playing].setMoney(-2000);
										player[now_playing].setHPY(10);
										player[now_playing].learn_to_play_guitar();
										cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
										cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
										cout << "case 2 ok(if)"<< endl;
										is_dice_release = false;
										is_dice_click = false;
										EventWindow.close();										
									}
									else if (gameevent.type == sf::Event::TextEntered && (gameevent.text.unicode == 'N' || gameevent.text.unicode == 'n')) 
									{
										cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
										cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
										cout << "case 2 ok(if)"<< endl;
										is_dice_release = false;
										is_dice_click = false;
										EventWindow.close();		
									}	
								}
								EventWindow.clear();
								showInstruction.draw(EventWindow);
								EventWindow.display();
							}
						}
						else
						{
							EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
							showInstruction.setString("You've learned guitar!","Revenue: $300, HPY: +5","Press any key to continue");
							//已經學過吉他了 
							while(EventWindow.isOpen())
							{
								sf::Event gameevent;
								while(EventWindow.pollEvent(gameevent))
								{
									if(gameevent.type == sf::Event::TextEntered)
									{
										player[now_playing].setMoney(300);
										player[now_playing].setHPY(5);
										cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
										cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
										cout << "case 2 ok(if)"<< endl;
										is_dice_release = false;
										is_dice_click = false;
										EventWindow.close();
									}
								}
								EventWindow.clear();
								showInstruction.draw(EventWindow);
								EventWindow.display();
							}

						}
						break;
					case 3:
						if(player[now_playing].getsing_skill() == false)
						{
							EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
							showInstruction.setString("Want to learn singing ?","Cost: $3000","(Y) Yes! (N) No...");
							while(EventWindow.isOpen())
							{
								sf::Event gameevent;
								while(EventWindow.pollEvent(gameevent))
								{
									//說明and輸入格 
									
									if(gameevent.type == sf::Event::TextEntered && (gameevent.text.unicode == 'Y' || gameevent.text.unicode == 'y'))
									{
										/*
										if (player[i].learn_to_sing == false)
										是否要和炫神學唱歌
										Yes -> $ -3000， <3 +15，player[i].learn_to_sing = true
										No  -> nothing
										*/
										player[now_playing].setMoney(-3000);
										player[now_playing].setHPY(15);
										player[now_playing].learn_to_sing();
										cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
										cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
										cout << "case 3 ok(if)"<< endl;
										is_dice_release = false;
										is_dice_click = false;
										EventWindow.close();											
									}
									
									else if(gameevent.type == sf::Event::TextEntered && (gameevent.text.unicode == 'N' || gameevent.text.unicode == 'n'))
									{
										cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
										cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
										cout << "case 3 ok(if)"<< endl;
										is_dice_release = false;
										is_dice_click = false;
										EventWindow.close();
									}
								}
								EventWindow.clear();
								showInstruction.draw(EventWindow);
								EventWindow.display();
							} 
						}
						else
						{
							EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
							showInstruction.setString("You've learned singing!","Revenue: $300, HPY +5","Press any key to continue");
							//學過唱歌了
							while(EventWindow.isOpen())
							{
								sf::Event gameevent;
								while(EventWindow.pollEvent(gameevent))
								{
									if(gameevent.type == sf::Event::TextEntered)
									{
										player[now_playing].setMoney(500);
										player[now_playing].setHPY(8);
										cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
										cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
										cout << "case 3 ok(if)"<< endl;
										is_dice_release = false;
										is_dice_click = false;
										EventWindow.close();
									}
								}
								EventWindow.clear();
								showInstruction.draw(EventWindow);
								EventWindow.display();
							}
						} 
						break;						
					case 4:
						EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
						showInstruction.setString("Go to the concert?", "Cost: $ 500", "(Y) Yes! (N) No...");
						while(EventWindow.isOpen())
						{
							sf::Event gameevent;
							while(EventWindow.pollEvent(gameevent))
							{
								//說明+輸入格
								if(gameevent.type == sf::Event::TextEntered && (gameevent.text.unicode == 'Y' || gameevent.text.unicode == 'y'))
								{
									/*
									是否要聽炫神演唱會
									yes -> $ -500，<3 +6
									no -> nothing
									*/
									player[now_playing].setMoney(-500);
									player[now_playing].setHPY(6);
									cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
									cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
									cout << "case 4 ok(if)"<< endl;
									is_dice_release = false;
									is_dice_click = false;
									EventWindow.close();
								 }
								else if(gameevent.type == sf::Event::TextEntered && (gameevent.text.unicode == 'N' || gameevent.text.unicode == 'n'))
								{
									cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
									cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
									cout << "case 4 ok(if)"<< endl;
									is_dice_release = false;
									is_dice_click = false;
									EventWindow.close();
								} 
							}
							EventWindow.clear();
							showInstruction.draw(EventWindow);
							EventWindow.display();
						} 
						break;
					case 5:
						EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
						show_qa(qa, qa_texture, answer);						
						while(EventWindow.isOpen())
						{
							sf::Event gameevent;
							while(EventWindow.pollEvent(gameevent))
							{
								//QA
								if(gameevent.type == sf::Event::TextEntered && (gameevent.text.unicode == answer || gameevent.text.unicode == tolower(answer)))
								{
									/*
									答對 
									*/
									player[now_playing].setHPY(10);
									cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
									cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
									cout << "case 5 ok(if)"<< endl;
									is_dice_release = false;
									is_dice_click = false;
									EventWindow.close();
								 }
								else if(gameevent.type == sf::Event::TextEntered && gameevent.text.unicode != answer)
								{
									/*
									答錯 
									*/
									player[now_playing].setMoney(-1000);
									cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
									cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
									cout << "case 5 ok(if)"<< endl;
									is_dice_release = false;
									is_dice_click = false;
									EventWindow.close();
								} 
							}
							EventWindow.clear();
							EventWindow.draw(qa);
							EventWindow.display();
						} 
						break;
					case 6:
						EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
						showInstruction.setString("joined 2016 IM night!", "HPY +15", "Press any key to continue");
						while(EventWindow.isOpen())
						{
							sf::Event gameevent;
							while(EventWindow.pollEvent(gameevent))
							{
								//聽之夜
								if(gameevent.type == sf::Event::TextEntered)
								{							
									player[now_playing].setHPY(15);
									cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
									cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
									cout << "case 5 ok(if)"<< endl;
									is_dice_release = false;
									is_dice_click = false;
									EventWindow.close();
								}
								
						 	}
						 	EventWindow.clear();
						 	showInstruction.draw(EventWindow);
						 	EventWindow.display();
						}
						break;
					case 7:
						if(player[now_playing].getdrum_skill() == false)
						{
							EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
							showInstruction.setString("Learn to play drum?","Cost: $1000", "(Y) Yes! (N) No..."); 
							while(EventWindow.isOpen())
							{
								sf::Event gameevent;
								while(EventWindow.pollEvent(gameevent))
								{
									if(gameevent.type == sf::Event::TextEntered && (gameevent.text.unicode == 'Y' || gameevent.text.unicode == 'y'))
									{
										/*
										if (player[i].learn_to_playdrum == false)
										是否要和炫神學鼓
										Yes -> $ -1000， <3 +5，player[i].learn_to_playdrum = true
										No  -> nothing
										*/
										player[now_playing].setMoney(-1000);
										player[now_playing].setHPY(5);
										player[now_playing].learn_to_play_drum();
										cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
										cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
										cout << "case 6 ok(if)"<< endl;
										is_dice_release = false;
										is_dice_click = false;
										EventWindow.close();											
									 }
									else if(gameevent.type == sf::Event::TextEntered && (gameevent.text.unicode == 'N' || gameevent.text.unicode == 'n'))
									{
										cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
										cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
										cout << "case 6 ok(if)"<< endl;
										is_dice_release = false;
										is_dice_click = false;
										EventWindow.close();
									}
								}
								EventWindow.clear();
								showInstruction.draw(EventWindow);
								EventWindow.display();
							}
						}
						else
						{
							EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
							showInstruction.setString("You've learned to play drum!","Revenue: $200, HPY +3", "Press any key to continue");
							//學過鼓了 
							while(EventWindow.isOpen())
							{
								sf::Event gameevent;
								while(EventWindow.pollEvent(gameevent))
								{
									if(gameevent.type == sf::Event::TextEntered)
									{
										player[now_playing].setMoney(200);
										player[now_playing].setHPY(3);
										cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
										cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
										cout << "case 6 ok(if)"<< endl;
										is_dice_release = false;
										is_dice_click = false;
										EventWindow.close(); 
									}
								}
								EventWindow.clear();
								showInstruction.draw(EventWindow);
								EventWindow.display();
							}				
						}
						break;
					case 8:
						if(player[now_playing].getguitar_club_member() == false)
						{
							EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
							showInstruction.setString("Want to join guitar club?","Cost: $1000","(Y) Yes! (N) No...");
							while(EventWindow.isOpen())
							{
								sf::Event gameevent;
								while(EventWindow.pollEvent(gameevent))
								{
									if(gameevent.type == sf::Event::TextEntered && (gameevent.text.unicode == 'Y' || gameevent.text.unicode == 'y'))
									{
										/*
										if (player[i].join_guitar_club == false)
										是否要加吉他社
										Yes- -> 社費 $ -1000
										*/
										player[now_playing].setMoney(-1000);
										player[now_playing].become_guitar_club_member() ;
										cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
										cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
										cout << "case 7 ok(if)"<< endl;
										is_dice_release = false;
										is_dice_click = false;
										EventWindow.close();
									}
									else if(gameevent.type == sf::Event::TextEntered && (gameevent.text.unicode == 'N' || gameevent.text.unicode == 'n'))
									{
										cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
										cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
										cout << "case 7 ok(if)"<< endl;
										is_dice_release = false;
										is_dice_click = false;
										EventWindow.close();
									}
								}
								EventWindow.clear();
								showInstruction.draw(EventWindow);
								EventWindow.display();
							}
						}
						else
						{
							EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
							showInstruction.setString("You've joined the club!","HPY +10", "Press any key to continue"); 
							while(EventWindow.isOpen())
							{
								sf::Event gameevent;
								while(EventWindow.pollEvent(gameevent))
								{
									if(gameevent.type == sf::Event::TextEntered)
									{
										player[now_playing].setHPY(10);
										cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
										cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
										cout << "case 6 ok(if)"<< endl;
										is_dice_release = false;
										is_dice_click = false;
										EventWindow.close(); // bug
									}
								}
								EventWindow.clear();
								showInstruction.draw(EventWindow);
								EventWindow.display();
							}				
						}
						break;
					case 9:
						EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
						showInstruction.setString("joined 2016 IM Karaoke!","HPY +5", "Press any key to continue"); 
						while(EventWindow.isOpen())
						{
							sf::Event gameevent;
							while(EventWindow.pollEvent(gameevent))
							{
								if(gameevent.type == sf::Event::TextEntered)
								//聽系卡 
								{
									player[now_playing].setHPY(5);
									cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
									cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
									cout << "case 8 ok(if)"<< endl;
									is_dice_release = false;
									is_dice_click = false;
									EventWindow.close();
						 		}
							}
							EventWindow.clear();
							showInstruction.draw(EventWindow);
							EventWindow.display();
						}	
						break;
					case 10:
						EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
						show_qa(qa, qa_texture, answer);						
						while(EventWindow.isOpen())
						{
							sf::Event gameevent;
							while(EventWindow.pollEvent(gameevent))
							{
								//QA
								if(gameevent.type == sf::Event::TextEntered && (gameevent.text.unicode == answer || gameevent.text.unicode == tolower(answer)))
								{
									/*
									答對 
									*/
									player[now_playing].setHPY(10);
									cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
									cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
									cout << "case 5 ok(if)"<< endl;
									is_dice_release = false;
									is_dice_click = false;
									EventWindow.close();
								 }
								else if(gameevent.type == sf::Event::TextEntered && gameevent.text.unicode != answer)
								{
									/*
									答錯 
									*/
									player[now_playing].setMoney(-1000);
									cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
									cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
									cout << "case 5 ok(if)"<< endl;
									is_dice_release = false;
									is_dice_click = false;
									EventWindow.close();
								} 
							}
							EventWindow.clear();
							EventWindow.draw(qa);
							EventWindow.display();
						} 
						break;
					case 11:
						EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
						showInstruction.setString("take the bus! shining light get!","HPY +10", "Press any key to continue"); 
						while(EventWindow.isOpen())
						{
							sf::Event gameevent;
							while(EventWindow.pollEvent(gameevent))
							{
								//坐公車
								if(gameevent.type == sf::Event::TextEntered)
								{								
									player[now_playing].setHPY(10);
									cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
									cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
									cout << "case 10 ok(if)"<< endl;
									is_dice_release = false;
									is_dice_click = false;
									EventWindow.close();
								}
							} 
							EventWindow.clear();
							showInstruction.draw(EventWindow);
							EventWindow.display();
						}						
						break;
					case 12:
						EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
						show_qa(qa, qa_texture, answer);						
						while(EventWindow.isOpen())
						{
							sf::Event gameevent;
							while(EventWindow.pollEvent(gameevent))
							{
								//QA
								if(gameevent.type == sf::Event::TextEntered && (gameevent.text.unicode == answer || gameevent.text.unicode == tolower(answer)))
								{
									/*
									答對 
									*/
									player[now_playing].setHPY(10);
									cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
									cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
									cout << "case 5 ok(if)"<< endl;
									is_dice_release = false;
									is_dice_click = false;
									EventWindow.close();
								 }
								else if(gameevent.type == sf::Event::TextEntered && gameevent.text.unicode != answer)
								{
									/*
									答錯 
									*/
									player[now_playing].setMoney(-1000);
									cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
									cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
									cout << "case 5 ok(if)"<< endl;
									is_dice_release = false;
									is_dice_click = false;
									EventWindow.close();
								} 
							}
							EventWindow.clear();
							EventWindow.draw(qa);
							EventWindow.display();
						} 
						break;				
					case 13:
						EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
						showInstruction.setString("joined 2015 IM BBQ!","HPY +10", "Press any key to continue"); 
						while(EventWindow.isOpen())
						{
							sf::Event gameevent;
							while(EventWindow.pollEvent(gameevent))
							{
								//系烤聽炫神唱歌 
								if(gameevent.type == sf::Event::TextEntered)
								{								
									player[now_playing].setHPY(10);
									cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
									cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
									cout << "case 9 ok(if)"<< endl;
									is_dice_release = false;
									is_dice_click = false;
									EventWindow.close();
								}
						 	}
						 	EventWindow.clear();
						 	showInstruction.draw(EventWindow);
						 	EventWindow.display();
						}							
					break;
					case 14:
						EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
						showInstruction.setString("PDOGS #1, unable to exceed...QQ","HPY -5", "Press any key to continue"); 
						while(EventWindow.isOpen())
						{
							sf::Event gameevent;
							while(EventWindow.pollEvent(gameevent))
							{
								//pdogs NO.1無法超越 
								if(gameevent.type == sf::Event::TextEntered)
								{								
									player[now_playing].setHPY(-5);
									cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
									cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
									cout << "case 11 ok(if)"<< endl;
									is_dice_release = false;
									is_dice_click = false;
									EventWindow.close();
								}
							} 
							EventWindow.clear();
							showInstruction.draw(EventWindow);
							EventWindow.display();
						}	
						break;
					case 15:
						EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
						show_qa(qa, qa_texture, answer);						
						while(EventWindow.isOpen())
						{
							sf::Event gameevent;
							while(EventWindow.pollEvent(gameevent))
							{
								//QA
								if(gameevent.type == sf::Event::TextEntered && (gameevent.text.unicode == answer || gameevent.text.unicode == tolower(answer)))
								{
									/*
									答對 
									*/
									player[now_playing].setHPY(10);
									cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
									cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
									cout << "case 5 ok(if)"<< endl;
									is_dice_release = false;
									is_dice_click = false;
									EventWindow.close();
								 }
								else if(gameevent.type == sf::Event::TextEntered && gameevent.text.unicode != answer)
								{
									/*
									答錯 
									*/
									player[now_playing].setMoney(-1000);
									cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
									cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
									cout << "case 5 ok(if)"<< endl;
									is_dice_release = false;
									is_dice_click = false;
									EventWindow.close();
								} 
							}
							EventWindow.clear();
							EventWindow.draw(qa);
							EventWindow.display();
						} 
						break;
					case 16:
						EventWindow.create(sf::VideoMode(800,800),"Event",sf::Style::Titlebar| sf::Style::Close);
						showInstruction.setString("want to be that bandage <3","do nothing", "Press any key to continue"); 
						while(EventWindow.isOpen())
						{
							sf::Event gameevent;
							while(EventWindow.pollEvent(gameevent))
							{
								//貼OK繃 
								if(gameevent.type == sf::Event::TextEntered)
								{
									cout << "Player " << now_playing << " money: " <<player[now_playing].getMoney() << endl;
									cout << "Player " << now_playing << " money: "<<player[now_playing].getHPY() << endl;
									cout << "case 12 ok(if)"<< endl;
									is_dice_release = false;
									is_dice_click = false;
									EventWindow.close();
								}
							} 
							EventWindow.clear();
							showInstruction.draw(EventWindow);
							EventWindow.display();
						}	
						break;
				}
				now_playing++;
				
				if(now_playing > number_player)
				{
					now_playing = now_playing % number_player;
				}
			}
			
			//Check Debt or Alive
			if( is_Debt( player, number_player ) ){
				for( int i = 1 ; i <= number_player ; i++ )
					if( player[i].getMoney() < 0 ){
						player[i].setNowStatus("Now Status : In Debt") ;
						player[i].setStatusText() ;
					}
			}
			else{
				for( int i = 1 ; i <= number_player ; i++ )
					if( player[i].getMoney() >= 0 ){
						player[i].setNowStatus("Now Status : Alive") ;
						player[i].setStatusText() ;
					}
			}
			
			
			//Check Victory
			if( judge_by_happiness == true ){
				if( is_Who_Victory( number_player, player) ){
					bool* winner = Who_Victory_HPY(number_player, player) ;
					draw_winner(winner, player, font) ;
					GameStartWindow.close() ;
				}
			}
			if( judge_by_time == true ){
				sf::Time check = clock.getElapsedTime() ;
				if( check.asSeconds() >= timelimit ){
					bool* winner = Who_Victory_TIME( number_player, player ) ;
					draw_winner( winner, player, font ) ;
					GameStartWindow.close() ;
				}
			}

			
			
			
			
			
			
			GameStartWindow.display();
			
		}
	}
	return 0;
}
void draw_now_playing(sf::RenderWindow &window, int now_player)
{
	
	// Who is playing 
	sf::Text who_is_playing;
	sf::Font font;
	if(!font.loadFromFile("fontfile.ttf"))
	{
		cout << " draw now playing error" << endl;
	}
	who_is_playing.setString("Now Player: " + to_string(now_player));
	who_is_playing.setCharacterSize(40);
	who_is_playing.setFont(font);
	who_is_playing.setColor(sf::Color::Magenta);
	who_is_playing.setPosition(window.getSize().x/6*3.23, window.getSize().y/5*4);
	window.draw(who_is_playing);
}
void draw_game_time(sf::RenderWindow &window, sf::Clock clock , sf::Time time_for_game)
{
	sf::Text timetext;
	sf::Font font;
	int now_time;
	if(!font.loadFromFile("fontfile2.ttf"))
	{
		cout << "Error in draw game time" << endl;
	}
	time_for_game = clock.getElapsedTime();
	now_time = static_cast<int>(time_for_game.asSeconds());
	timetext.setString(to_string(static_cast<int>(now_time/60)) + ':' + to_string(now_time%60));
	timetext.setCharacterSize(40);
	timetext.setFont(font);
	timetext.setPosition(1566, 765);
	timetext.setColor(sf::Color::Magenta);
	window.draw(timetext);
}
