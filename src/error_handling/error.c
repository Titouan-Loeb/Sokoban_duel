/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** my_sokoban
*/

#include "my.h"
#include "sokoban.h"

int error(char const *buff)
{
    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i] != '\n' && buff[i] != '#' && buff[i] != ' ' &&
            buff[i] != 'P' && buff[i] != 'O' && buff[i] != 'X' &&
            buff[i] != '.')
            return (84);
    return (0);
}
