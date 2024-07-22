/*
** EPITECH PROJECT, 2023
** disp.c
** File description:
** none
*/

#include <stdarg.h>
#include "shell.h"
#include "my_headerfiles.h"
#include <stddef.h>
#include <stdlib.h>

int disp(void *data, char **args)
{
    Hardware *list = *(Hardware **)data;
    Hardware *current = list;
    const char *const category_names[] =
    {"ACTUATOR", "DEVICE", "PROCESSOR", "SENSOR", "WIRE"};

    if (current == NULL) {
    mini_printf("Workshop is empty.\n");
    return 0;
    }
    while (current != NULL) {
    mini_printf("%s n°%d - \"%s\"\n",
    category_names[current->category],
    current->id, current->name);
    current = current->next;
    }
    return 0;
}
