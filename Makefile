CC		=	gcc
NAME	=	fractol
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm	-rf
SRCS 	=	main.c fractol.c fractal_utils_1.c fractal_utils_2.c mouse_functions.c
MLX_COMMAND = $(CC) $(CFLAGS) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx -03 -c $< -o $@

$(NAME): $(SRCS)
	$(MAKE) all -C mlx
	$(MLX_COMMAND)
	@echo "Fractol compiled:"
	@echo "1. For Mandlebort => ./$(NAME) 1"
	@echo "2. For Julia => ./$(NAME) -2 2"
	@echo "3. For Tricorn => ./$(NAME) 2"

clean:
	$(MAKE) clean -C mlx

fclean: clean
	$(RM) $(NAME)
	$(MAKE) clean -C mlx

re: fclean $(NAME)

.PHONY = all clean fclean re