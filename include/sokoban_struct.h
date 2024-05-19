/*
** EPITECH PROJECT, 2020
** my_rpg_struct.h
** File description:
** my_rpg_struct.h
*/

#ifndef __MY_RPG_STRUCT_H__
#define __MY_RPG_STRUCT_H__

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>

typedef enum block_type_t
{
    WALL,
    GROUND,
    CRATE,
    END_POINTS,
    PLAYER
} s_block_type;

enum Screens
{
    MENU,
    LEVEL_SELECTION,
    SOLO,
    DUEL,
    OPTIONS,
    CREDITS
};

enum Keys
{
    upArrow,
    downArrow,
    numberOfKeys
};

enum moves
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

enum numberOfPlayer
{
    noPlayer,
    onePlayer,
    twoPlayers,
};

enum players
{
    PLAYER1,
    PLAYER2
};

enum select_objects
{
    backgroundSelect
};

enum gameTexts
{
    gameMoves,
    gameTries,
    numberOfTexts
};

enum mainMenuButtons
{
    soloButton,
    duelButton,
    optionsButton,
    creditsButton,
    backgroundMenu
};

typedef struct object_t
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f speed;
    sfIntRect rect;
    sfColor color;
    bool draw;
} s_object;

typedef struct timer_t
{
    sfClock *clock;
    sfTime time;
    float seconds;
} s_timer;

typedef struct text_t
{
    sfText *text;
    sfFont *font;
    sfVector2f pos;
} s_text;

typedef struct window_t
{
    sfRenderWindow *win;
    sfVideoMode mode;
    sfEvent event;
} s_window;

typedef struct menu_t
{
    s_object *buttons;
} s_menu;

typedef struct game_data_t
{
    int nb_x;
    int moves;
    int tries;
    short last_move;
    int win_the_level;
    int lost_the_level;
    int nb_x_stuck;
    int p_c;
    int p_l;
    int block_size;
    char **tab;
    char **memtab;
    s_text *texts;
} s_game_data;

typedef struct level_t
{
    int number;
    s_text text;
    s_object crate;
    char *filepath;
} s_level;

typedef struct level_selection_t
{
    bool *keys;
    s_object *objects;
    s_level *level;
} s_level_selection;

typedef struct level_info_t
{
    int level;
    int l;
    int c;
    bool quit;
} s_level_info;

typedef struct sokoban_game
{
    int screen;
    int mode;
    s_level_selection select;
    s_object *objects;
    s_window window;
    s_game_data *game;
    s_level_info level_info;
    s_menu menu;
    sfVector2f offset;
    s_timer move_clock;
} my_map;

#endif /* !__MY_RPG_STRUCT_H__ */
