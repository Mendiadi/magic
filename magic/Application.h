#pragma once


#ifndef APPLICATION_H
#define APPLICATION_H
#include<SFML/Graphics.hpp>
#include<vector>
#include"Magic.h"
enum class State
{
	stepOne,
	stepTwo,
	stepThree,
	initStep
};
class Application
{
	
public:

	static void draw( sf::RenderWindow& win, std::vector<sf::Drawable* >&)  ;
	static void run(sf::RenderWindow& window,Magic& magic);

	static void eventProcess(
		sf::RenderWindow& window,
		sf::Event& ev,
		Magic& magic,
		int& update,
		int& count,
		bool& once
	);
	~Application();
};


#endif // !APPLICATION_H



