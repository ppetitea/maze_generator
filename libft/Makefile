.PHONY: all clean fclean re

SRC =	./sources/str/ft_strlen.c\
		./sources/str/ft_isspace.c\
		./sources/str/ft_isnumber.c\
		./sources/str/ft_strsplit.c\
		./sources/str/ft_strdup.c\
		./sources/nbr/ft_atoi.c\
		./sources/nbr/array.c\
		./sources/io/ft_putstr.c\
		./sources/io/ft_error.c\
		./sources/maths/positions.c\
		./sources/maths/size.c\
		./sources/maths/random.c\

OBJ = $(SRC:.c=.o)

HEADERS =	./includes/libft.h\
			./includes/types.h\
			./includes/maths.h\
			./includes/str.h\
			./includes/nbr.h\
			./includes/move.h\
			./includes/io.h

INCLUDES = $(HEADERS)

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar r $(NAME) $(OBJ)

$(OBJ): $(INCLUDES)

%.o: %.c
	@gcc -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all