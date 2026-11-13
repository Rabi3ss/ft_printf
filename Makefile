NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
CC = cc

SRC = ft_printf.c ft_putaddres.c ft_putunsi.c \
	ft_putchar.c ft_puthex.c \
	ft_putnbr.c ft_putstr.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re