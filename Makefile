# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/23 23:49:54 by taejkim           #+#    #+#              #
#    Updated: 2021/07/24 03:10:18 by taejkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRC_S = server.c
SRC_C = client.c
SRC_U = utils.c string.c

OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)
OBJ_U = $(SRC_U:.c=.o)


all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_S) $(OBJ_U)
			$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): $(OBJ_C) $(OBJ_U)
			$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ_S) $(OBJ_C) $(OBJ_U)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
