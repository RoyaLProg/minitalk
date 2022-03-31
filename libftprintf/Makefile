CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRCS = ft_printf.c\
	put_things.c\
	put_things2.c\
	tools.c
OBJS = $(SRCS:.c=.o)


all: $(NAME)

re: fclean $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)
	
fclean: clean
	rm -rf libftprintf.a

clean:
	rm -rf $(OBJS)
