#include <SFML/Graphics.hpp>
#include<string>
#include "Player.h"
using namespace std;
class Game
{
public:
	Game(){
		
	};
	~Game();
	void Move_Player(Player &Player);
	void Event_happen();
	void draw_now_player();
	void draw_PressEntertoContinue(sf::RenderWindow &window);
private:
	int which_player_is_playing;
	int how_many_player_we_have;
	int dice_number;
	sf::Text PressEntertoContinue;
	sf::Font font;
	
}
