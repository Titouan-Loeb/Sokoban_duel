/*
** EPITECH PROJECT, 2020
** Graphical_SOKOBAN
** File description:
** highlight_crate
*/

#include "my_sflib.h"
#include "my.h"

void highlight_crate(my_map *map, int i, int j, s_game_data *player)
{
        if (player->memtab[i][j] == 'O') {
            map->objects[CRATE].rect.left = 64;
            sfSprite_setTextureRect(map->objects[CRATE].sprite,
            map->objects[CRATE].rect);
        } else {
            map->objects[CRATE].rect.left = 0;
            sfSprite_setTextureRect(map->objects[CRATE].sprite,
            map->objects[CRATE].rect);
        }
}