/*
** EPITECH PROJECT, 2023
** stringint.c
** File description:
** none
*/

#include "shell.h"
#include "my_headerfiles.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int string_to_int(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
    sign = -1;
        i++;
    } else if (str[0] == '+') {
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
            i++;
        } else {
            return -1;
        }
    }
    return result * sign;
}

void *find_component_by_id(void *list, int id)
{
    Hardware *current = (Hardware *)list;

    while (current != NULL && current->id != id) {
        current = current->next;
    }
    return current;
}
