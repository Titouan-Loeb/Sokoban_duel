/*
** EPITECH PROJECT, 2019
** move_up.c
** File description:
** my_sokoban
*/

#include "my.h"
#include "sokoban.h"

void move_up_x(my_map *map, s_game_data *player)
{
    (void)map;

    if (player->tab[player->p_l - 2][player->p_c] == ' ' ||
        player->tab[player->p_l - 2][player->p_c] == 'O') {
        player->tab[player->p_l - 2][player->p_c] = 'X';
        player->tab[player->p_l - 1][player->p_c] = 'P';
        player->tab[player->p_l][player->p_c] = ' ';
        player->p_l -= 1;
    }
}

void move_up_sharp(my_map *map, s_game_data *player)
{
    (void)map;
    player->tab[player->p_l - 1][player->p_c] = 'P';
    player->tab[player->p_l][player->p_c] = ' ';
    player->p_l -= 1;
}

void move_up(my_map *map, s_game_data *player)
{
    if (player->tab[player->p_l - 1][player->p_c] == 'X')
        move_up_x(map, player);
    else if (player->tab[player->p_l - 1][player->p_c] != '#')
            move_up_sharp(map, player);
    replace_o(map, player);
}
