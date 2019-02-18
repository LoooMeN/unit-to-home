# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 15:12:54 by kbakhari          #+#    #+#              #
#    Updated: 2019/02/11 06:10:22 by kbakhari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = kbakhari.filler

FLAGS = -Werror -Wextra -Wall


all: $(NAME)

$(NAME):
	@make -C libft
	@cp ./libft/libft.a ./
	@gcc $(FLAGS) ./src/*.c -Iinclude -lft -L./ -o $(NAME)

clean:
	@rm -rf *.o
	@make clean -C libft

fclean: clean
	@rm -rf $(NAME) libft.a
	@make fclean -C libft

re: fclean all
