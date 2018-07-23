# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgonor <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/04 15:56:34 by dgonor            #+#    #+#              #
#    Updated: 2017/11/04 16:28:43 by dgonor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIB = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

SRCS = del_data.c lem_in.c move_objects.c pars_lem_in.c set_data.c \
shortest_path.c valid_data.c adjacency_list.c check_data.c \
ways_management.c del_management.c print_data.c \

OBJS = $(SRCS:.c=.o)

HEADERS = ft_lem.h

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	@gcc -c $(SRCS) -Wall -Wextra -Werror
	@gcc $(OBJS) $(LIB) -o $(NAME)
	@echo "\x1b[35mYour PROGRAM $(NAME) has been successfully created!\x1b[0m"

$(LIB):
	@make -C libft

clean:
	@make -C libft clean
	@rm -rf $(OBJS)
	@echo "\x1b[36mObject files $(NAME) have been deleted!\x1b[0m"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "\x1b[32mExecutable files $(NAME) have been deleted!\x1b[0m"

re: fclean all

.PHONY: all clean fclean re