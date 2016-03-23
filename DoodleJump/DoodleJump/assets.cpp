#pragma once

#include "stdafx.h"
#include "sheet.h"

Assets::Assets()
{
	addTexture(BACKGROUND_TEXTURE, "images/background.png", true);
	addTexture(TRAMPOLINE_TEXTURE, "images/TRAMPOLINE_20_7.png");
	addTexture(ROCKET_NONE_TEXTURE, "images/Rocket_none_23_36.png");
	addTexture(ROCKET_1_LEFT_TEXTURE, "images/Rocket_left_1_12_40.png");
	addTexture(ROCKET_1_RIGHT_TEXTURE, "images/Rocket_right_1_12_40.png");
	addTexture(ROCKET_2_LEFT_TEXTURE, "images/Rocket_left_2_15_52.png");
	addTexture(ROCKET_2_RIGHT_TEXTURE, "images/Rocket_right_2_15_52.png");
	addTexture(ROCKET_3_LEFT_TEXTURE, "images/Rocket_left_3_23_61.png");
	addTexture(ROCKET_3_RIGHT_TEXTURE, "images/Rocket_right_3_23_61.png");
	addTexture(HAT_HELOCPTER_NONE_RIGHT_TEXTURE, "images/Hat_Helicopter_None_Right_30_18.png");
	addTexture(HAT_HELOCPTER_NONE_LEFT_TEXTURE, "images/Hat_Helicopter_None_Left_30_18.png");
	addTexture(HAT_HELOCPTER_DIAGONAL_LEFT_TEXTURE, "images/Hat_Helicopter_Fly_Diagonal_Left_29_26.png");
	addTexture(HAT_HELOCPTER_DIAGONAL_RIGHT_TEXTURE, "images/Hat_Helicopter_Fly_Diagonal_Right_29_26.png");
	addTexture(HAT_HELOCPTER_FLY_LEFT_TEXTURE, "images/Hat_Helicopter_Left_29_23.png");
	addTexture(HAT_HELOCPTER_FLY_RIGHT_TEXTURE, "images/Hat_Helicopter_Right_29_23.png");
	addTexture(DOODLE_LEFT_TEXTURE, "images/Doodle45_45Left.png");
	addTexture(DOODLE_RIGHT_TEXTURE, "images/Doodle45_45Right.png");
	addTexture(DOODLE_JUMP_LEFT_TEXTURE, "images/Doodle45_42Left_Jump.png");
	addTexture(DOODLE_JUMP_RIGHT_TEXTURE, "images/Doodle45_42Right_Jump.png");
	addTexture(DOODLE_SHOOTING_TEXTURE, "images/Doodle_shooting_30_58.png");
	addTexture(PLATE_STATIC_TEXTURE, "images/Plate_63_15_Green.png");
	addTexture(PLATE_DYNAMIC_TEXTURE, "images/Plate_63_15_Blue.png");
	addTexture(PLATE_CLOUD_TEXTURE, "images/Plate_63_15_Cloud.png");
	addTexture(SPRING_TEXTURE, "images/Spring16_12.png");
	addTexture(SPRING_2_TEXTURE, "images/Spring16_26.png");
	addTexture(PLATE_UNSTABLE_TEXTURE, "images/Plate_63_15_Unstable.png");
	addTexture(PLATE_BROKEN_LEFT_TEXTURE, "images/Plate_broken_left_24_29.png");
	addTexture(PLATE_BROKEN_RIGHT_TEXTURE, "images/Plate_broken_right_20_32.png");
	addTexture(TITLE_TEXTURE, "images/Title_202_46.png");
	addTexture(STARS_1_TEXTURE, "images/stars_1_39_30.png");
	addTexture(STARS_2_TEXTURE, "images/stars_2_38_28.png");
	addTexture(BUTTON_ACTIVE_TEXTURE, "images/button_active_104_29.png");
	addTexture(BUTTON_INACTIVE_TEXTURE, "images/button_inactive_104_29.png");
	addTexture(HOLE_TEXTURE, "images/hole_60_54.png");
	addTexture(GARBAGE_1_TEXTURE, "images/Garbage_1_21_16.png");
	addTexture(GARBAGE_2_TEXTURE, "images/Garbage_2_20_23.png");
	addTexture(GARBAGE_3_TEXTURE, "images/Garbage_3_21_18.png");
	addTexture(GARBAGE_4_TEXTURE, "images/Garbage_4_36_18.png");
	addTexture(GARBAGE_5_TEXTURE, "images/Garbage_5_28_17.png");
	addTexture(LINE_TEXTURE, "images/line_320_5.png");
	addTexture(MONSTER_FLYING_1_TEXTURE, "images/Monster_flying_1_76_44.png");
	addTexture(MONSTER_FLYING_2_TEXTURE, "images/Monster_flying_2_76_44.png");
	addTexture(MONSTER_FLYING_3_TEXTURE, "images/Monster_flying_3_76_44.png");
	addTexture(MONSTER_FLYING_4_TEXTURE, "images/Monster_flying_4_76_44.png");
	addTexture(MONSTER_RED_TEXTURE, "images/Monster_red_46_35.png");
	addTexture(MONSTER_PURPLE_TEXTURE, "images/Monster_purple_55_49.png");
	addTexture(MONSTER_GREEN_TEXTURE, "images/Monster_green_82_53.png");
	addTexture(MONSTER_BLUE_LEFT_TEXTURE, "images/Monster_blue_left_37_49.png");
	addTexture(MONSTER_BLUE_RIGHT_TEXTURE, "images/Monster_blue_right_37_49.png");

	if (!font.loadFromFile("arial.ttf"))
	{
		printf("Error loaded arial\n");
	}
}

Assets::~Assets()
{

}

void Assets::addTexture(sf::Texture & texture, std::string string, const bool repeat) 
{
	if (!texture.loadFromFile(string))
	{
		printf("Error loaded file");
	}
	texture.setSmooth(true);
	texture.setRepeated(repeat);
}