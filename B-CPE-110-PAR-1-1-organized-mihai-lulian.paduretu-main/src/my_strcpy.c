/*
** EPITECH PROJECT, 2023
** my_strcpy.c
** File description:
** none
*/

#include "shell.h"
#include "my_headerfiles.h"
#include <stddef.h>
#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++) {
    dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
