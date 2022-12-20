# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoquard <jcoquard>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 13:46:33 by jcoquard          #+#    #+#              #
#    Updated: 2022/11/26 15:48:30 by jcoquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a 

FLAGS = -Wall -Wextra -Werror -I .

SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c 

BONUS =	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c
		
OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${BONUS:.c=.o}

HEADER = libft.h

all :	${NAME}

# $@ : NAME de la regle
# $^ : tous les OBJS
${NAME}:	${OBJS}
		${AR} rcs $@ $^

bonus: ${OBJS} ${OBJSBONUS}
		${AR} rcs ${NAME} ${OBJS} ${OBJSBONUS}

# cree les objets
# $< : premiere dependance
# ${HEADER} Makefile : pour eviter les relinks
%.o:	%.c ${HEADER} Makefile
		${CC} ${FLAGS} -c $< -o $@

clean:	
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		${RM} ${NAME}

re:	fclean
	${MAKE} all 

.PHONY: all clean fclean re bonus