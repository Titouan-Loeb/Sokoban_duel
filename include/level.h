/*
** EPITECH PROJECT, 2020
** Graphical_SOKOBAN
** File description:
** level
*/

#ifndef LEVEL_H_
#define LEVEL_H_

#include "sokoban.h"

void duel_game(my_map *map);

typedef struct objects_level_select_init_value_t
{
    char *path;
    sfIntRect rect;
    sfVector2f position;
} s_objects_level_select_init_value;

static const char *level_filepaths[] =
{
    "assets/test_maps/map.txt",
    "assets/test_maps/map1.txt",
    "assets/test_maps/map2.txt",
    "assets/test_maps/map3.txt",
    "assets/test_maps/map4.txt",
    "assets/test_maps/map4.txt",
    "assets/test_maps/map4.txt",
    "assets/test_maps/map4.txt",
    "assets/test_maps/map4.txt",
    "assets/test_maps/map4.txt",
    "assets/test_maps/map4.txt",
    "assets/test_maps/map4.txt",
    "assets/test_maps/map4.txt",
    "assets/test_maps/map4.txt",
    "assets/test_maps/map4.txt",
    "assets/test_maps/map4.txt",
    "assets/test_maps/map4.txt"
};

static const int nb_level = 17;

static const s_objects_level_select_init_value objects_level_selection[] =
{
    {"assets/level_selection/background_blue.png", {0, 0, 1920, 1080}, {0, 0}}
};

static const int nb_level_selection_objects = 1;

static const s_objects_level_select_init_value level_icon =
{"assets/level_selection/Crate_level.png", {0, 0, 196, 196}, {0, 0}};


#endif /* !LEVEL_H_ */