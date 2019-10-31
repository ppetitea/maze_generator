.PHONY: libft all clean fclean re

# C FILES
SRC =	./sources/generate_maze.c\
		./sources/dig_maze.c\
		./sources/show_maze.c\
		./sources/add_end_spawn_positions.c

# Objects files
OBJ = $(SRC:.c=.o)

# Header files
HEADERS =

# Librairies
LIBFT_FOLDER	= libft
LIBFT			= -lft

# Includes list
INCLUDES =	-I includes \
			-I $(LIBFT_FOLDER)/includes

# Name of executable
NAME = generate_maze

# Flags de compilation
CFLAGS = -Wall -Werror -Wextra

# Commande de compilation
CC = gcc -g

all: libft $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^ -L $(LIBFT_FOLDER) $(LIBFT) $(INCLUDES)

$(OBJ): $(HEADERS)

%.o: %.c
	@$(CC) -o $@ -c $< 
#$(CFLAGS)

libft:
	make -C ./libft

clean:
	@rm -rf $(OBJ)
	make -C $(LIBFT_FOLDER) clean

fclean: clean
	@rm -rf $(NAME)
	make -C $(LIBFT_FOLDER) fclean

re: fclean all