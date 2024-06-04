CC = cc
CFILES = ft_printf.c ft_tools.c ft_tools2.c
CFLAGS = -Wall -Wextra -Werror
OBJ = $(CFILES:.c=.o)
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $@ $^

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
