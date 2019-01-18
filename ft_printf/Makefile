# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/04 16:57:53 by kbakhari          #+#    #+#              #
#    Updated: 2019/01/05 14:53:11 by kbakhari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

all: $(NAME)

$(NAME):
	@gcc -c ./srcs/*.c -Iincludes/*
	@gcc *.o -o ft_printf -L./libft -lft test.c
	
clean:
	@rm -rf *.o

fclean: clean
	@rm -rf ft_printf

re: fclean all
