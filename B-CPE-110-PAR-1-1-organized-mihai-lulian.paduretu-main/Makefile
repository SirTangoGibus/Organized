##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## A makefile
##

SRC	=	src/my_strlen.c\
		src/my_putstr.c\
		src/my_put_nbr.c\
		src/mini_printf.c\
		src/my_strcpy.c\
		src/stringint.c\
		src/my_putchar.c\
		src/my_strcmp.c\
		src/add.c\
		src/sort.c\
		src/del.c\
		src/disp.c\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	organized

LIB	=	libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(LIB) $(OBJ)
	gcc -w $(OBJ) -o $(NAME) -L./ -lshell

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)

re: fclean all
