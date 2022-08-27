#include"Magic.h"

Magic::Magic()
{

	deck.shuffle();
	cards = deck.grab(SIZE);
	for (size_t i = 0; i < SIZE; i++)
	{
		merged.push_back(cards[i]);
	}
}



std::vector<Card*>& Magic::get_half_one()
{
	return half_one;
}

std::vector<Card*>& Magic::get_half_two()
{
	return half_two;
}

std::vector<Card*>& Magic::get_merged()
{
	return merged;
}

void Magic::draw(std::vector<Card*>& vec)
{
	int pos_draw = 0;
	for (auto& i : vec)
	{
		i->set_pos(sf::Vector2f(50 + pos_draw, 100));
		pos_draw += 125;

	}
	
	
}



void Magic::seperate()
{
	bool helper = 1;
	
	for (size_t i = 0; i < SIZE; i++)
	{
		if (helper)
		{
			if (merged.empty())
				exit(1);
			half_one.push_back(merged.back());
			merged.pop_back();
			helper = !helper;
		}
		else
		{
			if (merged.empty())
				exit(1);
			half_two.push_back(merged.back());
			merged.pop_back();
			helper = !helper;
		}
	}

}

void Magic::shuffle()
{
	this->cards.clear();
	merged.clear();
	cards = deck.grab(SIZE);
	for (size_t i = 0; i < SIZE; i++)
	{
		merged.push_back(cards[i]);
	}
}

void Magic::merge(std::vector<Card*>& first, std::vector<Card*>& second)
{


	if (!first.empty())
	{
		std::vector<Card*> temp(first);
		std::move(second.begin(), second.end(), std::back_inserter(temp));
		merged = temp;
		first.clear();
		second.clear();
	}
	else
		exit(1);

	
}

Card& Magic::find()
{
	if (merged.empty())
		exit(1);

	return *merged[SIZE - MAGIC];
}

Magic::~Magic()
{
	

}
