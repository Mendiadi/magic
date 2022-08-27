#pragma once

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H
#include"DeckOfCards.h"
#include<vector>
#include<iostream>
#include"Card.h"
class DeckOfCards
{
	static constexpr unsigned int DECK_SIZE = 52;
	std::vector<Card*> cards;
public:
	DeckOfCards();
	void sort();
	void shuffle();
	std::vector<Card*> grab(const size_t amount);
	void print() const;
	~DeckOfCards();
};





#endif // !DECKOFCARDS_H
