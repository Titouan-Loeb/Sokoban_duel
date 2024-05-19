/*
** EPITECH PROJECT, 2020
** Graphical_SOKOBAN
** File description:
** init_graphics
*/

#include "my.h"
#include "my_sflib.h"
#include "init_soko.h"
#include "level.h"

void create_window(my_map *map)
{
    map->window.mode.width = 1920;
    map->window.mode.height = 1080;
    map->window.mode.bitsPerPixel = 32;
    map->window.win = sfRenderWindow_create(map->window.mode, "SOKOBAN",
                                                    sfFullscreen, NULL);
}

void create_level_select_screen(my_map *map)
{
    map->select.level = malloc(sizeof(s_level) * nb_level);
    map->select.objects = malloc(sizeof(s_object) * nb_level_selection_objects);
    if (map->select.level == NULL || map->select.objects == NULL)
        exit(84);
    for (int i = 0; i < nb_level_selection_objects; i++) {
        map->select.objects[i].rect = objects_level_selection[i].rect;
        msfCreate_imageRect(&map->select.objects[i], objects_level_selection[i].path);
        if (map->select.objects[i].sprite == NULL || map->select.objects[i].texture == NULL)
            exit (84);
    }
    for (int i = 0; i < nb_level; i++) {
        map->select.level[i].crate.position.x = 204 + (i % 5) * (133 + 196);
        map->select.level[i].crate.position.y = 113 + (i / 5) * (133 + 196);
        map->select.level[i].crate.rect = level_icon.rect;
        msfCreate_imageRect(&map->select.level[i].crate, level_icon.path);
        if (map->select.level[i].crate.sprite == NULL || map->select.level[i].crate.texture == NULL)
            exit (84);
        sfSprite_setPosition(map->select.level[i].crate.sprite, map->select.level[i].crate.position);
        msfText_create(&map->select.level[i].text, "assets/fonts/font.ttf", (sfVector2f)
        {map->select.level[i].crate.position.x + 75 - 20 * ((i + 1) / 10), map->select.level[i].crate.position.y},
        140, my_nbr_to_str(i + 1));
    }
}

void create_graphics(my_map *map)
{
    create_window(map);
    create_level_select_screen(map);
    map->objects = malloc(sizeof(s_object) * nb_object_types);
    if (map->objects == NULL)
        exit (84);
    for (int i = 0; i < nb_object_types; i++) {
        map->objects[i].rect = init_object_values[i].rect;
        msfCreate_imageRect(&map->objects[i], init_object_values[i].path);
        if (map->objects[i].sprite == NULL || map->objects[i].texture == NULL)
            exit (84);
    }
    map->move_clock.clock = sfClock_create();
    map->select.keys = malloc(sizeof(bool) * numberOfKeys);
    for (int i = 0; i < numberOfKeys; i++)
        map->select.keys[i] = false;
    map->objects[PLAYER].position.x = -11;
    map->objects[PLAYER].position.y = -1;
    sfSprite_setOrigin(map->objects[PLAYER].sprite, map->objects[PLAYER].position);
}