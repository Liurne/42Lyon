# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 14:26:37 by jcoquard          #+#    #+#              #
#    Updated: 2023/05/09 16:29:38 by jcoquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $@ : NAME de la regle
# $^ : tous les OBJS
# $< : premiere dependance

NAME = philo

FLAGS = -Wall -Wextra -Werror -I .

SRCS = main.c \
		src/parsing.c\
		src/utils.c \
		src/init.c \
		src/thread.c \
		src/action.c

OBJS = ${SRCS:.c=.o}

HEADER = src/philo.h

all:	${NAME}

${NAME}:	${OBJS}
		@ ${CC} ${FLAGS} $^ -o $@ && echo \\npipex compilation...\\n\\n*===============*

%.o:	%.c ${HEADER}
		@ ${CC} ${FLAGS} -c $< -o $@ && echo $@

clean:
		@ ${RM} ${OBJS} && echo clean...

fclean:	clean
		@ ${RM} ${NAME} && echo full clean...

re:	fclean
		${MAKE} all

sus:
		@echo "           ⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀        "
		@echo "        ⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀     "
		@echo "        ⣼⣿⠋       ⢀⣀⣀⠈⢻⣿⣿⡄    "
		@echo "       ⣸⣿⡏   ⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄   "
		@echo "       ⣿⣿⠁  ⢰⣿⣿⣯⠁       ⠈⠙⢿⣷⡄ "
		@echo "  ⣀⣤⣴⣶⣶⣿⡟   ⢸⣿⣿⣿⣆          ⣿⣷ "
		@echo " ⢰⣿⡟⠋⠉⣹⣿⡇   ⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿ "
		@echo " ⢸⣿⡇  ⣿⣿⡇    ⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃ "
		@echo " ⣸⣿⡇  ⣿⣿⡇     ⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛⢻⣿⡇  "
		@echo " ⠸⣿⣧⡀ ⣿⣿⡇                ⣿⣿⠃  "
		@echo "  ⠛⢿⣿⣿⣿⣿⣇     ⣰⣿⣿⣷⣶⣶⣶⣶⠶ ⢠⣿⣿   "
		@echo "       ⣿⣿     ⣿⣿⡇ ⣽⣿⡏⠁  ⢸⣿⡇   "
		@echo "       ⣿⣿     ⣿⣿⡇ ⢹⣿⡆   ⣸⣿⠇   "
		@echo "       ⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁ ⠈⠻⣿⣿⣿⣿⡿⠏    "
		@echo "       ⠈⠛⠻⠿⠿⠿⠿⠋⠁              "
		@echo "         ░█▀▀░█░█░█▀▀"
		@echo "         ░▀▀█░█░█░▀▀█"
		@echo "         ░▀▀▀░▀▀▀░▀▀▀"

.PHONY: all clean fclean re