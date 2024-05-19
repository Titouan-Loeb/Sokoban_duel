/*
** EPITECH PROJECT, 2019
** move_right.c
** File description:
** my_sokoban
*/

#include "my.h"
#include "sokoban.h"

void move_right_x(my_map *map, s_game_data *player)
{
    (void)map;
    if (player->tab[player->p_l][player->p_c + 2] == ' ' ||
        player->tab[player->p_l][player->p_c + 2] == 'O') {
        player->tab[player->p_l][player->p_c + 2] = 'X';
        player->tab[player->p_l][player->p_c + 1] = 'P';
        player->tab[player->p_l][player->p_c] = ' ';
        player->p_c += 1;
    }
}

void move_right_sharp(my_map *map, s_game_data *player)
{
    (void)map;
    player->tab[player->p_l][player->p_c + 1] = 'P';
    player->tab[player->p_l][player->p_c] = ' ';
    player->p_c += 1;
}

void move_right(my_map *map, s_game_data *player)
{
    if (player->tab[player->p_l][player->p_c + 1] == 'X')
        move_right_x(map, player);
    else if (player->tab[player->p_l][player->p_c + 1] != '#')
        move_right_sharp(map, player);
    replace_o(map, player);
}
