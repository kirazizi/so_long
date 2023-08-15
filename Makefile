# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 19:46:23 by sbzizal           #+#    #+#              #
#    Updated: 2023/02/04 12:33:19 by sbzizal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = SO_LONG

CFLAGS = -Wall -Wextra -Werror

CC = cc

BFILES = get-next-line/get_next_line.c bonus/animation_enemy.c \
bonus/check_map.c bonus/part.c get-next-line/get_next_line_utils.c \
bonus/pars.c bonus/ft_itoa.c bonus/so_long_bonus.c \
bonus/move.c bonus/animation.c bonus/map.c bonus/put_bn.c \

MFILES = get-next-line/get_next_line.c mandatory/so_long.c mandatory/map_ma.c \
mandatory/move_ma.c get-next-line/get_next_line_utils.c mandatory/pars_ma.c \
mandatory/check_ma.c mandatory/put_ma.c \

BOFILES = $(BFILES:.c=.o)

MOFILES = $(MFILES:.c=.o)

all: $(NAME)

$(NAME): $(MOFILES)
	$(CC) $(MOFILES) -lmlx -framework OpenGL -framework AppKit -o so_long

bonus: $(BOFILES) 
	$(CC) $(BOFILES) -lmlx -framework OpenGL -framework AppKit -o so_long_bonus

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BOFILES) $(MOFILES) 

fclean: clean
	rm -f so_long so_long_bonus

re: fclean all bonus

PHONY: all clean fclean re