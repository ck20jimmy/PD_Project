#include<SFML/Graphics.hpp>

void click_the_dice( sf::Sprite dice[], sf::RenderWindow window ){
	sf::Vector2i mouse_position = sf::Mouse::getPosition(window) ;

	if(mouse_position.x <= 460 && mouse_position.x >= 340 )
		if(mouse_position.y <= 340 && mouse_position.y >= 220)
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				int random_number = rand() ;
				    
				if( random_number %7 == 1 ){
			    	window.draw(dice[1]) ;
			    	dice[0] = dice[1] ;
				}
			    if( random_number %7 == 2 ){
			    	window.draw(dice[2]) ;
			    	dice[0] = dice[2] ;
				}
			    if( random_number %7 == 3 ){
			    	window.draw(dice[3]) ;
			    	dice[0] = dice[3] ;
				}
			    if( random_number %7 == 4 ){
			    	window.draw(dice[4]) ;
			    	dice[0] = dice[4] ;
				}
			    if( random_number %7 == 5 ){
			    	window.draw(dice[5]) ;
			    	dice[0] = dice[5] ;
				}
				if( random_number %7 == 6 ){
			    	window.draw(dice[6]) ;
			    	dice[0] = dice[6] ;
				}
			}
}
