/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** my_putstr
*/

#include "shell.h"
#include "my_headerfiles.h"
#include <stddef.h>
#include <stdlib.h>

int my_putstr(char const *str)
{
    int cnt = 0;
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        if (str[i] != ' ') {
            cnt = cnt + 1;
        }
        i++;
    }
    return (cnt);
}
