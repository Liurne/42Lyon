# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoquard <jcoquard>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 13:46:33 by jcoquard          #+#    #+#              #
#    Updated: 2023/01/11 14:59:30 by jcoquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

FLAGS = -Wall -Wextra -Werror -I .

SRCS =	libft/ft_atol.c \
		libft/ft_bzero.c \
		libft/ft_calloc.c \
		libft/ft_isnumber.c \
		libft/ft_lstadd_back.c \
		libft/ft_lstadd_front.c \
		libft/ft_lstclear.c \
		libft/ft_lstdelone.c \
		libft/ft_lstlast.c \
		libft/ft_lstnew.c \
		libft/ft_lstsize.c \
		libft/ft_putstr.c \
		libft/ft_strcmp.c \
		libft/ft_strjoin.c \
		libft/ft_strlen.c \
		libft/ft_substr.c \
		libft/ft_split_atoi.c \
		push_swap_utils.c \
		push_swap.c \
		main.c

OBJS = ${SRCS:.c=.o}

HEADER = push_swap.h

all :	${NAME}

# $@ : NAME de la regle
# $^ : tous les OBJS
${NAME}:	${OBJS}
		@ ${CC} $^ -o $@ && echo \\npush_swap compilation...\\n\\n*===============*

# cree les objets
# $< : premiere dependance
# ${HEADER} Makefile : pour eviter les relinks
%.o:	%.c ${HEADER} Makefile
		@ ${CC} ${FLAGS} -c $< -o $@ && echo $@

clean:	
		@ ${RM} ${OBJS} && echo clean...

fclean:	clean
		@ ${RM} ${NAME} && echo full clean...

re:	fclean
	${MAKE} all

.PHONY: all clean fclean re bonus