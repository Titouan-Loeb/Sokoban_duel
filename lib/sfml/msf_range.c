/*
** EPITECH PROJECT, 2020
** LIB CSFML
** File description:
** is_in_range
*/

#include "my_sflib.h"

int msfIs_inRangeFromVect(sfVector2f pos1, sfVector2f pos2, unsigned int range)
{
    sfVector2f vector = {0, 0};
    float distance = 0;

    vector = (sfVector2f){pos1.x - pos2.x, pos1.y - pos2.y};
    distance = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
    return (distance <= range);
}

int msfIs_inRangeFromSprite(sfSprite *sprite1, sfSprite *sprite2,
unsigned int range)
{
    sfVector2f pos_sprite1 = sfSprite_getPosition(sprite1);
    sfVector2f pos_sprite2 = sfSprite_getPosition(sprite2);
    sfVector2f vector = {0, 0};
    float distance = 0;

    vector = (sfVector2f){pos_sprite1.x - pos_sprite2.x,
                            pos_sprite1.y - pos_sprite2.y};
    distance = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
    return (distance <= range);
}

double msfDistance_getFromVect(sfVector2f pos1, sfVector2f pos2)
{
    sfVector2f vector = {0, 0};

    vector = (sfVector2f){pos1.x - pos2.x, pos1.y - pos2.y};
    return (sqrt(pow(vector.x, 2) + pow(vector.y, 2)));
}

double msfDistance_getFromSprite(sfSprite *sprite1, sfSprite *sprite2)
{
    sfVector2f pos_sprite1 = sfSprite_getPosition(sprite1);
    sfVector2f pos_sprite2 = sfSprite_getPosition(sprite2);
    sfVector2f vect_distance = {pos_sprite1.x - pos_sprite2.x,
                                pos_sprite1.y - pos_sprite2.y};

    return (sqrt(pow(vect_distance.x, 2) + pow(vect_distance.y, 2)));
}