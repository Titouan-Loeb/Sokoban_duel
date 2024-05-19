/*
** EPITECH PROJECT, 2020
** Graphical_SOKOBAN
** File description:
** main_menu
*/

#include "my.h"
#include "init_soko.h"
#include "my_sflib.h"

void mm_event_mouse_on_button(my_map *map, sfVector2i mouse)
{
    for (int i = soloButton; i <= creditsButton; i++) {
        if (msfIs_onRect((sfVector2f){mouse.x, mouse.y},
        map->menu.buttons[i].position, map->menu.buttons[i].rect))
            map->menu.buttons[i].rect.left = map->menu.buttons[i].rect.width;
        else
            map->menu.buttons[i].rect.left = 0;
        sfSprite_setTextureRect(map->menu.buttons[i].sprite, map->menu.buttons[i].rect);
    }
}

void mm_event_clic(my_map *map, sfVector2i mouse)
{
    for (int i = soloButton; i <= creditsButton; i++) {
        if (msfIs_onRect((sfVector2f){mouse.x, mouse.y},
        map->menu.buttons[i].position, map->menu.buttons[i].rect)) {
            map->screen = i + 1;
            if (i == soloButton)
                map->mode = SOLO;
            else if (i == duelButton)
                map->mode = DUEL;
        }
    }
}

void main_menu_events(my_map *map)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(map->window.win);

    mm_event_mouse_on_button(map, mouse);
    while (sfRenderWindow_pollEvent(map->window.win, &map->window.event)) {
        if (map->window.event.type == sfEvtMouseButtonPressed)
            mm_event_clic(map, mouse);
        if (map->window.event.key.type == sfEvtKeyPressed &&
            map->window.event.key.code == sfKeyEscape)
            sfRenderWindow_close(map->window.win);
    }
}

void display_main_menu(my_map *map)
{
    for (int i = nb_main_menu_buttons - 1; i >= 0; i--)
        sfRenderWindow_drawSprite(map->window.win,
        map->menu.buttons[i].sprite, NULL);
    sfRenderWindow_display(map->window.win);
}

void main_menu(my_map *map)
{
    main_menu_events(map);
    display_main_menu(map);
}