#include<SFML/Graphics.hpp>

void chooseImageToShow (sf::Event& event, sf::Sprite &image_on_board, sf::Texture image_on_board_texture[], bool& anyImage)
{
	if (event.mouseMove.x<180)
	{
		if (event.mouseMove.y<180)
			image_on_board.setTexture(image_on_board_texture[1]);
		else if (event.mouseMove.y<360)
			image_on_board.setTexture(image_on_board_texture[2]);
		else if (event.mouseMove.y<540)
			image_on_board.setTexture(image_on_board_texture[3]); //Q&A
		else if (event.mouseMove.y<720)
			image_on_board.setTexture(image_on_board_texture[4]);
			
		image_on_board.setPosition(1100,500);
		anyImage = true;
		
		if (event.mouseMove.y>720 &&event.mouseMove.y<900)
			anyImage = false;
	}
	else if (event.mouseMove.x<360)
	{
		if (event.mouseMove.y<180)
			image_on_board.setTexture(image_on_board_texture[3]);
		else if (event.mouseMove.y>180 && event.mouseMove.y<720)
			image_on_board.setTexture(image_on_board_texture[0]); //center of map
		else if (event.mouseMove.y>720 && event.mouseMove.y<900)
			image_on_board.setTexture(image_on_board_texture[7]);
			
		image_on_board.setPosition(1100,500);
		anyImage = true;
	}
	else if (event.mouseMove.x<540)
	{
		if (event.mouseMove.y<180)
			image_on_board.setTexture(image_on_board_texture[6]);
		else if (event.mouseMove.y>180 && event.mouseMove.y<720)
			image_on_board.setTexture(image_on_board_texture[0]); //center of map
		else if (event.mouseMove.y>720 && event.mouseMove.y<900)
			image_on_board.setTexture(image_on_board_texture[5]);
			
		image_on_board.setPosition(1100,500);
		anyImage = true;
	}
	else if (event.mouseMove.x<720)
	{
		if (event.mouseMove.y<180)
			image_on_board.setTexture(image_on_board_texture[3]);
		else if (event.mouseMove.y>180 && event.mouseMove.y<720)
			image_on_board.setTexture(image_on_board_texture[0]); //center of map
		else if (event.mouseMove.y>720 && event.mouseMove.y<900)
			image_on_board.setTexture(image_on_board_texture[8]);
		
		image_on_board.setPosition(1100,500);
		anyImage = true;
	}
	else if (event.mouseMove.x<900)
	{
		if (event.mouseMove.y<180)
			image_on_board.setTexture(image_on_board_texture[9]);
		else if (event.mouseMove.y<360)
			image_on_board.setTexture(image_on_board_texture[10]);
		else if (event.mouseMove.y<540)
			image_on_board.setTexture(image_on_board_texture[11]); //Q&A
		else if (event.mouseMove.y<720)
			image_on_board.setTexture(image_on_board_texture[12]);
		else if (event.mouseMove.y<900)
			image_on_board.setTexture(image_on_board_texture[3]);		
	
		image_on_board.setPosition(1100,500);
		anyImage = true;	
	}
	// 做類似的事情，show出對應的圖片 
	else
	{	
		anyImage = false;
	} 
}
