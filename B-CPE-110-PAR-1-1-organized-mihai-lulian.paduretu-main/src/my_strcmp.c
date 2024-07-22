/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** none
*/

#include "shell.h"
#include "my_headerfiles.h"
#include <stddef.h>
#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}
