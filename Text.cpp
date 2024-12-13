#include "Text.h"

Text::Text(std::string text, float parentWidth, float parentHeight)
{
	_text = sf::Text();
	_text.setFont(_font);
	_text.setFillColor(sf::Color::White);
	_textString = text;
	_text.setString(text);
	sf::FloatRect bounds = _text.getLocalBounds();

	float maxHeight = 0;
	float currentHeight = 0;
	for (size_t characterIndex = 0; characterIndex < _textString.size(); ++characterIndex)
	{
		currentHeight = _font.getGlyph(_textString[characterIndex], 12, false).bounds.height;
		if (currentHeight > maxHeight)
		{
			maxHeight = currentHeight;
		}
	}

	_text.setOrigin(bounds.width / 2, maxHeight / 2);
	_text.setPosition(parentWidth / 2, (parentHeight / 2) - maxHeight * 1.5);
}
