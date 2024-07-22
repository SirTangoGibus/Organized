/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** my_strlen
*/

#include "shell.h"
#include "my_headerfiles.h"
#include <stddef.h>
#include <stdlib.h>

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (!(str[i] == '\0')) {
        i = i + 1;
    }
    return (i);
}
