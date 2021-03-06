#include "stdafx.h"
#include "sheet.h"

HelpScene::HelpScene(Assets & assets, sf::View & view, SoundHandler & soundHandler)
	:m_assets(assets)
	,m_view(view)
	,m_soundHandler(soundHandler)
{	
	m_goMenuButton = std::make_unique<Button>("Back", sf::Vector2f(232.f, 182.f), m_assets);

	m_buttonA = std::make_unique<sf::Sprite>();
	m_buttonA->setTexture(m_assets.BUTTON_A_TEXTURE);
	m_buttonA->setScale(sf::Vector2f(0.5f, 0.5f));
	m_buttonA->setPosition(170.f, 295.f);

	m_buttonD = std::make_unique<sf::Sprite>();
	m_buttonD->setTexture(m_assets.BUTTON_D_TEXTURE);
	m_buttonD->setScale(sf::Vector2f(0.5f, 0.5f));
	m_buttonD->setPosition(230.f, 295.f);
	
	m_helpText1.setFont(m_assets.ARIAL_FONT);
	m_helpText1.setCharacterSize(20);
	m_helpText1.setString("Press");
	m_helpText1.setStyle(sf::Text::Bold);
	m_helpText1.setPosition(100.f, 300.f);
	m_helpText1.setFillColor(sf::Color(0, 0, 0));

	m_helpText2.setFont(m_assets.ARIAL_FONT);
	m_helpText2.setCharacterSize(20);
	m_helpText2.setString("to move Doodle");
	m_helpText2.setStyle(sf::Text::Bold);
	m_helpText2.setPosition(290.f, 300.f);
	m_helpText2.setFillColor(sf::Color(0, 0, 0));

	m_background = std::make_unique<sf::Sprite>();
	m_background->setTextureRect(sf::IntRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
	m_background->setTexture(m_assets.BACKGROUND_TEXTURE);
	m_background->setPosition(0.f, 0.f);
}

HelpScene::~HelpScene()
{

}

SGameResult HelpScene::onHelpMenu(sf::RenderWindow & window)
{
	clearResult();

	checkEvents(window);
	render(window);
	window.display();
	return m_result;
}

void HelpScene::clearResult()
{
	m_result.status = GameStatus::HELP_SCENE;
}

void HelpScene::render(sf::RenderWindow & window) const
{
	window.clear();
	window.draw(*m_background);
	m_goMenuButton->draw(window);
	window.draw(m_helpText1);
	window.draw(m_helpText2);
	window.draw(*m_buttonA);
	window.draw(*m_buttonD);
}

void HelpScene::checkEvents(sf::RenderWindow & window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		checkMouseOnButtons(sf::Mouse::getPosition(window));
		checkMouseClick(window, event);
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void HelpScene::checkMouseOnButtons(sf::Vector2i mousePosition)
{
	m_goMenuButton->onMouse(mousePosition);
}

void HelpScene::checkMouseClick(sf::RenderWindow & window, sf::Event & event)
{
	(void)window;
	if (m_goMenuButton->onClick(event))
	{
		m_result.status = GameStatus::START_SCENE;
	}
}
