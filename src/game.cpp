#include "game.h"

Game::Game(int worldWidth, int worldHeight, int squareSide) : squares((int)(worldHeight / squareSide)) {
	this->squareSide = squareSide;

	for (std::vector<SquareType>& row : squares) {
		row.resize((int)(worldWidth / squareSide));
		std::cout << (int)(worldHeight / squareSide) << std::endl;
	}

	for (int y = 0; y < (int)(worldHeight / squareSide); y++) {
		for (int x = 0; x < (int)(worldWidth / squareSide); x++) {
			squares[y][x] = DEAD;
		}
	}
}

void Game::draw(sf::RenderWindow& window) {
	for (int y = 0; y < squares.size(); y++) {
		for (int x = 0; x < squares[y].size(); x++) {
			sf::RectangleShape shape(sf::Vector2f(squareSide, squareSide));
			shape.setPosition(x * squareSide, y * squareSide);
			shape.setFillColor(sf::Color(0xCCCCCCCC));
			window.draw(shape);
		}
	}
}