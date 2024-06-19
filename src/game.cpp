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
	
	selected = nullptr;
}

void Game::handleEvent(sf::Event event) {
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			*selected = (SquareType)(!*selected);
		}
	}
}

void Game::update(sf::RenderWindow& window) {
	sf::Vector2i position = sf::Mouse::getPosition(window);

	selected = &squares[(int)(position.y / squareSide)][(int)(position.x / squareSide)];

	if (hasStarted) {
		for (int y = 0; y < squares.size(); y++) {
			for (int x = 0; x < squares[y].size(); x++) {
				int livingNeighbors = 0;

				if (x - 1 >= 0) {
					if (squares[y][x - 1]) {
						
					}
				}
			}
		}
	}
}

void Game::draw(sf::RenderWindow& window) {
	for (int y = 0; y < squares.size(); y++) {
		for (int x = 0; x < squares[y].size(); x++) {
			sf::RectangleShape shape(sf::Vector2f(squareSide, squareSide));
			shape.setPosition(x * squareSide, y * squareSide);

			if (selected != nullptr && selected == &squares[y][x]) {
				shape.setFillColor(sf::Color(0x999999FF));
			} else if (squares[y][x] == DEAD) {
				shape.setFillColor(sf::Color(0x1a1919FF));
			} else if (squares[y][x] == ALIVE) {
				shape.setFillColor(sf::Color(0x0dde23FF));
			}

			window.draw(shape);
		}
	}
}