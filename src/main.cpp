#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
	sf::RenderWindow window = sf::RenderWindow{ { 640, 480 }, "CMake SFML Project" };
	window.setFramerateLimit(60);

	sf::View view(sf::Vector2f(640 / 2, 480 / 2), sf::Vector2f(640, 480));
	window.setView(view);

	Game game(640, 480, 16);

	while (window.isOpen())
	{
		for (sf::Event event = sf::Event{}; window.pollEvent(event);)
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			game.handleEvent(event);
		}

		window.clear();
		game.update(window);
		game.draw(window);
		window.display();
	}
}
