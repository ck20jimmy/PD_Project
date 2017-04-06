#include<SFML/Graphics.hpp>
#include<stdlib.h>
#include <time.h> 

bool click_the_dice( sf::Sprite dice[], sf::RenderWindow& window, int dice_position[2], int dice_range[2],sf::Event event,int& index ){

	sf::Vector2i mouse_position = sf::Mouse::getPosition(window) ;

	if( mouse_position.x <= dice_position[0] + dice_range[0] && mouse_position.x >= dice_position[0] )
		if( mouse_position.y <= dice_position[1] + dice_range[1] && mouse_position.y >= dice_position[1] )
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
		//	if(event.type == sf::Event::MouseButtonReleased)
		//	{
				
				int random_number = rand() ;
				
				while(random_number % 7 == 0)
				{
					random_number = rand();
				}
				
				if( random_number %7 == 1 ){
			    	
			    	dice[0] = dice[1] ;
			    	index = 1 ;
				}
			    if( random_number %7 == 2 ){
			    	
			    	dice[0] = dice[2] ;
			    	index = 2 ;
				}
			    if( random_number %7 == 3 ){
			    
			    	dice[0] = dice[3] ;
			    	index = 3 ;
				}
			    if( random_number %7 == 4 ){
			    
			    	dice[0] = dice[4] ;
			    	index = 4 ;
				}
			    if( random_number %7 == 5 ){
			    
			    	dice[0] = dice[5] ;
			    	index = 5 ;
				}
				if( random_number %7 == 6 ){
			  
			    	dice[0] = dice[6] ;
			    	index = 6 ;
				}
				
				return true;
			}
	return false;		
}
