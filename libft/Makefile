<<<<<<< HEAD
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 14:27:46 by pitriche          #+#    #+#              #
#    Updated: 2019/05/13 13:43:25 by pitriche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREY    = \033[030m
RED     = \033[031m
GREEN   = \033[032m
YELLOW  = \033[033m
BLUE    = \033[034m
MAGENTA = \033[035m
CYAN	= \033[036m
RESET   = \033[0m

# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Werror -Wextra
CFLAGS = -c $(FLAGS)

NAME = libft.a

SRC = \
pr_vasprintf.c\
formatting_raw.c\
formatting_flags.c\
formatting_flags_2.c\
formatting_part_cases.c\
formatting_floats.c\
\
ft_vasprintf.c\
ft_asprintf.c\
ft_dprintf.c\
ft_printf.c\
\
get_next_line.c\
\
ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c ft_strdup.c\
ft_strjoin_free.c ft_bzero.c ft_memalloc.c ft_strcpy.c ft_strndup.c\
ft_strnew.c ft_memcpy.c ft_strchr.c ft_lltos_base.c ft_strrev.c\
ft_ulltos_base.c ft_strncpy.c ft_memset.c ft_memmove.c ft_putnbr.c\
ft_putchar.c ft_toupper.c ft_tolower.c ft_strtrim.c ft_strtrim.c ft_strsub.c\
ft_strstr.c ft_strsplit.c ft_strrchr.c ft_strnstr.c ft_strnequ.c\
ft_strncpy_bw.c ft_strncmp.c ft_strncat.c ft_strmapi.c ft_strmap.c\
ft_strlcat.c ft_strjoin.c ft_striteri.c ft_striter.c ft_strequ.c ft_strdel.c\
ft_strcmp.c ft_strclr.c ft_strcat.c ft_putstr.c ft_putendl.c ft_putendl_fd.c\
ft_print_words_tables.c ft_memdup.c ft_memdel.c ft_memcmp.c ft_memchr.c\
ft_memccpy.c ft_lstnew.c ft_lstnew_empty.c ft_lstmap.c ft_lstiter.c\
ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_itoa.c ft_isspace.c ft_isprint.c\
ft_isdigit.c ft_isascii.c ft_isalpha.c ft_isalnum.c ft_atoi.c ft_lstrev.c\
ft_swap.c ft_pr_err.c ft_lstsort.c ft_longlen.c ft_lst_free_data.c\
ft_lst_free.c ft_pr_errno.c gnlite.c\

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)
	@echo "$(CYAN)Libft ready sir !$(RESET)"

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@

$(addprefix $(OBJ_DIR), %.o) : %.c
	@$(CC) $(CFLAGS) -o $@ $<
	@echo -n '.'

# $(LIB) :
#	make -C libft

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
=======
NAME = libft.a

SRC = ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strrchr.c \
	ft_strchr.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strnequ.c \
	ft_strsplit.c \
	ft_strtrim.c \
	ft_itoa.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_is_prime.c \
	ft_sqrt.c \
	ft_swap.c \
	ft_power.c \
	ft_isblank.c \
	get_next_line.c

OBJ = $(SRC:.c=.o)

	
all : $(NAME)

$(NAME) : $(OBJ)
	@gcc -c  -Wall -Wextra -Werror $(SRC)
	@ar rc $(NAME) $(OBJ)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

cp : re
	@gcc -Wall -Wextra -Werror $(NAME) ~/Desktop/main.c
	@rm -f $(OBJ)
	@./a.out

.PHONY : all, clean, fclean, re, cp
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
