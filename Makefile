NAME = so_long

SRC  = so_long.c ennemi.c play.c counters.c exit.c flood_fill_exit.c flood_fill_collectives.c element_drawing.c utils2.c ft_itoa.c draw.c hooks.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c utils1.c map_checker.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) -fsanitize=address -g3 $(OBJ)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
