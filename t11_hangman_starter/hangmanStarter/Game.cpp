#include <assert.h>

#include "Game.h"

using namespace std;
using namespace sf;

void Game::Init()
{
	srand(0);
	if (!font.loadFromFile("data/fonts/comic.ttf"))
		assert(false);
}

void Game::HandleInput(Uint32 key_, RenderWindow& window)
{
	key = key_;
	if (key == GC::ESCAPE_KEY)
		window.close();
	if (mode==Mode::ENTER_NAME && (isdigit(key) || isalpha(key)))
		name += static_cast<char>(key);
}

void Game::Update(RenderWindow& window)
{
	switch (mode)
	{
	case Mode::ENTER_NAME:
		UpdateEnterName();
		break;
	case Mode::WELCOME:
		break;
	case Mode::GUESS:
		break;
	case Mode::GAME_OVER:
		break;
	default:
		assert(false);
	}
}

void Game::UpdateEnterName()
{
	if (key == GC::ENTER_KEY && !name.empty())
		mode = Mode::WELCOME;
}

//ask the use what their name is
void Game::RenderEnterName(RenderWindow& window)
{
	string msg = "Enter your name (press return): ";
	msg += name;
	Text txt2(msg, font, 20);
	txt2.setPosition(window.getSize().x * 0.2f, window.getSize().y * 0.1f);
	window.draw(txt2);
}

void Game::ShowTitle(RenderWindow& window)
{
	Text txt("Hangman", font, 30);
	txt.setFillColor(Color::White);
	txt.setOutlineColor(Color::Red);
	txt.setOutlineThickness(5);
	txt.setPosition(window.getSize().x * 0.2f, window.getSize().y * 0.05f);
	window.draw(txt);
}

void Game::Render(RenderWindow& window)
{
	ShowTitle(window);
	switch (mode)
	{
	case Mode::ENTER_NAME:
		RenderEnterName(window);
		break;
	case Mode::WELCOME:
		break;
	case Mode::GUESS:
		break;
	case Mode::GAME_OVER:
		break;
	default:
		assert(false);
	}
	key = 0;
}
