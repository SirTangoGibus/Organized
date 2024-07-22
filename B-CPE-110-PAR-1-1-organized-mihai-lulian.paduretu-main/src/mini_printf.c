/*
** EPITECH PROJECT, 2023
** mini_printf.c
** File description:
** none
*/

#include <stdarg.h>
#include "shell.h"
#include "my_headerfiles.h"
#include <stddef.h>
#include <stdlib.h>

int mini_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    while (*format) {
        if (*format == '%') {
            format++;
        switch_function(ap, format);
        format++;
        } else {
        my_putchar(*format);
        format++;
        }
    }
    va_end(ap);
    return 0;
}

int switch_function(va_list ap, char *format)
{
    switch (*format) {
    case 'd':
    my_put_nbr(va_arg(ap, int));
    break;
    case 'i':
    my_put_nbr(va_arg(ap, int));
    break;
    case 's':
    my_putstr(va_arg(ap, char *));
    break;
    case 'c':
    my_putchar((char) va_arg(ap, int));
    break;
    case '%':
    my_putchar('%');
    break;
    }
    return 0;
}
