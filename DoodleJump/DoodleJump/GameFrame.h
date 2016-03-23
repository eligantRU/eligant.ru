#pragma once

#include "stdafx.h"
#include "sheet.h"

struct gameScene
{
public:
	gameScene();
	~gameScene();
	gameResult onGameFrame(sf::RenderWindow & window);
private:
	Bonus bonus[NUMBER_BONUSES];
	Plate plate[NUMBER_PLATES];
	Doodle hero;
	sf::Sprite * hole;
	bool endOfGame;
	void render(sf::RenderWindow & window);
	void initBonuses(void);
	void moveBonuses(void);
	void generBonuses(void);
	void update(sf::RenderWindow & window);
	void keyPressed(sf::RenderWindow & window);
	float checkDoodleFall(void);
	void dropUnstablePlates(void);
	void generHole(void);
	bool checkGameEnd(void);
	void checkCylinderEffect(sf::Vector2f & doodlePosition);
	Collision checkCollisionPlate(sf::Vector2f & doodlePosition, sf::Vector2f platePosition[NUMBER_PLATES]);
	Collision checkCollisionBonus(sf::Vector2f & doodlePosition, sf::Vector2f bonusPosition[NUMBER_PLATES]);
	Collision checkCollisionHole(sf::Vector2f & doodlePosition);
	void buildBonus(BonusType bonusType, int bonusIndex, sf::Vector2f platePosition, int plateIndex);
	void moveDynamicPlates(void);
	void generPlates(void);
	int qwerty; // TODO: What? R u crazy?
	sf::Text text;
	uint64_t points;
	BonusType actualBonus;
	int actualBonusId;
	int unstablePlateID;
	sf::Vector2f holePosition;
	int unstablePlatesCounter;
	sf::Sprite * background;
	std::vector<sf::Vector2f> platePosition;
	bool isPause;
	gameResult result;
	void resetGame(void);

	// Enemy * enemy[NUMBER_ENEMY];
};