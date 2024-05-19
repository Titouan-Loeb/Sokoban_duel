/*
** EPITECH PROJECT, 2020
** LIB CSFML
** File description:
** get_time.c
*/

#include "my_sflib.h"

void msfGet_time(s_timer *my_clock)
{
    my_clock->time = sfClock_getElapsedTime(my_clock->clock);
    my_clock->seconds = my_clock->time.microseconds / 1000000.0;
}

void msfGet_timeRestart(s_timer *my_clock)
{
    my_clock->time = sfClock_getElapsedTime(my_clock->clock);
    my_clock->seconds = my_clock->time.microseconds / 1000000.0;
    sfClock_restart(my_clock->clock);
}