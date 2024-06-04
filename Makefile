CFILES = server.c client.c helper.c
BONUS_FILES = server_bonus.c client_bonus.c helper.c
CFLAGS = -Wall -Wextra -Werror
NAME1 = server
NAME2 = client
NAME1_B = server_bonus
NAME2_B = client_bonus
MY_PRINT = my_printf/libftprintf.a
OBJ = $(CFILES:.c=.o)
B_OBJ = $(BONUS_FILES:.c=.o)

all : $(NAME1) $(NAME2) $(MY_PRINT)

$(NAME1) : $(OBJ) $(MY_PRINT)
	cc $(CFLAGS)  server.o helper.o $(MY_PRINT) -o $@

$(NAME2) : $(OBJ) $(MY_PRINT)
	cc $(CFLAGS) client.o helper.o $(MY_PRINT) -o $@

%.o : %.c minitalk.h minitalk_bonus.h
	cc $(CFLAGS) -c $< -o $@ 

$(MY_PRINT) :
	make -C my_printf

bonus:  $(NAME1_B) $(NAME2_B) $(MY_PRINT)

$(NAME1_B) : $(B_OBJ) $(MY_PRINT)
	cc $(CFLAGS)  server_bonus.o helper.o $(MY_PRINT) -o $@

$(NAME2_B) : $(B_OBJ) $(MY_PRINT)
	cc $(CFLAGS) client_bonus.o helper.o $(MY_PRINT) -o $@

clean :
	rm -rf *.o
	@make clean -C my_printf

fclean : clean
	rm -rf $(NAME1) $(NAME2)
	rm -rf $(NAME1_B) $(NAME2_B)
	@make fclean -C my_printf

re : fclean all

.PHONY : all clean fclean re bonus