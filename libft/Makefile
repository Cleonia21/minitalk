NAME		=	libft.a

SOURCES		=	ft_strlcat.c ft_strtrim.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
				ft_putnbr_fd.c ft_strmapi.c ft_strjoin.c ft_substr.c ft_strlcpy.c ft_memmove.c\
				ft_memcpy.c ft_memchr.c ft_memset.c ft_calloc.c ft_bzero.c ft_strnstr.c ft_strchr.c\
				ft_strdup.c ft_strncmp.c ft_memcmp.c ft_atoi.c ft_strlen.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
				ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c ft_strrchr.c ft_itoa.c ft_memccpy.c\

OBJECTS		=	ft_strlcat.o ft_strtrim.o ft_split.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o\
				ft_putnbr_fd.o ft_strmapi.o ft_strjoin.o ft_substr.o ft_strlcpy.o ft_memmove.o\
				ft_memcpy.o ft_memchr.o ft_memset.o ft_calloc.o ft_bzero.o ft_strnstr.o ft_strchr.o\
				ft_strdup.o ft_strncmp.o ft_memcmp.o ft_atoi.o ft_strlen.o ft_isalnum.o ft_isalpha.o ft_isascii.o\
				ft_isdigit.o ft_isprint.o ft_tolower.o ft_toupper.o ft_strrchr.o ft_itoa.o ft_memccpy.o\

all:			$(NAME)

$(NAME)		:
				gcc -c -Werror -Wall -Wextra $(SOURCES)
				ar r $(NAME) $(OBJECTS)
				ranlib $(NAME)

clean		:
				-rm -f $(OBJECTS)

fclean		:	clean
				-rm $(NAME)

re			:	fclean $(NAME)

.PHONY		:
				all clean fclean re