# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 12:11:13 by jcoquard          #+#    #+#              #
#    Updated: 2023/05/17 15:41:09 by jcoquard         ###   ########.fr        #
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

NAME = so_long

FLAGS		= -Wall -Wextra -Werror -I minilibx/
ARFLAGS		= rsc
MLXFLAGS	=  -Lminilibx/ -lmlx -lXext -lX11 -lm -lz
MLX			= minilibx/libmlx.a

SRCS =	main.c \
		src/utils/ft_bzero.c \
		src/utils/ft_strlen.c \
		src/utils/ft_strdup.c \
		src/utils/ft_putstr_fd.c \
		src/utils/ft_putnbr_fd.c \
		src/utils/ft_strjoin.c \
		src/utils/ft_strber.c \
		src/utils/ft_putmove_fd.c \
		src/utils/ft_calloc.c \
		src/utils/ft_itoa.c \
		src/init/window.c \
		src/init/load_img.c \
		src/init/destroy_img.c \
		src/init/error.c \
		src/parsing/parsing_map.c \
		src/parsing/verif_parsing.c \
		src/world/map.c \
		src/world/init_entity.c \
		src/world/map_img.c \
		src/display/display.c \
		src/display/display_entity.c \
		src/event/event.c \
		src/event/keyboard.c \
		src/event/dog.c \
		src/event/wolf.c \
		src/event/end.c

OBJS = ${SRCS:.c=.o}

HEADER = src/so_long.h

all:   ${NAME}

${NAME}:	display ${OBJS}
	@ ${CC} ${FLAGS} ${OBJS} -o $@ ${MLXFLAGS} && echo "${GREEN}\n* ${NAME} compilation completed !!!\n${END}"

%.o:	%.c ${HEADER}
	@ ${CC} ${FLAGS} -c $< -o $@ && echo "  $@"

clean:
	@ ${RM} ${OBJS} && echo "${RED} * object cleared..."

fclean: clean
	@ ${RM} ${NAME} && echo "${RED} * everything is cleared..."

re:	fclean
	${MAKE} all

display: ${OBJS}
		@echo "${BLUE}============================\n\n* ${NAME} compilation...\n\n============================\n${END}"

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
