# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 14:55:47 by kbakhari          #+#    #+#              #
#    Updated: 2019/02/04 15:28:43 by kbakhari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FT = *.c

OBJ = *.o


all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(FT) -I./includes
	@ar -rv $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
