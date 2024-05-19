/*
** EPITECH PROJECT, 2020
** my_sflib.h
** File description:
** my_sflib
*/

#ifndef MY_SFLIB_H_
#define MY_SFLIB_H_

#include "../../include/sokoban.h"

//ANIM
void msfAnim_left(s_object *object, int max);
void msfAnim_top(s_object *object, int max);

//CREATE_IMAGE
void msfCreate_imageRect(s_object *object, char const *filepath);
void msfCreate_image(s_object *object, char const *filepath);

//MOVE_SPRITE
void msfSprite_move(sfSprite *sprite, sfVector2f off_set, sfVector2f *pos);

//IS_ON_POSIOTION
int msfIs_onSpriteRect(sfVector2f elem_pos, sfSprite *sprite, sfIntRect rect);
int msfIs_onRect(sfVector2f elem_pos, sfVector2f rect_pos, sfIntRect rect);

//RANGE
int msfIs_inRangeFromVect(sfVector2f pos1, sfVector2f pos2, unsigned int range);
int msfIs_inRangeFromSprite(sfSprite *sprite1, sfSprite *sprite2,
unsigned int range);
double msfDistance_getFromVect(sfVector2f pos1, sfVector2f pos2);
double msfDistance_getFromSprite(sfSprite *sprite1, sfSprite *sprite2);

//SPRITE_ORIENTATION
void msfSprite_oriantate(sfSprite *sprite, sfIntRect *rect, sfVector2f move);

//SET_SOUND
void msfSet_sound(char const *filepath, sfMusic *sound);

//GET_TIME
void msfGet_time(s_timer *my_clock);
void msfGet_timeRestart(s_timer *my_clock);

//CREATE_TEXT
void msfText_create(s_text *my_text, char const *font, sfVector2f pos, unsigned int size, char const *score);
void msfText_refreshNumber(s_text *my_text, int number);

#endif /* !MY_SFLIB_H_ */