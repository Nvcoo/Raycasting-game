##
## EPITECH PROJECT, 2024
## Untitled (Workspace)
## File description:
## makefile
##

.PHONY: all clean fclean re

CC = gcc

CFLAGS = -Wall -Wextra -g -I./include

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

SRC =	./main.c \
		./src/map/map.c \
		./src/map/draw_map.c \
		./src/map/minimap.c \
		./src/map/draw_tiles.c \
		./src/map/map_layer.c \
		./src/map/adjust_map.c \
		./src/player/init_player.c \
		./src/player/draw_player.c \
		./src/player/update_player.c \
		./src/player/move_forwards.c \
		./src/player/strafe.c \
		./src/player/rotate_player.c \
		./src/player/set_player.c \
		./src/3d/draw_background.c \
		./src/3d/render_wall_column.c \
		./src/3d/draw_ceiling.c \
		./src/3d/draw_floor.c \
		./src/3d/coloring.c \
		./src/rays/is_wall.c \
		./src/rays/cast_single_ray.c \
		./src/rays/cast_all_rays.c \
		./src/rays/ray_utilities.c \
		./src/rays/choose_ray.c \
		./src/rays/normalize_angle.c \
		./src/rays/coloring.c \
		./src/rays/vertical_path.c \
		./src/rays/horizontal_path.c \
		./src/rays/handling/handle_horizontal_ray.c \
		./src/rays/handling/handle_vertical_ray.c \
		./src/rays/init/init_horizontal_ray.c \
		./src/rays/init/init_vertical_ray.c \
		./src/torch/update_torch.c \
		./src/torch/torch_presets.c \
		./src/torch/destroy_torch.c \
		./src/torch/init_torch.c \
		./src/torch/torch_math.c \
		./src/weapon/update_gun.c \
		./src/weapon/weapon_presets.c \
		./src/weapon/crosshair.c \
		./src/weapon/destroy_gun.c \
		./src/weapon/init_gun.c \
		./src/weapon/toggle.c \
		./src/weapon/gun_math.c \
		./src/core/destroy_assets.c \
		./src/core/events.c \
		./src/core/game_functions.c \
		./src/core/game_loop.c \
		./src/core/initialization.c \
		./src/core/mouse.c \
		./src/core/relative_pause.c \
		./src/core/resolution_view.c \
		./src/hud/ammo_text.c \
		./src/hud/health_text.c \
		./src/hud/hud_layer.c \
		./src/hud/stamina_text.c \
		./src/menu/set_bg.c \
		./src/menu/init_menu.c \
		./src/menu/draw_menu.c \
		./src/menu/handle_menu.c \
		./src/menu/set_up_buttons.c \
		./src/menu/set_key.c \
		./src/menu/buttons_pos.c \
		./src/menu/buttons_scale.c \
		./src/save/save.c \
		./src/save/load.c \

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
