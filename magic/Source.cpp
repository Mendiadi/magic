#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include<SFML/Graphics.hpp>
#include"Card.h"
#include"DeckOfCards.h"
#include"Magic.h"
#include"Application.h"



int main()
{
	Magic* magic = new Magic;
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1100,700), "Magic");
	Application::run(*window,*magic);
	delete magic; delete window;

	return EXIT_SUCCESS;
}









