/*
** EPITECH PROJECT, 2019
** my_popup.c
** File description:
** bootstrap my_sokoban
*/

#include "my.h"
#include "sokoban.h"
#include "init_soko.h"
#include "level.h"

void free_player(my_map *map, s_game_data *player);
void draw_game(my_map *map, int number_of_players);
void refresh_stats(my_map *map, s_game_data *player);

void events_solo(my_map *map, s_game_data *player)
{
    int keys[] = {sfKeyUp, sfKeyDown, sfKeyLeft, sfKeyRight};
    void (*moves[])(my_map *, s_game_data *) = {move_up, move_down,
                                                move_left, move_right};

    while (sfRenderWindow_pollEvent(map->window.win, &map->window.event)) {
        for (int i = 0; i < 4; i++) {
            if (map->window.event.key.type == sfEvtKeyPressed &&
                map->window.event.key.code == keys[i]) {
                moves[i](map, player);
                player->last_move = i;
                win_the_game(map, player);
                lose_the_game(map, player);
            }
        }
        if (map->window.event.key.type == sfEvtKeyPressed &&
            map->window.event.key.code == sfKeySpace) {
            reset_map(map, player, PLAYER1);
            player->tries++;
        }
        if (map->window.event.key.type == sfEvtKeyPressed &&
            map->window.event.key.code == sfKeyEscape)
            map->level_info.quit = true;
    }
}

void solo_game(my_map *map)
{
    map->game = malloc(sizeof(s_game_data) * 1);
    if (map->game == NULL)
        exit(84);
    init_values(map, &map->game[PLAYER1], PLAYER1, onePlayer);
    map->game[PLAYER1].tries = 1;
    while (map->game[PLAYER1].win_the_level != true &&
        map->game[PLAYER1].lost_the_level != true &&
        map->level_info.quit != true) {
        events_solo(map, &map->game[PLAYER1]);
        refresh_stats(map, &map->game[PLAYER1]);
        draw_game(map, onePlayer);
    }
    reset_map(map, &map->game[PLAYER1], PLAYER1);
    free_player(map, &map->game[PLAYER1]);
    free(map->game);
    map->level_info.level = -1;
}
