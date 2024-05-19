/*
** EPITECH PROJECT, 2020
** LIB CSFML
** File description:
** create_image.c
*/

#include "my_sflib.h"

void msfCreate_image(s_object *object, char const *filepath)
{
    object->sprite = sfSprite_create();
    object->texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
}

void msfCreate_imageRect(s_object *object, char const *filepath)
{
    object->sprite = sfSprite_create();
    object->texture = sfTexture_createFromFile(filepath, NULL);
    if (object->sprite == NULL || object->texture == NULL)
        return;
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setTextureRect(object->sprite, object->rect);
}