#ifndef SFML_GRAPHICS_HPP
#include "SFML/Graphics.hpp"
#endif
#include <vector>

namespace font {
	unsigned int width = 8,
				 height = 16;
	sf::Texture fontTex;
}

class unsignedString {
	std::vector <unsigned char> data;

public:
	unsignedString(std::string initStr) {
		for(unsigned int n = 0; n < initStr.size(); ++n) {
			data.push_back(initStr[n]);
		}
	}

	unsignedString(unsigned char initChar) :
	data(1, initChar)
	{}

	unsignedString() {}

	void operator+=(std::string str) {
		for(unsigned int n = 0; n < str.size(); ++n) {
			data.push_back(str[n]);
		}
	}

	void operator+=(unsigned char c) {
		data.push_back(c);
	}

	void clear() {
		data.clear();
	}

	size_t size() {
		return data.size();
	}

	unsigned char operator[](size_t pos) {
		return data.at(pos);
	}

	bool empty() {
		return data.empty();
	}
};

void write(unsignedString str, float textX, float textY, bool shadowing, sf::Color textColor = sf::Color::White){
	if(str.empty())
		return;
	unsigned int collumn = 0,
				 row = 0,
				 thisVertex = 0;
	sf::VertexArray fontVArray(sf::Quads, str.size() * 4 * (1 + shadowing));
	for (unsigned int n = 0; n < str.size(); ++n) {
		switch(str[n]) {
		case '\n':
			collumn = 0;
			++row;
			break;
		case ' ':
			++collumn;
			break;
		default:
			if(shadowing) {
				fontVArray[thisVertex  ].position  = sf::Vector2f(textX + (collumn * font::width) + 1, textY + (row * font::height) + 1);
				fontVArray[thisVertex  ].texCoords = sf::Vector2f(str[n] * font::width, 0);
				fontVArray[thisVertex++].color     = sf::Color(0, 0, 0, textColor.a);
				fontVArray[thisVertex  ].position  = sf::Vector2f(textX + (collumn * font::width) + font::width + 1, textY + (row * font::height) + 1);
				fontVArray[thisVertex  ].texCoords = sf::Vector2f(str[n] * font::width + font::width, 0);
				fontVArray[thisVertex++].color     = sf::Color(0, 0, 0, textColor.a);
				fontVArray[thisVertex  ].position  = sf::Vector2f(textX + (collumn * font::width) + font::width + 1, textY + (row * font::height) + font::height + 1);
				fontVArray[thisVertex  ].texCoords = sf::Vector2f(str[n] * font::width + font::width, font::height);
				fontVArray[thisVertex++].color     = sf::Color(0, 0, 0, textColor.a);
				fontVArray[thisVertex  ].position  = sf::Vector2f(textX + (collumn * font::width) + 1, textY + (row * font::height) + font::height + 1);
				fontVArray[thisVertex  ].texCoords = sf::Vector2f(str[n] * font::width, font::height);
				fontVArray[thisVertex++].color     = sf::Color(0, 0, 0, textColor.a);
			}
			fontVArray[thisVertex  ].position  = sf::Vector2f(textX + (collumn * font::width), textY + (row * font::height));
			fontVArray[thisVertex  ].texCoords = sf::Vector2f(str[n] * font::width, 0);
			fontVArray[thisVertex++].color     = textColor;
			fontVArray[thisVertex  ].position  = sf::Vector2f(textX + (collumn * font::width) + font::width, textY + (row * font::height));
			fontVArray[thisVertex  ].texCoords = sf::Vector2f(str[n] * font::width + font::width, 0);
			fontVArray[thisVertex++].color     = textColor;
			fontVArray[thisVertex  ].position  = sf::Vector2f(textX + (collumn * font::width) + font::width, textY + (row * font::height) + font::height);
			fontVArray[thisVertex  ].texCoords = sf::Vector2f(str[n] * font::width + font::width, font::height);
			fontVArray[thisVertex++].color     = textColor;
			fontVArray[thisVertex  ].position  = sf::Vector2f(textX + (collumn * font::width), textY + (row * font::height) + font::height);
			fontVArray[thisVertex  ].texCoords = sf::Vector2f(str[n] * font::width, font::height);
			fontVArray[thisVertex++].color     = textColor;
			++collumn;
			break;
		}
	}
	fontVArray.resize(thisVertex);
	data::window.draw(fontVArray, &font::fontTex);
}