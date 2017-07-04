# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/26 17:44:42 by itonoli-          #+#    #+#              #
#    Updated: 2017/07/04 03:40:13 by itonoli-         ###   ########.fr        #
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


#PROGRAM NAME
NAME = wolf3d

#SOURCES AND OBJECTS
SRC_NAME = main.c \
error.c \
hooks.c \
init.c \
parse.c \
raycast.c


OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = src/
OBJ_PATH = obj/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

#COMPILATION
CC = gcc
FLAGS = -Wall -Wextra -Werror -I.inc

#LIBRARY
LIBFT  = -L./libft -lft
MLX = -L./minilibx -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME):$(OBJ)
		@ make -C libft/
		@ make -C minilibx/
		@ $(CC) $(FLAGS) $(LIBFT) $(MLX) $^ -o $@
		@ echo "$(GREEN)Compilation done : Wold3D is ready to be used$(END)"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
		@ mkdir -p $(OBJ_PATH)
		@ $(CC) $(FLAGS) -o $@ -c $<

rtv1_only:
		@ $(CC) $(FLAGS) -I libft/ -I./minilibx/ -c $(SRC)
		@ $(CC) $(FLAGS) -g -o $(NAME) $(OBJ) $(LIBFT) $(MLX)
		@ echo "$(GREEN)Compilation done : Wold3D is ready to be used$(END)"

clean:
		@ echo "$(YELLOW)Cleaning the following files: $(END)"
		@ make -C libft/ clean
		@ make -C minilibx/ clean
		  rm -vf $(OBJ)
		@ rm -rfv $(OBJ_PATH)
		@ echo "$(PINK)The cleaning is done my friend!$(END)"

fclean: clean
		  rm -vf $(NAME)
		@ make -C libft/ fclean
		@ make -C minilibx/ fclean
		@ echo "$(PINK)The cleaning is done my friend!$(END)"

norm:
		@ echo "$(LBLUE)Norminette...$(END)"
		@ norminette src inc

re: 	fclean all

.PHONY: fclean all clean norm rtv1_only
