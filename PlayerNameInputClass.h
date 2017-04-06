#include <SFML/Graphics.hpp>
#include<string>
using namespace std;
class PlayerNameInputClass
{
public:
	PlayerNameInputClass(float width , float height);
	~PlayerNameInputClass();
	void draw(sf::RenderWindow &window, int which_player, string inputstr);
	
private:
	int Which_Player;
	sf::Text inputtextbox;
	sf::Text slogan;
	sf::Text slogan2; //Press enter to continue
	sf::Text slogan3; // Please input your player name( You can use backspace)
	sf::Font font;
	sf::Font font2;
	sf::RectangleShape box;
	sf::Texture pTexture[5];
	sf::Sprite pSprite[5]; 
	sf::Texture test[10];
};
