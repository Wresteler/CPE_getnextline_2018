/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "get_next_line.h"
#include <fcntl.h>

void my_putchar(char c);
void my_putstr(char *str);
char *get_next_line(int fd);

int  main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    char *s;

    if (ac < 1 || ac > 2)
        my_putstr("Error: Not enought arguments !\n");
    if (fd == -1)
        my_putstr("Error: Can't open file main !\n");
    while ((s = get_next_line(fd)) != NULL) {
        my_putstr(s);
        my_putchar('\n');
        free(s);
    }
    close(fd);
    return (0);
}
