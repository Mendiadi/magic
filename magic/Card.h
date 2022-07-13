#pragma once

#ifndef CARD_H
#define CARD_H
#include<SFML/Graphics.hpp>


enum class CardSuit
{
	Hearts,
	Spades,
	Diamonds,
	Clubs
};

enum class CardName
{

	two = 2,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	jack,
	queen,
	king,
	ace
};



class Card
{
public:
	CardSuit suit;
	CardName name;
	sf::Image image;
	sf::Sprite sprite;
	sf::Texture texture;
	std::string str;
	Card(CardSuit suit, CardName name);

	void texture_make(const std::string& path);
	sf::Sprite& display();
	void set_pos(const sf::Vector2f&);
};


#endif // !CARD_H
