# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 13:46:33 by jcoquard          #+#    #+#              #
#    Updated: 2023/02/24 13:58:42 by jcoquard         ###   ########.fr        #
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

NAME = pipex

FLAGS = -Wall -Wextra -Werror -I .

SRCS = pipex.c \
		child.c \
		free.c \
		utils/ft_bzero.c \
		utils/ft_calloc.c \
		utils/ft_putstr_fd.c \
		utils/ft_split.c \
		utils/ft_strdup.c \
		utils/ft_strjoin.c \
		utils/ft_strlen.c \
		utils/ft_strncmp.c \
		utils/ft_substr.c \

OBJS = ${SRCS:.c=.o}

HEADER = pipex.h

all:	${NAME}

${NAME}:	${OBJS}
	@ ${CC} ${FLAGS} $^ -o $@ ${MLXFLAGS} && echo \\npipex compilation...\\n\\n*===============*

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
