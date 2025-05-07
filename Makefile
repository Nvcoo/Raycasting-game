##
## EPITECH PROJECT, 2024
## Untitled (Workspace)
## File description:
## makefile
##

.PHONY: all clean fclean re

CC = gcc

CFLAGS = -Wall -Wextra -g -I./include

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

SRC =	./main.c \
		./src/map/map.c \
		./src/map/draw_map.c \
		./src/map/minimap.c \
		./src/map/draw_tiles.c \
		./src/player/init_player.c \
		./src/player/draw_player.c \
		./src/player/update_player.c \
		./src/player/move_forwards.c \
		./src/player/strafe.c \
		./src/is_wall.c \
		./src/3d/draw_background.c \
		./src/3d/render_wall_column.c \
		./src/rays/cast_single_ray.c \
		./src/rays/cast_all_rays.c \
		./src/rays/ray_utilities.c \
		./src/rays/choose_ray.c \
		./src/rays/normalize_angle.c \
		./src/rays/coloring.c \
		./src/rays/vertical_ray.c \
		./src/rays/horizontal_ray.c \

OBJ = $(SRC:.c=.o)

NAME = wolf3d

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all
