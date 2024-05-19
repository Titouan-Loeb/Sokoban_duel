/*
** EPITECH PROJECT, 2020
** Graphical_SOKOBAN
** File description:
** main loop
*/

#include "my_sflib.h"
#include "my.h"
#include "init_soko.h"

void level_selection(my_map *map);

void init_menu_buttons(my_map *map)
{
    map->menu.buttons = malloc(sizeof(s_object) * nb_main_menu_buttons);
    if (map->menu.buttons == NULL)
        exit (84);
    for (int i = 0; i < nb_main_menu_buttons; i++) {
        map->menu.buttons[i].rect = init_main_menu_objects[i].rect;
        map->menu.buttons[i].position = init_main_menu_objects[i].position;
        msfCreate_imageRect(&map->menu.buttons[i],
        init_main_menu_objects[i].path);
        sfSprite_setPosition(map->menu.buttons[i].sprite,
        map->menu.buttons[i].position);
    }
}

void init_game(my_map *map)
{
    map->screen = MENU;
    map->mode = -1;
    init_menu_buttons(map);
}

void main_loop(my_map *map)
{
    void (*screens[])(my_map *) = {main_menu, level_selection, level_selection, main_menu,
    main_menu};

    init_game(map);
    while (sfRenderWindow_isOpen(map->window.win)) {
        sfRenderWindow_setFramerateLimit(map->window.win, 60);
        screens[map->screen](map);
    }
}