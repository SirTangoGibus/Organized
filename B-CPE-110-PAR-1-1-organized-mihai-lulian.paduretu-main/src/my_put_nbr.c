/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** my_put_nbr
*/

#include "shell.h"
#include "my_headerfiles.h"
#include <stddef.h>
#include <stdlib.h>


static long int get_next(long int nb)
{
    long int next = nb % 10;
    int cnt = 0;

    nb = nb / 10;
    if (nb != 0) {
        get_next(nb);
    }
    cnt = cnt + 1;
    my_putchar(next + '0');
    return (cnt);
}

int my_put_nbr(int nb)
{
    long int length = nb;
    int cnt;

    if (length < 0) {
        my_putchar('-');
        length = length * -1;
    }
    cnt = get_next(length);
    return (cnt);
}
