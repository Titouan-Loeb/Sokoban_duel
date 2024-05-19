/*
** EPITECH PROJECT, 2020
** Graphical_SOKOBAN
** File description:
** init_game
*/

#include "my.h"
#include "my_sflib.h"
#include "init_soko.h"
#include "level.h"

void scale_objects(my_map *map, int number_of_players)
{
    float size_max = 950 / map->level_info.l;
    float size_max_width = 1920 / map->level_info.c / number_of_players;
    float scale_value = 0;

    map->offset = (sfVector2f){0, 0};
    if (size_max > size_max_width) {
        size_max = size_max_width;
        map->offset.y = (950 - size_max * map->level_info.l) / 2;
    } else
        map->offset.x = (1920 - size_max * map->level_info.c) / 2;
    scale_value = size_max / 64;
    map->game[PLAYER1].block_size = size_max;
    if (number_of_players == twoPlayers)
        map->game[PLAYER2].block_size = size_max;
    for (int i = 0; i < nb_object_types; i++) {
        sfSprite_setScale(map->objects[i].sprite,
        (sfVector2f){scale_value, scale_value});
    }
}

void create_text(/*my_map *map, */s_game_data *player, int num_player)
{
    char *data_count[] = {"Moves : ", "Tries : "};
    sfVector2f text_pos = {50, 950};

    if (num_player == PLAYER2)
        text_pos.x += 1920 / 2;
    player->texts = malloc(sizeof(s_text) * numberOfTexts);
    if (player->texts == NULL)
        exit (84);
    for (int i = 0; i < numberOfTexts; i++) {
        msfText_create(&player->texts[i], "assets/fonts/font.ttf", text_pos, 90, data_count[i]);
        if (player->texts[i].text == NULL)
            exit(84);
        text_pos.x += 400;
    }
}

void init_values(my_map *map, s_game_data *player, int num_player, int number_of_players)
{
    read_sokoban(map, level_filepaths[map->level_info.level], player);
    create_text(/*map, */player, num_player);
    find_p_position(map, player);
    win_the_game(map, player);
    lose_the_game(map, player);
    player->moves = 0;
    map->level_info.quit = false;
    player->last_move = DOWN;
    if (num_player == PLAYER1)
        scale_objects(map, number_of_players);
    sfRenderWindow_clear(map->window.win, (sfColor){0, 0, 0, 255});
}