/*
** EPITECH PROJECT, 2020
** Graphical_SOKOBAN
** File description:
** level_selection
*/

#include "my.h"
#include "level.h"
#include "my_sflib.h"

void init_level_selection(my_map *map)
{
    map->level_info.level = 0;
    map->select.keys[upArrow] = false;
    map->select.keys[downArrow] = false;
}

void draw_level_selection(my_map *map)
{
    for (int i = 0; i < nb_level_selection_objects; i++)
        sfRenderWindow_drawSprite(map->window.win, map->select.objects[i].sprite, NULL);
    for (int i = 0; i < nb_level; i++) {
        sfRenderWindow_drawSprite(map->window.win, map->select.level[i].crate.sprite, NULL);
        sfRenderWindow_drawText(map->window.win, map->select.level[i].text.text, NULL);
    }
    sfRenderWindow_display(map->window.win);
}

void ls_event_clic(my_map *map)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(map->window.win);

    for (int i = 0; i < nb_level; i++) {
        if (msfIs_onRect((sfVector2f){mouse.x, mouse.y},
        map->select.level[i].crate.position, map->select.level[i].crate.rect)) {
            map->level_info.level = i;
            if (map->mode == SOLO)
                solo_game(map);
            else if (map->mode == DUEL)
                duel_game(map);
        }
    }
}

void ls_events(my_map *map)
{
    while (sfRenderWindow_pollEvent(map->window.win, &map->window.event)) {
        if (map->window.event.type == sfEvtMouseButtonPressed)
            ls_event_clic(map);
        if (map->window.event.type == sfEvtKeyPressed &&
            map->window.event.key.code == sfKeyEscape)
            map->screen = MENU;
        if (map->window.event.type == sfEvtKeyPressed &&
            map->window.event.key.code == sfKeyUp)
            map->select.keys[upArrow] = true;
        if (map->window.event.type == sfEvtKeyReleased &&
            map->window.event.key.code == sfKeyUp)
            map->select.keys[upArrow] = false;
        if (map->window.event.type == sfEvtKeyPressed &&
            map->window.event.key.code == sfKeyDown)
            map->select.keys[downArrow] = true;
        if (map->window.event.type == sfEvtKeyReleased &&
            map->window.event.key.code == sfKeyDown)
            map->select.keys[downArrow] = false;
    }
}

void scroll_with_arrows(my_map *map)
{
    sfVector2f speed = {0, 0};

    if (map->select.keys[upArrow] == false && map->select.keys[downArrow] == true) {
        speed.y = map->move_clock.seconds * -3000;
        if (map->select.level[nb_level - 1].crate.position.y + speed.y < 1080 - 113 - 196)
            speed.y = 1080 - 113 - 196 - map->select.level[nb_level - 1].crate.position.y;
        for (int i = 0; i < nb_level; i++) {
            msfSprite_move(map->select.level[i].crate.sprite, speed, &map->select.level[i].crate.position);
            sfText_move(map->select.level[i].text.text, speed);
        }
    }
    if (map->select.keys[upArrow] == true && map->select.keys[downArrow] == false) {
        speed.y = map->move_clock.seconds * 3000;
        if (map->select.level[0].crate.position.y + speed.y > 113)
            speed.y = 113 - map->select.level[0].crate.position.y;
        for (int i = 0; i < nb_level; i++) {
            msfSprite_move(map->select.level[i].crate.sprite, speed, &map->select.level[i].crate.position);
            sfText_move(map->select.level[i].text.text, speed);
        }
    }
}

void level_selection(my_map *map)
{
    init_level_selection(map);
    ls_events(map);
    scroll_with_arrows(map);
    draw_level_selection(map);
    msfGet_timeRestart(&map->move_clock);
}