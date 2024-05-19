/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** my_sokoban
*/

#include "my.h"
#include "sokoban.h"
#include "init_soko.h"

int help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap\t");
    my_putstr("file representing the warehouse map, ");
    my_putstr("containing ‘#’ for walls,\n");
    my_putstr("\t\t‘P’ for the player, ‘X’ for boxes and ‘O’ ");
    my_putstr("for storage locations.\n");
    return (0);
}

int main(int ac, char **av)
{
    my_map map = {0};

    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h')
            return (help());
        write(2, "Too many arguments", 18);
        return (84);
    }
    else if (ac == 1) {
        create_graphics(&map);
        main_loop(&map);
        return (0);
    }
    return (84);
}
