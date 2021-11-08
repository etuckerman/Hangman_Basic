#include <assert.h>
#include <string>

#include "SFML/Graphics.hpp"

#include "Game.h"

using namespace std;
using namespace sf;



int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(GC::SCREEN_RES.x, GC::SCREEN_RES.y), "Hangman");

	sf::Font font;
	if (!font.loadFromFile("data/fonts/comic.ttf"))
		assert(false);

	Game game;
	game.Init();
	// Start the game loop 
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed) 
				window.close();
			if (event.type == sf::Event::TextEntered)
				game.HandleInput(event.text.unicode, window);
		} 

		// Clear screen
		window.clear();

		game.Update(window);
		game.Render(window);
		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
}
