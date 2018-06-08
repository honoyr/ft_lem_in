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

NAME = libft.a

SRC = ft_atoi.c ft_isalpha.c ft_isalnum.c ft_bzero.c ft_countsize.c ft_isascii.c \
ft_isdigit.c ft_isspace.c ft_isprint.c ft_lstadd.c ft_lstback.c ft_lstiter.c \
ft_itoa.c ft_lstdel.c ft_lstdelone.c ft_lstlen.c ft_lstmswap.c ft_lstmap.c \
ft_lstprint.c ft_lstnew.c ft_memalloc.c ft_memchr.c ft_memccpy.c ft_memdel.c \
ft_memcpy.c ft_memcmp.c ft_putchar.c ft_memmove.c ft_plusminus.c ft_memset.c \
ft_putchar_fd.c ft_putendl.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr.c \
ft_putnbr.c ft_putstr_fd.c ft_strchr.c ft_strclr.c ft_strcpy.c ft_strdel.c \
ft_strcat.c ft_strcmp.c ft_strdup.c ft_striteri.c ft_striter.c ft_strequ.c \
ft_strlen.c ft_strjoin.c ft_strlcat.c ft_strmap.c ft_strncat.c ft_strmapi.c \
ft_strncpy.c ft_strncmp.c ft_strnew.c ft_strrchr.c ft_strnequ.c ft_strstr.c \
ft_strnstr.c ft_strsub.c ft_strtrim.c ft_swap.c ft_tolower.c ft_toupper.c \
ft_strsplit.c ft_whitespaces.c ft_memdel_ar.c ft_strcheck.c \
ft_memdel_arlen.c ft_checklen.c ft_strljoin.c get_next_line.c\
print_hex.c rev_wstr.c ft_strrev.c ft_itoa_base.c print_base.c\
count_nbr.c \
type_o.c \
type_id.c \
type_p.c \
type_s.c \
type_su.c \
type_u.c \
type_und.c \
type_x.c \
ft_printf.c \
type_c.c \
type_cu.c \
ft_unicode.c \
ft_count_bait.c \
ft_width_pr.c \
ft_pointer_to_fu.c \
ft_pars_printf.c \
ft_pars_mod.c \
ft_data_mod.c \

FLAGSWWW = -Wall -Wextra -Werror -c -I.

OL = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc $(SRC) $(FLAGSWWW)
	ar rc $(NAME) $(OL)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OL)

fclean: clean
	/bin/rm -f $(NAME)
	
re: fclean all
