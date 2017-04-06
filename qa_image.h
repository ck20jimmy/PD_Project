#include<SFML/Graphics.hpp>
#include <time.h>
#include<string>

void show_qa(sf::Sprite &qa, sf::Texture qa_texture[], char &answer)
{
	int number = rand() ;
	switch(number%5)
	{
		case 0:
			qa.setTexture(qa_texture[1]);
			answer = 'C' ;
			break;
		case 1:
			qa.setTexture(qa_texture[2]);
			answer = 'C' ;
			break;
		case 2:
			qa.setTexture(qa_texture[3]);
			answer = 'C' ;
			break;
		case 3:
			qa.setTexture(qa_texture[4]);
			answer = 'C' ;
			break;
		case 4:
			qa.setTexture(qa_texture[5]);
			answer = 'B' ;
			break;
	}
	qa.setPosition(0,0);
}
