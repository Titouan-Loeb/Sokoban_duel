/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_str_to_word_path
*/

#include "my.h"

int is_alphanum_path(char c)
{
    if ((c >= '0' && c <= '9'))
        return (1);
    return (0);
}

int word_length_path(char *str, int i)
{
    for (i = i; str[i] != '\0'; i++)
        if (is_alphanum_path(str[i]) != 1)
            return (i);
    return (i);
}

int how_many_sep_path(char *str)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (is_alphanum_path(str[i]) == 1 && is_alphanum_path(str[i + 1]) != 1)
            j++;
    return (j);
}

char **my_str_to_word_arr(char *str)
{
    int sep = 0;
    char **arr = NULL;
    int i = 0;
    int k = 0;

    sep = how_many_sep_path(str);
    arr = malloc(sizeof(char *) * (sep + 1));
    for (int i = 0; i <= sep; i++)
        arr[i] = NULL;
    for (int j = 0; j < sep; j++) {
        for (i; str[i] != '\0' && word_length_path(str, i) == i; i++);
        arr[j] = malloc(sizeof(char) * (word_length_path(str, i) + 1));
        for (k = 0; str[i] != '\0' && is_alphanum_path(str[i]) == 1; k++) {
            arr[j][k] = str[i];
            i++;
        }
        arr[j][k] = '\0';
        i++;
    }
    return (arr);
}
