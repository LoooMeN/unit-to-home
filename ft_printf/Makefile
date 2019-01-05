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

NAME: ft_printf

all:
	@gcc -c -Wall -Wextra -Werror ./srcs/*.c -Iincludes/*
	@gcc *.o -o ft_printf -L./libft -lft
	
clean:
	@rm -rf *.o

fclean: clean
	@rm -rf ft_printf

re: fclean all
