#pragma once

#include <string>
#include "SFML/Graphics.hpp"
#include "GameConsts.h"

/*
A first stab at Hangman
Pick a random word from the library, let the player guess the letters
They've got 7 lives (failed guesses) before death
*/
struct Game
{
	enum class Mode {
		ENTER_NAME,		//get the player's name
		WELCOME,		//game instructions
		GUESS,			//player guesses at the word
		GAME_OVER		//game is over
	};
	Mode mode = Mode::ENTER_NAME; //current mode we are in
	sf::Font font;			//only need one font
	std::string name;		//player name
	char key = GC::NO_KEY;		//current key press 

	//set things up once at the start
	void Init();
	//update the logic
	void Update(sf::RenderWindow& window);
	//render what we can see
	void Render(sf::RenderWindow& window);
	//check what the player is typing
	void HandleInput(sf::Uint32 key_, sf::RenderWindow& window);

	//ask the use what their name is
	void RenderEnterName(sf::RenderWindow& window);
	//start the game as soon as they've typed a name and press enter
	void UpdateEnterName();
	//every screen has the game name on the top	
	void ShowTitle(sf::RenderWindow& window);
};

