/*
** EPITECH PROJECT, 2023
** sort.c
** File description:
** none
*/

#include "shell.h"
#include "my_headerfiles.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static void swap(Hardware *a, Hardware *b)
{
    int temp_id = a->id;
    Category temp_category = a->category;
    char temp_name[100];

    my_strcpy(temp_name, a->name);
    a->id = b->id;
    a->category = b->category;
    my_strcpy(a->name, b->name);
    b->id = temp_id;
    b->category = temp_category;
    my_strcpy(b->name, temp_name);
}

static int compare_elements(Hardware *a, Hardware *b)
{
    return my_strcmp(a->name, b->name);
}

static void bubble_pass(Hardware *list, Hardware *lptr,
    int reverse, int *swapped)
{
    Hardware *ptr1 = list;
    int comparison;

    while (ptr1->next != lptr) {
    comparison = compare_elements(ptr1, ptr1->next);
        if ((!reverse && comparison > 0) || (reverse && comparison < 0)) {
            swap(ptr1, ptr1->next);
            *swapped = 1;
        }
        ptr1 = ptr1->next;
    }
}

static void bubble_sort(Hardware *list, int reverse)
{
    int swapped;
    Hardware *lptr = NULL;

    if (list == NULL)
        return;
    do {
        swapped = 0;
        bubble_pass(list, lptr, reverse, &swapped);
        lptr = list->next;
    } while (swapped);
}

int sort(void *data, char **args)
{
    Hardware **list = (Hardware **)data;
    int reverse = 0;

    if (args[0] == NULL) {
        mini_printf("Usage: sort NAME [-r]\n");
        return 84;
    }
    if (args[1] != NULL && my_strcmp(args[1], "-r") == 0) {
        reverse = 1;
    }
    bubble_sort(*list, reverse);
    return 0;
}
