#pragma once

#include "stdafx.h"
#include "sheet.h"

class GameOverScene
{
public:
	GameOverScene(Assets & assets, sf::View & view, SoundHandler & soundHandler, std::function<uint64_t()> getter);
	~GameOverScene();
	SGameResult onGameOverMenu(sf::RenderWindow & window);
private:
	void render(sf::RenderWindow & window) const;
	void checkEvents(sf::RenderWindow & window);
	void checkMouseOnButtons(sf::Vector2i mousePosition);
	void checkMouseClick(sf::Event & event);
	void saveRecord();
	std::function<uint64_t()> m_getter;

	Assets & m_assets;
	sf::View & m_view;
	SoundHandler & m_soundHandler;

	std::unique_ptr<sf::Sprite> m_background;
	std::unique_ptr<sf::Sprite> m_title;

	std::unique_ptr<Button> m_playAgainButton;
	std::unique_ptr<Button> m_goMenuButton;

	uint64_t m_score;
	sf::Text m_lastRecord;

	SGameResult m_result;

	MasterAPI m_api;
};
