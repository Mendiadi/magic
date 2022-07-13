#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
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
	Card(CardSuit suit , CardName name);
	Card();
	void texture_make(const std::string& path);
	const sf::Sprite& display() const;
	void set_pos(const sf::Vector2f&);
};



class DeckOfCards
{
	static constexpr unsigned int DECK_SIZE = 52;
	std::vector<Card*> cards;
public:
	DeckOfCards();
	void sort();
	void shuffle();
	std::vector<Card*> grab(size_t amount);
	void print() const;
	~DeckOfCards();
};

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
	std::vector<Card*>& get_half_one() ;
	std::vector<Card*>& get_half_two() ;
	std::vector<Card*>& get_merged()  ;
	void draw_all(sf::RenderWindow& win);
	void draw_half_one(sf::RenderWindow& win);
	void draw_half_two(sf::RenderWindow& win);
	void seperate();
	void merge(bool isHalfOne);
	
	Card& find();
	~Magic();
};




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




DeckOfCards::DeckOfCards()
{
	int index = 0;
	std::string path = "D:\\c++_visual\\magic\\magic\\assets\\";
	for (size_t i = (size_t)CardSuit::Hearts; i <= (size_t)CardSuit::Clubs; i++)
	{
		for (size_t j = (size_t)CardName::two; j <= (size_t)CardName::ace; j++)
		{
			Card* c = new Card((CardSuit)i, (CardName)j);
			if(c->str != "adi")
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
	
	for (size_t i = 0; i < amount; i++)
	{
		cards.resize(8);
	}
	return cards;
}

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
	for (size_t i = 0; i < SIZE/2; i++)
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
inline Magic::~Magic()
{

	for (auto& i : cards)
	{
		delete i;
	}
}

Card::Card(CardSuit suit,CardName name)
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

const sf::Sprite& Card::display() const
{
	return sprite;
}

void Card::set_pos(const sf::Vector2f& pos)
{
	sprite.setPosition(pos);
}





