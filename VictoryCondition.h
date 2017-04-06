#include<iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include<string>
#include"stdlib.h"

using namespace std ;

//Function to check
bool is_Who_Victory( int number_player, Player player[5] ){
	for( int i = 1 ; i <= number_player ; i++ )
		if( player[i].getHPY() >= 100 )
			if( player[i].getNowStatus() == "Now Status : Alive" )
				return true ;

	return false ;
}

bool* Who_Victory_HPY( int number_player, Player p[5] ){
	bool* winner = new bool[5] ;
	
	for( int i  = 1 ; i <= 4 ; i++ )
		winner[i] = 0 ;
	
	for( int i = 1 ; i <= number_player ; i++ )
		if( p[i].getHPY() >= 100 && p[i].getNowStatus() == "Now Status : Alive" ){
			winner[i] = 1 ;
		}
	
	return winner ;
}

//因為可能有同分的狀況，所以我輸出一個 bool 的 array ，如果是winner了話 == 1 else == 0 ; 
bool* Who_Victory_TIME( const int number_player, Player p[5] ){
	int max = -100000 ;
	bool* winner = new bool [5] ;
	
	//initialize
	for(int i = 1 ; i <= 4 ; i++ )
		winner[i] = 0 ;
	
	for( int i = 1 ; i <= number_player ; i++ )
		if(  max < p[i].getHPY()  ){
			if( p[i].getNowStatus() == "Now Status : Alive" )
				max = p[i].getHPY() ;
		}
	
	for( int i = 1 ; i <= number_player ; i++ ){
		if( p[i].getHPY() == max )
			if( p[i].getNowStatus() == "Now Status : Alive" )
				winner[i] = 1 ;
	}
	
	return winner ;
}

//Windows

void draw_winner( const bool winner[5], Player player[5], sf::Font font ){
	sf::RenderWindow draw( sf::VideoMode(800,800), "Winner", sf::Style::Titlebar| sf::Style::Close ) ;

	float y = 50 ;			//y 座標 

	sf::Text text[5] ;

	for( int i = 1 ; i <= 4 ; i++ ){
		y+=150 ;
		text[i].setFont( font ) ;
		text[i].setPosition(260,y) ;
		text[i].setCharacterSize(80) ;
	}

	while( draw.isOpen() ){
		sf::Event event ;
	
		while( draw.pollEvent(event) ){
			if( event.type == sf::Event::Closed )
				draw.close() ;
		}

		draw.clear() ;

		sf::Text slogan( "Winner is :", font );
		slogan.setCharacterSize(100) ;
		slogan.setPosition(140,50);

		draw.draw(slogan) ;
		string ID ;

		for( int i = 1 ; i <= 4 ; i++ ){
			if( winner[i] == true ){
				ID = to_string(i) ;
				text[i].setString( "Player"+ID ) ;
				draw.draw( text[i] ) ;
			}
		}
		
		draw.display() ;
		
	}
	
}

bool is_Debt( Player player[5], int number_player ){

	for( int i = 1 ; i <= number_player ; i++ )
		if( player[i].getMoney() < 0 )
			return true ;

	return false ;
}

