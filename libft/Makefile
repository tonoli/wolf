# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 18:25:44 by itonoli-          #+#    #+#              #
#    Updated: 2017/07/02 22:27:51 by itonoli-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SELL COLORS
LRED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
LBLUE = \033[34;1m
PINK = \033[35m
LCYAN = \033[36m
END = \033[0m

# NAME
NAME = libft.a

#COMPILATION
CC= gcc
FLAGS= -Wall -Wextra -Werror

#SOURCES AND OBJECTS
SRC_NAME= ft_memset.c \
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
ft_strchr.c \
ft_strrchr.c \
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
ft_strnequ.c \
ft_strsub.c \
ft_strjoin.c \
ft_strtrim.c \
ft_strsub.c \
ft_strsplit.c \
ft_itoa.c \
ft_putchar.c \
ft_putstr.c \
ft_putendl.c \
ft_putnbr.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_lstadd.c \
ft_lstdel.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstmap.c \
ft_lstnew.c \
ft_iswhite.c \
ft_islower.c \
ft_isupper.c \
ft_lstadd_back.c \
ft_lstsize.c \
ft_join.c \
get_next_line.c \
ft_char_counter.c \
ft_puterror.c \
ft_tablen.c \
ft_memtab.c \
ft_power.c \
ft_strtol.c \
ft_swap

OBJ_NAME= $(SRC_NAME:.c=.o)

SRC_PATH = src/
OBJ_PATH = obj/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))


all: $(NAME)

$(NAME):$(OBJ)
	@ ar rc  $(NAME) $(OBJ)
	@ ranlib $(NAME)
	@ echo  "$(PINK)L$(END)$(LBLUE)I$(END)$(YELLOW)B$(END)$(GREEN)F$(END)$(LRED)T $(END):$(GREEN) Compilation done !$(END)"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(FLAGS) -o $@ -c $<

clean:
	@ rm -rf $(OBJ_PATH)

fclean: clean
	@ rm -f $(NAME)

norm:
	@ echo "\033[34;1mNorminette...\033[0m"
	@ norminette src inc

re: fclean  all

.PHONY: fclean all clean
