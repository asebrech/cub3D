# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alois <alois@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 16:13:10 by asebrech          #+#    #+#              #
#    Updated: 2021/11/14 23:18:31 by alois            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit
HEADER = includes
NAME = cub3D
RM = rm -rf
SRC =	srcs/main.c \
		srcs/parsing.c \
		srcs/parsing_resource.c \
		srcs/parsing_map.c \
		srcs/cub3d.c \
		srcs/find_wall.c \
		srcs/find_wall_1.c \
		srcs/minimap.c \
		srcs/move.c \
		srcs/map.c \
		srcs/utiles_1.c \
		srcs/utiles.c
SRCB =	bonus/main_bonus.c \
		bonus/parsing_bonus.c \
		bonus/parsing_resource_bonus.c \
		bonus/parsing_map_bonus.c \
		bonus/cub3d_bonus.c \
		bonus/find_wall_bonus.c \
		bonus/find_wall_1_bonus.c \
		bonus/minimap_bonus.c \
		bonus/move_bonus.c \
		bonus/map_bonus.c \
		bonus/utiles_1_bonus.c \
		bonus/sprite_bonus.c \
		bonus/event_bonus.c \
		bonus/xpm_bonus.c \
		bonus/animation_bonus.c \
		bonus/ma_animation_bonus.c \
		bonus/sh_animation_bonus.c \
		bonus/utiles_bonus.c

ifdef WHITH_BONUS
	OBJ = $(SRCB:.c=.o)
else
	OBJ = $(SRC:.c=.o)
endif

.c.o :
	$(CC) $(CFLAGS) -I$(HEADER) -Iminilibx -c $< -o $(<:.c=.o)

all : $(NAME)

bonus :
	@make WHITH_BONUS=1 all

$(NAME) : $(OBJ)
	@make -C minilibx 
	@make -C libft bonus
	$(CC) $(CFLAGS) $(LFLAGS) -I$(HEADER) -Llibft -lft $(OBJ) -o $(NAME)

clean :
	@make -C libft clean
	$(RM) */*.o

fclean : clean
	@make -C minilibx clean 
	@make -C libft fclean 
	$(RM) $(NAME)


re : fclean all

.PHONY : all clean fclean re bonus
