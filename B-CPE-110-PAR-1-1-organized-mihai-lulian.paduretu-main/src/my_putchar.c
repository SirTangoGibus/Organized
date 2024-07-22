/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** my_putchar
*/

#include <unistd.h>
#include "shell.h"
#include "my_headerfiles.h"
#include <stddef.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
