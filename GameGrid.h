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
		
		text_firstline.setCharacterSize(20);
		text_firstline.setFont(font);
		text_firstline.setColor(sf::Color::White);
		text_firstline.setPosition(205, 224);
		
		text_secondline.setCharacterSize(20);
		text_secondline.setFont(font);
		text_secondline.setColor(sf::Color::White);
		text_secondline.setPosition(208, 432);
		
		text_thirdline.setCharacterSize(20);
		text_thirdline.setFont(font);
		text_thirdline.setColor(sf::Color::White);
		text_thirdline.setPosition(208, 535);
	}
	~Tip_acronym();
	Tip_acronym.draw(sf::RenderWindow &window)
	{
		
	}
	Tip_acronym.setString(const string &str1, const string &str2, const string &str3)
	{
		
	}
private:
	string firstline;
	string secondline;
	string thirdline;
	sf::Text text_firstline;
	sf::Text text_secondline;
	sf::Text text_secondline;
	sf::Font font;
};
