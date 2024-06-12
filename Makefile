# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 14:11:15 by ael-abdi          #+#    #+#              #
#    Updated: 2024/06/11 10:11:47 by ael-abdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Werror -Wextra
LFOFA = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
obj = main.c utiles.c fractol_hook.c parsing_init.c mandelbrot_julia.c utiles1.c

OFILES = $(obj:.c=.o)
all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) $(LFOFA) -o ${NAME}

%.o : %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
