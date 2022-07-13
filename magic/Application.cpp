#include "Application.h"




void Application::draw(sf::RenderWindow& win, std::vector<sf::Drawable*>& objects)
{
	win.clear(sf::Color::Green);
	
	for (auto& i: objects)
	{
		win.draw(*i);

	}
	objects.clear();
	win.display();
}

void Application::run(sf::RenderWindow& window,Magic& magic)
{
	bool once = 1;
	static int count = 0;
	int updater = 0;
	std::vector<sf::Drawable*> to_draw;
	sf::Font font;
	sf::Text text;
	State state = State::initStep;
	while (window.isOpen())
	{
		sf::Event events;
		if (updater == 0 && once)
		{
			if (!font.loadFromFile("arial.ttf"))
			{
				exit(1);
			}
			text.setFont(font);
			text.setString("Think of one Card and remember it");
			text.setPosition(sf::Vector2f(350, 500));
			text.setStyle(sf::Text::Style::Bold);
			text.setFillColor(sf::Color::Blue);
			to_draw.push_back(&text);
			for (auto& i : magic.get_merged())
			{
				to_draw.push_back(&i->display());
			}
			magic.draw_all();
			Application::draw(window, to_draw);
			once = 0;
		}
		if (updater == 1 && count < 4)
		{
			magic.seperate();
			text.setString("Your Card is one of them? (y) or (n)");
			to_draw.push_back(&text);
			for (auto& i : magic.get_half_one())
			{
				to_draw.push_back(&i->display());
			}
			magic.draw_half_one();
			Application::draw(window, to_draw);
			updater = -1;
		}
		if (count == 4)
		{
			text.setString("This is your Card? (Press ESC to exit)");
			to_draw.push_back(&text);
			to_draw.push_back(&magic.find().display());
			Application::draw(window, to_draw);
			
		}
	
		Application::eventProcess(window, state, events, to_draw, magic, text, font, updater, count);
	}
}

void Application::eventProcess(sf::RenderWindow& window, State& state, sf::Event& ev,
	std::vector<sf::Drawable*>& objets,Magic& magic,sf::Text& text,sf::Font& font,int& update,int& count)
{

	while (window.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
		{
			window.close();
			break;
		}
		if (ev.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				update = 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
			{
				magic.merge(0);
				count++;
				update = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
			{
				magic.merge(1);
				count++;
				update = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				exit(0);
				break;
			}
		}
	}
}
