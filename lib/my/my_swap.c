/*
** EPITECH PROJECT, 2020
** my_swap.c
** File description:
** my_swap.c
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int c = 0;

    c = *a;
    *a = *b;
    *b = c;
}
