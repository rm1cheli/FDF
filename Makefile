FRAEMWORKS=-framework OpenGL -framework Appkit

NAME = fdf

CFILES =	FDF.c free.c ft_atoi1.c get_next_line.c get_next_line_utils.c matrix_filing.c point.c read_file.c сonnection_points.c

OBJECTS = $(CFILES:.c=.o)

LIB_PATH = libft2/

LIB_PATH1 = minilibx_macos/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: subsystem $(NAME)

subsystem:
	make -C $(LIB_PATH) all
	make -C $(LIB_PATH1) all

$(NAME): $(OBJECTS) FDF.h
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB_PATH1)libmlx.a $(LIB_PATH)libft.a $(FRAEMWORKS) -o $(NAME)

clean:
	make -C $(LIB_PATH) clean
	make -C $(LIB_PATH1) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIB_PATH) fclean
	make -C $(LIB_PATH1) clean
	rm -f $(NAME)

re: fclean all

call: all clean
	make -C $(LIB_PATH) fclean
	make -C $(LIB_PATH1) clean