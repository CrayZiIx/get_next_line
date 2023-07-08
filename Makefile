# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 10:11:20 by jolecomt          #+#    #+#              #
#    Updated: 2023/07/07 11:37:28 by jolecomt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	get_next_line.c	\
			get_next_line_utils.c

OBJS	= ${SRCS:.c=.o}

CC = gcc
AR = ar rcs
NAME 	= libgnl.a
FLAGS	= -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}
	ranlib ${NAME}

test: ${NAME}
	${CC} ${FLAGS} main.c ${NAME} -o prog

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}
	rm -f prog

re: fclean all

.PHONY: all clean fclean re
