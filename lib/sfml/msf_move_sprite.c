/*
** EPITECH PROJECT, 2020
** LIB CSFML
** File description:
** move_sprite.c
*/

#include "my_sflib.h"

void msfSprite_move(sfSprite *sprite, sfVector2f off_set, sfVector2f *pos)
{
    sfVector2f sprite_position = {0, 0};

    sfSprite_move(sprite, off_set);
    sprite_position = sfSprite_getPosition(sprite);
    pos->x = sprite_position.x;
    pos->y = sprite_position.y;
}