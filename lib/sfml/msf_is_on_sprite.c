/*
** EPITECH PROJECT, 2020
** LIB CSFLM
** File description:
** is_on_sprite
*/

#include "my_sflib.h"

int msfIs_onSpriteRect(sfVector2f elem_pos, sfSprite *sprite, sfIntRect rect)
{
    sfVector2f spr_pos = {0, 0};

    spr_pos = sfSprite_getPosition(sprite);
    if (elem_pos.x >= spr_pos.x && elem_pos.x <= spr_pos.x + rect.width &&
        elem_pos.y >= spr_pos.y && elem_pos.y <= spr_pos.y + rect.height)
        return (true);
    return (false);
}

int msfIs_onRect(sfVector2f elem_pos, sfVector2f rect_pos, sfIntRect rect)
{
    if (elem_pos.x >= rect_pos.x && elem_pos.x <= rect_pos.x + rect.width &&
        elem_pos.y >= rect_pos.y && elem_pos.y <= rect_pos.y + rect.height)
        return (true);
    return (false);
}