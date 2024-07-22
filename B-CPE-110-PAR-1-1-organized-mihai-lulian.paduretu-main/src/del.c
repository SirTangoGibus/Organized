/*
** EPITECH PROJECT, 2023
** del.c
** File description:
** none
*/

#include "shell.h"
#include "my_headerfiles.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

Hardware* find_previous_component(Hardware **list, Hardware *component)
{
    Hardware *current = *list;
    Hardware *prev = NULL;

    while (current != NULL && current != component) {
        prev = current;
        current = current->next;
    }
    return prev;
}

void delete_component(Hardware **list,
    Hardware *component, const char *category_names[])
{
    Hardware *prev = find_previous_component(list, component);

    if (component == NULL) {
        mini_printf("Component not found\n");
        return;
    }
    if (prev == NULL) {
        *list = component->next;
    } else {
        prev->next = component->next;
    }
    mini_printf("%s n°%d - \"%s\" deleted.\n",
                category_names[component->category],
                component->id, component->name);
    free(component);
}

int delete_single_component(Hardware **list,
    const char *category_names[], int id)
{
    Hardware *component = find_component_by_id(*list, id);

    if (id < 0) {
        mini_printf("Invalid index for deletion: %d\n", id);
        return 84;
    }
    if (component == NULL) {
        mini_printf("Component with ID %d not found\n", id);
        return 84;
    }
    delete_component(list, component, category_names);
    return 0;
}

int del_components(Hardware **list, const char *category_names[], char **args)
{
    int index = 0;
    int id;
    int error = 0;

    while (args[index] != NULL) {
        id = string_to_int(args[index]);
        if (delete_single_component(list, category_names, id) != 0) {
            error = 1;
        }
        index++;
    }
    return error ? 84 : 0;
}

int del(void *data, char **args)
{
    const char *const category_names[] =
    {"ACTUATOR", "DEVICE", "PROCESSOR", "SENSOR", "WIRE"};
    Hardware **list = (Hardware **)data;
    int result;

    if (args[0] == NULL) {
        mini_printf("Usage: del INDEX, ...\n");
        return 84;
    }
    result = del_components(list, category_names, args);
    if (result != 0) {
        return 84;
    }
    return 0;
}
