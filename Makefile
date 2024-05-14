# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 18:48:10 by rmarin-j          #+#    #+#              #
#    Updated: 2024/05/14 17:35:19 by rmarin-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
CFLAGS	:= -g -Wextra -Wall -Werror -Wunreachable-code
MLX_DIR = ./MLX42
MLX		:= $(MLX_DIR)/libmlx42.a
CC = gcc
HEADERS	:= -I$(MLX)
SRCS	:= so_long.c \
	hooks.c \
	GNL/get_next_line.c GNL/get_next_line_utils.c \
	PRINTF/ft_printf.c PRINTF/printf_utils.c \
	utils/utils_1.c utils/utils_2.c utils/map_checks.c utils/set_images.c utils/map_print.c
		
OBJS	:= ${SRCS:.c=.o}
all: $(NAME)
libmlx:
	@make -C $(MLX_DIR)
%.o: %.c
#	@$(CC) -g -o $@ -c $< && printf "Compiling: $(notdir $<)"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLX) $(HEADERS) -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ -o $(NAME)
clean:
	@rm -rf $(OBJS)
fclean: clean
	@rm -rf $(NAME)
re: clean all
.PHONY: all, clean, fclean, re, libmlx