/*
** EPITECH PROJECT, 2019
** nbr to str
** File description:
** bistro
*/

#include <stdlib.h>
#include "my.h"

void my_putchar(char c);

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char tmp;

    for (; str[i] != '\0'; i++);
    i--;
    while (j <= i) {
        tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
        i--;
        j++;
    }
    return (str);
}

int length_int(int nbr)
{
    int i = 0;

    if (nbr == 0)
        return (1);
    for (i = 0; nbr > 0; i++)
        nbr /= 10;

    return (i);
}

char *my_nbr_to_str(int nbr)
{
    int i = 0;
    int size = length_int(nbr);
    char *res_str = malloc(sizeof(char) * (size * 2));

    if (nbr == 0) {
        res_str[0] = '0';
        res_str[1] = '\0';
    }
    while (nbr != 0) {
        if (nbr >= 10) {
            res_str[i] = (nbr % 10 + 48);
            nbr /= 10;
            i++;
        } else {
            res_str[i] = (nbr + 48);
            nbr /= 10;
            res_str[i + 1] = '\0';
        }
    }
    return (my_revstr(res_str));
}
