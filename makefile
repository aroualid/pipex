# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 15:56:31 by aroualid          #+#    #+#              #
#    Updated: 2024/03/22 16:37:37 by aroualid         ###   ########.fr        #
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
SRCS = exec.c ft_calloc.c ft_strjoin.c ft_strncmp.c utils.c \
	   ft_bzero.c ft_split.c ft_strlen.c main.c

OBJS = $(SRCS:%.c=%.o)
NAME = pipex

.PHONY: all clean fclean re libft

all:  $(NAME) 
#	@echo "$(LIGHT_CYAN)Starting tasks..."
#	@i=0; while [ $$i -le 100 ]; do \
#        echo -n "Progress: [$$i%] "; \
#        printf "$(LIGHT_GREEN)=%.0s" $$(seq 1 $$((i / 2))); \
#        printf " "; \
#        printf "$(LIGHT_BLUE)%.0s" $$(seq $$((i / 2 + 1)) 50); \
#        echo -n "\r"; \
#        sleep 0.02; \
#        i=$$((i+1)); \
#    done
#	@echo "$(LIGHT_MAGENTA)All tasks completed !                                                                "

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

