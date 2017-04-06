#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>

using namespace std ;


void set_Dice_Data( sf::Sprite& y ,sf::Texture& x, int i, int dice_position[2] ,int dice_range[2] ){
	string name = "dice" ;
	string index = to_string(i) ;
	string form = ".png" ;
	name = name + index + form ;

	x.loadFromFile( name, sf::IntRect( 0, 0, dice_range[0], dice_range[1] ) ) ;
	x.setSmooth(true) ;

	y.setTexture( x ) ;
	y.setPosition( sf::Vector2f( dice_position[0] , dice_position[1] ) ) ;

}
