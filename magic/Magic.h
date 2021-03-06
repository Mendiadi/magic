#pragma once

#ifndef MAGIC_H
#define MEGIC_H
#include"DeckOfCards.h"
#include<vector>
#include<iostream>
#include"Card.h"

class Magic
{
#define MAGIC 0x3
	static constexpr unsigned int SIZE = 8;
	DeckOfCards deck;
	std::vector<Card*> cards;
	std::vector<Card*> merged;
	std::vector<Card*> half_one;
	std::vector<Card*> half_two;
public:
	Magic();
	std::vector<Card*>& get_half_one();
	std::vector<Card*>& get_half_two();
	std::vector<Card*>& get_merged();
	void draw_all();
	void draw_half_one();
	void draw_half_two();
	void seperate();
	void merge(bool isHalfOne);
	Card& find();
	~Magic();
};

#endif // !MAGIC_H
