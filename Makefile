# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkasandr <lkasandr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/09 13:59:30 by lkasandr          #+#    #+#              #
#    Updated: 2021/04/22 23:16:36 by lkasandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		cub3D
SRCS =		./src/cub3d.c \
			./src/check_map_one.c \
			./src/check_map_two.c \
			./src/draw.c \
			./src/exit.c \
			./src/get_color.c \
			./src/get_player_position.c \
			./src/init_struct.c \
			./src/init_texture.c \
			./src/make_screenshot.c \
			./src/move_player.c  \
			./src/move_wasd.c  \
			./src/parse_color_utils.c \
			./src/parse_color.c \
			./src/parse_map.c  \
			./src/parse_resolution.c \
			./src/parse_texture.c \
			./src/parser.c \
			./src/processing_sprites.c \
			./src/raycasting_utils.c \
			./src/raycasting.c \
			./src/render_press_release.c \
			./src/skip.c 

LIBFT =		./libft
MLX =		./minilibx_mms
LIBS = 		./libft/libft.a ./minilibx_mms/libmlx.dylib
HEADER =	./src/cub.h	
OBJS =		$(SRCS:.c=.o)

%.o:		%.c $(HEADER)
			${CC}   -c $< -o ${<:.c=.o}

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
OPTFLAGS =  -O2
FLAGS =		-framework OpenGL -framework Appkit 
RM =		rm -f

all :		${NAME}

$(LIBFT) :  libft/*.c
			$(MAKE) -C $(LIBFT) all

$(NAME) :	$(OBJS) $(LIBFT) 
			$(MAKE) -C $(LIBFT) all
			$(MAKE) -C $(MLX) all
			cp libft/libft.a ./
			cp ./minilibx_mms/libmlx.dylib ./
			$(CC) $(CFLAGS) $(FLAGS) $(OPTFLAGS) -o ${NAME} $(OBJS) -I$(HEADER) ${LIBS} 

clean :		
			$(MAKE) -C $(LIBFT) clean
			$(MAKE) -C $(MLX) clean
			$(RM) $(OBJS) ./screenshot.bmp

fclean 	:	clean
			$(MAKE) -C $(LIBFT) fclean
			$(RM) ${NAME}

re :		fclean all

.PHONY :	all clean fclean re 
