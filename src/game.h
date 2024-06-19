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
	int squareSide;

public:
	Game(int worldWidth, int worldHeight, int squareSide); 
	
	void draw(sf::RenderWindow& window);
};