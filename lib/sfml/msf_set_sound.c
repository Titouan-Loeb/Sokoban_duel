/*
** EPITECH PROJECT, 2020
** msf_set_sound.c
** File description:
** msf_set_sound.c
*/

#include "my_sflib.h"

void msfSet_sound(char const *filepath, sfMusic *sound)
{
    sfMusic_destroy(sound);
    sound = sfMusic_createFromFile(filepath);
    sfMusic_play(sound);
}