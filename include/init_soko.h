/*
** EPITECH PROJECT, 2020
** Graphical_SOKOBAN
** File description:
** init_soko
*/

#ifndef INIT_SOKO_H_
#define INIT_SOKO_H_

#include "sokoban.h"

void create_graphics(my_map *map);
void main_loop(my_map *map);

typedef struct objects_init_value_t
{
    s_block_type name;
    char *path;
    sfIntRect rect;
    sfVector2f position;
} s_objects_init_value;

static const s_objects_init_value init_object_values[] =
{
    {WALL, "assets/game_blocks/Walls.png", {0, 0, 64, 64}, {0, 0}},
    {GROUND, "assets/game_blocks/Grounds.png", {0, 0, 64, 64}, {0, 0}},
    {CRATE, "assets/game_blocks/Crates.png", {0, 0, 64, 64}, {0, 0}},
    {END_POINTS, "assets/game_blocks/End_points.png", {0, 0, 64, 64}, {0, 0}},
    {PLAYER, "assets/game_blocks/Character.png", {0, 64, 42, 62}, {0, 0}}
};

static const int nb_object_types = 5;

static const s_objects_init_value init_main_menu_objects[] =
{
    {0, "assets/menu/solo_button.png", {0, 0, 320, 77}, {1920 / 2 - 320 / 2, 1080 / 2 - 140}},
    {0, "assets/menu/duel_button.png", {0, 0, 320, 77}, {1920 / 2 - 320 / 2, 1080 / 2 - 140 + 85}},
    {0, "assets/menu/options_button.png", {0, 0, 320, 77}, {1920 / 2 - 320 / 2, 1080 / 2 - 140 + 85 * 2}},
    {0, "assets/menu/crédits_button.png", {0, 0, 320, 77}, {1920 / 2 - 320 / 2, 1080 / 2 - 140 + 85 * 3}},
    {0, "assets/menu/menu_sokoban.png", {0, 0, 1920, 1080}, {0, 0}}
};

static const int nb_main_menu_buttons = 5;

#endif /* !INIT_SOKO_H_ */
