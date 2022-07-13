#include"DeckOfCards.h"


DeckOfCards::DeckOfCards()
{
	int index = 0;
	std::string path = "D:\\c++_visual\\magic\\magic\\assets\\";
	for (size_t i = (size_t)CardSuit::Hearts; i <= (size_t)CardSuit::Clubs; i++)
	{
		for (size_t j = (size_t)CardName::two; j <= (size_t)CardName::ace; j++)
		{
			Card* c = new Card((CardSuit)i, (CardName)j);
			if (c->str != "adi")
				c->texture_make(path + c->str);
			cards.push_back(c);
			index++;
		}
	}
}


void DeckOfCards::shuffle()
{
	srand(time(NULL));
	for (int i = 0; i < DECK_SIZE; i++)
	{
		int index = rand() % DECK_SIZE;
		Card* temp = cards[i];
		cards[i] = cards[index];
		cards[index] = temp;
	}
}

void DeckOfCards::sort()
{

	for (size_t i = 0; i < DECK_SIZE; i++)
	{
		for (size_t j = i + 1; j < DECK_SIZE - 1; j++)
		{
			if ((int)cards[i]->name > (int)cards[j]->name)
			{
				std::swap(cards[i], cards[j]);
			}
		}

	}
}

inline void DeckOfCards::print() const
{
	for (size_t i = 0; i < DECK_SIZE; i++)
	{
		std::cout << cards[i] << "\n";
	}
}

DeckOfCards::~DeckOfCards()
{
	for (size_t i = 0; i < DECK_SIZE; i++)
	{
		delete cards[i];
	}
}

std::vector<Card*> DeckOfCards::grab(size_t amount = 1)
{
	if (amount > DECK_SIZE)
		exit(1);

	cards.resize(amount);
	return cards;
}