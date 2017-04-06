#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>

using namespace std ;

void set_Dice_Data( sf::Texture x, char i ){
	string name = "dice" ;
	name.push_back(i) ;
	string form = ".png" ;
	name = name + form ;
	x.loadFromFile( name, sf::IntRect(0,0,120,120) ) ;
	x.setSmooth(true) ;
}
