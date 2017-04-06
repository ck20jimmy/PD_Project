#include <SFML/Graphics.hpp>
#include<string>
using namespace std;
class Player
{
public:
	Player();
	~Player();
	void create(float width, float height,const string &playername,int ID);
	void draw(sf::RenderWindow &window, int now_player);
	void draw_playerChessman(sf::RenderWindow &window);
	void setPosition(sf::Sprite &GameBoard);
	void setPosition(sf::Sprite &GameBoard, sf::Sprite &previousSprite);
	sf::Sprite& getSprite() { return pSprite;};
	// For gamestart
	void move_playerChessman(const int dice_number, const sf::Vector2f vector[17], const int now_playing);
	int getMoney(){ return money;};
	void setMoney(int money_changed){ money = money + money_changed;};
	int getHPY(){ return happiness;};
	void setHPY(int hpy_changed){ happiness = happiness + hpy_changed;};
	
	void setNowStatus( string now_status ){ this->now_status = now_status ; }
	string getNowStatus(){ return this->now_status ; }
	
	void setStatusText(){ status_text.setString( this->getNowStatus() ) ; }


	int getGrid(){ return now_Grid;};
	
	void learn_to_play_guitar(){ guitar_skill = true;};
	void learn_to_play_drum(){ drum_skill = true;};
	void learn_to_sing(){ sing_skill = true;};
	void become_guitar_club_member(){ guitar_club_member = true;};
	bool getguitarskill(){ return guitar_skill;};
	bool getdrum_skill(){ return drum_skill;};
	bool getsing_skill(){ return sing_skill;};
	bool getguitar_club_member() { return guitar_club_member;};
private:
	int ID; // from 1 to 4
	int money;
	int happiness;
	int status; // if he was jailed
	int now_Grid;
	bool guitar_skill;
	bool drum_skill;
	bool sing_skill;
	bool guitar_club_member;
	string player_name;
	string now_status;
	string now_money;
	string now_happiness;
	sf::Text text_name; // player name
	sf::Text money_text; // money text
	sf::Text happiness_text;
	sf::Text status_text; // if he was jailed
	sf::Font font;
	sf::Font font_two; 
	sf::Texture pTexture;
	sf::Sprite pSprite;
	sf::Texture pChessTxt;
	sf::Sprite pChessSpr;
	sf::Texture pointer;
	sf::Sprite pointerSpr;
};
