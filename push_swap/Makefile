# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoquard <jcoquard>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 13:46:33 by jcoquard          #+#    #+#              #
#    Updated: 2023/01/18 12:36:51 by jcoquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
		libft/ft_lstbeforelast.c \
		libft/ft_lstnew.c \
		libft/ft_lstsize.c \
		libft/ft_putstr.c \
		libft/ft_strcmp.c \
		libft/ft_strjoin.c \
		libft/ft_strlen.c \
		libft/ft_substr.c \
		libft/ft_split_atoi.c \
		libft/ft_lstinit.c \
		push_swap_utils/push.c \
		push_swap_utils/reverse.c \
		push_swap_utils/rotate.c \
		push_swap_utils/swap.c \
		push_swap_utils/push_swap_utils.c \
		push_swap_utils/smart_sort.c \
		parsing.c \
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

hundred: hundred1 hundred2 hundred3 hundred4

hundred1:
	./a.out 14 12 13 15 18 19 34 35 27 26 21 24 56 42 40 36 100 145 10 5 8 123 78 79 48 127 251 143 98 7 69 61 74 132 357 240 789 564 215 365 354 230 745 654 278 412 0 2 -456 -12 -586 -3 -7 -698 -100 -35 -21 -856 -1000 -42 -17 -86 1452 -1452 -1 320 460 750 801  200 960 -45 -154 -879 -236 101 6 -6  3568 3200 1256 1786 2569 2456 -256 -2568 -789 -123 -20 -19 10000 7896 6532 -5236  -7854 -3214 4526 2000 52 -101 | wc -l
hundred2:
	./a.out 257 181 341 -235 -71 365 262 -422 61 310 -252 -239 372 -338 220 426 408 44 -159 306 485 -23 -87 -50 -176 38 -442 -440 -91 195 -258 -157 -366 -458 394 -131 119 141 -456 -186 240 -495 71 -75 -107 91 487 389 375 -32 -492 -143 -27 -205 -35 429 276 428 43 298 -128 334 -134 314 -282 -130 404 -394 77 -47 -443 104 418 282 417 284 68 -375 199 -347 -5 -15 468 161 -234 98 177 -363 -217 -226 407 -345 -483 -321 -1 370 -444 410 34 -154 | wc -l
hundred3:
	./a.out 56 -458 -251 432 321 -239 384 -26 -413 84 -406 456 -185 134 -210 127 -498 435 -316 24 217 305 -20 -257 -87 47 367 358 -128 476 -254 199 450 -412 483 240 -41 -51 280 -158 -315 -268 437 68 324 50 -7 -47 -29 -420 446 -356 -324 273 136 357 312 -309 -337 -5 153 -279 -18 -222 -230 78 244 328 -96 427 438 180 -290 -369 126 -419 175 -479 241 -8 482 3 296 -220 -98 -484 -433 -330 -287 497 39 -407 -306 -299 -144 -226 -265 -376 415 -181 | wc -l
hundred4:
	./a.out -50 51 -412 -471 273 175 -169 214 387 -263 455 -244 368 488 -229 265 -354 -163 -435 93 447 294 500 277 88 243 -498 -125 191 90 246 -197 115 160 463 406 308 443 -369 371 76 233 343 -122 -8 -333 -56 494 314 -21 -39 -38 330 295 63 -167 -218 412 -213 -433 -423 35 -205 182 -460 4 476 486 439 124 -468 432 -41 452 206 -120 241 -155 351 290 250 293 -373 216 263 101 369 -30 297 97 65 -97 -81 -441 44 218 450 -19 -291 451 | wc -l
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

.PHONY: all clean fclean re bonus