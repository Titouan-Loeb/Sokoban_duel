/*
** EPITECH PROJECT, 2020
** LIB CSFML
** File description:
** create_text
*/

#include "my_sflib.h"

void msfText_create(s_text *my_text, char const *font, sfVector2f pos,
unsigned int size, char const *score)
{
    my_text->font = sfFont_createFromFile(font);
    my_text->text = sfText_create();
    my_text->pos = (sfVector2f){pos.x, pos.y};
    sfText_setString(my_text->text, score);
    sfText_setFont(my_text->text, my_text->font);
    sfText_setCharacterSize(my_text->text, size);
    sfText_setPosition(my_text->text, my_text->pos);
}

// void msfText_refreshNumber(s_text *my_text, int number)
// {
//     char *score = my_nbr_to_str(number);

//     sfText_setString(my_text->text, score);
// }