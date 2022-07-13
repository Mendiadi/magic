#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include<SFML/Graphics.hpp>
#include"Card.h"
#include"DeckOfCards.h"
#include"Magic.h"






int main()
{
	Magic magic;
	sf::RenderWindow window(sf::VideoMode(1100,700), "sfml work");
	int pos_draw = 1;
	bool step_one = 1,step_two = 1;
	for (auto& i : magic.get_merged())
	{
		i->set_pos(sf::Vector2f(50 + pos_draw, 100));
		pos_draw += 125;

	}
	while (window.isOpen())
	{
		sf::Event events;
		while (window.pollEvent(events))
		{
			if (events.type == sf::Event::Closed)
			{
				window.close();
				break;
			}
		}
		if (step_one) {
			magic.draw_all(window);
			std::cin.get();
			step_one = 0;
		}
		if (step_two)
		{
			for (int i = 0; i < 4; i++)
			{
				int a = 0;
				magic.seperate();
				magic.draw_half_one(window);
				std::cin >> a;

				if (a == 2)
				{
					magic.merge(0);
				}
				else {
					magic.merge(1);
				}
			}
			step_two = false;
		}
		window.clear(sf::Color::Black);
		window.draw(magic.find().display());
		window.display();
	}
	

	
	return EXIT_SUCCESS;
}









