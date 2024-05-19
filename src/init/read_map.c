/*
** EPITECH PROJECT, 2019
** popup.c
** File description:
** bootstrap my_sokoban
*/

#include "my.h"
#include "my_sflib.h"

int line(char const *buff)
{
    int lines = 0;
    int i = 0;

    for (; buff[i] != '\0'; i++) {
        if (buff[i] == '\n')
            lines += 1;
    }
    return (lines);
}

int col(char const *buff)
{
    int col = 0;
    int nb_col = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n' && nb_col > col) {
            col = nb_col;
            nb_col = -1;
        } else if (buff[i] == '\n')
            nb_col = -1;
        nb_col++;
    }
    return (col);
}

char **fill_tab(char const *buff, char **tab1)
{
    int a = 0;
    int b = 0;
    int i = 0;

    for (; buff[i] != '\0'; i++) {
        if (buff[i] == '\n') {
            tab1[a][b++] = '\n';
            tab1[a++][b] = '\0';
            b = 0;
        } else
            tab1[a][b++] = buff[i];
    }
    return (tab1);
}

int sokoban(my_map *map, char const *buff, s_game_data *player)
{
    map->level_info.l = line(buff);
    map->level_info.c = col(buff);
    player->tab = malloc(sizeof(char *) * (map->level_info.l + 1));
    player->memtab = malloc(sizeof(char *) * (map->level_info.l + 1));
    if (player->tab == NULL || player->memtab == NULL)
        return (84);
    for (int k = 0; k < map->level_info.l; k++) {
        player->tab[k] = malloc(sizeof(char) * (map->level_info.c + 2));
        player->memtab[k] = malloc(sizeof(char) * (map->level_info.c + 2));
        if (player->tab[k] == NULL || player->memtab[k] == NULL)
            return(84);
    }
    player->tab[map->level_info.l] = NULL;
    player->memtab[map->level_info.l] = NULL;
    fill_tab(buff, player->tab);
    fill_tab(buff, player->memtab);
    return (0);
}

void read_sokoban(my_map *map, char const *filepath, s_game_data *player)
{
    struct stat size;
    int fd = open(filepath, O_RDONLY);
    int sf = stat(filepath, &size);
    int rf;
    char *buff;

    if (fd == -1 || sf == -1) {
        write(2, "Failed in file openning\n", 24);
        exit (84);
    }
    buff = malloc(sizeof(char) * (size.st_size + 1));
    buff[size.st_size] = '\0';
    rf = read(fd, buff, size.st_size);
    if (rf == -1 || rf == 0)
        exit (84);
    if (error(buff) != 0)
        exit (84);
    sokoban(map, buff, player);
    close(fd);
}
