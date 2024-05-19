/*
** EPITECH PROJECT, 2019
** end_of_game.c
** File description:
** my_sokoban
*/

#include "my.h"
#include "sokoban.h"

void win_the_game(my_map *map, s_game_data *player)
{
    player->win_the_level = true;
    for (int i = 0; i != map->level_info.l && player->win_the_level == true; i++)
        for (int j = 0; player->tab[i][j] != '\n' &&
                 player->win_the_level == true; j++) {
            if (player->memtab[i][j] == 'O' && player->tab[i][j] == 'X')
                player->win_the_level = true;
            else if (player->memtab[i][j] == 'O' && player->tab[i][j] != 'X')
                player->win_the_level = false;
        }
}

int is_it_stuck(my_map *map, int i, int j, s_game_data *player)
{
    (void)map;
    if (player->tab[i][j - 1] == '#' && player->tab[i - 1][j] == '#')
        return (1);
    else if (player->tab[i][j - 1] == '#' && player->tab[i + 1][j] == '#')
        return (1);
    else {
        if (player->tab[i][j + 1] == '#' && player->tab[i - 1][j] == '#')
            return (1);
        else if (player->tab[i][j + 1] == '#' && player->tab[i + 1][j] == '#')
            return (1);
    }
    return (0);
}

void lose_the_game(my_map *map, s_game_data *player)
{
    player->nb_x = 0;
    player->nb_x_stuck = 0;
    player->lost_the_level = false;
    for (int i = 0; i != map->level_info.l; i++)
        for (int j = 0; player->tab[i][j] != '\n'; j++)
            if (player->tab[i][j] == 'X') {
                player->nb_x += 1;
                player->nb_x_stuck += is_it_stuck(map, i, j, player);
            }
    if (player->nb_x == player->nb_x_stuck)
        player->lost_the_level = true;
}
