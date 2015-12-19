#pragma once

#include "stdafx.h"
#include <string>
#include <SFML/Graphics.hpp>

static const int NUMBER_PLATES = 30;
static const int NUMBER_BONUSES = 5;
static const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);
static const float STEP = 3.f;
static const int DOODLE_WIDTH = 45;
static const int DOODLE_HEIGHT = 45;
static const int PLATE_WIDTH = 63;
static const int PLATE_HEIGHT = 15;
static const int SPRING_WIDTH = 16;
static const int SPRING_HEIGHT = 12;
static const int HAT_HELICOPTER_WIDTH = 30;
static const int HAT_HELICOPTER_HEIGHT = 18;
static const int ROCKET_WIDTH = 23;
static const int ROCKET_HEIGHT = 36;
static const int TRAMPOLINE_WIDTH = 20;
static const int TRAMPOLINE_HEIGHT = 7;
static const int MAX_NUMBER_OF_ITEMS = 3;

bool g_noJumps;
bool g_endOfGame;
sf::Vector2f g_positionBeforeDown;

struct Assets
{
	sf::Sprite * BACKGROUND;
	sf::Texture BACKGROUND_TEXTURE;
	sf::Texture PLATE_STATIC_TEXTURE;
	sf::Texture PLATE_DYNAMIC_TEXTURE;
	sf::Texture PLATE_CLOUD_TEXTURE;
	sf::Texture SPRING_TEXTURE;
	sf::Texture SPRING_2_TEXTURE;
	sf::Texture DOODLE_LEFT_TEXTURE;
	sf::Texture DOODLE_RIGHT_TEXTURE;
	sf::Texture DOODLE_JUMP_LEFT_TEXTURE;
	sf::Texture DOODLE_JUMP_RIGHT_TEXTURE;
	sf::Texture HAT_HELOCPTER_DIAGONAL_RIGHT_TEXTURE;
	sf::Texture HAT_HELOCPTER_DIAGONAL_LEFT_TEXTURE;
	sf::Texture HAT_HELOCPTER_FLY_RIGHT_TEXTURE;
	sf::Texture HAT_HELOCPTER_FLY_LEFT_TEXTURE;
	sf::Texture HAT_HELOCPTER_NONE_RIGHT_TEXTURE;
	sf::Texture HAT_HELOCPTER_NONE_LEFT_TEXTURE;
	sf::Texture ROCKET_NONE_TEXTURE;
	sf::Texture ROCKET_1_LEFT_TEXTURE;
	sf::Texture ROCKET_1_RIGHT_TEXTURE;
	sf::Texture ROCKET_2_LEFT_TEXTURE;
	sf::Texture ROCKET_2_RIGHT_TEXTURE;
	sf::Texture ROCKET_3_LEFT_TEXTURE;
	sf::Texture ROCKET_3_RIGHT_TEXTURE;
	sf::Texture TRAMPOLINE_TEXTURE;
	sf::Font font;
};

Assets g_Assets;

enum class PlateType
{
	STATIC,
	DYNAMIC_X,
	CLOUD
};

enum class Collision
{
	COLLISION_SPRING,
	COLLISION_HAT_HELICOPTER,
	COLLISION_TRAMPLANE,
	COLLISION_MISSLE,
	COLLISION_PLATE,
	COLLISION_ROCKET,
	NO_COLLISION
};

enum class DirectionY
{
	UP,
	DOWN
};

enum class DirectionX
{
	NONE,
	LEFT,
	RIGHT
};

enum class BonusType
{
	HAT_HELICOPTER,
	SPRING,
	TRAMPOLINE,
	MISSILE,
	ROCKET,
	NO
};

struct Direction
{
	DirectionX x;
	DirectionY y;
};

struct Doodle
{
	sf::Sprite * body;
	sf::Texture texture;
	Direction direction;
	Collision collision;
	int deltaHeight;
	DirectionX lastDirectionX;
};

struct Plate
{
	sf::Sprite * body;
	sf::Texture texture;
	PlateType type;
	Direction direction;
};

struct Bonus
{
	BonusType type;
	sf::Sprite * body;
};

struct Game
{
	Doodle hero;
	BonusType actualBonus;
	int actualBonusId;
	int qwerty;
	Plate plate[NUMBER_PLATES];
	Bonus bonus[NUMBER_BONUSES];
	sf::Text text;
	unsigned long long int points;
};

bool checkGameEnd(Game & game);

void starter(sf::RenderWindow & window, Game & game);

void initialGame(Game & game, sf::View view);

void startGame(void);

void keyPressed(sf::RenderWindow & window, Game & game);

void update(sf::RenderWindow & window, Game & game, sf::View & view);

void render(sf::RenderWindow & window, Game & game);

void initAssets(void);

int checkDoodleFall(Game & game);

void generPlates(Game & game);

void initialPlates(Game & game);

void moveDynamicPlates(Game & game);

void initialHero(Game & game);

void initialBonuses(Game & game);

void generBonuses(Game & game);

void buildBonus(Game & game, BonusType bonusType, int i);

void buildBonus(Game & game, BonusType bonusType, int i, sf::Vector2f platePosition);
