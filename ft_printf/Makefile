NAME		= 	libftprintf.a
SRC_DIR_LIB	= 	../libft/
SRC_DIR		= 	./srcs/
HEADER		= 	printf.h
SRC_F		= 	ft_argv_char.c ft_argv_num.c ft_argv_pointer.c ft_argv_str.c ft_check_arg.c\
				ft_print_sumbols.c ft_printf.c ft_put_trimmed_str.c ft_type_redirection.c ft_putchar.c\
				ft_convert_to_six.c ft_numlen.c  ft_make_options.c\

SRCS_F_LIB	=	ft_itoa.c ft_strlen.c\

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_F))
SRCS_LIB	=	$(addprefix $(SRC_DIR_LIB), $(SRCS_F_LIB))
OBJS		=	$(SRCS:.c=.o)
OBJS_LIB	=	$(SRCS_LIB:.c=.o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
AR			=	ar
ARFLAGS		=	rc
RM			=	rm -f

.c.o:		
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(OBJS_LIB)
			@make -sC ../libft/ all
			$(AR) $(ARFLAGS) $(NAME) $?

all:		$(NAME)

clean:		
			$(RM) $(OBJS) $(SRCS_D)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clear fclean re