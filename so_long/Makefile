# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 12:11:13 by jcoquard          #+#    #+#              #
#    Updated: 2023/04/12 14:41:23 by jcoquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $@ : NAME de la regle
# $^ : tous les OBJS
# $< : premiere dependance

BLACK        = \033[1;30m
RED            = \033[1;31m
GREEN        = \033[1;32m
YELLOW        = \033[1;33m
BLUE        = \033[1;34m
VIOLET        = \033[1;35m
CYAN        = \033[1;36m
WHITE        = \033[1;37m
IGREY        = \x1b[40m
IRED        = \x1b[41m
IGREEN        = \x1b[42m
IYELLOW        = \x1b[43m
IBLUE        = \x1b[44m
IPURPLE        = \x1b[45m
ICYAN        = \x1b[46m
IWHITE        = \x1b[47m
END            = \x1b[0m
UNDERLINE    = \x1b[4m
REV            = \x1b[7m
ERASE        = \033[2K\r

NAME = so_long

FLAGS		= -Wall -Wextra -Werror -I minilibx/
ARFLAGS		= rsc
MLXFLAGS	=  -Lminilibx/ -lmlx -lXext -lX11 -lm -lz
MLX			= minilibx/libmlx.a

SRCS =	main.c \
		src/map/map.c \
		src/map/map_utils.c \
		src/map/map_img.c \
		src/map/map_parsing.c \
		src/map/verif_map.c \
		src/init/window.c \
		src/init/load_img.c \
		src/init/destroy_img.c \
		src/display/display.c \
		src/event/event.c

OBJS = ${SRCS:.c=.o}

HEADER = src/so_long.h

all:   ${NAME}

${NAME}:	${OBJS}
	@ ${CC} ${FLAGS} $^ -o $@ ${MLXFLAGS} && echo \\npush_swap compilation...\\n\\n*===============*

%.o:	%.c ${HEADER} Makefile
	@ ${CC} ${FLAGS} -c $< -o $@ && echo $@

clean:
	@ ${RM} ${OBJS} && echo clean...

fclean:	clean
	@ ${RM} ${NAME} && echo full clean...

re:	fclean
	${MAKE} all

sus:
	@echo "$(IRED)           ⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀        $(END)"
	@echo "$(IRED)        ⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀     $(END)"
	@echo "$(IRED)        ⣼⣿⠋       ⢀⣀⣀⠈⢻⣿⣿⡄    $(END)"
	@echo "$(IRED)       ⣸⣿⡏   ⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄   $(END)"
	@echo "$(IRED)       ⣿⣿⠁  ⢰⣿⣿⣯⠁       ⠈⠙⢿⣷⡄ $(END)"
	@echo "$(IRED)  ⣀⣤⣴⣶⣶⣿⡟   ⢸⣿⣿⣿⣆          ⣿⣷ $(END)"
	@echo "$(IRED) ⢰⣿⡟⠋⠉⣹⣿⡇   ⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿ $(END)"
	@echo "$(IRED) ⢸⣿⡇  ⣿⣿⡇    ⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃ $(END)"
	@echo "$(IRED) ⣸⣿⡇  ⣿⣿⡇     ⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛⢻⣿⡇  $(END)"
	@echo "$(IRED) ⠸⣿⣧⡀ ⣿⣿⡇                ⣿⣿⠃  $(END)"
	@echo "$(IRED)  ⠛⢿⣿⣿⣿⣿⣇     ⣰⣿⣿⣷⣶⣶⣶⣶⠶ ⢠⣿⣿   $(END)"
	@echo "$(IRED)       ⣿⣿     ⣿⣿⡇ ⣽⣿⡏⠁  ⢸⣿⡇   $(END)"
	@echo "$(IRED)       ⣿⣿     ⣿⣿⡇ ⢹⣿⡆   ⣸⣿⠇   $(END)"
	@echo "$(IRED)       ⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁ ⠈⠻⣿⣿⣿⣿⡿⠏    $(END)"
	@echo "$(IRED)       ⠈⠛⠻⠿⠿⠿⠿⠋⠁              $(END)"
	@echo "$(WHITE)         ░█▀▀░█░█░█▀▀$(END)"
	@echo "$(WHITE)         ░▀▀█░█░█░▀▀█$(END)"
	@echo "$(WHITE)         ░▀▀▀░▀▀▀░▀▀▀$(END)"

.PHONY: all clean fclean re bonussh-5.1$ 
