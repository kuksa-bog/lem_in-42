# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/15 12:53:31 by bkuksa            #+#    #+#              #
#    Updated: 2019/05/15 12:53:33 by bkuksa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCS := srcs/main.c
SRCS += srcs/help_lem.c
SRCS += srcs/valid.c
SRCS += srcs/valid_2.c
SRCS += srcs/valid_3.c
SRCS += srcs/alg.c
SRCS += srcs/alg_1_1.c
SRCS += srcs/alg_1_2.c
SRCS += srcs/alg_1_3.c


FLAGS = -Wall -Werror -Wextra -I./includes

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
