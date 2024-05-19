/*
** EPITECH PROJECT, 2020
** Graphical_SOKOBAN
** File description:
** duel_game
*/

#include "my.h"
#include "sokoban.h"
#include "init_soko.h"
#include "level.h"

void free_player(my_map *map, s_game_data *player);
void draw_game(my_map *map, int number_of_players);
void refresh_stats(my_map *map, s_game_data *player);

void events_duel(my_map *map)
{
    int keys_p1[] = {sfKeyZ, sfKeyS, sfKeyQ, sfKeyD};
    int keys_p2[] = {sfKeyUp, sfKeyDown, sfKeyLeft, sfKeyRight};
    void (*moves[])(my_map *, s_game_data *) = {move_up, move_down,
                                                move_left, move_right};

    while (sfRenderWindow_pollEvent(map->window.win, &map->window.event)) {
        for (int i = 0; i < 4; i++) {
            if (map->window.event.key.type == sfEvtKeyPressed &&
                map->window.event.key.code == keys_p1[i]) {
                map->game[PLAYER1].last_move = i;
                moves[i](map, &map->game[PLAYER1]);
                win_the_game(map, &map->game[PLAYER1]);
                lose_the_game(map, &map->game[PLAYER1]);
            }
            if (map->window.event.key.type == sfEvtKeyPressed &&
                map->window.event.key.code == keys_p2[i]) {
                map->game[PLAYER2].last_move = i;
                moves[i](map, &map->game[PLAYER2]);
                win_the_game(map, &map->game[PLAYER2]);
                lose_the_game(map, &map->game[PLAYER2]);
            }
        }
        if (map->window.event.key.type == sfEvtKeyPressed &&
            map->window.event.key.code == sfKeyR) {
            reset_map(map, &map->game[PLAYER1], PLAYER1);
            map->game[PLAYER1].tries++;
        }
        if (map->window.event.key.type == sfEvtKeyPressed &&
            map->window.event.key.code == sfKeyNumpad0) {
            reset_map(map, &map->game[PLAYER2], PLAYER2);
            map->game[PLAYER2].tries++;
        }
        if (map->window.event.key.type == sfEvtKeyPressed &&
            map->window.event.key.code == sfKeyEscape)
            map->level_info.quit = true;
    }
}

void duel_game(my_map *map)
{
    map->game = malloc(sizeof(s_game_data) * 2);
    if (map->game == NULL)
        exit(84);
    init_values(map, &map->game[PLAYER1], PLAYER1, twoPlayers);
    init_values(map, &map->game[PLAYER2], PLAYER2, twoPlayers);
    map->game[PLAYER1].tries = 1;
    map->game[PLAYER2].tries = 1;
    while (map->game[PLAYER1].win_the_level != true &&
        map->game[PLAYER1].lost_the_level != true &&
        map->game[PLAYER2].win_the_level != true &&
        map->game[PLAYER2].lost_the_level != true &&
        map->level_info.quit != true) {
        events_duel(map);
        refresh_stats(map, &map->game[PLAYER1]);
        refresh_stats(map, &map->game[PLAYER2]);
        draw_game(map, twoPlayers);
    }
    for (int i = PLAYER1; i <= PLAYER2; i++) {
        reset_map(map, &map->game[i], i);
        free_player(map, &map->game[i]);
    }
    free(map->game);
    map->level_info.level = -1;
}