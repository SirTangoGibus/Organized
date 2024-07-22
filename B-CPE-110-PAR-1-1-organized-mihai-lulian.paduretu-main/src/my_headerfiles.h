/*
** EPITECH PROJECT, 2023
** headerfiles.h
** File description:
** none
*/

#ifndef HEADERFILES_H
    #define HEADERFILES_H
    #include <stdarg.h>
typedef enum {
    ACTUATOR,
    DEVICE,
    PROCESSOR,
    SENSOR,
    WIRE
} Category;
typedef struct Hardware {
    int id;
    char name[100];
    Category category;
    struct Hardware *next;
} Hardware;
int my_strlen(char const *str);
int my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
char *my_strcpy(char *dest, char const *src);
int main(void);
int my_strcmp(char const *s1, char const *s2);
int mini_printf(const char *format, ...);
int switch_function(va_list ap, char *format);
int process_component(Hardware **list, char *category_str, char *material);
int add_single(Hardware **list, char *category_str, char *material);
int add_multiple(Hardware **list, char **args);
int string_to_int(const char *str);
void *find_component_by_id(void *list, int id);
Hardware* find_previous_component(Hardware **list, Hardware *component);
void delete_component(Hardware **list,
    Hardware *component, const char *category_names[]);
int delete_single_component(Hardware **list,
    const char *category_names[], int id);
int del_components(Hardware **list, const char *category_names[], char **args);
#endif
