#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

enum SquareType {
	DEAD,
	ALIVE
};

class Game {
private:
	std::vector<std::vector<SquareType>> squares;
	SquareType* selected;
	int squareSide;

	bool hasStarted;

	sf::Clock timer;

public:
	Game(int worldWidth, int worldHeight, int squareSide); 
	
	void handleEvent(sf::Event event);
	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
};