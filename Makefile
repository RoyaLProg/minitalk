CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
SERV_SRC = server.c\
			libftprintf/libftprintf.a
CLIENT_SRC = client.c\
				ft_atoi.c\
				ft_isdigit.c
LIBFTPRINTF = libftprintf/libftprintf.a
NAME=minitalk

all: $(NAME)

$(NAME): server client

server:
	$(CC) $(CFLAGS) $(SERV_SRC) -o server

client:
	$(CC) $(CFLAGS) $(CLIENT_SRC) -o client
