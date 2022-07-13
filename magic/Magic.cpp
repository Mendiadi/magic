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

void Magic::draw_all(sf::RenderWindow& win)
{
	win.clear(sf::Color::Black);
	for (size_t i = 0; i < SIZE; i++)
	{
		win.draw(merged[i]->display());
	}
	win.display();
}

void Magic::draw_half_one(sf::RenderWindow& win)
{
	win.clear(sf::Color::Black);
	for (size_t i = 0; i < SIZE / 2; i++)
	{
		win.draw(half_one[i]->display());
	}
	win.display();
}

void Magic::draw_half_two(sf::RenderWindow& win)
{
	win.clear(sf::Color::Black);
	for (size_t i = 0; i < SIZE / 2; i++)
	{
		win.draw(half_two[i]->display());
	}
	win.display();
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

void Magic::merge(bool isHalfOne)
{
	if (isHalfOne)
	{
		if (!half_two.empty())
		{
			std::vector<Card*> temp(half_one);
			std::move(half_two.begin(), half_two.end(), std::back_inserter(temp));
			merged = temp;
			half_one.clear();
			half_two.clear();
		}
		else
			exit(1);
	}
	else
	{
		if (!half_one.empty())
		{
			std::vector<Card*> temp(half_two);
			std::move(half_one.begin(), half_one.end(), std::back_inserter(temp));
			merged = temp;
			half_one.clear();
			half_two.clear();
		}
		else
			exit(1);
	}
}

Card& Magic::find()
{
	if (merged.empty())
		exit(1);

	return *merged[SIZE - MAGIC];
}

Magic::~Magic()
{

	for (auto& i : cards)
	{
		delete i;
	}
}
