NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
FREAMS = -framework OpenGL -framework Appkit

GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNLOBJS = $(GNL:.c=.o)
FT_PRINTF = $(wildcard ft_printf/*.c)
FT_PRİNTFOBJS = $(FT_PRINTF:.c=.o)
LIBFT = $(wildcard libft/*.c)
LIBFTOBJ = $(LIBFT:.c=.o)

SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(GNLOBJS) $(FT_PRİNTFOBJS) $(LIBFTOBJ)
	@make -C mlx
	@$(CC) $(FLAGS) $(OBJS) $(GNLOBJS) $(FT_PRİNTFOBJS) $(LIBFTOBJ) -Lmlx -lmlx $(FREAMS) -o $(NAME)
	@printf "\e[32m (✦ ‿ ✦) Ready (✦ ‿ ✦) \e[0m\n"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS) $(GNLOBJS) $(FT_PRİNTFOBJS) $(LIBFTOBJ)

fclean: clean
	@rm -f $(NAME)
	@make -C mlx clean
	@printf "\e[31m( ￣＾￣) Cleaning ( ￣＾￣) \e[0m\n"

re: fclean all

.PHONY: all clean fclean re