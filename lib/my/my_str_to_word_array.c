/*
** EPITECH PROJECT, 2020
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int is_printable(char c)
{
    if (c >= 33 && c <= 126)
        return (1);
    return (0);
}

int word_length(char const *str, int i)
{
    for (i; str[i] != '\0'; i++)
        if (is_printable(str[i]) != 1)
            return (i);
    return (i);
}

int how_many_separators(char const *str)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (is_printable(str[i]) == 1 && is_printable(str[i + 1]) != 1)
            j++;
    return (j);
}

char **my_str_to_word_array(char const *str)
{
    int separators = how_many_separators(str);
    char **array = malloc(sizeof(char *) * (separators + 1));
    int i = 0;
    int k = 0;

    array[separators] = NULL;
    for (int j = 0; j < separators; j++) {
        while (str[i] != '\0' && word_length(str, i) == i)
            i++;
        k = 0;
        array[j] = malloc(sizeof(char) * (word_length(str, i) + 1));
        while (str[i] != '\0' && is_printable(str[i]) == 1) {
            array[j][k] = str[i];
            k++;
            i++;
        }
        array[j][k] = '\0';
        i++;
    }
    return (array);
}
