/*
** EPITECH PROJECT, 2019
** get_next_line.c
** File description:
** get_next_line.c
*/

#include "get_next_line.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}

char *my_realloc(char *str)
{
    int i = 0;
    char *new = malloc(sizeof(char) * (my_strlen(str) + 3));

    if (new  == NULL)
        return (NULL);
    if (str[i] != '\0') {
        for (; str[i]; i++)
            new[i] = str[i];
        free(str);
    }
    new[i + 1] = '\0';
    return (new);
}

char *get_next_line(int fd)
{
    int i = 0;
    int j = 0;
    int k = 0;
    static char buffer[READ_SIZE / READ_SIZE];
    char *str = malloc(sizeof(char) + 3);

    if (fd < k || str == NULL)
        return (NULL);
    str[k] = '\0';
    for (; (j = read(fd, buffer, READ_SIZE / READ_SIZE) > k)
    && buffer[k] != '\n'; i++) {
        str = my_realloc(str);
        str[i] = buffer[k];
    }
    if (i == k && j == k)
        return (NULL);
    else
        return (str);
}
