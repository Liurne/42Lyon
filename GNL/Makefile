# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 16:31:01 by jcoquard          #+#    #+#              #
#    Updated: 2022/12/10 00:22:20 by jcoquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

FLAGS = -Wall -Wextra -Werror -I .

SRCS =	get_next_line.c \
		get_next_line_utils.c \

OBJS = ${SRCS:.c=.o}

HEADER = get_next_line.h

all :	${NAME}


${NAME}:	${OBJS}
		${AR} rcs $@ $^

%.o:	%.c ${HEADER} Makefile
		${CC} ${FLAGS} -c $< -o $@

clean:	
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:	fclean
	${MAKE} all 

test:	${NAME}
	gcc main.c ${NAME} && ./a.out

.PHONY: all clean fclean re

# $@ : NAME de la regle
# $^ : tous les OBJS
# $< : premiere dependance
# ${HEADER} Makefile : pour eviter les relinks