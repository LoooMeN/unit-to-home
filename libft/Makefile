# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 14:55:47 by kbakhari          #+#    #+#              #
#    Updated: 2018/10/31 14:56:58 by kbakhari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FT = ./*.c

OBJ = *.o


all: $(NAME)

$(NAME):
	@gcc -c $(FT) -I./
	@ar -rv $(NAME) $(OBJ)
	@ranlib $(NAME)
	# @gcc -D LEAKS *.c -o dprintf

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
