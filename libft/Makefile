# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkasandr <lkasandr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/13 13:07:59 by lkasandr          #+#    #+#              #
#    Updated: 2021/04/23 16:10:44 by lkasandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_strdup.c ft_dec_len.c ft_isdigit.c  ft_putstr_fd.c ft_split.c ft_strchr.c ft_strlen.c ft_strjoin.c ft_strncmp.c ft_strstr.c ft_substr.c get_next_line.c

OBJS	= 	${SRCS:.c=.o}

NAME	= 	libft.a

CC		= 	gcc

RM		=	rm -f

CFLAGS	= 	-Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
ARRC	= 	ar rc

$(NAME):	$(OBJS)
		$(ARRC) $(NAME) $(OBJS)

all:		$(NAME)		

clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}
re:			fclean all

.PHONY:		all clean fclean re
