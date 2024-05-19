/*
** EPITECH PROJECT, 2020
** LIB CSFML
** File description:
** sprite_orientation
*/

#include "my_sflib.h"

void msfSprite_oriantate(sfSprite *sprite, sfIntRect *rect, sfVector2f move)
{
    sfIntRect _rect = {rect->left, rect->top, rect->width, rect->height};

    if (ABS(move.x) >= ABS(move.y)) {
        if (move.x >= 0)
            rect->top = rect->height * 2;
        else
            rect->top = rect->height * 1;
    } else {
        if (move.y >= 0)
            rect->top = 0;
        else
            rect->top = rect->height * 3;
    }
    _rect.top = rect->top;
    sfSprite_setTextureRect(sprite, _rect);
}