#include"Card.h"


Card::Card(CardSuit suit, CardName name)
{

	switch (suit)
	{
	case CardSuit::Clubs:
		if ((int)name > 10)
		{
			if ((int)name == 11)
			{
				str = "clubs_J";
			}
			if ((int)name == 12)
			{
				str = "clubs_Q";
			}
			if ((int)name == 13)
			{
				str = "clubs_K";
			}
			if ((int)name == 14)
			{
				str = "clubs_A";
			}
		}
		else { str = "clubs_" + std::to_string((int)name); }
		str = str + ".png";
		break;
	case CardSuit::Hearts:
		if ((int)name > 10)
		{
			if ((int)name == 11)
			{
				str = "hearts_J";
			}
			if ((int)name == 12)
			{
				str = "hearts_Q";
			}
			if ((int)name == 13)
			{
				str = "hearts_K";
			}
			if ((int)name == 14)
			{
				str = "hearts_A";
			}
		}
		else { str = "hearts_" + std::to_string((int)name); }
		str = str + ".png";
		break;
	case CardSuit::Diamonds:
		if ((int)name > 10)
		{
			if ((int)name == 11)
			{
				str = "diamonds_J";
			}
			if ((int)name == 12)
			{
				str = "diamonds_Q";
			}
			if ((int)name == 13)
			{
				str = "diamonds_K";
			}
			if ((int)name == 14)
			{
				str = "diamonds_A";
			}
		}
		else { str = "diamonds_" + std::to_string((int)name); }
		str = str + ".png";
		break;
	case CardSuit::Spades:

		if ((int)name > 10)
		{
			if ((int)name == 11)
			{
				str = "spades_J";
			}
			if ((int)name == 12)
			{
				str = "spades_Q";
			}
			if ((int)name == 13)
			{
				str = "spades_K";
			}
			if ((int)name == 14)
			{
				str = "spades_A";
			}
		}
		else { str = "spades_" + std::to_string((int)name); }
		str = str + ".png";
		break;
	default:
		str = "adi";
		break;
	}
}


void Card::texture_make(const std::string& path)
{

	image.loadFromFile(path);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(0.5f, 0.5f));

}

sf::Sprite& Card::display() 
{
	return sprite;
}

void Card::set_pos(const sf::Vector2f& pos)
{
	sprite.setPosition(pos);
}
