/*
** EPITECH PROJECT, 2020
** Graphical_SOKOBAN
** File description:
** game_tools
*/

#include "my.h"
#include "sokoban.h"

void find_p_position(my_map *map, s_game_data *player)
{
    int find_p = false;

    for (int i = 0; i != map->level_info.l && find_p == false; i++)
        for (int j = 0; player->tab[i][j] != '\n' && find_p == false; j++)
            if (player->tab[i][j] == 'P') {
                player->p_l = i;
                player->p_c = j;
                find_p = true;
            }
}

void replace_o(my_map *map, s_game_data *player)
{
    for (int i = 0; i != map->level_info.l; i++)
        for (int j = 0; player->tab[i][j] != '\n'; j++)
            if (player->memtab[i][j] == 'O' && player->tab[i][j] == ' ')
                player->tab[i][j] = 'O';
}

void reset_map(my_map *map, s_game_data *player, int num_player) 
{
    (void)num_player;
    for (int i = 0; i != map->level_info.l; i++)
        for (int j = 0; player->tab[i][j] != '\n'; j++)
            player->tab[i][j] = player->memtab[i][j];
    find_p_position(map, player);
    win_the_game(map, player);
    lose_the_game(map, player);
    player->last_move = DOWN;
    player->moves = 0;
}

void refresh_stats(my_map *map, s_game_data *player)
{
    (void)map;
    char *str_moves = my_nbr_to_str(player->moves);
    char *str_tries = my_nbr_to_str(player->tries);

    str_moves = my_strmcat("Moves : ", str_moves);
    str_tries = my_strmcat("Tries : ", str_tries);
    sfText_setString(player->texts[gameMoves].text, str_moves);
    sfText_setString(player->texts[gameTries].text, str_tries);
}

void free_player(my_map *map, s_game_data *player)
{
    for (int i = 0; i < map->level_info.l; i++) {
        free(player->tab[i]);
        free(player->memtab[i]);
    }
    free(player->tab);
    free(player->memtab);
    free(player->texts);
}