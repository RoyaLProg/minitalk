CC = gcc
CFLAGS = -Wall -Wextra -Werror
SERV_SRC = server.c\
			ft_strlcpy.c
CLIENT_SRC = client.c\
				ft_atoi.c\
				ft_isdigit.c
NAME = minitalk
LIBFTPRINTF = libftprintf/libftprintf.a
SERV_OBJ = $(SERV_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
OBJS = $(SERV_OBJ)
OBJS += $(CLIENT_OBJ) 
all: $(NAME)

$(NAME): server client

server: $(SERV_OBJ)
	$(CC) $(SERV_OBJ) $(LIBFTPRINTF) -o server

client: $(CLIENT_OBJ)
	$(CC) $(CLIENT_OBJ) $(LIBFTPRINTF) -o client

clean:
	rm $(OBJS)

fclean: clean
	rm server client

re: fclean all

.o: .c
	$(CC) -o $@ -c $< $(CFLAGS)
