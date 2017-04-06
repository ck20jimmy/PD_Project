#include <SFML/Graphics.hpp>
#include<string>
using namespace std;
class Tip_acronym
{
public:
	Tip_acronym()
	{
		if(!font.loadFromFile("fontfile3.ttf"))
		{
			cout << "Error in tip acronym" << endl;
		}
		
		text_firstline.setCharacterSize(30);
		text_firstline.setFont(font);
		text_firstline.setColor(sf::Color::White);
		text_firstline.setPosition(125, 224);//205
		
		text_firstline_add.setCharacterSize(30);
		text_firstline_add.setFont(font);
		text_firstline_add.setColor(sf::Color::White);
		text_firstline_add.setPosition(125, 264);//205
		
		text_secondline.setCharacterSize(30);
		text_secondline.setFont(font);
		text_secondline.setColor(sf::Color::Yellow);
		text_secondline.setPosition(128, 432);//208
		
		text_thirdline.setCharacterSize(30);
		text_thirdline.setFont(font);
		text_thirdline.setColor(sf::Color::Magenta);
		text_thirdline.setPosition(128, 535);//208
	}
	~Tip_acronym()
	{
	}
	void draw(sf::RenderWindow &window)
	{
		window.draw(text_firstline);
		window.draw(text_firstline_add);
		window.draw(text_secondline);
		window.draw(text_thirdline);
	}
	void setString(const string &str1, const string &str2, const string &str3)
	{
		text_firstline.setString(str1);
		text_secondline.setString(str2);
		text_thirdline.setString(str3);
	}
	void setString(const string &str1, const string &stradd, const string &str2, const string &str3)
	{
		text_firstline.setString(str1);
		text_firstline_add.setString(stradd);
		text_secondline.setString(str2);
		text_thirdline.setString(str3);
	}
private:
	string firstline;
	string secondline;
	string thirdline;
	sf::Text text_firstline;
	sf::Text text_firstline_add;
	sf::Text text_secondline;
	sf::Text text_thirdline;
	sf::Font font;
};
