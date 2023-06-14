# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 17:47:33 by jcoquard          #+#    #+#              #
#    Updated: 2023/06/14 15:10:51 by jcoquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $@ : NAME de la regle
# $^ : tous les OBJS
# $< : premiere dependance

GREY = \033[30m
RED = \033[31m
GREEN = \033[32m
ORANGE = \033[33m
BLUE = \033[34m
PURPLE = \033[35m
LIGHTBLUE = \033[36m
WHITE = \033[37m

IRED=\033[41m
IWHITE=\033[47m
IBLUE=\033[44m
IPURPLE=\033[45m

END = \033[0m

NAME = philo

FLAGS = -Wall -Wextra -Werror -pthread

SRCS = main.c \
		src/utils.c \
		src/init.c \
		src/routine.c \
		src/action.c \
		src/error.c

OBJS = ${SRCS:.c=.o}

HEADER = src/philo.h

all:	${NAME}

${NAME}: ${OBJS}
		@ ${CC} ${FLAGS} ${OBJS} -o $@ && echo "${GREEN}\n* ${NAME} compilation completed !!!\n${END}"

%.o:	%.c ${HEADER}
		@ ${CC} ${FLAGS} -c $< -o $@ && echo "  $@"

clean:
		@ ${RM} ${OBJS} && echo "${RED} * object cleared..."

fclean: clean
		@ ${RM} ${NAME} && echo "${RED} * everything is cleared..."

re:	fclean
		${MAKE} all

sus:
		@echo "${BLUE}           ⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀        ${END}"
		@echo "${BLUE}        ⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀     ${END}"
		@echo "${BLUE}        ⣼⣿⠋       ${WHITE}⢀⣀⣀${BLUE}⠈⢻⣿⣿⡄    ${END}"
		@echo "${BLUE}       ⣸⣿⡏   ${WHITE}⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄   ${END}"
		@echo "${BLUE}       ⣿⣿⠁  ${WHITE}⢰⣿⣿⣯⠁       ⠈⠙⢿⣷⡄ ${END}"
		@echo "${BLUE}  ⣀⣤⣴⣶⣶⣿⡟   ${WHITE}⢸⣿⣿⣿⣆          ⣿⣷ ${END}"
		@echo "${BLUE} ⢰⣿⡟⠋⠉⣹⣿⡇   ${WHITE}⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿ ${END}"
		@echo "${BLUE} ⢸⣿⡇  ⣿⣿⡇    ${WHITE}⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃ ${END}"
		@echo "${BLUE} ⣸⣿⡇  ⣿⣿⡇     ${WHITE}⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛${BLUE}⢻⣿⡇  ${END}"
		@echo "${BLUE} ⠸⣿⣧⡀ ⣿⣿⡇                ⣿⣿⠃  ${END}"
		@echo "${BLUE}  ⠛⢿⣿⣿⣿⣿⣇     ⣰⣿⣿⣷⣶⣶⣶⣶⠶ ⢠⣿⣿   ${END}"
		@echo "${BLUE}       ⣿⣿     ⣿⣿⡇ ⣽⣿⡏⠁  ⢸⣿⡇   ${END}"
		@echo "${BLUE}       ⣿⣿     ⣿⣿⡇ ⢹⣿⡆   ⣸⣿⠇   ${END}"
		@echo "${BLUE}       ⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁ ⠈⠻⣿⣿⣿⣿⡿⠏    ${END}"
		@echo "${BLUE}       ⠈⠛⠻⠿⠿⠿⠿⠋⠁              ${END}"
		@echo "$(IBLUE)         ░█▀▀░█░█░█▀▀         ${END}"
		@echo "$(IBLUE)         ░▀▀█░█░█░▀▀█         ${END}"
		@echo "$(IBLUE)         ░▀▀▀░▀▀▀░▀▀▀         ${END}"

.PHONY: all clean fclean re bonussh-5.1$