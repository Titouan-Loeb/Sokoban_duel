/*
** EPITECH PROJECT, 2020
** Graphical_SOKOBAN
** File description:
** draw_game
*/

#include "sokoban.h"
#include "my.h"

void highlight_crate(my_map *map, int i, int j, s_game_data *player);

void draw_ground_and_walls(my_map *map, s_game_data *player, int num_player)
{
    for (int i = 0; i < map->level_info.l; i++)
        for (int j = 0; j < map->level_info.c; j++) {
            if (player->tab[i][j] == '#') {
                map->objects[WALL].position.x = player->block_size * j + map->offset.x + num_player * 1920 / 2;
                map->objects[WALL].position.y = player->block_size * i + map->offset.y;
                sfSprite_setPosition(map->objects[WALL].sprite,
                map->objects[WALL].position);
                sfRenderWindow_drawSprite(map->window.win,
                map->objects[WALL].sprite, NULL);
            } else if (player->tab[i][j] != '.') {
                map->objects[GROUND].position.x = player->block_size * j + map->offset.x + num_player * 1920 / 2;
                map->objects[GROUND].position.y = player->block_size * i + map->offset.y;
                sfSprite_setPosition(map->objects[GROUND].sprite,
                map->objects[GROUND].position);
                sfRenderWindow_drawSprite(map->window.win,
                map->objects[GROUND].sprite, NULL);
            }
        }
}

void draw_objects(my_map *map, s_game_data *player, int num_player)
{
    for (int i = 0; i < map->level_info.l; i++)
        for (int j = 0; j < map->level_info.c; j++) {
            if (player->tab[i][j] == 'X') {
                map->objects[CRATE].position.x = player->block_size * j + map->offset.x + num_player * 1920 / 2;
                map->objects[CRATE].position.y = player->block_size * i + map->offset.y;
                sfSprite_setPosition(map->objects[CRATE].sprite,
                map->objects[CRATE].position);
                highlight_crate(map, i, j, player);
                sfRenderWindow_drawSprite(map->window.win,
                map->objects[CRATE].sprite, NULL);
            }
            else if (player->tab[i][j] == 'O') {
                map->objects[END_POINTS].position.x = player->block_size * j + map->offset.x + num_player * 1920 / 2;
                map->objects[END_POINTS].position.y = player->block_size * i + map->offset.y;
                sfSprite_setPosition(map->objects[END_POINTS].sprite,
                map->objects[END_POINTS].position);
                sfRenderWindow_drawSprite(map->window.win,
                map->objects[END_POINTS].sprite, NULL);
            }
            else if (player->tab[i][j] == 'P') {
                map->objects[PLAYER].position.x = player->block_size * j + map->offset.x + num_player * 1920 / 2;
                map->objects[PLAYER].position.y = player->block_size * i + map->offset.y;
                map->objects[PLAYER].rect.top = player->last_move * map->objects[PLAYER].rect.height;
                sfSprite_setTextureRect(map->objects[PLAYER].sprite, map->objects[PLAYER].rect);
                sfSprite_setPosition(map->objects[PLAYER].sprite,
                map->objects[PLAYER].position);
                sfRenderWindow_drawSprite(map->window.win,
                map->objects[PLAYER].sprite, NULL);
            }
        }
}

void draw_texts(my_map *map, s_game_data *player)
{
    for (int i = 0; i < numberOfTexts; i++)
        sfRenderWindow_drawText(map->window.win, player->texts[i].text, NULL);
}

void draw_game(my_map *map, int number_of_players)
{
    sfRenderWindow_drawSprite(map->window.win,
    map->select.objects[backgroundSelect].sprite, NULL);
    for (int i = PLAYER1; i < number_of_players; i++) {
        draw_ground_and_walls(map, &map->game[i], i);
        draw_objects(map, &map->game[i], i);
        draw_texts(map, &map->game[i]);
    }
    sfRenderWindow_display(map->window.win);
}