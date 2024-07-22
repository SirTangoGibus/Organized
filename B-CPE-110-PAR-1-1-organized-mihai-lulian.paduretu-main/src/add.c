/*
** EPITECH PROJECT, 2023
** add.c
** File description:
** none
*/

#include "shell.h"
#include "my_headerfiles.h"
#include <stddef.h>
#include <stdlib.h>

static int count_elements(Hardware *list)
{
    int count = 0;

    while (list != NULL && list->next != NULL) {
        list = list->next;
        count++;
    }
    return count;
}

static int find_highest_id(Hardware *list)
{
    int new_id = 0;

    while (list != NULL) {
        if (list->id >= new_id) {
            new_id = list->id + 1;
        }
        list = list->next;
    }
    return new_id;
}

static int add_new_item(Hardware **list, char *itemName,
    Category itemCategory, int new_id)
{
    Hardware *new_item = (Hardware *)malloc(sizeof(Hardware));
    const char *category_names[] = {"ACTUATOR", "DEVICE",
    "PROCESSOR", "SENSOR", "WIRE"};

    if (new_item == NULL) {
        mini_printf("Memory allocation failed\n");
        return 84;
    }
    my_strcpy(new_item->name, itemName);
    new_item->category = itemCategory;
    new_item->id = new_id;
    new_item->next = *list;
    *list = new_item;
    mini_printf("%s n°%d - \"%s\" added.\n",
    category_names[itemCategory], new_item->id, itemName);
    return 0;
}

static int add_item(Hardware **list, char *itemName,
    Category itemCategory)
{
    int new_id = find_highest_id(*list);

    return add_new_item(list, itemName, itemCategory, new_id);
}

static int get_category(char *category_str)
{
    const char *category_names[] = {"ACTUATOR",
    "DEVICE", "PROCESSOR", "SENSOR", "WIRE"};
    int num_categories = sizeof(category_names) / sizeof(category_names[0]);
    int category = -1;

    for (int i = 0; i < num_categories; ++i) {
        if (my_strcmp(category_str, category_names[i]) == 0) {
            category = i;
            break;
        }
    }
    return category;
}

int process_component(Hardware **list, char *category_str, char *material)
{
    int category = get_category(category_str);

    if (category_str == NULL || material == NULL) {
        mini_printf("Incomplete input for component addition!\n");
        return 84;
    }
    if (category == -1) {
        mini_printf("Invalid category for %s!\n", material);
        return 84;
    }
    if (add_item(list, material, category) != 0) {
        return 84;
    }
    return 0;
}

int add_single(Hardware **list, char *category_str, char *material)
{
    return process_component(list, category_str, material);
}

int add_multiple(Hardware **list, char **args)
{
    int index = 0;

    while (args[index] != NULL) {
        if (process_component(list, args[index], args[index + 1]) != 0) {
            return 84;
        }
        index += 2;
    }
    return 0;
}

int add(void *data, char **args)
{
    Hardware **list = (Hardware **)data;

    if (args[0] == NULL) {
        mini_printf("Usage: add \"CATEGORY\" \"MATERIAL\", ...\n");
        return 84;
    }
    if (args[1] != NULL) {
        return add_multiple(list, args);
    } else {
        return add_single(list, args[0], args[1]);
    }
}
