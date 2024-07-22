/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** none
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_headerfiles.h"
#include "shell.h"

int main(void)
{
    Hardware *head = NULL;
    Hardware *temp = head;
    int return_code = 0;

    return_code = workshop_shell((void *)&head);
    if (return_code != 0) {
        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
        return return_code;
    }
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
