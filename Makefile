NAME        =    libftprintf.a

IDIR        =    ft_printf.h

SRCS		=	ft_printf.c \
				ft_printf_utils.c \
				ft_print_cspdi.c \

OBJS		=	$(SRCS:.c=.o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -c
RM			=	rm -f
NORM		=	norminette *.h && norminette *.c 

all			:	$(NAME)

$(NAME)		:	$(OBJS)
	cd libft && $(MAKE)
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) $(SRCS)
	ar rcs $(NAME) $(OBJS)

n			:
	$(NORM)

clean		:
	$(RM) $(OBJS)
	$(MAKE) clean -C ./libft

fclean		:	clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libft

re			:	fclean all

.PHONY:		all clean fclean re bonus
