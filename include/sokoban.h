/*
** EPITECH PROJECT, 2020
** my_rpg.h
** File description:
** my_rpg.h
*/

#ifndef __MY_RPG_H__
#define __MY_RPG_H__

#include <ncurses.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "sokoban_struct.h"

#define READ_SIZE (10)
#define ABS(a) ((a >= 0) ? (a) : -(a))


/*----------main----------*/
int line(char const *buff);
int col(char const *buff);
char **fill_tab(char const *buff, char **tab1);
int sokoban(my_map *map, char const *buff, s_game_data *player);
void read_sokoban(my_map *map, char const *filepath, s_game_data *player);

/*----------error---------*/
int error(char const *buff);

/*--------end_game--------*/
void win_the_game(my_map *map, s_game_data *player);
void lose_the_game(my_map *map, s_game_data *player);
int is_it_stuck(my_map *map, int i, int j, s_game_data *player);
void reset_map(my_map *map, s_game_data *player, int num_player);

/*--------sokoban---------*/
int disp_map(my_map *map);
void find_p_position(my_map *map, s_game_data *player);
void replace_o(my_map *map, s_game_data *player);
void move_p(int input, my_map *map);
void init_values(my_map *map, s_game_data *player, int num_player, int number_of_players);

/*---------move_up--------*/
void move_up(my_map *map, s_game_data *player);
void move_up_sharp(my_map *map, s_game_data *player);
void move_up_x(my_map *map, s_game_data *player);

/*-------move_down--------*/
void move_down(my_map *map, s_game_data *player);
void move_down_sharp(my_map *map, s_game_data *player);
void move_down_x(my_map *map, s_game_data *player);

/*-------move_right-------*/
void move_right(my_map *map, s_game_data *player);
void move_right_sharp(my_map *map, s_game_data *player);
void move_right_x(my_map *map, s_game_data *player);

/*-------move_left--------*/
void move_left(my_map *map, s_game_data *player);
void move_left_sharp(my_map *map, s_game_data *player);
void move_left_x(my_map *map, s_game_data *player);

//-------------------------SCREENS------------------------//

/*--------main_menu-------*/
void main_menu(my_map *map);
void display_main_menu(my_map *map);

/*-------solo-------------*/
void solo_game(my_map *map);


#endif /* !__MY_RPG_H__ */
