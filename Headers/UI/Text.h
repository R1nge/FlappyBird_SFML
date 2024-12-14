#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
class Text
{
public:
	Text(std::string text, float parentWidth, float parentHeight);
	void setPostion(int x, int y);
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f position);
	void setPosition();
	void setFont(sf::Font font);
	void setFillColor(sf::Color color);
	void setText(std::string text);
	void setCharacterSize(int size);
	void setOrigin(int x, int y);
	void setOrigin(float x, float y);
	void setOrigin(sf::Vector2f position);
private:
	sf::Font _font;
	sf::Color _color;
	sf::Text _text;
	std::string _textString;
	int _characterSize;
};

