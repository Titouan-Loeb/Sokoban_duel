/*
** EPITECH PROJECT, 2020
** LIB CSFML
** File description:
** anim.c
*/

#include "my_sflib.h"

void msfAnim_left(s_object *object, int max)
{
    object->rect.left += object->rect.width;
    if (object->rect.left >= max)
        object->rect.left = 0;
    sfSprite_setTextureRect(object->sprite,
    (sfIntRect){object->rect.left,
    object->rect.top,
    object->rect.width,
    object->rect.height});
}

void msfAnim_top(s_object *object, int max)
{
    object->rect.top += object->rect.height;
    if (object->rect.top >= max)
        object->rect.top = 0;
    sfSprite_setTextureRect(object->sprite,
    (sfIntRect){object->rect.left,
    object->rect.top,
    object->rect.width,
    object->rect.height});
}