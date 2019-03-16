# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 15:52:13 by nvienot           #+#    #+#              #
#    Updated: 2019/03/16 18:18:24 by nvienot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

SRCS	=	srcs/main.c srcs/ft_start.c srcs/ft_multithreading.c \
			srcs/ft_create.c srcs/ft_utilities.c srcs/ft_calc.c \
			srcs/ft_vignettes.c srcs/ft_deal_key.c srcs/ft_deal_mouse.c \
			srcs/ft_print.c 

CC		=	gcc

INC.	=	-I libft/ -I includes/ -I mlx/

INCL	=	libft/ includes/

FLAGS	=  -Wall -Werror -Wextra -O2

OBJS	=	$(SRCS:.c=.o)

F.WORK	=	-lpthread -lmlx -L mlx -framework OpenGL -framework Appkit

LIB		=	libft/libft.a

RM		=	rm -rf

.SILENT	:

.PHONY	: 	all clean fclean re

#Colors
_BLACK=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m

_END=\x1b[0m

all		:	$(NAME)

$(NAME)	:	$(OBJS) Makefile includes/fractol.h
			make -C libft/
			echo "$(_RED)Compiling libft... $(_GREEN)Done$(_END)"
			make -C mlx/
			echo "$(_RED)Compiling mlx... $(_GREEN)Done$(_END)"
			$(CC) -o $(NAME) $(OBJS) $(LIB) $(F.WORK)
			
			echo "$(_RED) _____              _    _      _    _                           _         _    "
			echo "$(_RED)|  ___|            | |  ( )    | |  (_)                         | |       | |   "
			echo "$(_BLUE)| |_ _ __ __ _  ___| |_ |/ ___ | |   _ ___    _ __ ___  __ _  __| |_   _  | |   "
			echo "$(_PURPLE)|  _| '__/ _  |/ __| __|  / _ \| |  | / __|  | '__/ _ \/ _  |/ _  | | | | | |  "
			echo "$(_CYAN)| | | | | (_| | (__| |_  | (_) | |  | \__ \  | | |  __/ (_| | (_| | |_| | |_|  "
			echo "$(_GREEN)\_| |_|  \__,_|\___|\__|  \___/|_|  |_|___/  |_|  \___|\__,_|\__,_|\__, | (_) "
			echo "$(_YELLOW)                                                                    __/ |    "
			echo "$(_WHITE)By $(_RED)nvienot $(_GREEN)2019 $(_YELLOW)!$(_WHITE)!$(_END)                                                 |___/     \n"

$(OBJS)	: 	%.o: %.c
			$(CC) $(FLAGS) $(INC.) -c $< -o $@

clean	:
			@$(RM) $(OBJS)
			make clean -C libft/
			make clean -C mlx/

			echo "$(_RED)Cleaning... $(_GREEN)Done$(_END)"

fclean	:	clean
			@$(RM) $(NAME)
			make fclean -C libft/

			echo "$(_RED)Deleting... $(_GREEN)Done$(_END)"

re		:	fclean all
			make re -C libft/
			make re -C mlx/

recl	:	all clean
			make recl -C libft/

norm	:	fclean
			echo "$(_RED)Starting norminette...$(_END)"
			norminette $(SRCS) $(INCL) | grep -B 1 '^Error' 2> /dev/null && echo "$(_RED)Norm KO :(" || echo "$(_GREEN)Norm OK ! :)$(_END)";
