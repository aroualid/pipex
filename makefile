# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 15:56:31 by aroualid          #+#    #+#              #
#    Updated: 2024/06/13 14:30:42 by aroualid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIGHT_RED=\033[1;31m
LIGHT_GREEN=\033[1;32m
LIGHT_YELLOW=\033[1;33m
LIGHT_BLUE=\033[1;34m
LIGHT_MAGENTA=\033[1;35m
LIGHT_CYAN=\033[1;36m
WHITE=\033[1;37m
LIGHT_GRAY=\033[0;37m
DARK_GRAY=\033[1;30m
LIGHT_PURPLE=\033[1;35m

CC = cc
CFLAGS=  -Wall -Wextra -Werror  -g3
SRCS = ft_calloc.c ft_strjoin.c ft_strncmp.c pars.c \
	   ft_bzero.c ft_split.c ft_strlen.c utils.c exec.c utils2.c
BNS =  ft_calloc.c ft_strjoin.c ft_strncmp.c pars.c \
	   ft_bzero.c ft_split.c ft_strlen.c utils.c exec_bonus.c \
	   apply_exec_bonus.c utils2.c
OBJS = $(SRCS:%.c=%.o)
OBJS_BNS = $(BNS:%.c=%.o)
NAME = pipex
NAME_BONUS = pipex_bonus

.PHONY: all clean fclean re bonus

all:  $(NAME) 

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BNS)
fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
re: fclean all

bonus: $(OBJS_BNS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BNS)
