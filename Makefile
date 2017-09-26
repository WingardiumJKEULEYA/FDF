# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkeuleya <jkeuleya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/21 12:10:15 by jkeuleya          #+#    #+#              #
#    Updated: 2015/01/21 12:10:17 by jkeuleya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = main.c fdf.c draw.c fill.c img.c get_next_line.c
HEADERS = fdf.h get_next_line.h
OBJ = $(SRC:.c=.o)
OPT = -Wall -Werror -Wextra
LIBS = -lm -L /usr/X11/lib -lmlx -lXext -lX11 -L libft -lft

all: $(NAME)

.PHONY: libft clean fclean re

$(NAME): libft
	@gcc $(OPT) -c $(SRC)
	@gcc -o $(NAME) $(OBJ) $(LIBS)

libft:
	@make -C libft fclean
	@make -C libft

clean:
	@/bin/rm -f $(OBJ) $(HEADERS:.h=.h.gch)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
